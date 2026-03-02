# samples/CMakeLists.txt
# simple example target that uses the library

set(target sample)

file(GLOB SAMPLE_SRCS "*.cpp")

add_executable(${target} ${SAMPLE_SRCS})

# samples нужно видеть заголовки библиотеки
target_include_directories(${target} PRIVATE ${INCLUDE})

# линкуем с нашей библиотекой
target_link_libraries(${target} PRIVATE ${LIBRARY})