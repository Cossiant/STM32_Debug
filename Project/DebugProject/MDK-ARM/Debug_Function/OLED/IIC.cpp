#include "include.h"

//����̳���ο�https://zhuanlan.zhihu.com/p/579536577
//����ֻ�ǳ�ʼ��IIC��ɣ�������дIIC������IIC�������룡

#define GPIO_PIN_SDA GPIO_PIN_5
#define GPIO_PIN_SCL GPIO_PIN_4
#define IIC_SCL_Hi   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SCL,GPIO_PIN_SET)//SCL����ߵ�ƽ
#define IIC_SCL_Lo   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SCL,GPIO_PIN_RESET) //SCL����͵�ƽ
#define IIC_SDA_Hi   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SDA,GPIO_PIN_SET) //SDA����ߵ�ƽ
#define IIC_SDA_Lo   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_SDA,GPIO_PIN_RESET) //SDA����͵�ƽ

#define IIC_SDA_In    GPIO_ReadInputDataBit (GPIOH,GPIO_Pin_5) //����SDA״̬
//A5�˿�OUT��ʼ��
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
//A5�˿�IN��ʼ��
void SDA_IN(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitStructure.Pin= GPIO_PIN_SDA;
		GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
		GPIO_InitStructure.Pull = GPIO_PULLUP;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}
//A4�˿�OUT��ʼ��
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
	 
//Ĭ�ϳ�ʼ������IIC�ӿ�
void IIC_Init(void)
{                        
    SDA_OUT();
    SCL_OUT();

    IIC_SCL_Hi;
    IIC_SDA_Hi;
}
