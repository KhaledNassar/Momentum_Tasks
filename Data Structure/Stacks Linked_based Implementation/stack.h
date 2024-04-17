#define StackEntry int

typedef struct stacknode{
    StackEntry entry;
    struct stacknode* next;
}StackNode;

typedef struct stack{
    StackNode* top;
}Stack;

void CreateStack(Stack *ps);
void push(StackEntry e, Stack *ps);
void Pop(StackEntry *pe, Stack *ps);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);
void StackTop(StackEntry *pe, Stack *ps);
int StackSize(Stack *ps);
void TraverseStack(Stack *ps, void(*pf)(StackEntry));
void ClearStack(Stack *ps);


