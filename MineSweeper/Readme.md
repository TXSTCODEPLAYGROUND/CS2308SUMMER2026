# Assignment: Minesweeper using Linked Structures

## Context

Minesweeper is a grid-based game where some cells contain mines and others are safe. When a safe cell is revealed, it shows how many of its neighboring cells contain mines.

Most implementations use a 2D array.

I do not want you to rely on that as your primary structure.

---

## How Minesweeper Works (Read This First)

### Goal

Reveal all safe cells without triggering a mine.

---

### Basic Rules

* The board is a grid (32 × 32 in this assignment)
* Some cells contain mines, others are safe
* When you reveal a cell:

    * If it is a mine → game over
    * If it is safe → it shows a number

---

### What the Number Means

Each number represents:

The number of mines in the 8 neighboring cells.

Neighbors include:

* top, bottom, left, right
* diagonals (top-left, top-right, bottom-left, bottom-right)

---

### Example

```text
. . .
. 2 .
. . .
```

The `2` means exactly two of the surrounding cells contain mines.

---

### Zero Behavior (Important)

If a cell has 0 neighboring mines:

* It reveals neighboring cells automatically
* This creates a flood-fill effect

---

### Optional Concept

* You can flag cells that you believe contain mines
* This is not required but can be implemented as an extension

---

## The Real Question

Can you extend linked list concepts to represent a 2D board?

Instead of thinking linearly, think in terms of connected nodes forming a grid.

---

## Your Task

Design and implement a 32 × 32 Minesweeper board using a linked data structure.

Each cell should behave like a node connected to its neighbors.

---

## What Each Cell Should Store

Each node should contain:

* whether it is a mine
* whether it is revealed
* whether it is flagged
* number of neighboring mines
* pointers to neighboring cells

---

## Required Neighbor Connections

At minimum:

* top
* bottom
* left
* right

Recommended:

* top-left
* top-right
* bottom-left
* bottom-right

---

## Requirements

Your program must:

1. Create a 32 × 32 grid of nodes
2. Link all nodes properly using pointers
3. Randomly generate mines across the board
4. Compute neighboring mine counts
5. Print the board

---

## Important Constraint

After building the structure:

* Traverse using only pointers
* Avoid relying on `board[i][j]` for logic
* Treat this as a linked grid or graph

---

## Example: Real Minesweeper Grid (Partial View)

Legend:

* `*` → mine
* `0` → no neighboring mines
* `1–8` → number of neighboring mines

```text
0 0 1 * 1 0 0 0
0 0 1 1 1 0 1 1
0 0 0 0 0 0 1 *
1 1 0 0 0 0 1 1
* 1 0 1 1 1 0 0
1 1 0 1 * 1 0 0
0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0
```

---

## What You Should Observe

* Cells with 0 form connected regions
* Numbers depend entirely on neighboring cells
* Mine counts must be computed using neighbors

---

## How This Connects to Your Task

To produce this type of board:

* Each node must access its neighbors
* Mine counts must be computed using linked pointers
* Zero regions naturally lead to graph traversal problems

---

## Think About This

* How will you build and connect all nodes?
* How will you handle edges and corners?
* How will you avoid infinite loops during traversal?
* How will you compute neighboring mine counts?
* Can you move across the board without indexing?

---

## Deliverables

You should provide:

* A `Node` or `Cell` structure
* A `Board` or `Minesweeper` structure
* Linked neighbor connections
* Random mine generation
* Neighbor mine count computation
* A printable board

---

## Extensions (Optional)

* Implement reveal logic
* Implement flood-fill (DFS or BFS) -- ADVANCE may be after Data Structure Class
* Add flagging functionality
* Detect win/loss conditions
* Build a playable terminal version

---

## Keep in mind..

This is not just a linked list.

This is a linked grid structure.

The goal is to see whether you can take the idea of linked lists and extend it into a multi-directional, board-based representation.

If you can do this cleanly, you understand pointers at a much deeper level.
