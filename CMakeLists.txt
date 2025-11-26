# # Minimum example(commit: 999bc5c667ee756b9fcae3cbefa1ffb1564e4f20):
# cmake_minimum_required(VERSION 3.15)
# project(okr_cmake_win VERSION 0.1 LANGUAGES CXX)
# add_executable(okr_cmake_win src/main.cpp)
#######################################################################
#######################################################################
# # use library(commit: c8729cf11d4713d316312173bc57ce0fdf13a77c):
# cmake_minimum_required(VERSION 3.15)
# project(okr_cmake_win VERSION 0.1 LANGUAGES CXX)
# add_library(greet STATIC src/greet.cpp)
# target_include_directories(greet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_compile_features(greet PUBLIC cxx_std_17)
# add_executable(okr_cmake_win src/main.cpp)
# target_link_libraries(okr_cmake_win PRIVATE greet)
#######################################################################
#######################################################################
# # public and private visibility(commit: 7b82457def6e8e885b0a4bcca7a913d76cc21b92):
# cmake_minimum_required(VERSION 3.15)
# project(okr_cmake_win VERSION 0.1 LANGUAGES CXX)
# add_library(greet STATIC src/greet.cpp)
# target_include_directories(greet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_compile_features(greet PUBLIC cxx_std_17)
# add_library(tool_lib src/tool.cpp)
# target_link_libraries(tool_lib PUBLIC greet)
# add_executable(tool_app src/tool_main.cpp)
# target_link_libraries(tool_app PRIVATE tool_lib)
#######################################################################
#######################################################################
# compile time option:
cmake_minimum_required(VERSION 3.15)
project(okr_cmake_win VERSION 0.1 LANGUAGES CXX)
option(ENABLE_EXTRA "Enable extra greeting" OFF)
add_library(greet STATIC src/greet.cpp)
if(ENABLE_EXTRA)
    target_sources(greet PRIVATE src/greet_extra.cpp)
    target_compile_definitions(greet PUBLIC ENABLE_EXTRA=1)
endif()
target_include_directories(greet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(greet PUBLIC cxx_std_17)
add_executable(okr_cmake_win src/main.cpp)
target_link_libraries(okr_cmake_win PRIVATE greet)
#######################################################################
#######################################################################
