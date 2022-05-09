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

#ifndef NATIVEBUFFER_H
#define NATIVEBUFFER_H

#include <stdint.h>
#include <string>
#include <jni.h>
#include "../Header.h"

#define INT_32 sizeof(int32_t)
#define INT_64 sizeof(int64_t)

class NativeBuffer {
private:
    uint32_t position = 0;
    uint32_t limit = 0;
    uint32_t capacity = 0;
    uint8_t *buffer = nullptr;
    bool inCalculate = false;
    NativeBuffer();
    jobject javaByteBuffer = nullptr;

public:
    NativeBuffer(uint32_t size);

    ~NativeBuffer();

    uint32_t getPosition() { return position; }
    uint32_t getLimit() { return limit; }
    uint32_t getCapacity() { return capacity; }

    bool isReadOnly();
    bool isDirect();
    jobject asByteBuffer();

    void putInt32(int32_t int32);
    void putInt64(int64_t x);

    int32_t readInt32();
    int64_t readInt64();

};


#endif
