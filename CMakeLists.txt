# CMakeList.txt: OpenCVPractice에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_FLAGS "-std=c++11")

project ("OpenCVPractice")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

# 이 프로젝트의 실행 파일에 소스를 추가합니다.
add_executable (OpenCVPractice "OpenCVPractice.cpp" )
target_link_libraries(OpenCVPractice ${OpenCV_LIBS})
