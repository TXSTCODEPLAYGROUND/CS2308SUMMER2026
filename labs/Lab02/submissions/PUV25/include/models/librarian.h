#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <string>

/**
 * Represents the single librarian who runs the library.
 *
 * In this prototype there is only one librarian. That object is created in
 * main.cpp and is responsible for managing the book inventory (adding and
 * deleting books via book_service).
 *
 * Fields:
 *   librarian_id   - Unique identifier for the librarian.
 *   librarian_name - Display name of the librarian.
 */
struct Librarian {
    std::string librarian_id;
    std::string librarian_name;
};

#endif
