//1 3 5 7 9
//2 4 6 8 10
#include <stdio.h>
#include <stdlib.h>

void main()
{
	while (p2 != NULL || p1 != NULL)
	{
		if (p1 != NULL&&p2 != NULL)
		{
			if (p1->data > p2->data)
			{
				phead = addback(phead, p2->data);
			}
			else
			{
				phead = addback(phead, p1->data);
			}
		}
		else
		{
			while (p1 != NULL)
			{
				phead = addback(phead, p1->data);
				p1 = p1->pnext;
			}
			while (p2 != NULL)
			{
				phead = addback(phead, p2->data);
				p2 = p2->pnext;
			}
			break;//不加会死循环
		}

	}
}