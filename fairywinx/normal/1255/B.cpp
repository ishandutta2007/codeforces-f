#include <bits/stdc++.h>

#define int ll
#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define ll long long
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

using namespace std;

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ct(vpii &a) {
    for (auto &i: a) cout << i.fi << ":" << i.se << ' ';
    cout << '\n';
}

void ct(vvpii &a) {
    for (auto &i: a) ct(i);
}

void ct(vector<vector<int>> &a) {
    for(auto &i: a) ct(i);
}

void ct(vector<set<int>> &a) {
    for(auto &i: a) {
        for(auto &j: i) cout << j << ' ';
        cout << '\n';
    }
}

void ct(set<pii> &a) {
    for(auto &i: a) cout << i.first << ':' << i.second << ' ';
    cout << '\n';
}

void ct(pii &a) {
    cout << a.first << ':' << a.second << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ci(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) ci(a[i]);
}
const int inf = 1e10;

signed main() {
    int t;
    cin >> t;
    fr(u, t)
    {
        iniit;
        vi a(n);
        ci(a);
        if(n == 2) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 0;
        fr(i, n)
        {
            ans += 2 * a[i];
        }
        if (m < n) {
            cout << -1 << '\n';
            continue;
        }
        vvi g(n, vi (n));
        fr(i, n) {
            fr(j, n) {
                if (i == j) {
                    g[i][j] = inf;
                    continue;
                }
                g[i][j] = a[i] + a[j];
                g[j][i] = a[i] + a[j];
            }
        }

        m -= n;
        int mn = inf;
        pii z;
        fr(i, n)
        {
            fr(j, n)
            {
               if (g[i][j] < mn) {
                    mn = g[i][j];
                    z = mp(i, j);
               }
            }

        }
        ans += mn * m;
        cout << ans << '\n';
        fr(i, m)
        {
            cout << z.first + 1 << ' ' << z.second + 1 << '\n';
        }
        fr(i, n) {
            cout << i + 1 << ' ' << (i + 2 - 1) % n + 1<< '\n';
        }
    }
}