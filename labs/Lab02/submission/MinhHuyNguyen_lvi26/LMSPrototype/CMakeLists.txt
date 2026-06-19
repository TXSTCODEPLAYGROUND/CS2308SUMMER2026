cmake_minimum_required(VERSION 4.1)
project(LMSPrototype)

set(CMAKE_CXX_STANDARD 20)

add_executable(LMSPrototype
    main.cpp
    src/models/librarian.cpp
    src/models/book.cpp
    src/models/student.cpp
    src/models/borrow_record.cpp
    src/services/book_service.cpp
    src/services/student_service.cpp
    src/services/rental_service.cpp
)

target_include_directories(LMSPrototype PRIVATE ${CMAKE_SOURCE_DIR}/include)
