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
#define N 75005
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
int m;
vector<pair<int,int> > ok[1<<15];
int a[15][N],dp[1<<15],pre[1<<15],n[15];
ll sum,s[N];
map<ll,int> mp;
set<ll> vis;
pair<int,int> ans[15];
void dfs(int u){
	if(!u)return;
	dfs(pre[u]);
	int t=u^pre[u];
	for(int i=0;i<(int)ok[t].size();++i){
		ans[ok[t][i].second]=make_pair(ok[t][i].first,ok[t][(i+1)%ok[t].size()].second);
	}
}
int main(){
	m=read();
	for(int i=0;i<m;++i){
		n[i]=read();
		for(int j=1;j<=n[i];++j){
			a[i][j]=read();
			s[i]+=a[i][j];	
			mp[a[i][j]]=i;
		}	
		sum+=s[i];
	}
	if(sum%m)return !printf("No\n");
	sum/=m;
	for(auto [_u,id]:mp){
		if(vis.count(_u))continue;
		static vector<int> st;
		static set<ll> ins;
		ll u=_u;
		while(true){
			if(vis.count(u)){
				if(!ins.count(u))break;
				int z=0;
				vector<pair<int,int> > vec;
				while(true){
					int v=st.back();
					st.pop_back();
					if(z>>mp[v]&1){
						vec.clear();
						break;
					}
					z|=1<<mp[v];
					vec.emplace_back(v,mp[v]);
					if(u==v)break;	
				}
				ok[z]=vec;
				break;
			}
			st.push_back(u);
			ins.insert(u);
			vis.insert(u);
			u=sum-s[mp[u]]+u;
			if(!mp.count(u))break;
		}
		ins.clear();
		st.clear();
	}
	dp[0]=1;
	for(int i=1;i<(1<<m);++i){
		for(int s=i;s;s=(s-1)&i){
			if(dp[s^i]&&ok[s].size()){
				dp[i]=1,pre[i]=(s^i);
				break;
			}	
		}
	}
	if(dp[(1<<m)-1]){
		printf("Yes\n");
		dfs((1<<m)-1);
		for(int i=0;i<m;++i){
			printf("%d %d\n",ans[i].first,ans[i].second+1);	
		}
	}
	else{
		printf("No\n");
	}
	return 0;
}