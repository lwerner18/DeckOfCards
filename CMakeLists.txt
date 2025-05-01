cmake_minimum_required(VERSION 3.14)
project(deck_of_cards)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.16.0 
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(card
    card.cpp
)

add_library(deck
    deck.cpp
)

add_executable(
  tests
  tests.cpp
)
target_link_libraries(
  tests
  card
  deck
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)