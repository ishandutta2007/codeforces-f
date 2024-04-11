#include<bits/stdc++.h>
using namespace std;
#define N 5150
typedef long long ll;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
namespace MCMF{
	int head[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[N*200];
	void add(int a,int b,int c,int d){
		edge[++ecnt]={head[a],b,c,d};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c,int d){
		add(a,b,c,d);
		add(b,a,0,-d);
	}
	void init(int _S,int _T){
		memset(head,0,sizeof(head));
		ecnt=1;
		S=_S,T=_T;
	}
	int vis[N],dis[N],mincost;
	queue<int> q;
	bool SPFA(){
		memset(dis,0x3f,sizeof(dis));
		q.push(S);
		dis[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&dis[v]>dis[u]+edge[i].cost){
					dis[v]=dis[u]+edge[i].cost;
					if(!vis[v]){
						q.push(v),vis[v]=1;
					}
				}
			}
		}
		return dis[T]<inf;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		vis[u]=1;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]==dis[u]+edge[i].cost&&!vis[v]&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
				mincost+=k*edge[i].cost;
			}
		}
		vis[u]=0;
		if(!flow)dis[u]=inf;
		return flow;	
	}
	pair<int,int> Dinic(){
		mincost=0;
		int maxflow=0;
		while(SPFA()){
			maxflow+=dfs(S,inf);
		}
		return make_pair(maxflow,mincost);
	}
}
int n,m,K,C,D;
int main(){
	n=read(),m=read(),K=read(),C=read(),D=read();
	MCMF::init(5120,5121);
	for(int i=0;i<=100;++i){
		MCMF::adde(i*n+1,MCMF::T,K,i*C);
	}
	for(int i=0;i<100;++i){
		for(int j=1;j<=n;++j){
			MCMF::adde(i*n+j,(i+1)*n+j,K,0);		
		}
	}
	for(int i=1;i<=K;++i){
		int x=read();
		MCMF::adde(MCMF::S,x,1,0);
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		for(int j=0;j<100;++j){
			for(int k=1;k<=K;++k){
				MCMF::adde(j*n+u,(j+1)*n+v,1,D*(2*k-1));
				MCMF::adde(j*n+v,(j+1)*n+u,1,D*(2*k-1));	
			}
		}
	}
	auto [flow,cost]=MCMF::Dinic();
	printf("%d\n",cost);
	return 0;
}