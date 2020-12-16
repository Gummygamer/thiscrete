package com.example.myapplication

import kotlin.math.roundToInt

class Scaler(val data: Array<Float>) {
    var multiplier:Float = 0F
    var padding:Float = 0F

    private fun calc() {

        var max:Float = data[0]
        var min:Float = data[0]

        for(e in data)
        {
            if(e > max)
            {
                max = e
            }

            if(e < min)
            {
                min = e
            }
        }

        multiplier = 255 / (max - min)

        padding = 255 - multiplier*max

    }

    fun scale():Array<UByte>{
        calc()

        val out = Array<UByte>(data.size)
        {
            i -> (multiplier*data[i] + padding).roundToInt().toUByte()
        }

        return out
    }

    fun scaleBack(dis: Array<UByte>):Array<Float>{
        val out = Array<Float>(dis.size)
        {
                i -> (dis[i].toFloat() - padding) / multiplier
        }

        return out
    }
}