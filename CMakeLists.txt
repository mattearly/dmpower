cmake_minimum_required (VERSION 3.8)
project ("dmpower")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# main exe
file(GLOB_RECURSE SRC_FILES "src/*.cpp" "src/*.h")
add_executable(${PROJECT_NAME} ${SRC_FILES})

# runtime data
file(COPY "${PROJECT_SOURCE_DIR}/data/lists/" DESTINATION "${CMAKE_BINARY_DIR}/data/lists/")

if (UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE -lstdc++fs)
endif()


