package aurora.nativebuffer.sample;

import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

import aurora.nativebuffer.core.NativeBuffer;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.loadLibrary("nativebuffer");

        NativeBuffer buffer = new NativeBuffer(128);
        Log.e("MainActivity", "onCreate: " + buffer.readInt32());
        Log.e("MainActivity", "onCreate: " + buffer.readInt32());
        Log.e("MainActivity", "onCreate: " + buffer.readInt32());
        Log.e("MainActivity", "onCreate: " + buffer.readInt32());
    }

    public static native long test2();
}