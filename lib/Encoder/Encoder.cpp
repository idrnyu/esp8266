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

/**
 * @brief EC11旋转编码器扫描
 *
 * @param EC11_Type 0：一定位一脉冲；1：两定位一脉冲
 * @return char 结果码 0：无动作；1：正传；-1：反转；2：只按下按键；3：按着按键正传；-3：按着按键反转；
 */
signed char EC11_Scan(char EC11_Type)
{
    char CLKPIN = digitalRead(EC_CLKPIN); // 获取CLK电平
    char DTPIN = digitalRead(EC_DTPIN);   // 获取DT电平
    static char EC_CLK_Last = 0;          // 记录上一次时钟的电平信号
    signed char ScanResult = 0;           // 0：无动作；1：正传；-1：反转；2：只按下按键；3：按着按键正传；-3：按着按键反转；

    // EC11按下
    static char key_up = 1; // 按键松开标志，key_up=1 无按键按下，key_up=0 有按键按下
    if (key_up && digitalRead(EC_SWPIN) == 0)
        key_up = 0; // 有按键按下（标志位置位）
    else if (!key_up && digitalRead(EC_SWPIN) == 1)
    {
        key_up = 1;
        ScanResult = 2;
    }

    // 一定位一脉冲
    if (EC11_Type == 0)
    {
    }

    // 两定位一脉冲
    // CLK上升沿  DT为高电平  反转
    // CLK下降沿  DT为低电平  反转
    // CLK上升沿  DT为低电平  正传
    // CLK下降沿  DT为高电平  正传
    else
    {
        // 比较上一次电平，编码器有动作
        if (CLKPIN != EC_CLK_Last)
        {
            EC_CLK_Last = CLKPIN;
            if (CLKPIN == DTPIN) // CLK == DT 反转
            {
                if(!key_up)
                    ScanResult = -3;
                else
                    ScanResult = -1;
            }
            else
            {
                if(!key_up)
                    ScanResult = 3;
                else
                    ScanResult = 1;
            }
        }
    }
    return ScanResult;
}
