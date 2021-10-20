#include<iostream>
#include"chalk.h"
using namespace std;
int main()
{
	int n=5,m=10,maxw=20;
	GraphMaker gm(n,m,maxw);//设置点数，边数，最大边权
	gm.RandomNormal();//随机一个图
	auto edge=gm.GetEdge();//获取边
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<edge.size();i++)
		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	return 0;
}
