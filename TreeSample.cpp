#include<iostream>
#include"chalk.h"
using namespace std;
int main()
{
	TreeMaker tm(10,100);//(a1,a2,a3),a1表示树的大小，a2表示树的最大权值
	tm.RandomNormal();//随机一棵树
	auto edge=tm.GetEdge();//获得树边
	for(int i=0;i<edge.size();i++)
		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	return 0;
}
