#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int max_len=1<<19,N=max_len+5,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>inline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
void print(const poly &a){
	for(auto it:a)printf("%d ",it);
	printf("\n");
}
inline poly operator << (poly a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator <<= (poly &a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator >> (const poly &a,uint b){return b>=a.size()?poly():poly{a.begin()+b,a.end()};}
inline poly operator >>= (poly &a,uint b){return a=b>=a.size()?poly():poly{a.begin()+b,a.end()};}
poly operator += (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i) add(a[i],b[i]);
	return a;
}
inline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i) sub(a[i],b[i]);
	return a;
}
inline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
const ull Omg=ksm(3,(mod-1)/max_len);ull Omgs[N];
int getlen(int len){int limit=1;while(limit<len)limit<<=1;return limit;}
void setup(){
	Omgs[max_len>>1]=1;
	for(int i=(max_len>>1)+1;i<max_len;++i)Omgs[i]=Omgs[i-1]*Omg%mod;
	for(int i=(max_len>>1)-1;i>0;--i)Omgs[i]=Omgs[i<<1];
}
void DIF(ull *A,int limit){
	for(int len=limit>>1;len;len>>=1)for(int i=0;i<limit;i+=len<<1){
		ull *w(Omgs+len),*p(A+i),*q(A+i+len);
        for(int _=0;_<len;++_,++p,++q,++w){
        	ull tmp=*p+*q;if(tmp>=mod)tmp-=mod;
        	*q=*w*(*p+mod-*q)%mod,*p=tmp;
        }
	}
}
void DIT(ull *A,int limit){
	for(int len=1;len<limit;len<<=1)for(int i=0;i<limit;i+=len<<1){
		ull *w(Omgs+len),*p(A+i),*q(A+i+len);
        for(int _=0;_<len;++_,++p,++q,++w){
        	const ull tmp(*w**q%mod);
        	*q=*p+mod-tmp,*p=*p+tmp;
        }
	}
	for(int i=0;i<limit;++i)A[i]%=mod;
}
inline void dft(ull *A,int limit){DIF(A,limit);}
void idft(ull *A,int limit){
	DIT(A,limit),std::reverse(A+1,A+limit);
	ull inv=mod-(mod-1)/limit;for(int i=0;i<limit;++i)A[i]=inv*A[i]%mod;
}
ull _f[N],_g[N],_tp[N];
poly operator * (const poly &a,const poly &b){
	uint len=a.size()+b.size()-1;
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size();++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	uint limit=getlen(len);
	memset(_f+a.size(),0,(limit-a.size())<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	memset(_g+b.size(),0,(limit-b.size())<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
	dft(_f,limit),dft(_g,limit);
	for(uint i=0;i<limit;++i)_f[i]=_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
poly mul(const poly &a,const poly &b,uint len,bool need=true){
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size()&&i+j<len;++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<len&&j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	int limit=getlen(len);
	memset(_f+a.size(),0,(limit-a.size())<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	dft(_f,limit);
	if(need){
		memset(_g+b.size(),0,(limit-b.size())<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
		dft(_g,limit);
	}
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
inline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>inline poly operator *= (poly &a,const _Tp &b){
	for(auto &&it:a)it=1ULL*it*b%mod;
	return a;
}
template<typename _Tp>inline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>inline poly operator * (const _Tp &b,poly a){return a*=b;}
template<typename _Tp>inline poly operator /= (poly &a,const _Tp &b){
	ull inv=ksm(b);for(auto &&it:a)it=1ULL*it*inv%mod;
	return a;
}
template<typename _Tp>inline poly operator / (poly a,const _Tp &b){return a/=b;}
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int f[N],ans[N];
int main(){
	setup(),init();int n;read(n);int lim=(n+1)/2;
	poly A(n+1),B(n+1);
	for(int i=lim;i<n;++i)A[i]=fac[n-i-1];
	for(int i=0;i<=n;++i)B[i]=ifac[i];
	A*=B,f[1]=fac[n-1];for(int i=2;i<=n;++i)f[i]=fac[n-i]*ifac[i-2]%mod*A[n-i+1]%mod;
	ll sum=0;
	for(int i=n;i>=1;--i){
		ans[i]=f[i],sub(ans[i],ifac[i-1]*sum%mod),ans[i]=ans[i]*fac[i-1]%mod;
		if(i>1)add(sum,1LL*f[i]*fac[i-2]%mod);
	}
	for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}