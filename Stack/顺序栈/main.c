//
// Created by MI on 2024/9/19.
//
/**
*
用于学习顺序栈
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 去掉分号

// 定义的数据类型
typedef struct selemType {
    char data;
} SelemType;

// 这个就是栈
typedef struct Stack {
    SelemType* top;
    SelemType* base;
    int stackSize;
} SqStack;

// 栈的初始化
SqStack* InitStack() {
    SqStack* s = (SqStack*)malloc(sizeof(SqStack));
    s->base = (SelemType*)malloc(MAXSIZE * sizeof(SelemType)); // 分配MAXSIZE大小
    if (s->base == NULL) {
        printf("fail to malloc\n");
        exit(0);
    }
    s->top = s->base;
    s->stackSize = MAXSIZE;
    return s;
}

// 入栈操作
void Push(SqStack* s, SelemType e) {
    if (s->top - s->base == s->stackSize) { // 栈满
        printf("Stack Overflow\n");
        exit(0);
    }
    *s->top++ = e; // 将e压入栈顶，栈顶指针加一
}

// 出栈操作
void Pop(SqStack* s) {
    if (s->top == s->base) { // 空栈
        printf("Stack Underflow\n");
        exit(0);
    }
    s->top--; // 栈顶指针减一
}

// 取出栈顶元素
SelemType GetTop(SqStack* s) {
    if (s->top == s->base) { // 判断栈非空
        printf("Stack Underflow\n");
        exit(0);
    }
    SelemType e = *(s->top - 1);
    return e;
}

int main() {
    SelemType selem[3];
    for (int i = 0; i < 3; i++) {
        selem[i].data = 'A' + i;
    }

    // 初始化栈
    SqStack* s = InitStack();

    // 循环入栈
    for (int i = 0; i < 3; i++) {
        printf("%c", selem[i].data);
        Push(s, selem[i]);
    }
    printf("\n");

    // 取栈顶元素
    printf("%c\n", GetTop(s).data);
    printf("%c\n", GetTop(s).data);

    // 出栈操作
    printf("%c\n", GetTop(s).data);

    Pop(s);
    printf("%c\n", GetTop(s).data);

    Pop(s);
    printf("%c\n", GetTop(s).data);

    free(s->base);
    free(s);

    return 0;
}
