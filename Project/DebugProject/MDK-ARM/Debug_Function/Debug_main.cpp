#include "include.h"
#include "include_to_c.h"
//这两个include必须写，不写必定报错！

Debug_Class Debug;

void Debug_Main() {

}

void Debug_Main_While() {
	//printf("W");//测试代码，记得删除（测试串口发送数据是否成功）
  Debug.LED_Debug();
	Debug.IO_Debug('C',13,1);//对对应IO进行电平操作（未测试）
	Debug.UART_Debug("Hello World!");//对传入数据进行UART输出(输出为字符串)（可使用RCT6与PC进行通讯测试结果）（未测试）
}