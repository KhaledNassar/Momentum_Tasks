
#ifndef _LIST_INTERFACE_H
#define _LIST_INTERFACE_H

#define ListEntry int
#define MAXLIST 10

typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
}ListNode;

typedef struct list{
    ListNode *head;
    int Size;
}List;

void List_Init(List *pl);
int List_Empty(List *pl);
int List_Full(List *pl);
int List_Size(List *pl);
void List_Destroy(List *pl);
void List_Traverse(List *pl, void(*visit)(ListEntry));
int List_Insert_Node(int position, ListEntry e, List *pl);
void List_Delete_Node(int position, ListEntry *pe, List *pl);
void List_Retrieve(int p, ListEntry *pe, List *pl);
void List_Replace(int p, ListEntry e, List *pl);

#endif // _LIST_INTERFACE_H
