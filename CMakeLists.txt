cmake_minimum_required(VERSION 3.23)
project(Blog_Range_v3)

set(CMAKE_CXX_STANDARD 20)
add_executable(Blog_Range_v3 main.cpp data_processing.cpp data_processing.h)

include(FetchContent)

FetchContent_Declare(
        range-v3
        GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
        GIT_TAG        master  # You can specify a specific release tag here
)
FetchContent_MakeAvailable(range-v3)

target_link_libraries(Blog_Range_v3 PRIVATE range-v3)

