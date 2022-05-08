cmake_minimum_required(VERSION 3.10.2)
project("nativebuffer")

add_library(nativebuffer SHARED JNIBri.cpp)

target_link_libraries(nativebuffer -landroid log)


