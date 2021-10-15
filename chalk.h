#include<random>
#include<algorithm>
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
			std::shuffle(edge.begin(),edge.end(),random_device());
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
	long long len,maxValue;
	bool negative,repeat;
	public:
	vector<long long>seq;
	SequenceMaker(int c1=10,long long c2=50,bool c3=false)
	{
		len=c1,maxValue=c2,negative=c3;
		RandomNormal();
	}
	void set(int c1=10,long long c2=50,bool c3=false)
	{
		len=c1,maxValue=c2,negative=c3;
	}
	void RandomNormal()
	{
		seq.clear();
		mt19937 rand(time(0));
		for(int i=1;i<=len;i++)
			seq.push_back(rand()%maxValue);
		if(negative)
			for(int i=0;i<len;i++)
				seq[i]=(rand()&1)?seq[i]:-seq[i];
	}
	vector<long long> GetSequence()
	{
		return seq;
	}
};
