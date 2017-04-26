cmake_minimum_required(VERSION 2.8)
project(lecture2017s_image_system)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imshow src/imshow.cpp)
target_link_libraries(imshow ${OpenCV_LIBS})

add_executable(capture_video src/capture_video.cpp)
target_link_libraries(capture_video ${OpenCV_LIBS})

add_executable(gray src/gray.cpp)
target_link_libraries(gray ${OpenCV_LIBS})
