cmake_minimum_required(VERSION 3.15)

# Папка parser: сюда будем добавлять ANTLR грамматику и генерацию
# Пока — пустой CMake, чтобы add_subdirectory(parser) в корне не ломал сборку.

# => Когда будешь подключать ANTLR:
# - добавь grammar/Polynom.g4
# - настрой путь к antlr-jar и java
# - добавь add_custom_command(...) для генерации C++ файлов в ${CMAKE_BINARY_DIR}/parser/generated
# - затем add_library(parser_generated STATIC ${GENERATED_SRCS}) и target_include_directories(parser_generated PUBLIC <generated-dir>)
#
# Пример (псевдо, добавлять при наличии jar и грамматики):
#
# file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)
# add_custom_command(
#   OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomLexer.cpp ...
#   COMMAND java -jar /path/to/antlr-4.x-complete.jar -Dlanguage=Cpp -o ${CMAKE_CURRENT_BINARY_DIR}/generated ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Polynom.g4
#   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Polynom.g4
# )
# add_library(parser_generated STATIC ${CMAKE_CURRENT_BINARY_DIR}/generated/*.cpp)
# target_include_directories(parser_generated PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/generated)