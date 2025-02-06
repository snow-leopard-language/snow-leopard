cmake_minimum_required(VERSION 3.30)

project(sl
        DESCRIPTION
        "Snow Leopard programming language"
        HOMEPAGE_URL
        "https://lisi4ok.com"
        LANGUAGES
        C
)

set(SL_VERSION_MAJOR 0)
set(SL_VERSION_MINOR 0)
set(SL_VERSION_PATCH 1)
set(SL_VERSION "" CACHE STRING "Override Snow Leopard Language version string. Default is to find out with git.")

set(CMAKE_C_STANDARD 23)

add_executable(sl
        src/util.c
        src/utf8.c
        src/error.c
        src/token.c
        src/lexer.c
        src/main.c
)