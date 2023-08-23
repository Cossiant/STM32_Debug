#include "include.h"

//详情教程请参考https://zhuanlan.zhihu.com/p/579536577
//现在只是初始化IIC完成，后续请写IIC启动和IIC结束代码！

#define GPIO_PIN_SDA GPIO_PIN_5
#define GPIO_PIN_SCL GPIO_PIN_4
#define IIC_SCL_Hi   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SCL,GPIO_PIN_SET)//SCL输出高电平
#define IIC_SCL_Lo   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SCL,GPIO_PIN_RESET) //SCL输出低电平
#define IIC_SDA_Hi   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SDA,GPIO_PIN_SET) //SDA输出高电平
#define IIC_SDA_Lo   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SDA,GPIO_PIN_RESET) //SDA输出低电平

#define IIC_SDA_In    GPIO_ReadInputDataBit (GPIOH,GPIO_Pin_5) //输入SDA状态
//A5端口OUT初始化
void SDA_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitStructure.Pin = GPIO_PIN_SDA; 
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD; 
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH; 
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
   }
//A5端口IN初始化
void SDA_IN(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitStructure.Pin= GPIO_PIN_SDA;
		GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
		GPIO_InitStructure.Pull = GPIO_PULLUP;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}
//A4端口OUT初始化
void SCL_OUT(void)//PA1
{
    GPIO_InitTypeDef GPIO_InitStructure;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStructure.Pin= GPIO_PIN_SCL;
		GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
		GPIO_InitStructure.Pull = GPIO_PULLUP;
		GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA,&GPIO_InitStructure);
}
	 
//默认初始化配置IIC接口
void IIC_Init(void)
{                        
    SDA_OUT();
    SCL_OUT();

    IIC_SCL_Hi;
    IIC_SDA_Hi;
}
