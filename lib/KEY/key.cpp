#include "key.h"

/**
 * @brief 初始化按键GPIO 模式
 * 
 */
void KEY_GPIO_INIT()
{
    pinMode(KEYPIN, INPUT);
    pinMode(KLEDPIN, OUTPUT);
    digitalWrite(KLEDPIN, HIGH);
}

/**
 * @brief 执行按钮程序
 * @deprecated 判断按钮按下 -> 延时防抖 -> 再次确认按钮是否按下 -> 执行内容 -> 等待按钮松开
 * 
 */
void KEY_Task()
{
    if (digitalRead(KEYPIN) == LOW)
    {
        delay(50);
        if (digitalRead(KEYPIN) == LOW)
        {
            digitalWrite(KLEDPIN, !digitalRead(KLEDPIN));
        }
        while (digitalRead(KEYPIN) == LOW);
    }
}
