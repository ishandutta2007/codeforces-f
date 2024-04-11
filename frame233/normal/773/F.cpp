// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

int maxn,maxa,mod;
const int max_len=1<<16;
const int N=max_len+5;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>Finline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
void print(const poly &a)
{
	for(auto it:a) printf("%d ",it);
	printf("\n");
}
poly operator += (poly &a,const poly &b)
{
	if(SZ(b)>SZ(a)) a.resize(SZ(b));
	for(uint i=0;i<b.size();++i) add(a[i],b[i]);
	return a;
}
Finline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b)
{
	if(SZ(b)>SZ(a)) a.resize(SZ(b));
	for(uint i=0;i<b.size();++i) sub(a[i],b[i]);
	return a;
}
Finline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
const double PI=acos(-1);
struct comp{
	double a,b;
	Finline comp operator + (const comp &o)const{return (comp){a+o.a,b+o.b};}
	Finline comp operator - (const comp &o)const{return (comp){a-o.a,b-o.b};}
	Finline comp operator * (const comp &o)const{return (comp){a*o.a-b*o.b,a*o.b+b*o.a};}
};
comp Omgs[N];
int r[N];
int calc(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
	for(int i=0;i<limit;++i) Omgs[i]=(comp){std::cos(2.0*PI*i/limit),std::sin(2.0*PI*i/limit)};
	return limit;
}
void dft(comp *a,int limit)
{
	for(int i=0;i<limit;++i) if(i<r[i]) std::swap(a[i],a[r[i]]);
	for(int len=2,qwq=(limit>>1);len<=limit;len<<=1,qwq>>=1)for(int pos=0;pos<limit;pos+=len)
	{
		comp *p(Omgs),*A(a+pos),*B(a+pos+(len>>1));
		for(int i=0;i<len>>1;++i,p+=qwq)
		{
			comp tmp(*p**B);
			*B=*A-tmp,*A=*A+tmp;
			++A,++B;
		}
	}
}
Finline void idft(comp *a,int limit){std::reverse(a+1,a+limit);dft(a,limit);}
poly operator * (const poly &a,const poly &b)
{
	if(a.size()<=40u||b.size()<=40u)
	{
		poly c(SZ(a)+SZ(b)-1);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) add(c[i+j],1ull*a[i]*b[j]%mod);
		return c.resize(maxn+1),c;
	}
	static comp A0[N],A1[N],B0[N],B1[N];
	int tmp=SZ(a)+SZ(b),limit=calc(tmp);
	for(int i=0;i<SZ(a);++i) A0[i]=(comp){double(a[i]&32767),0.0},A1[i]=(comp){double(a[i]>>15),0.0};
	for(int i=0;i<SZ(b);++i) B0[i]=(comp){double(b[i]&32767),0.0},B1[i]=(comp){double(b[i]>>15),0.0};
	for(int i=SZ(a);i<limit;++i) A0[i]=A1[i]=(comp){0.0,0.0};
	for(int i=SZ(b);i<limit;++i) B0[i]=B1[i]=(comp){0.0,0.0};
	dft(A0,limit),dft(A1,limit),dft(B0,limit),dft(B1,limit);
	for(int i=0;i<limit;++i)
	{
		comp a0=A0[i],a1=A1[i],b0=B0[i],b1=B1[i];
		A0[i]=a1*b1;
		A1[i]=a1*b0+a0*b1;
		B0[i]=a0*b0;
	}
	idft(A0,limit),idft(A1,limit),idft(B0,limit);
	poly c(tmp-1);
	for(int i=0;i+1<tmp;++i) c[i]=(((ll)(A0[i].a/(double)limit+0.5)%mod<<30)+((ll)(A1[i].a/(double)limit+0.5)<<15)+(ll)(B0[i].a/(double)limit+0.5))%mod;
	return c.resize(maxn+1),c;
}
Finline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>Finline poly operator *= (poly &a,const _Tp &b)
{
	for(auto &&it:a) it=1ll*it*b%mod;
	return a;
}
template<typename _Tp>Finline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>Finline poly operator * (const _Tp &b,poly a){return a*=b;}
template<typename _Tp>Finline poly operator /= (poly &a,const _Tp &b)
{
	ll inv=ksm(b);
	for(auto &&it:a) it=1ll*it*inv%mod;
	return a;
}
template<typename _Tp>Finline poly operator / (poly a,const _Tp &b){return a/=b;}
template<typename _Tp>Finline poly operator / (const _Tp &b,poly a){return a/=b;}
std::map<int,poly> mp[2];
int calc(const poly &o)
{
	int ans=0;
	for(int i=1;i<SZ(o);i+=2) add(ans,o[i]);
	return ans;
}
poly solve(int a,int p)
{
	if(!a) return (poly){0};
	if(mp[p].find(a)!=mp[p].end()) return mp[p][a];
	if(a&1)
	{
		poly ans(solve(a-1,p));
		if((a&1)==p) ans+=(solve(a-1,0)+solve(a-1,1)+(poly){1})*(poly){0,1};
		return mp[p][a]=ans;
	}
	else
	{
		poly ans(solve(a>>1,p));
		ans+=(solve(a>>1,0)+solve(a>>1,1)+(poly){1})*solve(a>>1,p^((a>>1)&1));
		return mp[p][a]=ans;
	}
}
int main()
{
	read(maxn,maxa,mod);
	poly tmp(2);tmp[1]=1;mp[1][1]=tmp;
	tmp[1]=0;mp[0][1]=tmp;
	int ans=0;for(int i=1;i<=30;++i) add(ans,calc(solve(maxa/(1<<i),1)));
	printf("%d\n",ans);
	return 0;
}