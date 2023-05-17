#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int* a;
	int top;
	int capcity;
};

void StackInit(struct Stack* ps, int DefaultCapcity = 4);

void StackPush(struct Stack* ps, int x);

void StackPush(struct Stack* ps, double x);