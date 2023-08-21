#ifndef DEBUG_H
#define DEBUG_H

//Debug发送出去的数据（测试用）
/*
class Debug_Data_Class {
public:
    char *String_Data;//(可以正常使用)
    //unsigned char Data;(单个字符发送，暂未测试)
    int Data_Num;
};
 */
//Debug的类函数，继承了Debug的Data以便程序的编写（记得初始化Data！）
class Debug_Class {
public:
    //Debug_Data_Class Debug_Data;
    void LED_Debug();//LED闪烁Debug函数
    void UART_Debug(const char *Data);//串口输出数据Debug函数（需要对应接收端，而且使用前记得修改波特率）
    void IO_Debug(char GPIO_PORT, int GPIO_PIN, unsigned char IO_Setting);//IO输出对应电平的Debug函数
    //void Data_Init(Debug_Data_Class *Debug_Data,const char *Input_Data);//数据初始化函数
};

#endif