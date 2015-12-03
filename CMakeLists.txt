#indicate minimum version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#project name
PROJECT(opencv_facedetector)

#Create an executable
ADD_EXECUTABLE(opencv_facedetector src/opencv_facedetector.cpp)

#find required packages (look for the package, usually at /usr/share/cmake-2.8/Modules/ or /usr/share/)
FIND_PACKAGE(OpenCV REQUIRED)

#set header directories
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIR})

#Link with libraries
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})
