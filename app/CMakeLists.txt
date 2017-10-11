add_executable(shell-app main.cpp)
find_package(OpenCV REQUIRED)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries( shell-app ${OpenCV_LIBS} )
