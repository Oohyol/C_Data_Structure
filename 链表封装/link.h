
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
struct linknode
{
	int data;
	struct linknode *pnext;
};
typedef struct linknode node;

void init(node*phead);
node *addback(node*phead, int data);
void showall(node*phead);
void showall2(node*phead);
void addhead(node**pphead, int data);
node *search(node*phead, int finddata, int newdata);
node *searchfirst(node*phead, int finddata);
node *insertfirst(node*phead, int finddata, int data);
node *deletefirst(node*phead, int finddata);
void bubblesort(node*phead);
void quicksort(node*pbegin, node*pback);
node *fen(node *begin, node *pback);
int getnum(node*phead);
int getnum1(node*phead);
node* revit(node*phead);
node* revitgui(node*phead);