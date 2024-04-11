/*
//
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@O[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
//                                   ............=OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOooOO@@@OO`................
//                                   ...........=OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOoOO@OO^...............
//                                   ..........,oOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOO\*................
//                                   .........*oOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO@OO*...............
//                              .............*OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@O...............*/
//                              ............*/OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..............
//                                .........*oOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\..............
//                                 ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.............
//                              .. ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@O^............
//                              .. ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOooooooooOOooooooooooooOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^...........
//                              .. ........=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOoooooooooooooooooooooooOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..........
//                                .........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOooooooooooooooooooOOOOOO@@@@@OOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@O\....... ..
//                                .........=O@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@OOOOOOooooooooooooOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@O*......... .
//                                 ........=O@@@@@@@@@@@@@@@@@@@@@@OOOOOOoooooOOOOOOOOOOOoooo/*,\ooooOOOOOOOOOOOooooOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@O............
//                                 ........=O@@@@@@@@@@@@@@OOOOOOOOOOoooo^****=ooooooooooooo^****,oooOOOOOOOOO@OOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@o..........
//                              .. ........=O@@@@@@@@@OOOOOOOOOOOOoooooo^*****[oooOOOOOOoooo`*****oooOOO@@@OOoooOOO@@@@@@@@@@@@@OOOO@@@@@@@@@@@@@@@@@O`.............
//                              ...........*O@@@@@@@@OOOOOOOOOOoooooooooooOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@OOo..,OOOOOOOO@@@@@@@@@@@@@O@@@@@@@@@@@@@@@@@OO`............
//                     ......   ...........*O@@@@@@@@OOOOOOOooooooooOOOOOoo**oO@@@@@@@OOOOOOOO@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOO@@@OOOO@@@@@@@@@@@Oo*...........
//                     ......   .. .........o@@@@@@@@@OOOooooOOO@@@OOooOOOOOOOOOOOOOOOOooOOooOO@@@OoOOO@@@OOOOOOOOOOOOOOOOOOOOOOOOOO@@OOOOO@@@@@@@@@@@@O\.......
//                     ......   .. .........=@@@@@@@@@OOOO@@@@@@@@OooOOOOOOOOoooOOOOoooooooooO@@@OoooOO@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@OO^......
//                     . .       .........../O@@@@@@@@@@@@@@@@@@@@@OOOOOOoo/[[`,ooo/[[[[ooooOO@@Oo/[ooOOO@@@OOOOOOoooooooooOOOOOO@@@OOOOO@@@@@@@@@@@@@@Oo*......
//                     . .       .........*/OO@@@@@@@@@OOOOOOOOOOO@Ooooooo/**************\oooOOO*****,ooOOO@@@@OOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@Oo*.............
//                     . .         .....*/o/=ooooooOOOOOOOOoooooooOOOo[\o****************=ooOOO`*****]oOOOOOOO@@@OOOOOOOOOOooOOOOOOOOOO@@@@@@@@@@@@@@OO^........   .....
//                     . .         .....=ooO@@@OOOoo/OOOOOOooooooooOOO`**************]]/OOOOO[ooooOOOOOOO@@@OOOO@@OooooooooooOOOOOOOOOOO@@@@@@@@@@@@@OO*........   .....
//                                   ...=OOOOOOo/,ooooOOOOOOoooooooooOOOOOOOOOOOOOOOoooooooooOO@@@OOOOO@@@@@OOO@@OOoooooooooOOOOOOOOOO@@@@@@@@@@@@@@OO/..................
//                                 .....*oOoOOOoo****/OOOOOOOoooooooo\`*****[`*****,[[[[,oOOOOOOoooOOOOOOOOOOOOOOOOOooooooOOOOOOOOOOOO@@@@@@@@@@@@@@OO*..................
//                                 ......*oOoOOooooOOOOOOOOOOOooooooooo`******.....******,ooOOOoo`*,ooooooOOOOOOOOOOOOooOOOOOOOOOOOOO@@@@@@@@@@@@@@@O^...................
//                                   .....*\OOooooOOOOOoOOOOOOOooooooooooo]]]`****..*****************ooooooOOOOOOOOOOOOOOOO@OOOOOOOOO@@@@@@@@@@@@@@OO^...................
//                                   .......,OOOooOOOo`*\OOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooo\]***,oooooOOOOOOOOOOOOOO@@@@OOOOOOOOO@@@@@@@@@@@@@@OOOOOo]*..............
//                                ...........*oOOoooo\***=OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@OOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@OOO]............. .
//                                ............*OOOooooo[[oOOOOO@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\........... .
//                              ...............=O@OOOooo**oOO@@@@@OOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@OOOOOOO@@@@@OOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`...........
//                              ...............*oO@@Oo^****\O@@@@@@@OOOOOOOOOOOOOOOOO@@@@@@@@@@@@OOOOOOOOO@@@@@@@@OOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..........
//                     ....................,]oOOO@@@@Oo]]/ooOO@@@@@@@@OOOOOOOOOOOOOOO@@@@@@OOOOOOOOO@@@@@@@@@@@@@@@@@OOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`.........
//                     ...................=O@@@@@@@@@@@OOOOOOO@@@@@@@@@@@OOOOOOOOOOOO@@@@@OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@o........
//                 . ..................../O@@@@@@@@@@@@@@@Oo[[OOO@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@OOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.......
//                 ...................../O@@@@@@@@@@@@@@@@OO\`,oOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@@@@@^..... .
//                 ...................,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`......
//                 ..................,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`......
//                 .................OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.........
//                 ...............=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`.........
//                 ............../O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO[`*..=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..........
//                 ............./O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOooo[ooOO@@@@@OOOOOO@OOO[........[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O`..............
//                 .........../O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@OOOOOOO@@@@@@@@@OOOOOOOOOOOooooooo[[.............=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^...............
//                 .........,OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@OO@@@@@@@OOOO/[*.,O@OOOOOO@@@OOOOOo*.........................\O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^................
//                 ........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@OO@@@@@OOOO[*.....OOOOooO@@@OOoooo`...........................O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^.................
//                 .......=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@OO@@@@@OO/`.........\OOOOooO@@Oooo/*............................,OO@@@@@@@@@@@@@@@@@@@@@@@@@@/..................
//                 ......,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOO@OO@@@@OO[..............,oOOOO@@O/`*...............................,O@@@@@@@@@@@@@@@@@@@@@@@@@O..................
//               ........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOO@@@O`....................,oOOO*...................    ...........=O@@@@@@@@@@@@@@@@@@@@@@@O^...................
//               ........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@@/.................................................... ..........=O@@@@@@@@@@@@@@@@@@@@@@O....................
//                .......=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOO@@@@O..................................................... ...........\O@@@@@@@@@@@@@@@@@@@@O^....................
//          ...    .....,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..................................................................O@@@@@@@@@@@@@@@@@@@@O*....................
//        ......   .....O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO^..................................................................=O@@@@@@@@@@@@@@@@@@@^.....................
//        ... ... ......=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O/................***.................................................oO@@@@@@@@@@@@@@@@@O^.....................
//            .. ........\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Oo*...........*,oOOOOOOOOOOOOOOOOOOOOOOOOOOOOo]].............*]]]]*....,O@@@@@@@@@@@@@@@@@@^...................
//            .. .........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.........*/OOOO@@OOOOOOOOOOOOOOOOOO@@OOOOOOOOOOO@@@@@@@@@@@@@@@O^.....\O@@@@@@@@@@@@@@@@@^...................
//          .....  ........,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O*........*/oOOOOOOOOOOOOOOOOOOOOOOOOOOo[[[[[[[[[[[[[\o//[[[\OO@@@o.....,O@@@@@@@@@@@@@@@@O^.....................
//                 ..........O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Oo*.......*oOOO^..............................................,O@@@O*.....O@@@@@@@@@@@@@@@@O`.....................
//                 ..........O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO`.........*\OO\............   ......   .......................oO@@O......\O@@@@@@@@@@@@@@@O^..........=OOOO].......
//               ............O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Oo*...........oOo`..............................................=O@Oo......=O@@@@@@@@@@@@@@@O^.............,\OOO......
//               .............\O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^............\OOO........... ..............  ..................*O@@O......=O@@@@@@@@@@@@@@@O^................\OO*. ..
//                 ............=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^............=O@@o...........   .....   .......................=O@@O*......O@@@@@@@@@@@@@@@@^......=O@OO\.....\@O.....
//                 .............,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^............=O@@O^.........    .....    ......................=O@@O*......O@@@@@@@@@@@@@@@@^.........,\O/....=OO\....
//                 ..............,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^.............o@@O\.........            .......................=O@O\.......OO@@@@@@@@@@@@@@@O..................,[`....
//                 ...............,O@@@@@@@@@@@@@@@@@@@@@@@@@@@O^..............\O@O^........             .....................=O@@O/......*O@@@@@@@@@@@@@@@@@\........................
//                 .................\O@@@@@@@@@@@OOO@@@@@@@@@@@O^................\OO`...........       ....       ............=@@O/.......*O@@@@@@@O/...,[\O@O\..............  .......
//                  ..................\O@@@@@@O`...=O@@@@@@@@@@O^.................=OO\........  ..  .......       ............O@@O^.......,O@@@@@@@Oo......*OOO^.........
//                     .  ..............O@@@@/.....,O@@@@@@@@@@O^..................*oOO\.....................................=O@@O*......,OO@@@@@@O/`.......=OOO.........
//                      ................O@O^.......O@@@@@@@@@@@Oo**..................*\OOO\................................*O@@@@O\]OOOOOO@@@@@@@O^.......*/O@OO.........
//                 .....................OO^........=@@@@@@@@@@@OOOOoooooOOOOOOOOOOOo\/oOOOOO\]]]]]*****................*]oO@@@@@@@@@@@@@@@@@@@@@@@O...*/OO@@@@O`.........
//                 .....................OO^.......*/O@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@@OOO\]]]]]/OOO@@@@@@@@@@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@/........
//                 .....................oO\.......=O@@@@@@@@@@@@@@@OOOO/[[`**.*..***...***[[[[[\oOOOOOOOOO@@@@@@@@@@@@@@@@@@@@OOOO/[[[[oooOO@@@@@@@@@@@@@@O[.....  .
//                 ......................OO@O\....=O@@@@@@@@@@@@@@@O/****..........................***,\o/[**,[[[`*,[[[[[[[[***...******`oOO@@@@@@@@@@@@@O^.......
//               ........,....,\*.........\@@@O\]]/@@@@@@@@@@@@@@@@@O^*................................*=oo]*........................***ooO@@@@@@@@@@@@@@O*.......
//                 ......O\....,O^..........\O@@@@@@@@@@@@@@@@@@@@@@Oo**...............................*oOOO`........................*.*]OO@@@@@@@@@@@@@O^......
//                 ......=O^.....\o...........,[O@@@@@@@@@@@@@@@@@@@@O^**..............................=OOOO^......................,]/OO@@@@@@@@@@@@@@@@O\........
//                 ........O\....................,O@@@@@@@@@@@@@@@@@@@Oo`*****.........................*\OO/*.................**]OOOO@@@@@@@@@@@@@@@@@@@@@O^....
//               ...........,`................../O@@@@@@@@@@@@@@@@@@@@@@@OOOo\]]*********...............****.*............**]OOO@@@@@@@@@@@@@@@@@@@@@@@@@OOO.....
//               ..............................*O@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOo\]]]]]**************,]/oOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O^........
//                 ..         .....  ........,OO@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O.........
//                                   .......,OOO@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOO@O@@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@OOOOOOOOOO@@O`.........
//                               ............O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOO@@@O......
//                               ...........=O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@OOOOOO@@@@O`....
//                              .. ........*O@@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@OOOO@@@@@@O^.....
//                              .. ........=O@@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O........
//                              .. ........=O@@@OOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O/...    .
//                                 ...........,.......................................................**...................................................
//                                   ................................................................/@^....O@@@@@^........................................
//                                     ...  ..                             ...                    .@/[[[\@^.@@...@^....
//                                                                                                .@^=@.=@^,@^...@O....
//                                                                                              ...@^.\/=@^O/....,[[[..
//                                                                         .@@@@@@@@@@@@@@@@@@@O.=@@@@@@@@^@@@@@@@@@...
//                                                                                                .@^,`.=@^,@\...,@^.
//                                                                                                =@^.@\=@^.,@\.,@/..
//                                                                                             .../@....=@^...O@@^...
//                                                                                             ..,@/..]]/@^]@@@[[@@@]..
// ...                                                                                         ...`...,[`..............

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> poly;
const int mod1=1e9+7;
const int mod2=998244353;
const int SZ=1<<17;
#define N 100010
typedef long long ll;
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
map<pair<int,int>,int> mp;
int n,m;
int dfn[N],low[N],num,vis[N];
int st[N],top;
poly A(SZ),B(SZ);
vector<int> G[N];
#define ck(x) (x>=mod?x-mod:x)
int qpow(int a,int b,const int mod){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void FWT(poly &A,int flag,int n,const int mod){
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				int t1=A[i],t2=A[i+len];
				A[i]=ck(t1+t2);
				A[i+len]=ck(t1-t2+mod);
			}		
		}
	}	
	if(!flag){
		int iSZ=qpow(n,mod-2,mod);
		for(int i=0;i<n;++i){
			A[i]=1LL*A[i]*iSZ%mod;
		}
	}
}
poly Xor(poly A,poly B,const int mod){
	FWT(A,1,SZ,mod),FWT(B,1,SZ,mod);
	poly C(SZ);
	for(int i=0;i<SZ;++i){
		C[i]=1LL*A[i]*B[i]%mod;
	}
	FWT(C,0,SZ,mod);
	return C;	
}
void Tarjan(int u){
	dfn[u]=low[u]=++num;
	vis[u]=1;
	st[++top]=u;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				if(st[top]^v){
					poly C(SZ);
					++C[mp[make_pair(st[top],u)]];
					int t=0;
					while(t^v){
						t=st[top--];
						int nxt=st[top];
						++C[mp[make_pair(t,nxt)]];
					}
					A=Xor(A,C,mod1);
					B=Xor(B,C,mod2);
				}
				else --top;
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	n=read(),m=read();
	A[0]=B[0]=1;
	int all=0;
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].push_back(v);
		G[v].push_back(u);
		mp[make_pair(u,v)]=mp[make_pair(v,u)]=w;
		all^=w;
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])Tarjan(i);
	}
	poly C(SZ);
	C[all]=1;
	A=Xor(A,C,mod1);
	B=Xor(B,C,mod2);
	for(int i=0;;++i){
		if(A[i]||B[i]){
			printf("%d %d\n",i,A[i]);
			break;
		}	
	}
	return 0;
}