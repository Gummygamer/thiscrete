package com.example.myapplication

import kotlin.math.roundToInt

class Scaler(var data: FloatArray) {
    var multiplier:Float = 0F
    var padding:Float = 0F
    val growth:Float = 2F
    var std = 0.0
    val mean = data.average()

    private fun normalize(){
        for (e in data) {
            std += Math.pow(e.toDouble() - mean, 2.0)
        }

        std = Math.sqrt(std / data.size)

        for (i in 0..(data.size - 1)){
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

        normalize()

        val max = growth
        val min = -growth

        multiplier = 255 / (max - min)

        padding = 255 - multiplier*max

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
                i -> (dis[i].toFloat() - padding) / multiplier
        }

        return denormalize(out)
    }
}