cmake_minimum_required(VERSION 3.16)
project(GameOfLife CXX)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_MakeAvailable(googletest)

add_library(GameOfLife src/Game.cpp src/Board.cpp)
target_include_directories(GameOfLife PUBLIC include)

add_executable(test src/GameTests.cpp src/BoardTests.cpp)
target_link_libraries(test gtest_main GameOfLife)

add_executable(Game src/main.cpp)
target_link_libraries(Game GameOfLife)