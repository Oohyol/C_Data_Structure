#include<stdio.h>
#include<stdlib.h>

int myatoi(char *str)//整数转字符串
{
	char*istr = str;
	while (*istr != '\0')
	{
		if (*istr<'0' || *istr>'9')
		{
			return NULL;
		}
			istr++;
		
	}
	int lastnum = 0;
	for (int i = 0;i < strlen(str);i++)
	{
		printf("%d\n", i);
		lastnum *= 10;
		lastnum += str[i] - '0';
	}
	return lastnum;
}

char *myitoa(int num, char *str)//整数转字符串
{
	int wei = 0;
	for (int inum=num;inum;inum /=10)
	{
		wei++;
	}
	for (int i = wei - 1;num;num/=10, i--)
	{
		str[i] = num % 10 + '0';
	}
	str[wei] = '\0';
	return str;
}

void main()
{
	int num = 12314342;
	char str[20] = { 0 };

	printf("%s", myitoa(num,str));
	getchar();
}