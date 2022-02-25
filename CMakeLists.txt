# CMakeLists.txt

# Older versions of CMake are likely to work just fine but, since
# I don't know where to cut off I just use the version I'm using
cmake_minimum_required(VERSION "3.17")

# name of this example project
project(simple-demo)

# set OpenCV_DIR variable equal to the path to the cmake
# files within the previously installed opencv program
#set(OpenCV_DIR /Users/adammcquistan/code/c++/opencv/install/lib/cmake/opencv4)
set(OpenCV_DIR /Users/wataruoshima/opencv-4.5.5/build/opencv2)
# Tell compiler to use C++ 14 features which is needed because
# Clang version is often behind in the XCode installation
set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHREAD_FLAG ON)
# configure the necessary common CMake environment variables
# needed to include and link the OpenCV program into this
# demo project, namely OpenCV_INCLUDE_DIRS and OpenCV_LIBS
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

# tell the build to include the headers from OpenCV
include_directories( ${OpenCV_INCLUDE_DIRS} )

# specify the executable target to be built
add_executable(houghlines houghLines.cpp)
add_executable(houghcircles houghCircles.cpp)
# add_executable(canny_img canny_image.cpp)
# add_executable(videocap videocap.cpp)
# tell it to link the executable target against OpenCV
target_link_libraries(houghlines ${OpenCV_LIBS}  ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries(houghcircles ${OpenCV_LIBS}  ${CMAKE_THREAD_LIBS_INIT} )


