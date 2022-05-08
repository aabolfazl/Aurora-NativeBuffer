cmake_minimum_required(VERSION 3.10.2)
project("aurora-nativebuffer")

add_library(aurora-nativebuffer SHARED
        JNIWrapper.cpp
        core/NativeBuffer.cpp
        logger/Logger.cpp
        jvm/AndroidJvm.cpp
        )
target_link_libraries(aurora-nativebuffer -landroid log)