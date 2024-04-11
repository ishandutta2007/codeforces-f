#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

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
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

#define max_n 100005

int ile[205];

void add(int x,int k){
  ile[x]+=k;
}

int query(int u){
  //debug(u);
  int ans = 0;
  if(u==0) return 0;
  FOR(i,0,201){
    int minus = min(u,ile[i]);
    u -= minus;
    ans += minus*i;
    if(u==0) break;
  }
  return ans;
}

int main(){
  make(n);
  vector<PII> v;
  int sum = 0;
  makev(w,n);
  makev(w2,n);
  FOR(i,0,n){
    v.pb(mp(w[i],w2[i]));
    sum +=w2[i];
  }
  sort(all(v));
  int best = 1e9;
  int last = -1;
  int jest = 0;
  VI act;
  v.pb(mp(1e6,0));
  FOR(i,0,n+1){
    if(v[i].st==last){
      jest++;
      act.pb(v[i].nd);
      sum -= v[i].nd;
    }
    else{
      if(jest>0){
        best = min(best,sum+query(i-jest-jest+1));
      }
      sum -=v[i].nd;
      FORE(j,act) add(*j,1);
      act.clear();
      act.pb(v[i].nd);
      last = v[i].st;
      jest = 1;
    }
    //debug3(best,jest,v[i].st);
  }
  printf("%d\n",best);

}