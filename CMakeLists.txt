#CMAKE INITIALIZATION
SET (CMAKE_C_COMPILER "/opt/rh/devtoolset-2/root/usr/bin/gcc")
SET (CMAKE_CXX_COMPILER "/opt/rh/devtoolset-2/root/usr/bin/g++")

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(mr4c-testing)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# this didn;'t seem to work -- set(CMAKE_CXX_STANDARD 11)

#
# Custom Project Variables
#
set(MR4C_BASE "/usr/local/mr4c/native")
set(MR4C_LIBS mr4c gdal)

ADD_DEFINITIONS(
  -g  -std=c++11 # Or -std=c++0x
)

include_directories(
    "${MR4C_BASE}/include"
)
link_directories(
    "${MR4C_BASE}/lib"
)

#g++ (Linux and MAC OS X) specific options
SET (CMAKE_CXX_FLAGS "-m64 -Wunused-variable -Wall -Wunused-parameter -fPIC -std=c++11 -fmessage-length=0 -pthread")
set (CMAKE_SKIP_RPATH TRUE)

set (LINKER_FLAGS "-pthread -rdynamic -Wl,-z,defs")

SET (CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb3 -pg" )
SET (CMAKE_CXX_FLAGS_RELEASE "-O3")


IF(CMAKE_BUILD_TYPE MATCHES "Debug")
ADD_DEFINITIONS(-DDEBUG)
ADD_DEFINITIONS(-DDEBUG_LOG)
ADD_DEFINITIONS(-DFTLOG)
ADD_DEFINITIONS(-DPGMA_DEBUG=True)
ENDIF(CMAKE_BUILD_TYPE MATCHES "Debug")

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/api)

add_library(Mr4cProperties SHARED "src/cpp/Mr4cProperties.cpp")
target_link_libraries( Mr4cProperties ${MR4C_LIBS} ${LINKER_FLAGS})

add_library(Mr4cThreads SHARED "src/cpp/Mr4cThreads.cpp")
target_link_libraries( Mr4cThreads ${MR4C_LIBS} ${LINKER_FLAGS})

add_library(MessagingMaster SHARED "src/cpp/MessagingMaster.cpp")
target_link_libraries( MessagingMaster ${MR4C_LIBS} ${LINKER_FLAGS})

add_library(MessagingWorker SHARED "src/cpp/MessagingWorker.cpp")
target_link_libraries( MessagingWorker ${MR4C_LIBS} ${LINKER_FLAGS})

# add_library(Mr4cMessaging SHARED "src/cpp/Mr4cMessaging.cpp")
# target_link_libraries( Mr4cMessaging ${MR4C_LIBS} ${LINKER_FLAGS})

