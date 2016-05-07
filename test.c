#include "CommentConvert.h"

void test()
{
	//CommentConvert();
}

int main()
{	
	FILE *r = fopen("input.c", "r");
	FILE *w = fopen("output.c", "w");

	ConvertWork(r, w);
	//test();
	system("pause");
	return 0;
}

