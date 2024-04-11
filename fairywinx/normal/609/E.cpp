#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <random>
// #include <cmath>
#include <bitset>

#include <algorithm>
// #define int long long
#define SOLVE int t; cin >> t; while(t--) solve();
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3")

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif 
		srand(time(0));
}

const int N = 2e5 + 228;
const int K = 19;

struct DSU {
	vector<int> p;
	vector<int> r;
	DSU(int n) {
		p.resize(n + 5);
		r.resize(n + 5);
		for(int i = 0; i < n + 5; ++i)
			p[i] = i;
	}

	int get(int a) {
		if (a == p[a])
			return a;
		return p[a] = get(p[a]);
	}

	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b)
			return;
		if (r[a] == r[b])
			++r[a];
		if (r[a] > r[b])
			p[b] = a;
		else
			p[a] = b;
	}	
};

vector<pair<int, int>> G[N];
pair<int, int> up[K][N];
int d[N];

void dfs(int v, int p, int w, int now_d) {
	up[0][v] = make_pair(w, p);
	d[v] = now_d;
	for(auto i: G[v]) {
		if (i.first != p)
			dfs(i.first, v, i.second, now_d + 1);
	}
}

pair<int, int> la(pair<int, int> v, int level) {
	for(int i = K - 1; i >= 0; --i) {
		if ((1 << i) <= level) {
			level -= (1 << i);
			v.first = max(v.first, up[i][v.second].first);
			v.second = up[i][v.second].second;
		}
	}
	return v;
}

pair<int, int> lca(pair<int, int> a, pair<int, int> b) {
	if (d[a.second] < d[b.second])
		swap(a, b);
	a = la(a, d[a.second] - d[b.second]);
	if (a.second == b.second)
		return a;

	for(int i = K - 1; i >= 0; --i) {
		if (up[i][a.second].second != up[i][b.second].second) {
			a.first = max(a.first, up[i][a.second].first);
			b.first = max(b.first, up[i][b.second].first);
			a.second = up[i][a.second].second;
			b.second = up[i][b.second].second;
		}
	}
	a.first = max(a.first, up[0][a.second].first);
	b.first = max(b.first, up[0][b.second].first);
	return {max(a.first, b.first), up[0][a.second].second};
}

signed main() {
	setup();
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edge;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.emplace_back(c, make_pair(a - 1, b - 1));
	}
	long long res = 0;
	{	
		auto z = edge;
		sort(z.begin(), z.end());
		DSU A(n);
		for(auto i: z) {
			if (A.get(i.second.first) != A.get(i.second.second)) {
				// cout << i.second.first + 1 << ' ' << i.second.second + 1 << ' ' << i.first << '\n';
				G[i.second.first].emplace_back(i.second.second, i.first);
				G[i.second.second].emplace_back(i.second.first, i.first);
				res += i.first;
				A.merge(i.second.first, i.second.second);
			}
		}
	}
	// cout << res << '\n';

	dfs(0, 0, -1, 0);
	for(int k = 1; k < K; ++k) {
		for(int i = 0; i < n; ++i) {
			up[k][i].first = max(up[k - 1][i].first, up[k - 1][up[k - 1][i].second].first);
			up[k][i].second = up[k - 1][up[k - 1][i].second].second;
		}
	}

	for(auto e: edge) {
		pair<int, int> v = lca({-1, e.second.first}, {-1, e.second.second});
		// assert(res - v.first + e.first >= res);
		// cout << v.first << ':' << v.second << '\n';
		cout << res - v.first + e.first << "\n";
		// cout << e.first << '\n';
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}

/*
===%@%=====@@@@@%**@##@@%%@%@@@@%%%%@@@@@@@@@@@@@@@@@@@@@%%%%%+*::::::::::::::::::::::::::::::::::::::::::
=====%@@%=%@@@@@%*%###@@@@@@@@@@%%%@@@@@@@@@@@@@@@@@@@@@@@@%======+:::::::::::::::::::::::::::::::::::::::
=======%@@@@@@@@%*@###@@@@@@@@@@%%%%%%@@@@@@@@@@@@@@@@@@@@@%%%==%===*:::::::::::::::::::::::::::::::::::::
#%=======%@@@@@@==####@@@@@@@@%%%%%%%+%%@@@@@@@@@@@@@@@@@@#%%%=%=+=%=+::::::::::::::::::::::::::::::::::::
+:::*======%@@@@=@####@@@@@@@%%+=%=+=%%%%@@@@@@@@@@@@@@@@@@#%%%%=%%==%*:::::::::::::::::::::::::::::::::::
*::::::*=====@@@=#####@@@@@@%%%%=++%%%%%%@@@@@@@@@@@@@@@@@@@#@%%%%=%%%=:::::::::::::::::::::::::::::::::::
=:::::::**======@#####@@@@@@%%%++%=++%%%@@@@@@@@@@@@@@@@@@@@@@##@%%%%%=:::::::::::::::::::::::::::::::::::
%+*::::****+====#######@@@@@%=+=%%%%%%%@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%*:::::::::::::::::::::::::::::::::
%=***********+=%#######@@@@@@%%%%%%%%%##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%**::::::::::::**************:::::
%%+***::::::::*=#######@@@@@@@#@@@@##@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%==:::::::::::*************::::::
%%@%%+:::::::::%########@@@@@@@@@@@@@%%%%%%%%%%%%%%%%=====+++++++%%%%%%=+++++::::::::::**********:::::::::
+=%%%%%=*:::::*@########@@@@@@@%%%%%%==++++=%%%%%%%=++++++++++++%%%+++=%%=+*+=*:::::::::::::::::::::::::::
+%%@%%%%%=::::+@########@@@%%%%=+++++++++=%%%=+++=%%%%+++++++++%%=++++++=%%=+%=:::::::::::::::::::::::::::
%%%%@@@%%%%*::=##########%%=+++++++++++=%%%=++++++++=%%%=++++=%%=+++++++++%%%%%=*::::::::::::::::::::::::*
@@@@@@@@@%%=::%##########@%%%=+++++++=%%%=+++++++++++++=%%%==%%=+++++++=+++=%%%++*:::::::::::::::::::::::-
@@@@@@@@@@@@+*@#########@%==%%%%%%=+%%%=++=====+++++===%%%%%%%%%%%%%%%%%%%%%%%%%%%=+::::::::::::::::::::--
@@@@@@@@%@@@=*@#####@@#@%%%++++=%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:::::::::::::::::::---
@@@@@@@@@@@#=*@##@%%@#@%%%%%=%%%%%%%%@@@@@@@@@@@@@#########@@@@@@@@@@@@@@@@@@@@@@@@%*:::::::::::::::::----
@@@@@@@@@##@+=##%%%@#@%%%@##@%%@@@@@@@###########@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%+*:::::::::*-----
@@@@@@#####%++##@%@#@%%%@################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=+*:*:-----
@#########@++=@####@@@#############@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%=*::
#########%+++=%@##############@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%=++******************************++==%%%@@@
#######@++*++%@##########@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=+******************++++================++++********
###@@=+****+@########@@@@@@@@@@@@@@@@@@@@@@@@@@%=+***********+=%@@######################@@@@@@@@@@@@@@@@@@
=++********+@####@@@@@@@@@@@@@@@@@@@@@@@@@%+**********+=@###############################@@@@@@@@@@@@@@@@@@
****:::::*=@#@@@@@@@@@@@@@@@@@@@@@@@@@=*********++++++@##############@##################@@@@@@@@@@@@@@@@@@
:::::::=@@@@@@@@@@@@@@@@@@@@@@@@@%=*********=@##=+++++@##############+%#################@@@@@@@@@@@@@@@@@@
::::=@@@@@@@@@@@@@@@@@@@@@@@@%=********+%=++@###%=++++%@@###########@++@##@%############@@@@@@@@@@@@@@@@@@
:+@@@@@@@@@@@@@@@@@@@@@@@%+*******+%@###=+++=#@%+++=%==%%###########%=+*%%=:=%%%%%@%@@##@@@@@@@@@@@@@@@%=+
@@@@@@@@@@@@@@@@@@@@@=+******+=@#######%+++++@@++*****+%+@#@@@%%%%%%:---*=+-:%%%%%@%%%%%@@@@@@@@%%=:******
@@@@@@@@@@@@@@@@%=******+=@###########@+++++++@+++****:***%%%%%%%%%*-----+:--+%%%%@%%%%%@@==+*::::*:******
@@@@@@@@@@@@=+*****+=@################=++++++++++*::------+=%%%%%==*::---:---:=%%%@%%%%%%+:::::-::::+*****
@@@@@@@%+*****+%@####################%@#@@@#####@@%%*-----:====*::=@@@@%%@=---+%%%@%%%%%%=:::::::::*+::***
@@%+*****+%@@@######################@*:+:-%@@###=----------**-----+@@@=--*---:%@%%@%%%%%%=:------::**:****
+=++=%@@@@@@@@#########%#######@@%%%=:----=@##@#=..---------------=@@@*.-----=@@%%@@%%%%%=:------::*::****
+=%%@@@@@@@@@##########=##@@@%%%%%%%%:----:%%=%%*-----------------+=%%-.----+@##%%#@%%%%%%*------*:*-:****
+@%===%%+*:=%*:@#####@@*%%%%%%%%%%%%%+------------------------------:::----*@###@@#@%%%%%%*:-----**:-:****
%@========*::::+##@@%%%==%@@%%%%%%%%%%:-----------------------------------:@@###@@##%%%%%%+------**--:****
@%===========+::=%=%%%%@@@@@%@@%%%%%%%+-----------------------------------=@####@###@%%%%%*------**--:****
@%============+::*+=%%@@@@@@@@@@@@%%%%%*---------------------------------:%#########@%%%%%*-----:+:--:****
@%===========%=:::*%@@@@@@@@@@@@@@%%%%%=:--------------------------------*@#########@%%=%=:-----**---:****
@%==========%==:::+@@@@@@@@@@@@@@@@@@%%%*-------------------------------:%@#####+##@%%=:==:----*+*---:****
@%=========%%@=*:*=@@@@@@@#@@@@@@@@@@%@@%*-------------:---------------*@######=:@@@%%:-++----*+=----:****
@%========%%@@=***%@@@@@@@@#@@@@@@@@@@@#@%*------------------:-------*@#######@*-=@@%*--**---*+=*---:::*:*
@@@%====%%@@#@%+*+@@@@@@@@@@#@@@@@@@@@@##@%+*:--------------------:=@#########%--+@%=---*:---:*+:--::--:**
*%@@@===%@@@#@%*:=@@@@@@@@@@@#@@@@@@@@@@#@+%+++*::-------------:*%@#########@%*--+%=----:--::::--........-
-:+@@@@@@@@@#@%**@@@@@@@@@@@@@#@@@@@@@@@##=++***+++**:-------:=%@@@########@%=:::+=:---.-.........----::--
---:%@@@@@@@#@%*%@@@@@@@@@@@@@@#@@#@@@@@@##=++++++++++++++*+%@@@@@@#######@%%--.-*:------.----::---.......
-::::=@@@@@@#@%%@@@@@@@@@@@@@@@@@####@@@@##########@@%%%%%@@@@@@@@######@@%%+::*****:---:::::--...........
:::::*@@@@@@@@%%==%%@@@@@@@@@@@@@@#####@@@############@%###@@@@@@@#####@@%%=*-:*:---:::::::::-----........
--::::%@@@@@%%==************+=%%@@@######@@###########@@##@@@@@@@@@###@@%%%**--..--------.................
------*@@%======@@@@%%=+++*********=@########@++++++==%%%@%@@@@@@%%##@@@%@=**-..............-.............
:-----:%@%======@@@@@@@@@@@@@@@@%%==@@@#######%+++++***:--::=@%%%%%#@@@@@#@**:-.........---...............
*/