#include "services/book_service.h"

#include <iostream>

// Complete this file
void add_book(Books& books, const std::string& isbn, const std::string& title, int count) {
    Book book;
    book.isbn = isbn;
    book.title = title;
    book.total_count = count;
    book.available_count = count;
    book.rented_count = 0;
    books.items.push_back(book);
}

Book* find_book_by_isbn(
    Books& books,
    const std::string& isbn) {

    for (Book& book : books.items) {
        if (book.isbn == isbn) return &book;
    }
    return nullptr;
};
