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

    void putInt(int32_t int32);
    bool isReadOnly();
    bool isDirect();
    jobject asByteBuffer();
};


#endif
