/**
 * @file key2.cpp
 * @author idrnyu
 * @brief 按钮控制LED
 * @version 0.1
 * @date 2021-09-20
 * 
 * 使用状态机思想来实现按钮功能，不完全霸占CPU资源。
 * 实现单击、双击、长按功能的按键程序
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "key2.h"

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
 * @brief 执行按钮程序
 * @deprecated 使用状态机形式处理按键程序
 * 
 */
void KEY_Task()
{

}
