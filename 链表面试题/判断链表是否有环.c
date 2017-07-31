int isir(node *phead)
{
	int flag = 0;
	for (node*p1 = phead, *p2 = phead;p1 != NULL&&p2 != NULL;p1 = p1->pnext, p2 = p2->pnext)
	{                              //死循环
		if (p2->pnext != NULL)
		{
			p2 = p2->pnext;
		}
		if (p1 == p2)
			flag = 1;
		break;
	}
	return flag;
}