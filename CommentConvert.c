#include "CommentConvert.h"

STATE state;
void DoNULLState(FILE *read, FILE *write)
{
	int first = fgetc(read);
	int second = 0;
	switch (first)
	{
	case'/':
		second = fgetc(read);
		if (second == '*')
		{
			fputc(first, write);
			fputc('/', write);
			state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, write);
			fputc(second, write);
			state = CPP_STATE;
		}
		else
		{
			fputc(first, write);
			fputc(second, write);
		}
		break;
	case EOF:
		fputc(first, write);
		state = END_STATE;
		break;
	default:
		fputc((char)first, write);
		break;
	}
}

void DoCState(FILE*read, FILE*write)
{
	int first = fgetc(read);
	int second = 0;
	switch (first)
	{
	case '*':
		second = fgetc(read);
		if (second == '/')
		{
			fputc('\n', write);
			state = NULL_STATE;
		}
		else
		{
			fputc(first, write);
			ungetc(second, read);
        }
		break;
	case '\n':
		fputc(first, write);
		fputc('/', write);
		fputc('/', write);
	
		
		break;
	case EOF:
		fputc(first, write);
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}
}
void DoCPPState(FILE *read, FILE *write)
{
	int first = 0;
	int second = 0;
	first = fgetc(read);
	switch (first)
	{
	case '\n':
		fputc(first, write);
	
		state = NULL_STATE;
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}
}
void ConvertWork(FILE *read, FILE *write)
{
	state = NULL_STATE;
	while (state != END_STATE)
	{
		switch (state)
		{
		case NULL_STATE:
				DoNULLState(read, write);
				break;
		case C_STATE:
			
			DoCState(read, write);
                break;
		case CPP_STATE:
			DoCPPState(read, write);
			break;

		}
	}
}




