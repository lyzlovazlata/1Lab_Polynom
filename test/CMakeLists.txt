# test/CMakeLists.txt

set(target ${TESTS})

# берем все тестовые cpp (поддерживает test_main.cpp, test_monom.cpp, test_polynom.cpp)
file(GLOB TEST_SRCS "*.cpp")

add_executable(${target} ${TEST_SRCS})

# тесты должны видеть заголовки библиотеки
target_include_directories(${target} PRIVATE ${INCLUDE})

# У тебя есть test_main.cpp со своим main -> линкуем GTest::gtest (а не GTest::gtest_main)
# Если у тебя НЕТ собственного main, то линкуй GTest::gtest_main вместо GTest::gtest.
target_link_libraries(${target} PRIVATE GTest::gtest ${LIBRARY})

# Регистрируем тест в ctest (запуск через ctest)
enable_testing()
add_test(NAME ${target} COMMAND ${target})