#include<iostream>
#include"chalk.h"
using namespace std;
int main()
{
	TreeMaker tm(10,100);//(a1,a2,a3),a1��ʾ���Ĵ�С��a2��ʾ�������Ȩֵ
	tm.RandomNormal();//���һ����
	auto edge=tm.GetEdge();//�������
	for(int i=0;i<edge.size();i++)
		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	return 0;
}
