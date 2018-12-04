cmake_minimum_required(VERSION 3.5)
project(example2_2)
# 引入opencv(import opencv)
# 寻找opencv库(look for opencv library)
find_package(OpenCV REQUIRED)
# 添加Opencv头文件(add head file of Opencv)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(example2_2 main.cpp)
# 链接Opencv库(link Opencv library)
target_link_libraries(example2_2 ${OpenCV_LIBS})