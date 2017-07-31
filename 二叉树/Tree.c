#include<stdio.h>
#include<stdlib.h>

typedef struct BiTnode
{
	char data;
	struct BiTnode *lchild, *rchild;
}bitnode ,*bitree;

void CreateBitree(bitree T)//二叉树的建立
{
	char ch;
	scanf("%s", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (bitree)malloc(sizeof(bitnode));
		
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);


	}
}

//遍历二叉树
void Preordertraverse(bitree T)//前序遍历
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	Preordertraverse(T->lchild);
	Preordertraverse(T->rchild);
}

void InorderTraverse(bitree T)//中序遍历
{
	if (T == NULL)
		return;
	InorderTraverse(T->lchild);
	printf("%c", T->data);
	InorderTraverse(T->rchild);
}

void Postordertraverse(bitree T)//后序遍历
{
	if (T ==NULL)
		return;
	Postordertraverse(T->lchild);
	Postordertraverse(T->rchild);
	printf("%c", T->data);
}

int treedeep(bitree T)//二叉树深度
{
	int deep = 0;
	if (T != NULL)
	{
		int leftdeep = treedeep(T->lchild);

		int rightdeep = treedeep(T->rchild);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;

	}
	return deep;
}

int leafcount(bitree T)//叶子节点个数
{
	int count;
	if (T != NULL)
	{
		if (T->lchild == NULL&&T->rchild == NULL)
		{
			count++;
		}
		leafcount(T->lchild);
		leafcount(T->rchild);
	}
	return count;
}