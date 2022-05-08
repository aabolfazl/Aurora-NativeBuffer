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

    public static native long native_create(int cap);

    public static native ByteBuffer native_get_java_buffer(long address);

}
