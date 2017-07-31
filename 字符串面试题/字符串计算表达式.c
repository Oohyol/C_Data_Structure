//char*str="1+2*(3+(1*2+4*(1+3)-3+2*(1+2)"
//char *str="1+2+3+4+5+6+7"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

void eatspace(char *str)//ָ�뷨
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



void eatspac(char *str)//�±귨
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



double  getnum(char*str, int*pindex)// pindex ��ĳ��λ�ü���
{
	double value = 0.0;
	int index = *pindex;

	while (isnum(*(str + index)))//str[index]
	{
		value = value * 10 + (str[index] - '0');//�ַ�ת����
		index++;
	}
	if (*(str + index) == '.')
	{
		double xiaoshu = 1.0;
		while (isnum(*(str + ++index)))//ѭ����С�������ķ�����
		{
			xiaoshu /= 10;
			value += xiaoshu*(*(str + index) - '0');
		}
	}
	*pindex = index;//�ı�һ���ⲿ������Ҫһ����ַ
	return value;
}



double topfenxi(char *str, int *pindex)
{
	double value = 0.0;

	value = getnum(str, pindex);//��ȡһ������
	while (1)
	{
		if (*(str + (*pindex)) == '*')
		{
			(*pindex)++;//�ƶ��±�
			value *= getnum(str, pindex);//����˷�
		}
		else if (*(str + (*pindex)) == '/')
		{
			(*pindex)++;//�ƶ��±�
			value /= getnum(str, pindex);//�������
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
	value = topfenxi(str, &index);//��ȡ��һ������
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
			 value += topfenxi(str, &index);//����return   ��Ҫ����break
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
	printf("\n��һ�����ֵ�����%f", value);

	double Oo = fenxi(str);
	printf("\n���%f", Oo);

	system("pause");
}