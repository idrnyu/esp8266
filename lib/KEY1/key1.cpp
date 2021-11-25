/**
 * @file key1.cpp
 * @author idrnyu
 * @brief 按钮控制LED
 * @version 0.1
 * @date 2021-09-20
 * 
 * 经典按键扫描检测 减少CPU占用时间
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "key1.h"

/**
 * @brief 初始化GPIO模式
 * 
 */
void KEY_GPIO_INIT()
{
    pinMode(KEYPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, HIGH);
}

/**
 * @brief 扫描按键程序 
 * 
 * @param mode 模式， 0 不支持连续触发（长按连续触发）  1 长按会被连续触发
 * @return u8 返回键码 0 无按键按下
 */
u8 KEY_Scan(u8 mode)
{
    static u8 key_up = 1; // 按键松开标志，key_up=1 为无按键按下，key_up=0 为有按键按下

    if (mode)
        key_up = 1; // 强制标志位释放

    // 有按键按下
    if (key_up && (digitalRead(KEYPIN) == LOW))
    {
        delay(10);  // 按键消抖
        key_up = 0; // 有按键按下（标志位置位）

        if(digitalRead(KEYPIN) == LOW)
            return 1;
    }
    // 无按键按下
    else if (digitalRead(KEYPIN) == HIGH)
        key_up = 1;
    return 0;
}

/**
 * @brief 测试程序
 * 
 */
void KEY_Test()
{
    u8 key_code = KEY_Scan(0);
    switch (key_code)
    {
    case 1:
        digitalWrite(LEDPIN, !digitalRead(LEDPIN));
        break;
    
    default:
        break;
    }
}
