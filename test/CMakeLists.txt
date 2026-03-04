# test/CMakeLists.txt

set(target ${TESTS})

file(GLOB TEST_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${target} ${TEST_SRCS})

target_include_directories(${target} PRIVATE ${INCLUDE})

# Линковка с GTest (FetchContent был выполнен в корневом CMake)
# Если у тебя в тестах свой main (test_main.cpp) - линкуем GTest::gtest, иначе GTest::gtest_main
# Предположим, что test_main.cpp есть => используем GTest::gtest
target_link_libraries(${target} PRIVATE GTest::gtest ${LIBRARY})

# Добавляем тест для ctest
enable_testing()
add_test(NAME ${target} COMMAND ${target})