/*
 * Copyright © 2022 Aurora open source project
 *
 * This is the source code of Aurora NativeBuffer for Android.
 * It is licensed under GNU GPL v.2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Author:  Abolfazl Abbasi
 *
 */

#include <jni.h>
#include <algorithm>
#include "logger/Logger.h"
#include "core/NativeBuffer.h"

extern "C" {
JNIEXPORT jlong Java_aurora_nativebuffer_core_JNILoader_test(
        JNIEnv *env,
        jclass clazz) {
    return 123;
}

JNIEXPORT jlong Java_aurora_nativebuffer_core_NativeBufferJniWrapper_nativeCreate(
        JNIEnv *env,
        jclass clazz,
        jint cap) {


    return (jlong) (intptr_t) new NativeBuffer(cap);
}
JNIEXPORT jobject Java_aurora_nativebuffer_core_NativeBufferJniWrapper_nativeGetJavaBuffer(
        JNIEnv *env,
        jclass clazz,
        jlong address) {

    auto *buffer = (NativeBuffer *) (intptr_t) address;
    if (buffer == nullptr) {
        return nullptr;
    }
    return buffer->asByteBuffer();
}


}
