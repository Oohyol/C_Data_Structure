#include"link.h"
void main()
{
	node* p=NULL;
	/*init(p);*/
	
	p=addback(p, 14);
	p=addback(p, 12);
	p=addback(p, 13);
	addhead(&p, 9);
	addhead(&p, 10);
	addhead(&p, 11);
	quicksort(p, NULL);
	p=revit(p);
	showall(p);
	getchar();
}