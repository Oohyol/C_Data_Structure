//char*str="1+2*(3+(1*2+4*(1+3)-3+2*(1+2)"
//char *str="1+2+3+4+5+6+7"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

void eatspace(char *str)//指针法
{
	char *p1 = str;
	char *p2 = str;
	while ((*p1 = *(p2++)) != '\0')
	{
		if (*p1 != ' ')
		{
			p1++;
		}
	}

	/*while (*p1 != '\0')
	{
	*p1 = *p2;
	if (*p1 != ' ')
	p1++;
	p2++;
	}*/
}



void eatspac(char *str)//下标法
{
	int i = 0, j = 0;
	while (str[i] != '\0')
	{
		str[i] = str[j];
		if (str[i] != ' ')
		{
			i++;
		}
		j++;
	}
}



int isnum(char ch)
{
	int is = 0;
	if (ch >= '0'&&ch <= '9')
	{
		is = 1;
	}
	return is;
}



double  getnum(char*str, int*pindex)// pindex 从某个位置检索
{
	double value = 0.0;
	int index = *pindex;

	while (isnum(*(str + index)))//str[index]
	{
		value = value * 10 + (str[index] - '0');//字符转整数
		index++;
	}
	if (*(str + index) == '.')
	{
		double xiaoshu = 1.0;
		while (isnum(*(str + ++index)))//循环到小数点后面的非数字
		{
			xiaoshu /= 10;
			value += xiaoshu*(*(str + index) - '0');
		}
	}
	*pindex = index;//改变一个外部变量需要一个地址
	return value;
}



double topfenxi(char *str, int *pindex)
{
	double value = 0.0;

	value = getnum(str, pindex);//获取一个数据
	while (1)
	{
		if (*(str + (*pindex)) == '*')
		{
			(*pindex)++;//移动下标
			value *= getnum(str, pindex);//计算乘法
		}
		else if (*(str + (*pindex)) == '/')
		{
			(*pindex)++;//移动下标
			value /= getnum(str, pindex);//计算除法
		}
		else
		{
			break;
		}
	}
	return value;
}



double fenxi(char *str)
{
	double value = 0.0;
	int index = 0;
	value = topfenxi(str, &index);//获取第一个数据
	while (1)
	{
		char ch = *(str + index);

		index++;

		switch (ch)
		{
		case'\0':
			return value;
			break;
		case'+':
			 value += topfenxi(str, &index);//不能return   不要忘了break
			 break;
		case'-':
			value -= topfenxi(str, &index);
			break;
		}
	}
}






void main()
{
	char str[1024] = { 0 };
	scanf("%[^\n]", str);
	printf("%s\n", str);
	eatspace(str);
	printf("%s\n", str);
	int index = 0;
	double value = getnum(str, &index);
	printf("\n第一个出现的数据%f", value);

	double Oo = fenxi(str);
	printf("\n结果%f", Oo);

	system("pause");
}