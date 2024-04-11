#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 100005

VI obok[max_n];
VI v;

int main(){
	IOS;
	make2(n,m);

	int last = -1;
	FOR(i,0,m){
		make(a); v.pb(a); 
	}

	FOR(i,0,v.size()){
		if(i+1<v.size() && v[i]!=v[i+1] ){
			obok[v[i]].pb(v[i+1]);
		}
		if(i-1>=0 && v[i]!=v[i-1] ){
			obok[v[i]].pb(v[i-1]);
		}
	}

	lint ans1 = 0; 
	FOR(i,0,m-1) ans1+= max(v[i]-v[i+1],v[i+1]-v[i]);

	lint ans = ans1;

	FOR(i,0,n+1){
		if(obok[i].size()!=0){
			
			lint locAns = 0;
			FORE(j,obok[i]) locAns+= max(*j-i,i-*j);
			
			sort(obok[i].begin(),obok[i].end());
			int pop = obok[i][obok[i].size()/2];
			
			lint locAns2 = 0;
			FORE(j,obok[i]) locAns2+= max(*j-pop,pop-*j);
			
			ans = min(ans, ans1+locAns2-locAns);
		}
	}
cout<<ans<<endl;

}