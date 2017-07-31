#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct linknode
{
	int data;
	struct linknode*pnext;
}node,*pnode;

pnode addback(pnode phead, int data);
pnode addfront(pnode phead, int data);
void showall(pnode phead);
pnode findfirst(pnode phead, int data);
int getnum(pnode phead);
pnode insert(pnode p, int data,int finddata);