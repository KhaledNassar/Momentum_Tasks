#include "stack.h"

void CreateStack(Stack *ps){
    ps -> top = 0;
}


void push(StackEntry e, Stack *ps){
    ps -> entry[ps -> top++] = e;
}


void Pop(StackEntry *pe, Stack *ps){
    *pe = ps -> entry[--ps -> top];
}


int StackFull(Stack *ps){
    return (ps -> top >= MAXSTACK);
}


int StackEmpty(Stack *ps){
    return (!(ps -> top));
}


void StackTop(StackEntry *pe, Stack *ps){
    *pe = ps -> entry[ps -> top - 1];
}


int StackSize(Stack *ps){
    return ps -> top;
}


void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
    for(int i = ps -> top; i>0; i--)
        (*pf)(ps -> entry [i-1]);
}


void ClearStack(Stack *ps){
    ps -> top = 0;
}

