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

import java.nio.ByteBuffer;
import java.nio.ByteOrder;


public class NativeBuffer {
    private final String TAG = getClass().getSimpleName();

    protected long address;
    public ByteBuffer buffer;
    private int position;

    public NativeBuffer(int capacity) {
        address = NativeBufferJniWrapper.nativeCreate(capacity);
        if (address != 0) {
            buffer = NativeBufferJniWrapper.nativeGetJavaBuffer(address);
            if (buffer != null) {
                buffer.position(0);
                buffer.limit(capacity);
                buffer.order(ByteOrder.LITTLE_ENDIAN);
            }
        }
    }

    public int readInt32() {
        try {
            return buffer.getInt();
        } catch (Exception e) {
            Log.e(TAG, "readInt32: ", e);
        }
        return 0;
    }
}
