#include <stdio.h>
#include <stdlib.h>
#include "InfexToPostfixOrPrefix.h"

int main()
{
    char Infix[10];
    char Postfix[10];
    char Prefix[10];
    unsigned char Choice;

    printf("Enter Your Process: ");
    scanf("%s", Infix);
    printf("Choose The preferred Method, 1-Prefix \t 2-Postfix\n");
    scanf("%s", &Choice);

    printf("\n");

    switch(Choice){
    case '1':
        InfixToPrefix(Infix, Prefix);
        printf("The Prefix of your process is: ");

        for(int i=0; Prefix[i]!='\0'; i++){
            printf("%c", Prefix[i]);
        }
        printf("\n");
        break;

    case '2':
        InfixToPostfix(Infix, Postfix);
        printf("The Postfix of your process is: %s \n", Postfix);
        printf("\n");
        break;

    default:
        printf("Invalid Choice, Please Try again!!\n");
    }

    return 0;
}
