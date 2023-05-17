#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
void StackInit(struct Stack* ps, int DefaultCapcity)
{
	ps->a = (int*)malloc(sizeof(int) * DefaultCapcity);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->top = 0;
	ps->capcity = DefaultCapcity;
}

void StackPush(struct Stack* ps, int x)
{
	//.....
	
	//.....
}

void StackPush(struct Stack* ps, double x)
{
	//.....

	//.....
}
