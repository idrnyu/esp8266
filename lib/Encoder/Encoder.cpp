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

#include <HardwareSerial.h>
#include "Encoder.h"

/**
 * @brief 初始化GPIO模式
 * 配置 GPIO 上拉输入模式
 */
void EC11_GPIO_INIT()
{
    Serial.begin(9600); // 初始化串口 波特率9600
    Serial.print("初始化中...\r\n");

    pinMode(EC_CLKPIN, INPUT_PULLUP); // 上拉输入模式
    pinMode(EC_DTPIN, INPUT_PULLUP);
    pinMode(EC_SWPIN, INPUT_PULLUP);
}

/**
 * @brief EC11旋转编码器扫描
 *
 * @param EC11_Type 0：一定位一脉冲；1：两定位一脉冲
 * @return unsigned char 结果码 0：无动作；1：正传；-1：反转；2：只按下按键；3：按着按键正传；-3：按着按键反转；
 */
signed char EC11_Scan(unsigned char EC11_Type)
{
    signed char ScanResult = 0;                    // 0：无动作；1：正传；-1：反转；2：只按下按键；3：按着按键正传；-3：按着按键反转；
    unsigned char CLKPIN = digitalRead(EC_CLKPIN); // 获取CLK电平
    unsigned char DTPIN = digitalRead(EC_DTPIN);   // 获取DT电平
    unsigned char SWPIN = digitalRead(EC_SWPIN);   // 获取SW电平
    static unsigned char EC_CLK_Last = CLKPIN;     // 记录上一次时钟的电平信号
    static unsigned char key_up = 0;               // 按键松开标志，0：无按键按下；1：有按键按下
    static unsigned char is_turn = 0;              // 编码器是否有转动，0：编码器无转动过；1：编码器有转动过

    // EC11按下
    if (!key_up && SWPIN == 0)
    {
        delay(50); // 加个消抖动作
        if (digitalRead(EC_SWPIN) == 0)
        {
            key_up = 1;  // 有按键按下（标志位置位）
            is_turn = 0; // 旋转动作清零
        }
    }
    else if (key_up && SWPIN == 1)
    {
        key_up = 0;   //按键松开了
        if (!is_turn) // 编码器没有转动过
            ScanResult = 2;
    }

    // 一定位一脉冲 && CLK为低电平 && 需要等待一个CLK周期脉冲完成后才能继续进入
    // CLK为低电平时  DT为低电平  反传
    // CLK为低电平时  DT为高电平  正传
    if (EC11_Type == 0 && CLKPIN != EC_CLK_Last)
    {
        is_turn = 1; // 编码器动作置位
        EC_CLK_Last = CLKPIN;
        if (CLKPIN == 0)
        {
            ScanResult = DTPIN ? (key_up ? 3 : 1) : (key_up ? -3 : -1);
        }
    }

    // 两定位一脉冲 && 比较上一CLK次电平，编码器有动作（电平跳变沿触发）
    // CLK上升沿  DT为高电平  反转
    // CLK下降沿  DT为低电平  反转
    // CLK上升沿  DT为低电平  正传
    // CLK下降沿  DT为高电平  正传
    else if (EC11_Type == 1 && CLKPIN != EC_CLK_Last)
    {
        is_turn = 1; // 编码器动作置位
        EC_CLK_Last = CLKPIN;
        // CLK当前电平 等于 DT当前电平 表示反转；否则正传；key_up：1，EC11自带的按键被按下；
        ScanResult = CLKPIN == DTPIN ? (key_up ? -3 : -1) : (key_up ? 3 : 1);
    }
    return ScanResult;
}

/**
 * @brief 测试EC11编码器
 *
 */
void EC11_Test()
{
    static int TestNumber = 0;
    signed char data = EC11_Scan(1);
    switch (data)
    {
    case -1:
        Serial.println("反转-1");
        TestNumber -= 1;
        break;
    case 1:
        Serial.println("正转+1");
        TestNumber += 1;
        break;
    case 2:
        Serial.println("按钮按下+5");
        TestNumber += 5;
        break;
    case -3:
        Serial.println("按下反转-3");
        TestNumber -= 3;
        break;
    case 3:
        Serial.println("按下正转+3");
        TestNumber += 3;
        break;

    default:
        break;
    }
    if (data != 0)
    {
        Serial.println(TestNumber);
    }
}
