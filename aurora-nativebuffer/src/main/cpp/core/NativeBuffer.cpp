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

#include "NativeBuffer.h"
#include "../jvm/AndroidJvm.h"


NativeBuffer::NativeBuffer(uint32_t cap) {
    buffer = new uint8_t[cap];
    limit = cap;
    capacity = cap;
}

NativeBuffer::~NativeBuffer() {
    if (buffer != nullptr) {
        delete[] buffer;
        buffer = nullptr;
    }
}

void NativeBuffer::putInt(int32_t int32) {
    if (inCalculate) {
        capacity += 4;
    } else {
        if (position + 4 > limit) {

        }
        buffer[position++] = (uint8_t) int32;
        buffer[position++] = (uint8_t) (int32 >> 8);
        buffer[position++] = (uint8_t) (int32 >> 16);
        buffer[position++] = (uint8_t) (int32 >> 24);
    }
}

bool NativeBuffer::isReadOnly() {
    return false;
}

bool NativeBuffer::isDirect() {
    return false;
}

jobject NativeBuffer::asByteBuffer() {
    if (javaByteBuffer == nullptr) {
        JNIEnv *env = AndroidJvm::shared().getJavaEnv();

        javaByteBuffer = env->NewDirectByteBuffer(buffer, capacity);
        if (javaByteBuffer == nullptr) {
            LOGE("can't allocate NativeByteBuffer buffer");
            exit(1);
        }
        jobject globalRef = env->NewGlobalRef(javaByteBuffer);
        env->DeleteLocalRef(javaByteBuffer);
        javaByteBuffer = globalRef;
    }

    return javaByteBuffer;
}

