#define StackEntry char
#define MAXSTACK 10


typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];
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
void InfixToPostfix(char Infix[], char Postfix[]);
void InfixToPrefix(char Infix[], char Prefix[]);

int IsOperand(char character);
int HigherPrecedence(char Operator1, char Operator2);
