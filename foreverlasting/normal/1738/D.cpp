//2022.9.30 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include <bits/stdc++.h>
#include <random>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1000000000000000000
#define unl __int128
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define Pair pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define pi acosl(-1.0)
#define pb push_back
#define eb emplace_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
#define ld long db

//inline int gc() {
//  static char buf[100000], *p1, *p2;
//  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
//}

//char sr[1 << 21], z[20];
//int C = -1, Z = 0;
//inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
//
//inline void print(LL x) {
//    if (C > 1 << 20)Ot();
//    if (x < 0)sr[++C] = '-', x = -x;
//    while (z[++Z] = x % 10 + 48, x /= 10);
//    while (sr[++C] = z[Z], --Z);
//}

template<typename T>
inline void Read(T &x) {
	int c = gc();
	bool f = false;
	for (x = 0; !isdigit(c); c = gc())if (c == '-')f = true;
	for (; isdigit(c); c = gc())x = x * 10 + c - '0';
	if (f)x = -x;
}

inline int read() {
	int s = 0, ch = gc(), w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		else if (ch == EOF) break;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
	return s * w;
}

inline LL Read() {
	LL s = 0;
	int ch = gc(), w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		else if (ch == EOF) break;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
	return s * w;
}

void write(unl x) {
	if (x > 9)write(x / 10);
	putchar(int(x % 10) + '0');
}
template<int kcz>
struct ModInt {
#define T (*this)
	int x;
	ModInt() : x(0) {}
	ModInt(int y) : x(y >= 0 ? y : y + kcz) {}
	ModInt(LL y) : x(y >= 0 ? y % kcz : (kcz - (-y) % kcz) % kcz) {}
	inline int inc(const int &v) {
		return v >= kcz ? v - kcz : v;
	}
	inline int dec(const int &v) {
		return v < 0 ? v + kcz : v;
	}
	inline ModInt &operator+=(const ModInt &p) {
		x = inc(x + p.x);
		return T;
	}
	inline ModInt &operator-=(const ModInt &p) {
		x = dec(x - p.x);
		return T;
	}
	inline ModInt &operator*=(const ModInt &p) {
		x = (int)((LL)x * p.x % kcz);
		return T;
	}
	inline ModInt inverse() const {
		int a = x, b = kcz, u = 1, v = 0, t;
		while (b > 0)t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
		return u;
	}
	inline ModInt &operator/=(const ModInt &p) {
		T *= p.inverse();
		return T;
	}
	inline ModInt operator-() const {
		return -x;
	}
	inline friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) += rhs;
	}
	inline friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) -= rhs;
	}
	inline friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) *= rhs;
	}
	inline friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) /= rhs;
	}
	inline bool operator==(const ModInt &p) const {
		return x == p.x;
	}
	inline bool operator!=(const ModInt &p) const {
		return x != p.x;
	}
	inline ModInt qpow(LL n) const {
		ModInt ret(1), mul(x);
		while (n > 0) {
			if (n & 1)ret *= mul;
			mul *= mul, n >>= 1;
		}
		return ret;
	}
	inline friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}
	inline friend istream &operator>>(istream &is, ModInt &a) {
		LL t;
		is >> t, a = ModInt<kcz>(t);
		return is;
	}
	static int get_mod() {
		return kcz;
	}
	inline bool operator<(const ModInt &A) const {
		return x < A.x;
	}
#undef T
};

const int kcz = 998244353;
using Z = ModInt<kcz>;

inline LL qpow(LL x, LL y, const LL &ljc) {
	LL ret = 1;
	while (y) {
		if (y & 1)ret = ((LL)ret * x % ljc);
		x = ((LL)x * x % ljc), y >>= 1;
	}
	return ret;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//2022.9.30 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e5+10;
namespace MAIN {
	int n;
	int b[N];
	int s[N];
	int a[N];
	vector<int> A[N];
	inline void MAIN(const int &Case) {
		n=read();
		for(int i=0;i<=n+1;i++)vector<int>().swap(A[i]),s[i]=0;
		for(int i=1;i<=n;i++){
			b[i]=read();
			int l=i,r=b[i];
			if(l>r)swap(l,r);
			s[l]++,s[r+1]--;
		}
		for(int i=1;i<=n;i++)s[i]+=s[i-1];
		int k=0;
		for(int i=0;i<=n;i++){
			if(s[i]==n){k=i;break;}
		}
		for(int i=1;i<=k;i++)A[b[i]].pb(i);
		for(int i=k+1;i<=n;i++)A[b[i]].pb(i);
		int now=0;
		if(!A[0].empty())now=0;
		if(!A[n+1].empty())now=n+1;
		int ax=0;
		while(ax<n){
			int id=0;
			for(auto x:A[now]){
				if(!A[x].empty())id=x;
			}
			for(auto x:A[now]){
				if(x!=id)a[++ax]=x;
			}
			a[++ax]=id,now=id;
		}
		printf("%d\n",k);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
}

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

//    srand(time(0));
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	int Case = read();
	for (int T = 1; T <= Case; T++)MAIN::MAIN(T);
//    Ot();
	return 0;
}