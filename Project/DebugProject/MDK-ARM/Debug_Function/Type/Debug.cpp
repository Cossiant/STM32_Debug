#include "include.h"

/*此Debug函数用来检测函数执行到哪一条
 *表现为单片机进入死循环，小灯一直闪烁
 *可以用于排查代码是否被执行
*/
void Debug_Class::LED_Debug() {
    while (1) {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        HAL_Delay(500);
    }
}

//串口输出函数
void Debug_Class::UART_Debug(const char *Data) {
    printf("%s", Data);
}

void Debug_Class::IO_Debug(char GPIO_PORT, int GPIO_PIN, unsigned char IO_Setting) {
    GPIO_TypeDef *Setting_GPIO_PORT;
    int Setting_GPIO_PIN;
    switch (GPIO_PIN) {
        case (0):
            Setting_GPIO_PIN = GPIO_PIN_0;
            break;
        case (1):
            Setting_GPIO_PIN = GPIO_PIN_1;
            break;
        case (2):
            Setting_GPIO_PIN = GPIO_PIN_2;
            break;
        case (3):
            Setting_GPIO_PIN = GPIO_PIN_3;
            break;
        case (4):
            Setting_GPIO_PIN = GPIO_PIN_4;
            break;
        case (5):
            Setting_GPIO_PIN = GPIO_PIN_5;
            break;
        case (6):
            Setting_GPIO_PIN = GPIO_PIN_6;
            break;
        case (7):
            Setting_GPIO_PIN = GPIO_PIN_7;
            break;
        case (8):
            Setting_GPIO_PIN = GPIO_PIN_8;
            break;
        case (9):
            Setting_GPIO_PIN = GPIO_PIN_9;
            break;
        case (10):
            Setting_GPIO_PIN = GPIO_PIN_10;
            break;
        case (11):
            Setting_GPIO_PIN = GPIO_PIN_11;
            break;
        case (12):
            Setting_GPIO_PIN = GPIO_PIN_12;
            break;
        case (13):
            Setting_GPIO_PIN = GPIO_PIN_13;
            break;
        case (14):
            Setting_GPIO_PIN = GPIO_PIN_14;
            break;
        case (15):
            Setting_GPIO_PIN = GPIO_PIN_15;
            break;
    }
    if (GPIO_PORT == 'A') {
        Setting_GPIO_PORT = GPIOA;
    }
    if (GPIO_PORT == 'B') {
        Setting_GPIO_PORT = GPIOB;
    }
    if (GPIO_PORT == 'C') {
        Setting_GPIO_PORT = GPIOC;
    }
    if (IO_Setting == 1) {
        HAL_GPIO_WritePin(Setting_GPIO_PORT, Setting_GPIO_PIN, GPIO_PIN_SET);
    }
    if (IO_Setting == 0) {
        HAL_GPIO_WritePin(Setting_GPIO_PORT, Setting_GPIO_PIN, GPIO_PIN_RESET);
    }
}

/*//测试代码
void Debug_Class::Data_Init(Debug_Data_Class *Debug_Data,const char *Input_Data) {
    strcpy(Debug_Data->String_Data,Input_Data);
}
 */