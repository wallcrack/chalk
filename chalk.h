#include<random>
#include<queue>
#include<map>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
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
		void PruferConstruct()
		{
			mt19937 rand(time(0));
			SequenceMaker sm(n,n);
			auto prufer=sm.GetSequence();
			vector<int> deg(n+10,1);
			set<int> leaves;
			for(int i:prufer)deg[i]++;
			for(int i=1;i<=n;i++)
				if(deg[i]==1)leaves.insert(i);
			for(int v:prufer)
			{
				int leaf=*leaves.begin();
				leaves.erase(leaves.begin());
				edge.push_back(GraphEdge(leaf,v,rand()%maxWeight));
				if(--deg[v]==1)leaves.insert(v);
			}
			edge.push_back(GraphEdge(*leaves.begin(),n,rand()%maxWeight));
			for(auto e:edge)
				if(rand()&1)swap(e.u,e.v);
			std::shuffle(edge.begin(),edge.end(),random_device());
		}
		void ConstructNormally()
		{
			mt19937 rand(time(0));
			edge.clear();
			for(int i=2;i<=n;i++)
			{
				int ver=rand()%i+1,wei=rand()%maxWeight;
				while(ver==i)ver=rand()%i+1;
				if(rand()&1)edge.push_back(GraphEdge(ver,i,wei));
				else edge.push_back(GraphEdge(i,ver,wei));//50%¸ÅÂÊ½»»»
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
			ConstructNormally();
		}
};

class GraphMaker
{
	private:
		int n,m,maxWeight;
		vector<GraphEdge>edge;
	public:
		GraphMaker(int a1=10,int a2=20,long long a3=20)
		{
			n=a1,m=a2,maxWeight=a3;
			TreeMaker tm(n,maxWeight);
			edge=tm.GetEdge();
		}
		void MakeGraphEdge(vector<GraphEdge> &tmp,map<pair<int,int>,bool> &repeat)
		{
			double k=0.5;//p
			for(int u=1;u<=n;u++)
			{
				for(int v=1;v<=n;v++)
				{
					if(u==v or repeat[make_pair(u,v)])continue;
					int val=rand()%10000;
					if(val<10000*k)continue;
					long long w=rand()%maxWeight;
					tmp.push_back(GraphEdge(u,v,w));
				}
			}
		}
		void RandomNormal()
		{
			mt19937 rand(time(0));
			map<pair<int,int>,bool>rep;
			TreeMaker tm(n,maxWeight);
			tm.ConstructNormally();
			edge=tm.GetEdge();
			for(int i=0;i<edge.size();i++)
				rep[make_pair(edge[i].u,edge[i].v)]=true;
			vector<GraphEdge> tmp;
			MakeGraphEdge(tmp,rep);
			shuffle(tmp.begin(),tmp.end(),rand);
			for(int i=0;i<=m-n;i++)
				edge.push_back(tmp[i]);
			shuffle(edge.begin(),edge.end(),rand);
		}
		vector<GraphEdge> GetEdge()
		{
			return edge;
		}
};
