
#include "STM8s.h"
main()
{
GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_SLOW);
while (1);
}
