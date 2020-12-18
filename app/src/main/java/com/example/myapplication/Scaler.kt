package com.example.myapplication

import kotlin.math.roundToInt

class Scaler(var data: FloatArray) {
    var multiplier:Float = 0F
    var padding:Float = 0F
    private val growth:Float = 2F
    var std = 0.0

    var max = data[0]
    var min = data[0]
    val mean = data.average()

    private fun normalize(){
        for (e in data) {
            std += Math.pow(e.toDouble() - mean, 2.0)
        }

        std = Math.sqrt(std / data.size)

        for (i in data.indices){
            data[i] = ((data[i].toDouble() - mean) / std).toFloat()
        }
    }

    private fun denormalize(input:FloatArray):FloatArray{
        val out = FloatArray(input.size)
        {
            i -> (std*input[i].toDouble() + mean).toFloat()
        }

        return out
    }

    private fun calc() {

        for(e in data){
            if(e > max){
                max = e
            }
            if(e < min){
                min = e
            }
        }

        /* if(max >= 0F){
            max *= growth
        }
        else{
            max /= growth
        }

        if(min <= 0F){
            min *= growth
        }
        else{
            min /= growth
        }*/

        multiplier = 255F.div (max - min)

        padding = -multiplier*min

    }

    fun scale():UByteArray{
        calc()

        val out = UByteArray(data.size)
        {
            i -> (multiplier*data[i] + padding).roundToInt().toUByte()
        }

        return out
    }

    fun scaleBack(dis: UByteArray):FloatArray{
        val out = FloatArray(dis.size)
        {
                i -> (dis[i].toFloat() - 2*padding) / multiplier
        }

        return out
    }
}