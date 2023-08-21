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
		if(GPIO_PORT=='A')
		{
			Setting_GPIO_PORT=GPIOA;
		}
		if(GPIO_PORT=='B')
		{
			Setting_GPIO_PORT=GPIOA;
		}
		if(GPIO_PORT=='C')
		{
			Setting_GPIO_PORT=GPIOA;
		}
		if(IO_Setting==1)
		{
			HAL_GPIO_WritePin(Setting_GPIO_PORT,GPIO_PIN,GPIO_PIN_SET);
		}
		if(IO_Setting==0)
		{
			HAL_GPIO_WritePin(Setting_GPIO_PORT,GPIO_PIN,GPIO_PIN_RESET);
		}
}

/*//测试代码
void Debug_Class::Data_Init(Debug_Data_Class *Debug_Data,const char *Input_Data) {
    strcpy(Debug_Data->String_Data,Input_Data);
}
 */