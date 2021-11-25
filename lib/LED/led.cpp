#include "led.h"

/**
 * @brief 初始化LED所在的IO口为输出模式
 */
void LED_GPIO_INIT()
{
    pinMode(LEDPIN, OUTPUT); // 将LEDPIN 设置为输出模式
}

/**
 * @brief LED闪烁
 * 
 */
void LED_twinkle()
{
    digitalWrite(LEDPIN, HIGH); // 数字写入  让指定的IO口输出高电平
    delay(500);  // 延时500ms
    digitalWrite(LEDPIN, LOW);  // 数字写入  让指定的IO口输出低电平
    delay(500);  // 延时500ms
}
