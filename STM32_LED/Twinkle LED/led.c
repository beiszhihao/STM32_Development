//�����·��ַ  
#define BLOCK_2 (unsigned int)0x40000000        //BLOCK_2��ַ  
#define BLOCK_2_APB2_GPIO_C (BLOCK_2+0x11000)   //APB2������GPIOC_���Ŷ˿�  
#define BLOCK_2_GPIOC_CRL        *(unsigned int*)(BLOCK_2_APB2_GPIO_C+0x00) //GPIO_CRL�Ĵ���  
#define BLOCK_2_GPIOC_BSRR       *(unsigned int*)(BLOCK_2_APB2_GPIO_C+0x10)//GPIO_BSRR�Ĵ���  
#define BLOCK_2_RCC_BASE         (BLOCK_2 + 0x21000)    //APB2ʱ�ӵ�·��ַ  
#define BLOCK_2_RCC_APB2         *(unsigned int*)(BLOCK_2_RCC_BASE+0x18)    //APB2ʱ�ӵ�·��ַ  
//stm32��ʼ������  
void SystemInit()  
{  
  
}  
//�ӳٺ���  
void sleep(int time){  
    while (time--); //�ݼ���whileѭ����Ϊ0ѭ����������timeΪ0ʱѭ������  
}  
int main(){  
    BLOCK_2_RCC_APB2 |= 1 << 4;   //����ʱ�ӵ�·  
    BLOCK_2_GPIOC_CRL |= (2 << 4 * 0);    //����GPIO_C�˿�Ϊ����״̬  
    BLOCK_2_GPIOC_BSRR = (1 << (16 + 0)); //���ø�λ16+0������pc0���һ���ߵ�ƽ  
    while (1){  //��ѭ����˸  
        BLOCK_2_GPIOC_BSRR = (1 << (16 + 0)); //��  
        sleep(0xFFFF);  
        BLOCK_2_GPIOC_BSRR = (1 << (0));  //��  
    }  
}  