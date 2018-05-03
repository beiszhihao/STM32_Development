//定义电路地址  
#define BLOCK_2 (unsigned int)0x40000000        //BLOCK_2基址  
#define BLOCK_2_APB2_GPIO_C (BLOCK_2+0x11000)   //APB2总线上GPIOC_引脚端口  
#define BLOCK_2_GPIOC_CRL        *(unsigned int*)(BLOCK_2_APB2_GPIO_C+0x00) //GPIO_CRL寄存器  
#define BLOCK_2_GPIOC_BSRR       *(unsigned int*)(BLOCK_2_APB2_GPIO_C+0x10)//GPIO_BSRR寄存器  
#define BLOCK_2_RCC_BASE         (BLOCK_2 + 0x21000)    //APB2时钟电路基址  
#define BLOCK_2_RCC_APB2         *(unsigned int*)(BLOCK_2_RCC_BASE+0x18)    //APB2时钟电路基址  
//stm32初始化函数  
void SystemInit()  
{  
  
}  
//延迟函数  
void sleep(int time){  
    while (time--); //递减，while循环不为0循环继续，当time为0时循环结束  
}  
int main(){  
    BLOCK_2_RCC_APB2 |= 1 << 4;   //开启时钟电路  
    BLOCK_2_GPIOC_CRL |= (2 << 4 * 0);    //设置GPIO_C端口为推送状态  
    BLOCK_2_GPIOC_BSRR = (1 << (16 + 0)); //设置高位16+0，即向pc0输出一个高电平  
    while (1){  //死循环闪烁  
        BLOCK_2_GPIOC_BSRR = (1 << (16 + 0)); //亮  
        sleep(0xFFFF);  
        BLOCK_2_GPIOC_BSRR = (1 << (0));  //灭  
    }  
}  