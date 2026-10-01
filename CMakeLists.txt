cmake_minimum_required(VERSION 3.16)
project(settle CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_library(settle STATIC
  src/io.cpp
  src/net_balance.cpp
)
target_include_directories(settle PUBLIC includes)
target_compile_options(settle PRIVATE -Wall -Wextra -Wshadow)

# Debug builds run under AddressSanitizer + UndefinedBehaviorSanitizer.
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(settle PUBLIC -fsanitize=address,undefined -fno-omit-frame-pointer -g)
  target_link_options(settle PUBLIC -fsanitize=address,undefined)
endif()

# --- tests -----------------------------------------------------------------
# Add each new test executable to UNIT_TESTS (and an add_test line below it).
set(UNIT_TESTS test_task1)

set(CMAKE_CTEST_ARGUMENTS "--output-on-failure")
enable_testing()

add_executable(test_task1 tests/unit/test_task1.cpp)
target_link_libraries(test_task1 PRIVATE settle)
target_compile_options(test_task1 PRIVATE -Wall -Wextra -Wshadow)
add_test(NAME task1 COMMAND test_task1)

# --- make targets ------------------------------------------------------------
#   make         build library + all tests (default target)
#   make test    run already-built tests via ctest (built-in target, does not rebuild)
#   make unit    rebuild the tests, then run them
#   make clean   built-in: remove build outputs
add_custom_target(unit
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
  DEPENDS ${UNIT_TESTS}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  USES_TERMINAL
  COMMENT "Building and running unit tests")