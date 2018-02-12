/*
 * IncFile1.h
 *
 * Created: 10/20/2016 12:40:11 AM
 *  Author: m.mamdooh
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


////////////////////////////////////////////////////////
////////// prototypes /////////////////////////////////
//////////////////////////////////////////////////////
void SEG_Init(void );
void SEG_write(char val);
void SEG_BCDWrite(char val);
void SEG1 (char val);
void SEG2 (char val);
//////////////////////////////////////////////////////
//////////////// Configuration //////////////////////
////////////////////////////////////////////////////
#define SEG_Init_NUM  
#define SEG1_Enable  1
#define SEG2_Enable  1
#define SEG1_Disable 0
#define SEG2_Disable 0
#define SEGA 20
#define SEG1_En_Pin 18
#define SEG2_En_Pin 19
#define SEGB 21
#define SEGC 22
#define SEGD 23

  



#endif /* INCFILE1_H_ */