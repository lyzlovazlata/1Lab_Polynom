# samples/CMakeLists.txt
set(target sample)

file(GLOB SAMPLE_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${target} ${SAMPLE_SRCS})

# samples должно видеть заголовки библиотеки
# Родительский CMake выставил переменную INCLUDE
target_include_directories(${target} PRIVATE ${INCLUDE})

# Линкуем с нашей библиотекой и (опционально) с parser_generated если есть
target_link_libraries(${target} PRIVATE ${LIBRARY})
if (TARGET parser_generated)
  target_link_libraries(${target} PRIVATE parser_generated)
endif()