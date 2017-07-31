#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct string
{
	char *p;
	int reallength;
};
typedef struct string mystring;

void init(mystring *string);//初始化
void initwithlength(mystring *string, int length);//初始化规定长度
void initwithstring(mystring *string, char *copystr);//初始化规定字符串
void prinfstr(mystring *string);//打印字符串
int mystrlen(char *str);//求字符串长度
char *mystrcpy(char *dest, const char *source);//字符串copy
char *mystrcat(char*dest, const char*source);//字符串拼接
char *mystrchr(const char *str, char ch);//查找字符串中第一次出现的字符
char *mystrstr(const char const *str1, const char const  *str2);//判断字符串str2是否是str1的子串
char *findfirststr(mystring *string, char *str);//寻找第一次出现的字符串
void addback(mystring *string, char *ch);//尾插
int deletechar(mystring *string, char ch);//删除字符串中字符
int deletestr(mystring *string, char *str);//删除字符串中字符串
int changechar(mystring *string, const char c, const char ch);//改变字符串中字符
int changestr(mystring *string, const char *s, const char *str);//改变字符串中字符串
void addchar(mystring *string, char ch, char *pos);//字符串中增加字符
void addchar(mystring *string, char ch, char *pos);//字符串中增加字符
void  addstr(mystring *string, char *str, char *pos);//字符串中增加字符串