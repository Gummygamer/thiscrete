package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.myapplication.Scaler

class MainActivity : AppCompatActivity() {
    private fun parsecplusplus(input: String):UByteArray {
        val parts = input.split(" ")

        var out = UByteArray(parts.size - 1)

        for(i in 0..(parts.size-2)){
            out[i] = parts[i].toInt().toUByte()
        }

        return out
    }

    private fun parsecomplemented(input: ShortArray):String
    {
        var out = ""

        for(e in input)
        {
            out += e.toString() + " "
        }

        return out
    }

    private fun purebyteValues(input: UByteArray):ShortArray
    {
        var out = ShortArray(input.size)

        for(i in input.indices)
        {
            if(input[i] >= 0u)
            {
                out[i] = input[i].toShort()
            }
            else
            {
                out[i] = (256.toShort() + input[i].toShort()).toShort()
            }
        }

        return out
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val kotlinvec = arrayOf(1.0F,1.2F,0.5F,2.0F).toFloatArray()

        val scaler:Scaler = Scaler(kotlinvec)

        val converted:UByteArray = scaler.scale()

        val complemented:ShortArray = purebyteValues(converted)

        val datastr = parsecomplemented(complemented)

        val cplusplus:String = scaleVector(datastr, converted.size)

        val convertedResult = parsecplusplus(cplusplus)

        val finalResult = scaler.scaleBack(convertedResult)

        var finalstring:String = ""

        for(f in finalResult) {
            finalstring += f.toString()
            finalstring += " "
        }

        //println(scaler.scaleBack(scaleVector(converted,converted.size)).toString())

        // Example of a call to a native method
        findViewById<TextView>(R.id.sample_text).text = finalstring
    }


    external fun scaleVector(datastr:String, dim:Int):String

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("thiscretematrix")
        }
    }
}