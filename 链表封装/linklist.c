#include "link.h"


void init(node*phead)
{
	phead->data = 0;
	phead->pnext = NULL;
}

node *addback(node*phead, int data)
{
	node* pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pnext = NULL;
	if (phead == NULL)
	{
		phead = pnew;
	}
	else
	{
		node*ptemp = phead;
		while (ptemp->pnext !=NULL)
		{
			ptemp = ptemp->pnext;
		}
		ptemp->pnext = pnew;
	}
	return phead;

void showall(node*phead)
{
	if (phead == NULL)
		return;
	else
	{

		
		while (phead!=NULL)
		{
			printf("%d,%p,%p\n",phead->data, phead, phead->pnext);
			phead = phead->pnext;

		}
	}
}

void showall2(node*phead)
{
	if(phead == NULL)
	{
		return;
	}
	else
	{
		
		showall2(phead->pnext);
		printf("%d,%p,%p\n", phead->data, phead, phead->pnext);
	}
}

void addhead(node**pphead, int data)
{
	node *pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pnext = NULL;
	if (*pphead == NULL)
	{
		*pphead = pnew;

	}
	else
	{
		pnew->pnext = *pphead;
		*pphead = pnew;
	}
}

node *search(node*phead, int finddata, int newdata)
{
	for (node *p = phead;p->pnext != NULL;p = p->pnext)
	{
		if (p->data == finddata)
		{
			p->data = newdata;
			return p;
		}
	}
	return NULL;
}

node *searchfirst(node*phead, int finddata)
{
	if (phead == NULL)
	{
		return NULL;

	}
	else
	{
		while (phead->pnext != NULL)
		{
			if (phead->data == finddata)
				return phead;


		}
	}
	return NULL;
}

node *deletefirst(node*phead, int finddata)
{
	node *p1 = NULL;
	node*p2 = NULL;
	p1 = phead;
	while (p1 != NULL)
	{
		if (p1->data != finddata)
		{
			p2 = p1;
			p1 = p1->pnext;
		}
		else
		{
			break;
		}
	}
	if (p1!= phead)
	{
		p2->pnext = p1->pnext;
		free(p1);
	}
	else
	{
		phead = phead->pnext;
		free(p1);
	}
	return phead;
}


node *insertfirst(node*phead, int finddata, int data)
{
	node *p1 = NULL;
	node *p2 = NULL;
	p1 = phead;
	while (p1 != NULL)
	{
		if (p1->data != finddata)
		{
			p2 = p1;
			p1 = p1->pnext;
		}
		else
			break;
	}
	node *pnew = malloc(sizeof(node));
	pnew->data = finddata;
	pnew->pnext = NULL;
	if (phead == p1)
	{
		pnew->pnext = phead;
		phead = pnew;
	}
	else
	{
		pnew->pnext = p1;
		p2->pnext = pnew; 
	}
	return phead;
}  

void bubblesort(node*phead)
{
	for(node*p1=phead;p1!=NULL;p1=p1->pnext )
		for (node*p2 = phead;p2 != NULL;p2 = p2->pnext)
		{
			if (p1->data > p2->data)
			{
				int temp;
				temp = p2->data;
				p2->data = p1->data;
				p1->data = temp;
			}
		}
}

//void quicksort(int left, int right)
//{
//	if (left<right)
//	{
//		return ERROR;
//	}
//	int temp = a[left];
//	int i = left;
//	int j = right;
//	while (i != j)
//	{
//		while (a[j] >= temp&&i < j)
//			j--;
//		while (a[i] <= temp&&i < j)
//			i++;
//		if (i < j)
//		{
//			int t = a[j];
//			a[j] = a[i];
//			a[i] = t;
//
//		}
//	}
//	a[left] = a[i];
//	a[i] = temp;
//
//	quicksort(left - 1, i - 1);
//	quicksort(i + 1, right);
//
//
//
//}
void quicksort(node*pbegin, node*pback)

{
	if (pbegin != pback)
	{
		node*p = fen(pbegin, pback);
		quicksort(pbegin, p);
		quicksort(p->pnext, pback);//p->pnext
	}
	return;
}

node *fen(node *pbegin, node *pback)
{
	int key = pbegin->data;
	node *p = pbegin;
	node *q = pbegin->pnext;
	while (q != pback)
	{
		if (q->data < key)
		{
			p = p->pnext;
			int temp = p->data;
			p->data = q->data;
			q->data = temp;
		}
		q = q->pnext;
	}
	int temp = p->data;
	p->data = pbegin->data;
	pbegin->data = temp;
	return p;
}

//if (a[i] < a[j])
//{
//	++i;
//	swap(a[i], a[j])
//}
//j++;

int getnum(node*phead)
{
	int i = 0;
	for (;phead != NULL;phead = phead->pnext)
	{
		i++;
		return i;
	}
}

int getnum1(node*phead)
{
	if (phead == NULL)
		return 0;
	else
	{
		return 1 + getnum1(phead->pnext);
	}

}

node* revit(node*phead)
{
	if (phead == NULL || phead->pnext == NULL)
	{
		return;
	}
	else
	{
		node*pre = NULL;
		node*pcur = NULL;
		node*pnext = NULL;
		pre = phead;
		pcur = phead->pnext;
		while (pcur)
		{
			pnext = pcur->pnext;
			pcur->pnext = pre;
			pre = pcur;
			
			pcur = pnext;
			
		}
		phead->pnext = NULL;
		phead = pre;
		
	    
	}
	return phead;
}

node *revitgui(node *phead)
{
	if (phead == NULL || phead->pnext == NULL)
	{
		return phead;
	}
	else
	{

		node* next = phead->pnext;
		node*head = revitgui(next);
		next->pnext = phead;
		phead->pnext = NULL;
		return head;

	}

}