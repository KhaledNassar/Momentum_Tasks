#include <stdlib.h>
#include "list_interface.h"

void List_Init(List *pl){
    pl -> head = NULL;
    pl -> Size = 0;
}

int List_Empty(List *pl){
    return (!pl -> Size);
}

int List_Full(List *pl){
    return 0;
}

int List_Size(List *pl){
    return pl -> Size;
}

void List_Destroy(List *pl){
    ListNode *q;
    while(pl -> head){
        q = pl -> head -> next;
        free(pl -> head);
        pl -> head = q;
    }
    pl -> Size = 0;
}

void List_Traverse(List *pl, void(*visit)(ListEntry)){
    ListNode *p = pl -> head;
    if(p == NULL){
        printf("There is no elements!!");
    }
    else{
            while(p){
        (*visit)(p -> entry);
        p = p -> next;
        }
    }
}

int List_Insert_Node(int position, ListEntry e, List *pl){
    ListNode *p, *q;
    int i;
    if(p = (ListNode *)malloc(sizeof(ListNode))){
        p -> entry = e;
        p -> next = NULL;

        if(position == 0){
            p -> next = pl -> head;
            pl -> head = p;
        }

        else{
            for(q = pl -> head, i = 0; i < (position - 1); i++){
                q = q -> next;
            }
            p -> next = q -> next;
            q -> next = p;
        }

        pl -> Size++;
        return 1;
    }
    else return 0;

}

void List_Delete_Node(int position, ListEntry *pe, List *pl){
    int i;
    ListNode *q, *temp;
    if(position == 0){
        *pe = pl -> head -> entry;
        temp = pl -> head -> next;
        free(pl -> head);
        pl -> head = temp;
    }
    else{
        for(q = pl -> head, i = 0; i < (position - 1); i++){
            q = q -> next;
        }
        *pe = q -> next -> entry;
        temp = q -> next -> next;
        free(q -> next);
        q -> next = temp;
        }
        pl -> Size--;
}

void List_Retrieve(int p, ListEntry *pe, List *pl){
    int i;
    ListNode *q;
    for(q = pl -> head, i = 0; i < p; i++){
        q = q -> next;
        *pe = q -> entry;
    }
}

void List_Replace(int p, ListEntry e, List *pl){
    int i;
    ListNode *q;
    for(q = pl -> head, i = 0; i < p; i++){
        q = q -> next;
        q -> entry = e;
    }
}
