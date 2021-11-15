#include "time.h"

int timer_counter = 0;
int timer_flag = 0;
int time_cycle = 10;

void setTimer(int duration){
	timer_counter = duration/time_cycle;
	timer_flag = 0;
}
void timer_run(){
	if(timer_counter > 0){
		timer_counter --;
		if(timer_counter <= 0) timer_flag = 1;
	}
}

int timer_counter_1 = 0;
int timer_flag_1 = 0;

void setTimer_1(int duration){
	timer_counter_1 = duration/time_cycle;
	timer_flag_1 = 0;
}
void timer_run_1(){
	if(timer_counter_1 > 0){
		timer_counter_1 --;
		if(timer_counter_1 <= 0) timer_flag_1 = 1;
	}
}
