project(emulator)
include_directories(include)
set(SOURCES "src/*.c")
add_library(SOURCES SHARED)