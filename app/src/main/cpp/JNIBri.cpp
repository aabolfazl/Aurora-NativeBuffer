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

extern "C" {
JNIEXPORT jlong Java_aurora_nativebuffer_sample_MainActivity_test2(
        JNIEnv *env,
        jclass clazz) {

    return 123;
}

}
