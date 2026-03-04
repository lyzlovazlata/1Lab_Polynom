# parser/CMakeLists.txt

set(PARSER_GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
file(GLOB PARSER_SRCS "${PARSER_GEN_DIR}/*.cpp")

add_library(parser_generated STATIC ${PARSER_SRCS})

# === ПРАВИЛЬНЫЕ INCLUDE ПУТИ ===
target_include_directories(parser_generated
    PUBLIC
        ${PARSER_GEN_DIR}
        ${ANTLR_INSTALL_DIR}/include/antlr4-runtime  # <-- ВАЖНО
)

# Линкуем runtime библиотеку
target_link_libraries(parser_generated
    PUBLIC
        ${ANTLR_INSTALL_DIR}/lib/antlr4-runtime.lib
)
