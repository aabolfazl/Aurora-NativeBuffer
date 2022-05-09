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

void NativeBuffer::putInt32(int32_t int32) {
    if (inCalculate) {
        capacity += INT_32;
    } else {
        if (position + INT_32 > limit) {
            loge("error on putInt32: your limit is %d but position is %d", limit, position);
        }

        buffer[position++] = (uint8_t) int32;
        buffer[position++] = (uint8_t) (int32 >> 8);
        buffer[position++] = (uint8_t) (int32 >> 16);
        buffer[position++] = (uint8_t) (int32 >> 24);

        logi("size of int 32 is: %d", INT_32);
    }
}

void NativeBuffer::putInt64(int64_t x) {
    if (inCalculate) {
        capacity += INT_64;
    } else {
        if (position + INT_64 > limit) {
            loge("error on putInt64: your limit is %d but position is %d", limit, position);
        }
        buffer[position++] = (uint8_t) x;
        buffer[position++] = (uint8_t) (x >> 8);
        buffer[position++] = (uint8_t) (x >> 16);
        buffer[position++] = (uint8_t) (x >> 24);
        buffer[position++] = (uint8_t) (x >> 32);
        buffer[position++] = (uint8_t) (x >> 40);
        buffer[position++] = (uint8_t) (x >> 48);
        buffer[position++] = (uint8_t) (x >> 56);

        logi("size of int 64 is: %d", INT_64);
    }
}


int32_t NativeBuffer::readInt32() {
    if (position + INT_32 > limit) {
        loge("read int32 error");
        return 0;
    }

    int32_t result = ((buffer[position] & 0xff))
                     | ((buffer[position + 1] & 0xff) << 8)
                     | ((buffer[position + 2] & 0xff) << 16)
                     | ((buffer[position + 3] & 0xff) << 24);


    position += INT_32;
    return result;
}

int64_t NativeBuffer::readInt64() {
    if (position + INT_64 > limit) {
        loge("read int64 error");
        return 0;
    }

    int64_t result = ((int64_t) (buffer[position] & 0xff)) |
                     ((int64_t) (buffer[position + 1] & 0xff) << 8) |
                     ((int64_t) (buffer[position + 2] & 0xff) << 16) |
                     ((int64_t) (buffer[position + 3] & 0xff) << 24) |
                     ((int64_t) (buffer[position + 4] & 0xff) << 32) |
                     ((int64_t) (buffer[position + 5] & 0xff) << 40) |
                     ((int64_t) (buffer[position + 6] & 0xff) << 48) |
                     ((int64_t) (buffer[position + 7] & 0xff) << 56);

    position += INT_64;
    return result;
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
            loge("can't allocate NativeByteBuffer buffer");
            exit(1);
        }
        jobject globalRef = env->NewGlobalRef(javaByteBuffer);
        env->DeleteLocalRef(javaByteBuffer);
        javaByteBuffer = globalRef;
    }

    return javaByteBuffer;
}

NativeBuffer::~NativeBuffer() {
    if (javaByteBuffer != nullptr) {
        JNIEnv *env = AndroidJvm::shared().getJavaEnv();
        env->DeleteGlobalRef(javaByteBuffer);
        javaByteBuffer = nullptr;
    }

    if (buffer != nullptr) {
        delete[] buffer;
        buffer = nullptr;
    }
}

