#include "include.h"

/*此Debug函数用来检测函数执行到哪一条
 *表现为单片机进入死循环，小灯一直闪烁
 *可以用于排查代码是否被执行
*/
void Debug_Class::LED_Debug() {
    while(1)
    {
       HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET);
       HAL_Delay(500);
       HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET);
       HAL_Delay(500);
    }
}