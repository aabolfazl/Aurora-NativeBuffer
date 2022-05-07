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

#ifndef SAMPLE_JVM_H
#define SAMPLE_JVM_H

#include <jni.h>
#include "../logger/Logger.h"

class AndroidJvm {
public:
    static AndroidJvm &shared() {
        static AndroidJvm jvm;
        return jvm;
    }

    void init(JavaVM *jvm, JNIEnv *pEnv);

protected:
    JavaVM *javaVm;
    JNIEnv *javaEnv;
};

#endif //SAMPLE_JVM_H
