#include <stdio.h>
#include "ex02.h"
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 10

int top = -1;
char stack[STACK_SIZE][10];

int a() {
	push((const char *)"a");
	printf("before calling b() \n");
	print_stack();

	b();

	pop();
	printf("after calling b()\n");
	print_stack();

	return 0;
	
}

int b() {
	push((const char *)"b");
	printf("before calling c() \n");
	print_stack();

	c();

	pop();
	printf("after calling c()\n");
	print_stack();
	return 0;
}

int c() {
	push((const char *)"c");
	printf("\n");
	print_stack();

	printf("\n");
	pop();
	print_stack();
	return 0;


}

void push(const char *item) {
	if (top >= STACK_SIZE - 1)
	printf("Stack is overflow!!!\n");
	else {
		top++;
		strcpy_s(stack[top], item);
	}
}

char* pop() {
	if (top == -1) {
		printf("Stack is empty!!!\n");
		exit(1);
	}
		return stack[top--];
	
}

void print_stack() {
	for(int i = 0; i <=top; i++) {
		printf("%s\n", stack[i]);
	}
}

/*
int main() {

	push((const char *)"main");
	printf("before calling a() \n");
	print_stack();

	a();

	pop();
	printf("after calling a()\n");
	print_stack();
	return 0;
}
*/