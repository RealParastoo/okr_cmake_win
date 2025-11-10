cmake_minimum_required(VERSION 3.15)
project(okr_cmake_win VERSION 1.0 LANGUAGES CXX)

add_library(greet STATIC src/greet.cpp)
target_include_directories(greet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(greet PUBLIC cxx_std_17)

# add_executable(okr_cmake_win src/main.cpp)
# add_executable(tool_app src/tool.cpp)

# target_link_libraries(okr_cmake_win PRIVATE greet)
# target_link_libraries(tool_app PRIVATE greet)

add_library(tool_lib src/tool.cpp)
target_link_libraries(tool_lib PUBLIC greet)

add_executable(tool_app src/tool_main.cpp)
target_link_libraries(tool_app PRIVATE tool_lib)