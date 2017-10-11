add_executable(shell-app main.cpp)
find_package(OpenCV REQUIRED)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries( shell-app ${OpenCV_LIBS} )
