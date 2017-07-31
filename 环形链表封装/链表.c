#include"circlelist.h"

pnode addback(pnode phead, int data)
{
	pnode pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pnext = NULL;
	if (phead == NULL)
	{
		phead = pnew;
		pnew->pnext = phead;
	}
	else
	{
		pnode p = phead;
		while(p->pnext!=phead)
		{
			p = p->pnext;
		}
		p->pnext = pnew;
		pnew->pnext = phead;
		
	}
	return phead;
}

pnode addfront(pnode phead, int data) 
{
	pnode pnew = malloc(sizeof(node));
	pnew->pnext = NULL;
	pnew->data = data;
	if (phead == NULL)
	{
		phead = pnew;
		pnew->pnext = phead;
	}
	else
	{
		pnode p = phead;
		while (p->pnext != phead)
		{
			p = p->pnext;

		}
		pnew->pnext = phead;
		p->pnext = pnew;
		phead = pnew;
	}
	return phead;
}

void showall(pnode phead)
{
	if (phead == NULL)
		return;
	else if (phead->pnext == phead)
	{
		printf("%d,%p,%p\n", phead->data, phead, phead->pnext);
	}
	else
	{
		pnode p = phead;
		while (p->pnext != phead)
		{
			printf("%d,%p,%p\n", p->data, p, p->pnext);
			p = p->pnext;
		}
		printf("%d,%p,%p\n", p->data, p, p->pnext);
	}
}

pnode findfirst(pnode phead, int data)
{
	if (phead == NULL)
		return NULL;
	else if (phead->pnext == phead)
	{
		if (phead->data == data)
			return phead;
		else
			return	NULL;
	}
	else
	{
		pnode p = phead;
		while (p->pnext != phead)
		{
			if (p->data == data)
				return p;
			p = p->pnext;

		}
		if (p->data == data)
		{
			return p;
		}
		
	}
	return NULL;
}

pnode deletefirst(pnode phead, int data)
{
	pnode p1 = NULL;
	pnode p2 = NULL;
	p1 = phead;
	while (p1->pnext != phead)
	{
		if (p1->data == data)
		{
			break;
		}
		else
		{
			p2 = p1;
			p1 = p1->pnext;
		}
	}
	if (p1 == phead)
	{
		pnode p = phead;
		while (p->pnext != phead)
		{
			p = p->pnext;
		}
		p->pnext = p1->pnext;
		free(p1);
		phead = p1->pnext;//phead =phead->pnext;
						  //free(p1)
						  //p->pnext=phead;
	}
	else
	{
		p2->pnext = p1->pnext;
		free(p1);
	}
	return phead;
}


	int getnum(pnode phead)
	{
		if (phead == NULL)
			return 0;
		else if (phead->pnext == phead)//==
		{
			return 1;
		}
		else
		{
			pnode p = phead;
			int i = 1;//*
			while (p->pnext != phead)
			{
				i++;
				p = p->pnext;
			}
			return i;
		}
	}

	pnode insert(pnode phead, int data,int finddata)
	{
		pnode p1 = NULL;
		pnode p2 = NULL;
		p1 = phead;
		while (p1->pnext != phead)
		{
			if (p1->data == finddata)
			{
				break;
			}
			else
			{
				p2 = p1;
				p1 = p1->pnext;
			}
		}
		pnode pnew = malloc(sizeof(node));
		pnew->data = data;
		pnew->pnext = NULL;
		if (p1 != phead)
		{
			pnew->pnext = p1;
			p2->pnext = pnew;
		}
		else
		{
			pnode p=phead;
			while (p->pnext != phead)
			{
				p = p->pnext;
			}
			p->pnext = pnew;
			 pnew->pnext=phead;
			
		}
		return phead;
	}

		

