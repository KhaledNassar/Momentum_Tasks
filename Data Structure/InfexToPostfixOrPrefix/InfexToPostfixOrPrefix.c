#include "InfexToPostfixOrPrefix.h"

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

void InfixToPostfix(char Infix[], char Postfix[]){
    int i, j;
    char Operator, character;
    Stack s;
    CreateStack(&s);
    for(i=0, j=0; (character = Infix[i]) != '\0' ; i++){
        if(IsOperand(character)){
            Postfix[j++] = character;
        }
        else{
            if(!StackEmpty(&s)){
                StackTop(&Operator, &s);
                if(character == '('){
                        push(character, &s);
                   }

                else if(character == ')'){
                    while(Operator != '('){
                            Pop(&Operator, &s);
                            Postfix[j++] = Operator;
                            StackTop(&Operator, &s);
                          }
                          Pop(&Operator, &s);
                }

                else{
                    while(!StackEmpty(&s) && HigherPrecedence(Operator, character)){
                        Pop(&Operator, &s);
                        Postfix[j++] = Operator;
                        if(!StackEmpty(&s))
                            StackTop(&Operator, &s);
                    }
                    push(character, &s);
                }

            }
            else push(character, &s);

        }

    }
    //All Condition are Checked
        while(!StackEmpty(&s)){
            Pop(&Operator, &s);
            Postfix[j++] = Operator;
        }
    //End of Postfix
    Postfix[j] = '\0';

}



void InfixToPrefix(char Infix[], char Prefix[]){

   Stack s;
    CreateStack(&s);
    int i, j = 0;
    char Operator, character;

    reverseString(Infix);

    for (i = 0; Infix[i] != '\0'; i++) {
        if (Infix[i] == '(')
            Infix[i] = ')';
        else if (Infix[i] == ')')
            Infix[i] = '(';
    }

    for (i = 0; Infix[i] != '\0'; i++) {
        character = Infix[i];
        if (IsOperand(character)) {
            Prefix[j++] = character;
        } else if (character == '(') {
            push(character, &s);
        } else if (character == ')') {
            StackTop(&Operator, &s);
            while ((!StackEmpty(&s)) && (Operator != '(')) {
                Pop(&Operator, &s);
                Prefix[j++] = Operator;
                StackTop(&Operator, &s);
            }
            Pop(&Operator, &s); // Pop '('
        } else {
            StackTop(&Operator, &s);
            while (!StackEmpty(&s) && HigherPrecedence(Operator, character)) {
                Pop(&Operator, &s);
                Prefix[j++] = Operator;
                if (!StackEmpty(&s))
                    StackTop(&Operator, &s);
            }
            push(character, &s);
        }
    }

    while (!StackEmpty(&s)) {
        Pop(&Operator, &s);
        Prefix[j++] = Operator;
    }

    Prefix[j] = '\0';

    reverseString(Prefix);

}



int IsOperand(char character){
    return(character >= '0' && character <= '9');
}


int HigherPrecedence(char Operator1, char Operator2){
    //() > ^ > *,/ > +,-
    switch(Operator1){
        case'(': return 0;
        case'^': return 1; break;
        case'*':
        case'/': return((Operator2 != '^')); break;
        case'+':
        case'-': return((Operator2 != '^') && (Operator2 != '*') && (Operator2 != '/')); break;
    }
}


void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

