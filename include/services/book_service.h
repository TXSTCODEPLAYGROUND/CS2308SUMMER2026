#ifndef BOOK_SERVICE_H
#define BOOK_SERVICE_H

#include <string>

#include "models/book.h"

/**
 * Adds a new book to the library inventory.
 *
 * Called by the librarian to register a title on the shelf. Creates one Book
 * record and appends it to the Books collection.
 *
 * Parameters:
 *   books - The library's book collection to update.
 *   isbn  - Unique identifier; must not match an existing book.
 *   title - Human-readable book title.
 *   count - Number of physical copies to add (sets total_count and
 *           available_count; rented_count starts at 0).
 *
 * If a book with the same ISBN already exists, the add is skipped and a
 * message is printed to stdout.
 */
void add_book(Books& books, const std::string& isbn, const std::string& title, int count);
bool delete_book(Books& books, const std::string& isbn);
Book* find_book_by_isbn(Books& books, const std::string& isbn);
void display_books(const Books& books);

#endif
