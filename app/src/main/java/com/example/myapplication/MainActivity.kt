package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.myapplication.Scaler

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val kotlinvec = arrayOf(1.0F,1.2F,2.0F,0.5F)

        val scaler:Scaler = Scaler(kotlinvec)

        val converted:Array<UByte> = scaler.scale()

        // Example of a call to a native method
        findViewById<TextView>(R.id.sample_text).text = stringFromJNI()
    }


    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("thiscretematrix")
        }
    }
}