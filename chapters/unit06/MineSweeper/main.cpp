#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

constexpr int ROWS = 32;
constexpr int COLS = 32;
constexpr int MINE_PERCENT = 15;

struct Cell {
    bool isMine;
    bool revealed;
    bool flagged;
    int neighborCount;

    Cell* top;
    Cell* bottom;
    Cell* left;
    Cell* right;
    Cell* topLeft;
    Cell* topRight;
    Cell* bottomLeft;
    Cell* bottomRight;

    Cell()
        : isMine(false),
          revealed(false),
          flagged(false),
          neighborCount(0),
          top(nullptr),
          bottom(nullptr),
          left(nullptr),
          right(nullptr),
          topLeft(nullptr),
          topRight(nullptr),
          bottomLeft(nullptr),
          bottomRight(nullptr) {}
};

struct MinesweeperBoard {
    Cell* topLeft;

    MinesweeperBoard() : topLeft(nullptr) {}

    ~MinesweeperBoard() {
        Cell* grid[ROWS][COLS] = {};

        collectCells(grid);
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                delete grid[row][col];
            }
        }
        topLeft = nullptr;
    }

    void build() {
        Cell* grid[ROWS][COLS];

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                grid[row][col] = new Cell();
            }
        }

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                Cell* cell = grid[row][col];

                if (row > 0) {
                    cell->top = grid[row - 1][col];
                }
                if (row < ROWS - 1) {
                    cell->bottom = grid[row + 1][col];
                }
                if (col > 0) {
                    cell->left = grid[row][col - 1];
                }
                if (col < COLS - 1) {
                    cell->right = grid[row][col + 1];
                }
                if (row > 0 && col > 0) {
                    cell->topLeft = grid[row - 1][col - 1];
                }
                if (row > 0 && col < COLS - 1) {
                    cell->topRight = grid[row - 1][col + 1];
                }
                if (row < ROWS - 1 && col > 0) {
                    cell->bottomLeft = grid[row + 1][col - 1];
                }
                if (row < ROWS - 1 && col < COLS - 1) {
                    cell->bottomRight = grid[row + 1][col + 1];
                }
            }
        }

        topLeft = grid[0][0];
        placeMines();
        computeNeighborCounts();
    }

    void placeMines() {
        Cell* grid[ROWS][COLS] = {};
        collectCells(grid);

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                grid[row][col]->isMine = (rand() % 100) < MINE_PERCENT;
            }
        }
    }

    void computeNeighborCounts() {
        Cell* grid[ROWS][COLS] = {};
        collectCells(grid);

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                Cell* cell = grid[row][col];
                if (cell->isMine) {
                    cell->neighborCount = 0;
                    continue;
                }

                int count = 0;
                Cell* neighbors[8] = {
                    cell->top,         cell->bottom,       cell->left,        cell->right,
                    cell->topLeft,     cell->topRight,     cell->bottomLeft,  cell->bottomRight};

                for (Cell* neighbor : neighbors) {
                    if (neighbor && neighbor->isMine) {
                        count++;
                    }
                }

                cell->neighborCount = count;
            }
        }
    }

    bool reveal(Cell* cell) {
        if (!cell || cell->revealed || cell->flagged) {
            return true;
        }

        cell->revealed = true;

        if (cell->isMine) {
            return false;
        }

        if (cell->neighborCount == 0) {
            floodReveal(cell);
        }

        return true;
    }

    bool revealAt(int row, int col) {
        Cell* grid[ROWS][COLS] = {};
        collectCells(grid);

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            return true;
        }

        return reveal(grid[row][col]);
    }

    void printSolution() const {
        Cell* grid[ROWS][COLS] = {};
        collectCells(grid);

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                Cell* cell = grid[row][col];
                if (cell->isMine) {
                    cout << '*';
                } else {
                    cout << cell->neighborCount;
                }

                if (col < COLS - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    void printPlayerView() const {
        Cell* grid[ROWS][COLS] = {};
        collectCells(grid);

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                Cell* cell = grid[row][col];

                if (!cell->revealed) {
                    cout << (cell->flagged ? 'F' : '.');
                } else if (cell->isMine) {
                    cout << '*';
                } else {
                    cout << cell->neighborCount;
                }

                if (col < COLS - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    int countMines() const {
        int mines = 0;
        Cell* grid[ROWS][COLS] = {};
        collectCells(grid);

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                if (grid[row][col]->isMine) {
                    mines++;
                }
            }
        }

        return mines;
    }

private:
    void collectCells(Cell* grid[ROWS][COLS]) const {
        if (!topLeft) {
            return;
        }

        Cell* rowStart = topLeft;
        for (int row = 0; row < ROWS; ++row) {
            Cell* curr = rowStart;
            for (int col = 0; col < COLS; ++col) {
                grid[row][col] = curr;
                curr = curr->right;
            }
            rowStart = rowStart->bottom;
        }
    }

    void floodReveal(Cell* cell) {
        Cell* neighbors[8] = {
            cell->top,         cell->bottom,       cell->left,        cell->right,
            cell->topLeft,     cell->topRight,     cell->bottomLeft,  cell->bottomRight};

        for (Cell* neighbor : neighbors) {
            if (!neighbor || neighbor->revealed || neighbor->flagged || neighbor->isMine) {
                continue;
            }

            neighbor->revealed = true;
            if (neighbor->neighborCount == 0) {
                floodReveal(neighbor);
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    MinesweeperBoard board;
    board.build();

    cout << "32x32 Minesweeper board (linked grid)\n";
    cout << "Total mines: " << board.countMines() << "\n\n";
    cout << "Full solution view:\n";
    board.printSolution();

    cout << "\nPlayer view before revealing:\n";
    board.printPlayerView();

    cout << "\nRevealing top-left cell and flood-fill region:\n";
    board.revealAt(0, 0);
    board.printPlayerView();

    return 0;
}
