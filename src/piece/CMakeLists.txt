FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)
add_library(piece piece.cpp king.cpp queen.cpp bishop.cpp rook.cpp pawn.cpp knight.cpp piece_factory.cpp)
target_include_directories(piece
 PUBLIC
  PUBLIC ${CMAKE_SOURCE_DIR}/board/
  )
target_link_libraries( piece board sfml-graphics)
