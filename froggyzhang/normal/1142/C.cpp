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
int n,ans;
struct Point{
	ll x,y;
	Point(ll _x=0,ll _y=0){x=_x,y=_y;}
	friend bool operator < (const Point &a,const Point &b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend ll operator % (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;
	}
}p[N];
inline bool Left(Point a,Point b){
	return b%a>0;
}
int st[N],top;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		p[i].x=x,p[i].y=y-1LL*x*x;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		while(top>1&&!Left(p[st[top]]-p[st[top-1]],p[i]-p[st[top-1]]))--top;
		st[++top]=i;
	}
	for(int i=1;i<top;++i){
		ans+=p[st[i]].x!=p[st[i+1]].x;
	}
	printf("%d\n",ans);
	return 0;
}