#ifndef _ISTACK_H_
#define _ISTACK_H_

#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
    int length;
} Stack;

Stack *s_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->length = 0;
    return s;
}

int s_push(Stack *s, int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = s->top;
    s->top = newNode;
    s->length++;
    return n;
}

int s_pop(Stack *s)
{
    if (s->top == NULL)
    {
        return -1; // Indicate that stack is empty.
    }
    int pop_val = s->top->data;
    Node *topNode = s->top;
    s->top = s->top->next;
    s->length--;
    free(topNode);
    return pop_val;
}

int s_top(Stack *s)
{
    if (s->top == NULL)
    {
        return -1; // Indicate that stack is empty.
    }
    return s->top->data;
}

int s_empty(Stack *s)
{
    return (s->top == NULL);
}

int s_length(Stack *s)
{
    return s->length;
}

#endif
