#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

extern int mode;
extern int red, yel, gre;
extern int red_set, yel_set, gre_set;
extern int idx;

void update7SEG(int num, int a, int b);
void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
