#include<iostream>
#include"chalk.h"
using namespace std;
int main()
{
	int n=5,m=10,maxw=20;
	GraphMaker gm(n,m,maxw);//���õ���������������Ȩ
	gm.RandomNormal();//���һ��ͼ
	auto edge=gm.GetEdge();//��ȡ��
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<edge.size();i++)
		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	return 0;
}
