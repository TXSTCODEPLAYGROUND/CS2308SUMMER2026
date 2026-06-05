#include "services/book_service.h" 

#include <iostream>

Book* find_book_by_isbn(Books& books, const std::string& isbn) {
    for (auto& book : books.items) {
        if (book.isbn == isbn) {
            return &book;
        }
    }
    return nullptr;
}

void add_book(Books& books, const std::string& isbn, const std::string& title, int count) {
    if (count <= 0) {
        std::cout << "Cannot add book '" << title << "': count must be positive.\n";
        return;
    }

    if (find_book_by_isbn(books, isbn) != nullptr) {
        std::cout << "Book with ISBN " << isbn << " already exists. Skipping add.\n";
        return;
    }

    Book book;
    book.isbn = isbn;
    book.title = title;
    book.total_count = count;
    book.available_count = count;
    book.rented_count = 0;

    books.items.push_back(book);
    std::cout << "Added book: " << title << " (" << isbn << ") count=" << count << "\n";
}

bool delete_book(Books& books, const std::string& isbn) {
    for (auto it = books.items.begin(); it != books.items.end(); ++it) {
        if (it->isbn == isbn) {
            if (it->rented_count != 0) {
                std::cout << "Cannot delete book " << it->title << " because it is currently rented.\n";
                return false;
            }
            books.items.erase(it);
            std::cout << "Deleted book with ISBN " << isbn << "\n";
            return true;
        }
    }
    std::cout << "Book with ISBN " << isbn << " not found.\n";
    return false;
}

void display_books(const Books& books) {
    std::cout << "Library Inventory:\n";
    std::cout << "ISBN\tTitle\tAvailable\tRented\tTotal\n";
    for (const auto& book : books.items) {
        std::cout << book.isbn << "\t" << book.title << "\t"
                  << book.available_count << "\t" << book.rented_count << "\t"
                  << book.total_count << "\n";
    }
}



