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

#ifndef FILELOG_H
#define FILELOG_H

#include <iosfwd>
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include "Logger.h"

#include <android/log.h>

class Logger {
public:
    static Logger &shared() {
        static Logger shared;
        return shared;
    }

    static void e(const char *message, ...) __attribute__((format (printf, 1, 2)));
    static void i(const char *message, ...) __attribute__((format (printf, 1, 2)));

};

#define loge Logger::shared().e
#define logi Logger::shared().i

#endif
