//判断字符串是否对称
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

int isit(char*p)
{
	int flag = 1;
	char *p1 = p;
	char *p2 = p + strlen(p) - 1;
	while (p2 > p1)
	{
		if (*p1 != *p2)
		{
			flag = 0;
			break;
		}
		p1++;
		p2--;
	}
	return flag;

}

void main()
{
	char str[1024] = "";
	scanf("%s", str);
	
	printf("%d", isit(str));
	system("pause");
}