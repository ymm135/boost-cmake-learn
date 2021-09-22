cmake_minimum_required(VERSION 3.5)

# 工程名
set(PROJECT_NAME_STR boost_learn)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin") # 设置输出目录为:/bin

project(${PROJECT_NAME_STR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#增加pthread依赖库
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Include 目录
set(BOOST_LEARN_INCLUDES ${BOOST_LEARN_INCLUDES} ${PROJECT_SOURCE_DIR}/src)

# Gather the header and source files
#file(GLOB_RECURSE INC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
#file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Build object files for reuse (e.g. in test)
#ADD_LIBRARY(demo_objects OBJECT ${INC_FILES} ${SRC_FILES})

# 添加依赖 Found Boost: /usr/local/include (found version "1.69.0") found components: filesystem system unit_test_framework 
find_package(Boost COMPONENTS thread filesystem system unit_test_framework REQUIRED)

# Unit tests
# add_subdirectory(test)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

#gdb 调试参数
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Build
#set(SOURCE_FILES src/main.cpp $<TARGET_OBJECTS:demo_objects>)
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES})
add_executable(boost_learn ${SOURCE_FILES})
target_link_libraries(boost_learn ${Boost_LIBRARIES} rt)