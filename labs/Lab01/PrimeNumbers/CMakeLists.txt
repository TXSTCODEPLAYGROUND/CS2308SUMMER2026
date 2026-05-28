cmake_minimum_required(VERSION 4.1)
project(PrimeNumbers)

set(CMAKE_CXX_STANDARD 20)

add_executable(PrimeNumbers main.cpp src/tests/tests.cpp src/utils/utils.cpp)

target_include_directories(PrimeNumbers PRIVATE
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/src/utils
  ${CMAKE_SOURCE_DIR}/src/tests
)
