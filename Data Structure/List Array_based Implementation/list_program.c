#include "list_interface.h"

void List_Init(List *pl){
    pl -> Size = 0;
}

int List_Empty(List *pl){
    return (!pl -> Size);
}

int List_Full(List *pl){
    return (pl -> Size == MAXLIST);
}

int List_Size(List *pl){
    return pl -> Size;
}

void List_Destroy(List *pl){
    pl -> Size = 0;
}

void List_Traverse(List *pl, void(*visit)(ListEntry)){
    int i;
    if(pl -> Size == 0){
        printf("There is no elements!!");
    }
    else{
        for(i = 0; i < pl -> Size; i++){
        (*visit)(pl -> entry[i]);
        }
    }
}

int List_Insert_Node(int position, ListEntry e, List *pl){
    int i;
    for(i = pl -> Size-1; i >= position; i--){
        pl -> entry[i+1] = pl -> entry[i];
    }
    pl -> entry[position] = e;
    pl -> Size++;
}

void List_Delete_Node(int position, ListEntry *pe, List *pl){
    *pe = pl -> entry[position];
    for(int i = position+1; i <= pl -> Size-1; i++){
        pl -> entry[i-1] = pl -> entry[i];
    }
    pl -> Size--;
}

void List_Retrieve(int p, ListEntry *pe, List *pl){
    *pe = pl -> entry[p];
}

void List_Replace(int p, ListEntry e, List *pl){
    pl -> entry[p] = e;
}
