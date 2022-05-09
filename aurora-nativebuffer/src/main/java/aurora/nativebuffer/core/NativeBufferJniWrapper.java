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

import java.nio.ByteBuffer;

class NativeBufferJniWrapper {

    public static native long nativeCreate(int cap);

    public static native ByteBuffer nativeGetJavaBuffer(long address);

}
