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

package aurora.nativebuffer.core;

import android.util.Log;

public class JNIBinder {
    private static final String LIBRARY_NAME = "aurora-nativebuffer";
    private static boolean initialized;

    public static void load() {
        if (initialized) {
            return;
        }

        try {
            System.loadLibrary(LIBRARY_NAME);
            initialized = true;
        } catch (Exception e) {
            e.printStackTrace();
        }

        Log.i("akay", "load: " + test());
    }

    public static native long test();
}
