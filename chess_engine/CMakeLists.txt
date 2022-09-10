cmake_minimum_required(VERSION 3.10)

# set the project name
project(chess_engine)

# add the executable
add_executable(chess_engine main.cpp)


add_subdirectory(piece)

target_link_directories(${PROJECT_NAME} PUBLIC piece)
target_link_libraries(${PROJECT_NAME} piece)
