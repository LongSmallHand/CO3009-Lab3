#include "main.h"

#define N0_OF_BUTTONS 				       3

#define BUTTON_IS_PRESSED                  GPIO_PIN_SET
#define BUTTON_IS_RELEASED                 GPIO_PIN_RESET

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

void button_1_reading(void){
	debounceButtonBuffer2[0] = debounceButtonBuffer1[0];
	debounceButtonBuffer1[0] = HAL_GPIO_ReadPin(B0_GPIO_Port, B0_Pin);
	if(debounceButtonBuffer1[0] == debounceButtonBuffer2[0])
		buttonBuffer[0] = debounceButtonBuffer1[0];
}
void button_2_reading(void){
	debounceButtonBuffer2[1] = debounceButtonBuffer1[1];
	debounceButtonBuffer1[1] = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	if(debounceButtonBuffer1[1] == debounceButtonBuffer2[1])
		buttonBuffer[1] = debounceButtonBuffer1[1];
}
void button_3_reading(void){
	debounceButtonBuffer2[2] = debounceButtonBuffer1[2];
	debounceButtonBuffer1[2] = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);
	if(debounceButtonBuffer1[2] == debounceButtonBuffer2[2])
		buttonBuffer[2] = debounceButtonBuffer1[2];
}
unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
