cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)
# set the project name
project(chess_engine)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)

#get the sfml lib
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# add the executable
add_executable(chess_engine main.cpp piece/piece.cpp  board/board.cpp)

add_subdirectory(piece)
add_subdirectory(board)

target_include_directories(chess_engine
 PUBLIC
  piece/
  board/
 ) 
target_link_directories(${PROJECT_NAME} PUBLIC piece board)
target_link_libraries(${PROJECT_NAME} piece board sfml-graphics)
