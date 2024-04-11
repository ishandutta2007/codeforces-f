#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const constexpr int maxN = 1e5 + 3;
const constexpr int iinf = 2147483647;
const constexpr ll linf = 9223372036854775807LL;
const constexpr int mod = 1e9 + 7;
const constexpr db pi = std::acos(-1.0);
const constexpr db eps = 1e-10;
typedef std::string str;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef bool boolvec[maxN];
typedef db dbvec[maxN];
template <typename T> const constexpr T abs(T x){return x>=0?x:-x;}

llvec p_conv;
int K;
void convert(ll p,ll k)
{
	std::fill_n(p_conv,maxN,0);
	K = 0;
	while (p)
	{
		p_conv[K] = p%k;
		if (p_conv[K] < 0) p_conv[K] -= k;
		p = (p-p_conv[K])/k;
		++K;
	}
}
int main()
{
	ll p,k;
	std::scanf("%I64d %I64d",&p,&k);
	convert(p,-k);
	std::printf("%d\n",K);
	for (int i=0;i<K;++i)
	{
		std::printf("%I64d",p_conv[i]);
		if (i != K-1) std::printf(" ");
	}
}