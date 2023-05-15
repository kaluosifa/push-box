aux_source_directory(${PROJECT_SOURCE_DIR}/src/include inc)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/game game)

add_executable(push_box main.c ${inc} ${game})