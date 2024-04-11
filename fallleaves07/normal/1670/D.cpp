#include<bits/stdc++.h>

using ll = long long;
using ld = long double;

namespace GTI
{
	char gc(void)
   	{
		const int S = 1 << 16;
		static char buf[S], *s = buf, *t = buf;
		if (s == t) t = buf + fread(s = buf, 1, S, stdin);
		if (s == t) return EOF;
		return *s++;
	}
	ll gti(void)
   	{
		ll a = 0, b = 1, c = gc();
		for (; !isdigit(c); c = gc()) b ^= (c == '-');
		for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
		return b ? a : -a;
	}
	int gts(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
	int gtl(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
}
using GTI::gti;
using GTI::gts;
using GTI::gtl;

int main(void)
{
    std::vector<int> a;
    a.reserve(1e6);
    int lst = 0;
    for (int i = 2; lst <= 1e9; i += 4)
    {
        a.push_back(lst + i - 2);
        a.push_back(lst + i - 2 + i);
        a.push_back(lst + i + i + i);
        lst += i * 3;
    }
    for (int T = gti(); T; T--)
    {
        int n = gti(), ans = std::lower_bound(a.begin(), a.end(), n) - a.begin() + 1;
        printf("%d\n", ans);
    }
	return 0;
}