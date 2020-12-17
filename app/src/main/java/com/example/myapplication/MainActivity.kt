package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.myapplication.Scaler

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val kotlinvec = arrayOf(1.0F,1.2F,2.0F,0.5F).toFloatArray()

        val scaler:Scaler = Scaler(kotlinvec)

        val converted:UByteArray = scaler.scale()

        //println(scaler.scaleBack(scaleVector(converted,converted.size)).toString())

        // Example of a call to a native method
        findViewById<TextView>(R.id.sample_text).text = scaleVector(converted, converted.size)
    }


    external fun scaleVector(data: UByteArray, dim:Int):String

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("thiscretematrix")
        }
    }
}