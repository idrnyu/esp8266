/**
 * @file Encoder.cpp
 * @author idrnyu
 * @brief EC11 旋转编码器 两定位一脉冲
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Encoder.h"

/**
 * @brief 初始化GPIO模式
 * 配置 GPIO 上拉输入模式
 */
void EC11_GPIO_INIT()
{
    pinMode(EC_CLKPIN, INPUT_PULLUP); // 上拉输入模式
    pinMode(EC_DTPIN, INPUT_PULLUP);
    pinMode(EC_SWPIN, INPUT_PULLUP);
}


char EC11_Scan(char EC11_Type)
{
    char CLKPIN = digitalRead(EC_CLKPIN);  // 获取CLK电平
    char DTPIN = digitalRead(EC_DTPIN);  // 获取DT电平

    static char EC_CLK_Last = 0; // 记录上一次时钟的电平信号

    char ScanResult = 0; // 扫描结果 0：误动作；    1：正传；         -1：反转
                         //         2：只按下按键； 3：按着按键正传； -3：按着按键反转

    // 一定位一脉冲
    if (EC11_Type == 0)
    {

    }

    // 两定位一脉冲
    else
    {
        // 比较上一次电平
        if(CLKPIN != EC_CLK_Last)
        {
            EC_CLK_Last = CLKPIN;
            // if(CLKPIN == 1 && DTPIN == 1) // CLK上升沿  DT为高电平  反转
            // {
            //     ScanResult = -1;
            // }
            // else if(CLKPIN == 0 && DTPIN == 0) // CLK下降沿  DT为低电平  反转
            // {
            //     ScanResult = -1;
            // }
            // else if(CLKPIN == 1 && DTPIN == 0) // CLK上升沿  DT为低电平  正传
            // {
            //     ScanResult = 1;
            // }
            // else if(CLKPIN == 0 && DTPIN == 1) // CLK下降沿  DT为高电平  正传
            // {
            //     ScanResult = 1;
            // }

            if(CLKPIN == DTPIN)  // CLK == DT 反转
            {
                ScanResult = -1;
            }
            else
            {
                ScanResult = 1; 
            }
        }
    }
    return ScanResult;
}
