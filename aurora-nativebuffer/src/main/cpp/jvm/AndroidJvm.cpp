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

#include "AndroidJvm.h"

void AndroidJvm::init(JavaVM *pJvm, JNIEnv *pEnv) {
    javaVm = pJvm;
    javaEnv = pEnv;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("JNI_OnLoad started");
    JNIEnv *env = nullptr;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    AndroidJvm::shared().init(vm, env);

    LOGI("JNI_OnLoad successfully");

    return JNI_VERSION_1_6;
}

void JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGI("JNI_OnUnload");
}