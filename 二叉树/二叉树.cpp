#include <iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

struct bintree
{
	int Nodedata=0;
	struct bintree *pleft=nullptr ;
	struct bintree *pright=nullptr ;
};


struct nosame
{
	struct bintree *pnode;
	bool issame;
};



void show(struct bintree* proot,int n)
{
	if (proot == nullptr)
	{
		return;
	}
	else
	{
		show(proot->pleft, n + 1);
		
		cout << proot->Nodedata << endl;
		show(proot->pright, n + 1);
	}
}



void shown(struct bintree* proot, int n)
{
	if (proot == nullptr)
	{
		return;
	}
	else                                //���������ͨ��n���Ʋ���
	{
		shown(proot->pleft, n + 1);
		for (int i = 0;i < n;i++)
		{
			cout << "  ";
		}
		cout << proot->Nodedata << endl;
		shown(proot->pright, n + 1);
	}
}



void zhong(struct bintree*proot)//�������(�ݹ飩
{
	if (proot == nullptr)
	{
		return ;
	}
	else
	{
		if (proot->pleft != nullptr)
		{
			zhong(proot->pleft);
		}
		cout << " " << proot->Nodedata << endl;
		if (proot->pright != nullptr)
		{
			zhong(proot->pright);
		}
	}

}



void zhongstack(struct bintree*proot)//����ǵݹ�
{
	if (proot == nullptr)
	{
		return;
	}
	else
	{
		struct bintree*pcurr = proot;
		stack<bintree*>mystack;
		while (!mystack.empty() || pcurr != nullptr)//��ֹ����
		{
			while (pcurr != nullptr)
			{
				mystack.push(pcurr);
				pcurr = pcurr->pleft;//��ڵ�ȫ����ջ
			}
			if (!mystack.empty())
			{
				pcurr = mystack.top();
				cout << " " << pcurr->Nodedata << endl;
				mystack.pop();
				pcurr = pcurr->pright;//��ջ
			}

		}
	}
}



void xian(struct bintree*proot)//�������(�ݹ飩
{
	if (proot == nullptr)
	{
		return;
	}
	else
	{
		cout << " " << proot->Nodedata << endl;
		if (proot->pleft != nullptr)
		{
			xian(proot->pleft);
		}
		
		if (proot->pright != nullptr)
		{
			xian(proot->pright);
		}
	}

}



void xianstack(struct bintree*proot)//����ǵݹ�
{
	if (proot == nullptr)
	{
		return;
	}
	else
	{
		struct bintree*pcurr = proot;
		stack<bintree*>mystack;
		while (!mystack.empty() || pcurr != nullptr)//��ֹ����
		{
			while (pcurr != nullptr)
			{
				mystack.push(pcurr);
				cout << " " << pcurr->Nodedata << endl;
				pcurr = pcurr->pleft;
			}
			if (!mystack.empty())
			{
				pcurr = mystack.top();
				mystack.pop();
				pcurr = pcurr->pright;
			}
			

		}
	}
}



void houstack(struct bintree *proot)//����ǵݹ�
{
	if (proot == nullptr)
		return;
	else
	{
		struct bintree *pcurr = proot;
		stack<nosame*> mystack;
		nosame *ptemp = new nosame;
		while (!mystack.empty() || pcurr != nullptr)
		{
			while (pcurr != nullptr)
			{
				nosame *ptr = new nosame;
				ptr->issame = true;
				ptr->pnode = pcurr;//�ڵ�����ظ�
				mystack.push(ptr);
				pcurr = pcurr->pleft;

			}
			if (!mystack.empty())
			{
				ptemp = mystack.top();
				mystack.pop();
				if (ptemp->issame == true)
				{
					ptemp->issame = false;
					mystack.push(ptemp);
					pcurr = ptemp->pnode->pright;
				}
				else
				{
					cout << ptemp->pnode->Nodedata << endl;
					pcurr == nullptr;
				}
			}

		}
	}
}



int getheight(struct bintree *proot)//�����������
{
	int height = 0;
	int left = 0;
	int right = 0;
	if (proot == nullptr)
	{
		return 0;
	}
	left = getheight(proot->pleft);
	right = getheight(proot->pright);
	height = left > right ? left : right;
	return height + 1;
}



int getall(struct bintree*proot)//��Ҷ�����
{
	if (proot == nullptr)
		return 0;
	else
	{
		int all = 0;
		int left = 0;
		int right = 0;
		if (proot->pleft == nullptr&&proot->pright == nullptr)
		{
			return 1;
		}
		left = getall(proot->pleft);
		right = getall(proot->pright);
		all = right + left;

	}
}



void ceng(struct bintree*proot)//�ǵݹ������
{
	if (proot == nullptr)
	{
		return;
	}
	//queue<bintree *>myq;
	bintree *myq[100] = { 0 };
	int head = 0;
	int back = 0;
	bintree *pcurr = nullptr;
	myq[back++] = proot;
	while (head != back)
	{
		pcurr = myq[head];
		head++;
		cout << pcurr->Nodedata << endl;
		if (pcurr->pleft != nullptr)
		{
			myq[back++] = pcurr->pleft;
		}
		if (pcurr->pright != nullptr)
		{
			myq[back++] = pcurr->pright;
		}
	}
}



int getakknode(bintree*proot)//��ڵ���
{
	if (proot == nullptr)
		return 0;
	else
	{
		return getakknode(proot->pleft) + getakknode(proot->pright) + 1;
	}
}



bool isall(struct bintree*proot)//�жϵ�֧������
{
	if (proot == nullptr)
	{
		return false;
	}
	bool isok;
	if ((proot->pleft == nullptr&&proot->pright == nullptr) || (proot->pleft != nullptr&&proot->pright != nullptr))
	{
		isok = true;
	}
	else
	{
		isok = false;
	}
	return isok&&isall(proot->pleft) && isall(proot->pright);
}



bool iscompetebintree(bintree*proot)//�ж϶������Ƿ�Ϊ��ȫ������
{
	if (proot == nullptr)
	{
		return false;
	}
	else
	{
		queue<bintree*>myq;
		myq.push(proot);
		bool musthavechild = false;
		bool result = true;
		while (!myq.empty())
		{
			bintree *node = myq.front();
			myq.pop();
			if (musthavechild)
			{
				if (node->pleft != nullptr || node->pright != nullptr)
				{
					result = false;
					break;
				}
			}
			else
			{
				if (node->pleft != nullptr&&node->pright != nullptr)
				{
					myq.push(node->pleft);
					myq.push(node->pright);
				}
				else if (node->pleft != nullptr&&node->pright == nullptr)
				{
					musthavechild = true;
					myq.push(node->pleft);
				}
				else if (node->pleft == nullptr&&node->pright != nullptr)
				{
					musthavechild = true;
					myq.push(node->pleft);
				}
				else
				{
					musthavechild = true;
				}
			}
			return result;
		}
	}
}



bintree *rev(bintree *proot)//�������ľ���
{
	if (proot == nullptr)
	{
		return nullptr;
	}
	bintree *leftp= rev(proot->pleft);
	bintree *rightp = rev(proot->pright);//�ݹ�
	proot->pleft = rightp;
	proot->pright = leftp;   //����
	return proot;
}


int getlevel(bintree *proot, int k)//�������k��ڵ����
{
	if (proot == nullptr || k < 1)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{ 
		int left = getlevel(proot->pleft, k - 1);
		int right = getlevel(proot->pright, k - 1);
		return(left + right);
	}
}



int getmaxdistance(bintree*proot)

void main()
{
	struct bintree *proot;
	struct bintree tree1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	struct bintree tree2;
	struct bintree tree3;
	struct bintree tree4;
	struct bintree tree5;
	struct bintree tree6;
	struct bintree tree7;
	struct bintree tree8;
	proot = &tree1;
	tree1.Nodedata = 1;
	tree2.Nodedata = 2;
	tree3.Nodedata = 3;
	tree4.Nodedata = 4;
	tree5.Nodedata = 5;
	tree6.Nodedata = 6;
	tree7.Nodedata = 7;
	tree8.Nodedata = 8;
	tree1.pleft = &tree2;
	tree1.pright = &tree3;

	tree2.pleft = &tree4;
	tree2.pright = &tree5;

	tree3.pleft = &tree6;
	tree3.pright = &tree7;

	tree4.pleft = &tree8;

	
	show(proot, 1);
	
	shown(proot, 1);
	cout << "����ݹ�" << endl;
	zhong(proot);
	cout << "����ǵݹ�" << endl;
	zhongstack(proot);
	cout << "����ݹ�" << endl;
	xian(proot);
	cout << "����ǵݹ�" << endl;
	xianstack(proot);
	cout << "����ǵݹ�" << endl;
	houstack(proot);
	cout << "Ҷ�����" << getall(proot) << endl;
	ceng(proot);
	cout << "�ڵ���" << getakknode(proot) << endl;
	cout << iscompetebintree(proot) << endl;
	shown(rev(proot), 1);
	
	cout << getlevel(proot, 3) << endl;
	cin.get();
}



