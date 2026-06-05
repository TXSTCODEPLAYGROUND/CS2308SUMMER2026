#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

struct Book {
    std::string isbn;
    std::string title;
    int total_count;
    int available_count;
    int rented_count;
};

struct Books {
    std::vector<Book> items;
};

#endif
