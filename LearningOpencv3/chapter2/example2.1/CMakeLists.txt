cmake_minimum_required(VERSION 2.8)
project(example2_1)

set(CMAKE_CXX_STANDARD 11)

# 引入opencv(import opencv)
# 寻找opencv库(look for opencv library)
find_package(OpenCV REQUIRED)
# 添加Opencv头文件(add head file of Opencv)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(example2_1 main.cpp)

# 链接Opencv库(link Opencv library)
target_link_libraries(example2_1 ${OpenCV_LIBS})