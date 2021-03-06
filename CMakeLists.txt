cmake_minimum_required (VERSION 3.6)


if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin" )
  message(STATUS "Load Darwin Toolchain for arm")
  set(SOS_TOOLCHAIN_CMAKE_PATH /Applications/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
endif()
if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows" )
  message(STATUS "Load Windows Toolchain for arm")
  set(SOS_TOOLCHAIN_CMAKE_PATH C:/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
endif()

include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-resolve-build-config.cmake)

if( ${SOS_BUILD_CONFIG} STREQUAL arm )
  message(STATUS "Load SOS Lib Toolchain for arm: " ${SOS_TOOLCHAIN_CMAKE_PATH})
  set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/sos-lib-toolchain.cmake)
elseif( ${SOS_BUILD_CONFIG} STREQUAL link )
  set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/link-toolchain.cmake)
endif()

set(SOS_LIB_NAME lwip)
project(${SOS_LIB_NAME} CXX C)

set(LWIP_NAME lwip-2.0.3)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY ${LWIP_NAME}/src/include/ DESTINATION include)
set(SOS_LIB_DEFINITIONS HAVE_LWIP_SOCKETS_H=1)
set(SOS_LIB_BUILD_FLAGS -Wno-address)
set(SOS_LIB_INCLUDE_DIRECTORIES include)


include( ${CMAKE_SOURCE_DIR}/${SOS_BUILD_CONFIG}.cmake )
