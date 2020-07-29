cmake_minimum_required(VERSION 3.16)
project(QtKeychain CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 20)

if (DEFINED ENV{QT_DIR})
    message(STATUS "QT CMAKE DIR....$ENV{QT_DIR}")
else()
    message(FATAL_ERROR "QT_DIR environment variable is unset. \n  ")
endif()

set(CMAKE_PREFIX_PATH $ENV{QT_DIR})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

FIND_LIBRARY(SECURITY Security)

add_executable(QtKeychain MACOSX_BUNDLE main.cpp mainwindow.cpp mainwindow.h KeyManager.h constants.h MacKeyManager.cpp MacKeyManager.h KeyManagerFactory.h)

target_link_libraries(QtKeychain Qt5::Core Qt5::Widgets ${SECURITY})