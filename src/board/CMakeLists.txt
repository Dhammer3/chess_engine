FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)
add_library(board board.cpp game_info.cpp)
target_include_directories(board
 PUBLIC
  PUBLIC ${CMAKE_SOURCE_DIR}/piece/
  )
target_link_libraries( board piece sfml-graphics) 
