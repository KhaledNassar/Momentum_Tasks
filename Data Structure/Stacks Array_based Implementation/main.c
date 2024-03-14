#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Print_Items(int);

int main()
{
    Stack s;
    StackEntry e, Top;
    CreateStack(&s);
    int IsEmpty = StackEmpty(&s);
    if(IsEmpty == 1)
        printf("Stack is Empty \n");
    push(5, &s);
    push(6, &s);
    push(7, &s);
    push(8, &s);
    int Size = StackSize(&s);
    printf("Stack Size is: %d \n", Size);
    Pop(&e, &s);
    printf("The Poped Item is: %d \n", e);
    int IsFull = StackFull(&s);
    if(IsFull == 1)
        printf("Stack is Full \n");
    else
        printf("Stack is not Full \n");
    StackTop(&Top, &s);
    printf("The On_Top Item is: %d \n", Top);
    TraverseStack(&s, &Print_Items);
    printf("\n");
    ClearStack(&s);
    IsEmpty = StackEmpty(&s);
    if(IsEmpty == 1)
        printf("Stack is Empty \n");

    return 0;
}

void Print_Items(int item){
    printf("%d ");
}
