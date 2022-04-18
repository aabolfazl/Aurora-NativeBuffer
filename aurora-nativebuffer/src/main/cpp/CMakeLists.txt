cmake_minimum_required(VERSION 3.10.2)
project("aurora-nativebuffer")

add_library(aurora-nativebuffer SHARED JNIWrapper.cpp)

target_link_libraries(aurora-nativebuffer -ljnigraphics)