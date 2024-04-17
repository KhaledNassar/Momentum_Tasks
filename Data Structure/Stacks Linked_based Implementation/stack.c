#include<stdlib.h>
#include"stack.h"

void CreateStack(Stack* ps) {
    ps->top = NULL;
}

void push(StackEntry e, Stack* ps) {
    StackNode* pn = (StackNode*)malloc(sizeof(StackNode));
    if (pn == NULL) {
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
}

void Pop(StackEntry* pe, Stack* ps) {
    *pe = ps->top->entry;
    StackNode* pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
}

int StackFull(Stack* ps) {
    return 0; // Linked list-based stack cannot be full
}

int StackEmpty(Stack* ps) {
    return (ps->top == NULL);
}

void StackTop(StackEntry* pe, Stack* ps) {
    *pe = ps->top->entry;
}

int StackSize(Stack* ps) {
    int count = 0;
    StackNode* pn = ps->top;
    while (pn) {
        count++;
        pn = pn->next;
    }
    return count;
}

void TraverseStack(Stack* ps, void(*pf)(StackEntry)) {
    StackNode* pn = ps->top;
    while (pn) {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}

void ClearStack(Stack* ps) {
    StackNode* pn = ps->top;
    StackNode* qn = ps->top;
    while (pn) {
        pn = pn->next;
        free(qn);
    }
    ps->top = NULL;
}
