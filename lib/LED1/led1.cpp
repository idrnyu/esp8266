#include "led1.h"

// 非阻塞LED闪烁
unsigned long previousMillis = 0;
const long interval = 100; // 灯闪烁的时间间隔

/**
 * @brief 初始化LED所在的IO口为输出模式
 */
void LED1_GPIO_INIT()
{
    pinMode(LED1PIN, OUTPUT); // 将LEDPIN 设置为输出模式
}

void LED1_twinkle()
{
    unsigned long currentMillis = millis(); // 获取当前的系统运行时间长度
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        if (digitalRead(LED1PIN) == LOW)
        {
            digitalWrite(LED1PIN, HIGH);
        }
        else
        {
            digitalWrite(LED1PIN, LOW);
        }
    }
}