#include <stdio.h>
#include <stdlib.h>
#include "list_interface.h"

void Display(ListEntry e);

int main()
{
    int isFull, isEmpty, size;
    ListEntry element;

    List my_list;
    List_Init(&my_list);

    isEmpty = List_Empty(&my_list);
    if(isEmpty == 0){
        printf("The List is not Empty\n");
    }
    else{
        printf("The List is Empty!!\n");
    }

    size = List_Size(&my_list);
    printf("The Size of the List is: %d\n", size);

    List_Insert_Node(0, 5, &my_list);
    List_Insert_Node(1, 6, &my_list);
    List_Insert_Node(2, 7, &my_list);
    List_Insert_Node(3, 8, &my_list);
    printf("The List elements are: ");
    List_Traverse(&my_list, &Display);
    printf("\n");

    List_Replace(2, 1, &my_list);
    printf("The List elements are: ");
    List_Traverse(&my_list, &Display);
    printf("\n");

    List_Delete_Node(3, &element, &my_list);
    printf("The deleted element is: %d\n", element);
    printf("The List elements are: ");
    List_Traverse(&my_list, &Display);
    printf("\n");

    isFull = List_Full(&my_list);
    if(isFull == 0){
        printf("The List is not Full\n");
    }
    else{
        printf("The List is Full!!\n");
    }

    List_Retrieve(2, &element, &my_list);
    printf("The element in this position is: %d\n", element);
    printf("The List elements are: ");
    List_Traverse(&my_list, &Display);
    printf("\n");

    List_Destroy(&my_list);
    printf("The List elements are: ");
    List_Traverse(&my_list, &Display);
    printf("\n");
    isEmpty = List_Empty(&my_list);
    if(isEmpty == 0){
        printf("The List is not Empty\n");
    }
    else{
        printf("The List is Empty!!\n");
    }

    return 0;
}

void Display(ListEntry e){
    printf("%d \t", e);
}
