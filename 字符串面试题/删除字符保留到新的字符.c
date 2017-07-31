//删除字符串的字符保留原来字符串，删除以后的字符串存到新的字符串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char str[30] = "hello yincheng";
	char ch = 'c';
	char*p = str;
	char laststr[30] = { 0 };
	int i = 0;
	while (*p != '\0')
	{
		if (*p != ch)
		{
			laststr[i] = *p;
			i++;
		}
		p++;
	}
	printf("%s", laststr);
	getchar();
}