cmake_minimum_required(VERSION 3.15)
project(PolynomProject LANGUAGES CXX)

# --- стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- MSVC runtime для согласованной линковки (оставлено, как было в твоём варианте)
if (MSVC)
  # Оставляем возможность переопределить в CMake GUI/CLI
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" CACHE STRING "MSVC runtime" FORCE)
endif()

# --- Параметры: путь к ANTLR runtime (можно задать при вызове cmake)
set(ANTLR_INSTALL_DIR
    "C:/Users/Zlata/source/ANTLR/antlr_install"
    CACHE PATH "Path to ANTLR C++ runtime installation (contains include/, lib/, bin/)"
)

# Пытаемся найти include и библиотеку в указанной папке, иначе попробуем поиск по стандартным путям
if (EXISTS "${ANTLR_INSTALL_DIR}")
  set(_try_paths "${ANTLR_INSTALL_DIR}")
else()
  set(_try_paths "")
endif()

find_path(ANTLR_INCLUDE_DIR
  NAMES antlr4-runtime/antlr4-runtime.h
  PATHS ${_try_paths} ${ANTLR_INSTALL_DIR}/include
  NO_DEFAULT_PATH
)

# возможные имена библиотек: antlr4-runtime.lib / libantlr4-runtime.a / antlr4-runtime
find_library(ANTLR_LIB
  NAMES antlr4-runtime libantlr4-runtime
  PATHS ${_try_paths} ${ANTLR_INSTALL_DIR}/lib ${ANTLR_INSTALL_DIR}/lib64
  NO_DEFAULT_PATH
)

if (NOT ANTLR_INCLUDE_DIR OR NOT ANTLR_LIB)
  message(WARNING "ANTLR runtime not found automatically.\n\
  Please set -DANTLR_INSTALL_DIR to the directory that contains include/, lib/, bin/ for your antlr runtime.\n\
  Current ANTLR_INSTALL_DIR='${ANTLR_INSTALL_DIR}'.\n\
  Continued configuration will fail if parser library cannot find the runtime.")
endif()

# --- Проектные переменные (пути)
set(LIBRARY "${PROJECT_NAME}")
set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE  "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TESTS   "test_${PROJECT_NAME}")

# --- GoogleTest (для тестовой подсборки) - используем FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Не добавляем MAKE_AVAILABLE пока — но выполним его чтобы GTest цели стали доступны
FetchContent_MakeAvailable(googletest)

# --- Собираем основную библиотеку (src/*.cpp)
file(GLOB LIB_SRCS "${SOURCE}/*.cpp")
add_library(${LIBRARY} STATIC ${LIB_SRCS})
target_include_directories(${LIBRARY} PUBLIC ${INCLUDE})

# Если ANTLR найден — доступен для целей, иначе оставляем, парсер добавит линковку
if (ANTLR_INCLUDE_DIR)
  target_compile_definitions(${LIBRARY} PRIVATE HAS_ANTLR=1)
endif()

# --- Поддиректории ---
add_subdirectory(parser)   # собирает parser_generated из parser/generated
add_subdirectory(samples)  # собирает примеры (sample)
add_subdirectory(test)     # собирает и регистрирует тесты

# --- Линкуем parser_generated к библиотеке, если парсер-библиотека создан
if (TARGET parser_generated)
  target_link_libraries(${LIBRARY} PRIVATE parser_generated)
endif()

# --- Установка (опционально) — копирование dll рядом с бинарниками (Windows)
if (WIN32 AND ANTLR_INSTALL_DIR)
  # Если у тебя есть antlr4-runtime.dll в bin/, копируем его в выходные директории при сборке
  add_custom_command(TARGET ${LIBRARY} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Note: If program needs antlr4-runtime.dll, ensure it's in PATH or copied to runtime dir."
  )
endif()

# --- Удобные переменные для внешних вызовов (например в IDE)
set_property(GLOBAL PROPERTY POLYNOM_INCLUDEDIR ${INCLUDE})
set_property(GLOBAL PROPERTY POLYNOM_ANTLR_INCLUDE ${ANTLR_INCLUDE_DIR})
set_property(GLOBAL PROPERTY POLYNOM_ANTLR_LIB ${ANTLR_LIB})