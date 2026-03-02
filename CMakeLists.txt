cmake_minimum_required(VERSION 3.15)

# Имя проекта (можешь изменить)
set(PROJECT_NAME PolynomProject)
project(${PROJECT_NAME})

# --- C++ стандарт и настройки MSVC runtime (чтобы не было конфликтов /MD vs /MT) ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  # Устанавливаем /MD (динамическая CRT) для всех целей (Debug -> /MDd)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" CACHE STRING "" FORCE)
endif()

# --- Пути/переменные проекта (сохраняем твой стиль переменных) ---
set(LIBRARY "${PROJECT_NAME}")                         # имя библиотеки
set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")     # путь к заголовкам
set(SOURCE  "${CMAKE_CURRENT_SOURCE_DIR}/src")         # путь к cpp
set(TESTS   "test_${PROJECT_NAME}")                    # имя тестового exe

# --- FetchContent для GoogleTest (тянем современную версию с GitHub) ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Загрузит и сделает доступными цели GTest::gtest и GTest::gtest_main
FetchContent_MakeAvailable(googletest)

# --- Собираем библиотеку из src (без заголовков в списке источников) ---
file(GLOB LIB_SRCS "${SOURCE}/*.cpp")
add_library(${LIBRARY} STATIC ${LIB_SRCS})

# Заголовки видимы публично (чтобы примеры и тесты могли #include "Monom.h")
target_include_directories(${LIBRARY} PUBLIC ${INCLUDE})

# --- Subdirectories (parser пока пустой, но пусть будет) ---
add_subdirectory(parser)    # заготовка для ANTLR (см. parser/CMakeLists.txt)
add_subdirectory(samples)   # примеры/демонстрации
add_subdirectory(test)      # тесты (будут линкуются с GTest)