#include <stdio.h>
#include<stdlib.h>

node *etmid(node *phead)
{
	if (phead == NULL || phead->pnext == NULL)
		return phead;
	else
	{
		node *p1 = phead, *p2 = phead;
		while (p2->pnext != NULL)
		{
			p1 = p->pnext;//前进一步
			p2 = p->pnext;//前进两步
			if (p2->pnext != NULL)
			{
				p2 = p2->pnext;
			}
		}
		
	}
	return p1;
}