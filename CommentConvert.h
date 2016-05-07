#define _CRT_SECURE_NO_WARNINGS
#ifndef _COMMENT_CONVERT_H_
#define _COMMENT_CONVERT_H_
#include<stdio.h>
#include<stdlib.h>


#define READ_FILE_NAME "input.c"
#define WRITE_FILE_NAME "output.c"

typedef enum STATE
{
	NULL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
}STATE;

void DoConvertWorTk(char*readfile, char*writefile);
void CommentConvert();
void ConvertWork(FILE*read, FILE*write);
void DoCState(FILE*read, FILE*write);
void DoNullState(FILE*read, FILE*write);
void DoCPPState(FILE*read, FILE*write);
#endif
