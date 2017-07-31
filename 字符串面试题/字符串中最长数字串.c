//寻找字符串中最长数字串
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char *str = "ssdad12345sdsads12345678sds9807897";
	char *p = NULL;
	char *p2 = NULL;
	int max = 0;
	while (*str != '\0')
	{
		while (*str<'0' || *str>'9')
		{
			str++;
		}
		p = str;
		while (*str >='0'&&*str <='9')
		{
			str++;
		}
		if (str - p > max)
		{
			max = str - p;
			p2 = p;
		}
		
		
	}
	for (int i = 0;i < max;i++)
	{
		putchar(p2[i]);
	}
	printf("\n%d", max);
	getchar();
}