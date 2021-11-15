#include "main.h"
#include "input_reading.h"

enum ButtonState{UNKNOWN, BUTTON_RELEASED, BUTTON_PRESSED};
enum ButtonState buttonState = UNKNOWN;

int mode = 1;
int button_flag = 0;
int red = 5, yel = 2, gre = 3;
int red_set, yel_set, gre_set;
int idx = 0;

void display7SEG_1(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin|L4_Pin|L5_Pin|L6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L4_Pin|L5_Pin|L6_Pin|L7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, L2_Pin|L3_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L4_Pin|L5_Pin|L7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, L3_Pin|L6_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin|L4_Pin|L7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, L5_Pin|L6_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L4_Pin|L5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, L2_Pin|L3_Pin|L6_Pin|L7_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, L2_Pin|L5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L3_Pin|L4_Pin|L6_Pin|L7_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L3_Pin|L4_Pin|L5_Pin|L6_Pin|L7_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, L4_Pin|L5_Pin|L6_Pin|L7_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin|L4_Pin|L5_Pin|L6_Pin|L7_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin|L4_Pin|L6_Pin|L7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, SET);
		break;
	}
}
void display7SEG_2(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L9_Pin|L10_Pin|L11_Pin|L12_Pin|L13_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L14_GPIO_Port, L14_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L11_Pin|L12_Pin|L13_Pin|L14_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, L9_Pin|L10_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L9_Pin|L11_Pin|L12_Pin|L14_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, L10_Pin|L13_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L9_Pin|L10_Pin|L11_Pin|L14_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, L12_Pin|L13_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L11_Pin|L12_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, L9_Pin|L10_Pin|L13_Pin|L14_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, L9_Pin|L12_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L10_Pin|L11_Pin|L13_Pin|L14_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L10_Pin|L11_Pin|L12_Pin|L13_Pin|L14_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L9_Pin|L10_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, L11_Pin|L12_Pin|L13_Pin|L14_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L9_Pin|L10_Pin|L11_Pin|L12_Pin|L13_Pin|L14_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, L8_Pin|L9_Pin|L10_Pin|L11_Pin|L13_Pin|L14_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, SET);
		break;
	}
}
void update7SEG(int num, int a, int b){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, E0_Pin|E2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, E1_Pin|E3_Pin, GPIO_PIN_SET)	;
		display7SEG_1(a/10);
		display7SEG_2(b/10);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, E1_Pin|E3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, E0_Pin|E2_Pin, GPIO_PIN_SET);
		display7SEG_1(a%10);
		display7SEG_2(b%10);
		break;
	}
 }
void fsm_for_input_processing(void){
	switch(buttonState){
		case UNKNOWN:
			buttonState = BUTTON_RELEASED;
			break;
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				buttonState = BUTTON_PRESSED;
				button_flag = 1;
				mode++;
				if(mode > 4) mode = 1;

				if(red_set == 0) red_set = red;
				if(yel_set == 0) yel_set = yel;
				if(gre_set == 0) gre_set = gre;
			}

			if(is_button_pressed(1)){
				buttonState = BUTTON_PRESSED;
				button_flag = 2;
				if(mode == 2){
					red_set++;
					if(red_set > 99) red_set = 1;
				}
				else if(mode == 3){
					yel_set++;
					if(yel_set + gre > red) yel_set = 1;
				}
				else if(mode == 4){
					gre_set++;
					if(yel + gre_set > red) gre_set = 1;
				}
			}

			if(is_button_pressed(2)){
				buttonState = BUTTON_PRESSED;
				button_flag = 3;
				if(mode == 2){
					red = red_set;
					red_set = 0;
				}
				else if(mode == 3){
					yel = yel_set;
					yel_set = 0;
				}
				else if(mode == 4){
					gre = gre_set;
					gre_set = 0;
				}
			}
			break;

		case BUTTON_PRESSED:
			if(button_flag == 1){
				if(!is_button_pressed(0)){
					buttonState = BUTTON_RELEASED;
					button_flag = 0;
					break;
				}
			}
			if(button_flag == 2){
				if(!is_button_pressed(1)){
					buttonState = BUTTON_RELEASED;
					button_flag = 0;
					break;
				}
			}
			if(button_flag == 3){
				if(!is_button_pressed(2)){
					buttonState = BUTTON_RELEASED;
					button_flag = 0;
					break;
				}
			}
		}
}
