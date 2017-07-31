#include "字符串.h"
void init(mystring *string)//初始化
{
	string->p = NULL;
	string->reallength = 0;
}



void initwithlength(mystring *string, int length)//初始化规定长度
{
	string->p = (char *)calloc(length, sizeof(char));
	string->reallength = length;
}



void initwithstring(mystring *string, char *copystr)//初始化规定字符串
{
	int length = strlen(copystr);
	string->p = (char *)calloc(length+1, sizeof(char));//length+1 '\0'
	string->p = copystr;
	int reallength = length+1;
}



void prinfstr(mystring *string)//打印字符串
{
	printf("\nstring=%s", string->p);
}



int mystrlen(char *str)//求字符串长度
{
	int length;
	if (str == NULL)
	{
		return NULL;
	}
	else
	{
		
		while (*str->p != '\0')
		{
			str->p++;
			length++;
		}
	}
	return length;
}



char *mystrcpy(char *dest,const char *source)//字符串copy
{
	char *destbak = dest;//保存返回地址;
	if (dest == NULL || source == NULL)
	{
		return NULL;
	}
	else
	{
		while (*source != '\0')
		{
			*dest = *source;
			dest++;
			source++;
		}
		*dest = '\0';
	}
	return destbak;
}



char *mystrcat(char*dest, const char*source)//字符串拼接
{
	char *destbak = dest;//保存字符串返回地址
	if (*dest == NULL || *source == NULL)
	{
		return NULL;
	}
	else
	{
		while (*dest != '\0')
		{
			dest++;
		}
		while (*source != '\0')
		{
			*dest = *source;
			source++;
			dest++;
		}
		*dest = '\0';
	}
	return destbak;
}



char *mystrchr(const char *str, char ch)//查找字符串中第一次出现的字符
{
	if (str == NULL)
	{
		return NULL;
	}
		while (*str != '\0')
		{
			if (*str == ch)
			{
				return str;
			}
			str++;
		}
		return NULL;
}



char *mystrstr(const char const *str1, const char const  *str2)//判断字符串str2是否是str1的子串
{
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char *strbak = str1;
	char*p = NULL;
	while (*str1 != NULL)
	{
		int flag = 1;
		char *findstr = str2;
		char *nowstr = str1;
		while (*str2 != NULL)
		{
			if (*nowstr != NULL)
			{
				if (*findstr != *nowstr)
				{
					flag = 0;	
				}
				findstr++;
				nowstr++;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			p = str1;
			return p;
		}
		str1++;
	}
	return NULL;
}



void addback(mystring *string, char *ch)//尾插
{
	int nowlength = mystrlen(string->p);
	int addlength = mystrlen(ch);
	if (nowlength + 1 + addlength < string->reallength)
	{
		int needlength = nowlength + 1 + addlength - string->reallength;
		string->p = (char *)realloc(string->p, string->reallength + needlength);//realloc
		mystrcat(string->p, ch);
		string->reallength += needlength;
	}
	else
	{
		mystrcat(string->p, ch);
	}
}



char *findfirststr(mystring *string, char *str)//寻找第一次出现的字符串
{
	char *p = mystrstr(string->p, str);
	return p;
}



int deletechar(mystring *string, char ch)//删除字符串中字符
{
	char *p = mystrchr(string->p, ch);
	if (p == NULL)
	{
		return NULL;
	}
	char *pnext = p + 1;//双指针：1.删除 2.快排
	while (pnext != '\0')
	{
		*p = *pnext;
		pnext++;
		p++;
	}
	*p = '\0';
	return 1;
}



int deletestr(mystring *string, char *str)//删除字符串中字符串
{
	char *p = mystrstr(string->p, str);
	if (p == NULL)
	{
		return NULL;
	}
	int dellength = mystrlen(str);
	char *pnext = p + dellength;
	while (*pnext != '\0')
	{
		*p = *pnext;
		pnext++;
		p++;
	}
	*p = '\0';
	return 1;

}



int changechar(mystring *string, const char c, const char ch)//改变字符串中字符
{
	if (string->p == NULL)
	{
		return NULL;
	}
	while (*string->p != '/0')
	{
		if (*string->p == c)
		{
			*string->p = ch;
			return 1;
		}
	}
	return NULL;
}



void changestr(mystring *string, const char *s, const char *str)//改变字符串中字符串
{
	char *p = mystrstr(string->p, s);
	if（p != NULL)
	{
	deletestr（string, s);
	addstr(string, str, s);
	}
}



void addchar(mystring *string, char ch, char *pos)//字符串中增加字符
{
	if (pos == NULL || string == NULL)
	{
		return;
	}
	if (mystrlen(string->p) + 1 == string->reallength)
	{
		string->p = (char*)realloc(string->p, string->reallength + 1);
		string->reallength += 1;
		int nowlength = mystrlen(string->p);
		int movelength = mystrlen(pos);
		for (int i = nowlength;i > nowlength - movelength;i--)
		{
			string->p[i] = string->p[i - 1];//字符数组下标法  没有处理'\0'
		}
		string->p[nowlength - movelength] = ch;
		string->p[nowlength + 1] = '\0';
	}
	else
	{
		int nowlength = mystrlen(string->p);
		int movelength = mystrlen(pos);
		for (int i = nowlength;i > nowlength - movelength;i--)
		{
			string->p[i] = string->p[i - 1];//字符数组下标法
		}
		string->p[nowlength - movelength] = ch;
		string->p[nowlength + 1] = '\0';
	}
}



void  addstr(mystring *string, char *str, char *pos)//字符串中增加字符串
{
	if (pos == NULL || string == NULL)
	{
		return NULL;
	}
	int addlength = mystrlen(string->p) + addlength + 1 - string->reallength;
	if (mystrlen(string->p) + addlength + 1 > string->reallength)
	{

		string->p = (char *)realloc(string->p, string->reallength + addlength);
		int movelength = mystrlen(pos);
		int nowlength = mystrlen(string->p);
		int insert = mystrlen(str);
		for (int i = nowlength;i >= nowlength - movrlength;i--)
		{
			string->p[i + insert] = string->p[i];//已经处理'\0'
		}
		for (int j = 0;j < insert;j++)
		{
			string->p[nowlength - movelength + j] = str[j];
		}
	}
	else
	{
		int movelength = mystrlen(pos);
		int nowlength = mystrlen(string->p);
		int insert = mystrlen(str);
		for (int i = nowlength;i >= nowlength - movrlength;i--)
		{
			string->p[i + insert] = string->p[i];
		}
		while (*str != '\0')//指针法
		{
			*pos = *str;
			pos++;
			str++;

		}

		
	}
}