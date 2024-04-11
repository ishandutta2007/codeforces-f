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
    for (int T = gti(); T; T--)
    {
        int n = gti();
        std::vector<int> a, b;
        std::map<int, int> cnt;
        for (int i = 0; i < n; i++)
            ++cnt[gti()];
        int mid = -1;
        for (auto [x, y] : cnt)
            if (y == 1 && mid == -1)
            {
                mid = x;
                a.push_back(mid);
                b.push_back(mid);
            }
            else
            {
                if (y == 1)
                {
                    if (a.size() < b.size()) a.push_back(x);
                    else b.push_back(x);
                }
                else
                {
                    a.push_back(x);
                    b.push_back(x);
                }
            }
        printf("%d\n", (int)std::min(a.size(), b.size()));
    }
	return 0;
}