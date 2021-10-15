#include<random>
#include<vector>
#include<ctime>
using namespace std;
class GraphEdge
{
	public:
	int u,v,w;
	GraphEdge(int c1,int c2,int c3)
	{
		u=c1,v=c2,w=c3;
	}
};
class TreeMaker
{
	private:
		int n,maxWeight,type;
	public:
		vector<GraphEdge>edge;
		void RandomNormal()
		{
			edge.clear();
			mt19937 rand(time(0));
			for(int i=2;i<=n;i++)
			{
				int ver=rand()%i+1,wei=rand()%maxWeight;
				while(ver==i)ver=rand()%i+1;
				edge.push_back(GraphEdge(ver,i,wei));
			}
		}
		void Set(int c1=10,int c2=10,int c3=1)
		{
			n=c1,maxWeight=c2,type=c3;
		}
		vector<GraphEdge> GetEdge()
		{
			return edge;
		}
		TreeMaker(int c1=10,int c2=10,int c3=1)
		{
			n=c1,maxWeight=c2,type=c3;
			RandomNormal();
		}
};
class SequenceMaker
{
	private:
		int n,maxValue;
		bool negative,repeat;
	SequenceMaker()
	{
	}
};
