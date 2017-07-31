void showall(phead)
{
	for (node*p = phead;p->pnext != phead;p = p->pnext)
	{
		printf("%d", p->data);
	}
	printf("%d", p->data);
}