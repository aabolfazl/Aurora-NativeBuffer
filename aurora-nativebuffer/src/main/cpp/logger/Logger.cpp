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

#include "Logger.h"

#define TAG "Aurora-logger"

void Logger::e(const char *message, ...) {
    va_list argptr;
    va_start(argptr, message);
    __android_log_vprint(ANDROID_LOG_ERROR, TAG, message, argptr);
    va_end(argptr);
    va_start(argptr, message);

    va_end(argptr);
}

void Logger::i(const char *message, ...) {
    va_list argptr;
    va_start(argptr, message);
    __android_log_vprint(ANDROID_LOG_INFO, TAG, message, argptr);
    va_end(argptr);
    va_start(argptr, message);
    va_end(argptr);
}

