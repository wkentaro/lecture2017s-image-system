cmake_minimum_required(VERSION 2.8)
project(lecture2017s_image_system)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

macro(add_program filename executable)
  add_executable(${executable} ${filename})
  target_link_libraries(${executable} ${OpenCV_LIBS})
endmacro(add_program)

add_program(src/imshow.cpp imshow)
add_program(src/capture_video.cpp capture_video)
add_program(src/gray.cpp gray)
add_program(src/add_scalor.cpp add_scalor)
