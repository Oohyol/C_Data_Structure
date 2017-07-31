#include "circlelist.h"

void main()
{
	pnode p = NULL;
	p=addback(p, 11);
	p=addback(p, 13);
	p=addback(p, 12);
	p=addfront(p, 14);
	p=addfront(p, 15);
	
	showall(p);
  p=insert( p, 9,15);

  printf("\n");
  showall(p);
  getchar();
}