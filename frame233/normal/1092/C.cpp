// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=105;
struct node{
    std::string s;
    int id;
    Finline node(std::string ss="",int ID=0):s(ss),id(ID){}
};
std::vector<node> v[N];
int ans[N<<1],n;
bool check(std::string s1,std::string s2)
{
    return s1.substr(0,s2.length())==s2;
}
bool CHECK(std::string s1,std::string s2)
{
    return s1.substr(s1.length()-s2.length(),s2.length())==s2;
}
bool judge(std::string s1,std::string s2)
{
	memset(ans,0,sizeof(ans));
    for(int i=1;i<n-1;++i)
    {
    	if(check(s1,v[i][0].s)&&CHECK(s2,v[i][1].s))
    	{
    		ans[v[i][0].id]=1;
		}
		else if(check(s1,v[i][1].s)&&CHECK(s2,v[i][0].s))
		{
			ans[v[i][1].id]=1;
		}
		else return 0;
    }
    return 1;
}
int main()
{
    read(n);
    int tmp=(n-1)<<1;
    std::string s;
    for(int i=1;i<=tmp;++i)
    {
        std::cin>>s;
        v[s.length()].push_back(node(s,i));
    }
    if(!judge(v[n-1][0].s,v[n-1][1].s))
    {
    	judge(v[n-1][1].s,v[n-1][0].s);
    	ans[v[n-1][1].id]=1;
	}
	else
	{
		ans[v[n-1][0].id]=1;
	}
    for(int i=1;i<=tmp;++i)
    {
        printf("%c",ans[i]?'P':'S');
    }
    printf("\n");
    return 0;
}