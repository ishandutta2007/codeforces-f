// #define GLIBCXX_DEBUG

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
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long
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

string mx(string &a, string &b) {
	if (a == "!")
		return b;
	if (b == "!")
		return a;
	if (a.size() < b.size())
		return a;
	if (b.size() < a.size())
		return b;
	for(int i = 0; i < a.size(); ++i) {
		if (a[i] < b[i])
			return a;
		else if (b[i] < a[i])
			return b;
	}
	return a;
}

void solve(int n, int k) {
	// int n, k;
	// cin >> n >> k;
	string ans = "!";
	for(int i = 0; i < 10; ++i) {
		int sum = 0;
		for(int j = 0; j <= k; ++j) {
			sum += (i + j) % 10 + ((i + j) / 10) % 10;
		}
		if (sum == n) {
			cout << i << '\n';
			return;
		}
	}
	for(int sum = 0; (k + 1) * sum <= n; ++sum) {
		for(int i = 0; i < 10; ++i) {
			int res = 0;
			for(int j = 0; j <= k; ++j) 
				res += (i + j) % 10;
			if (i + k < 10) {
				if (res + sum * (k + 1) == n) {
					string z = "";
					if (sum % 9 != 0)
						z += to_string(sum % 9);
					for(int j = 0; j < sum / 9; ++j)
						z += "9";
					z += to_string(i);
					ans = mx(ans, z);
				}
			}
			else {
				int _n = n - ((k + 1) * sum + res + (i - 9 + k));
				if (_n % (9 * (10 - i)) == 0 && _n >= 0) {
					string z = "";
					// cout << k + i << ' ' << sum << ' ' << i << ' ' << z << '\n';
					if (sum != 0) {
						if (sum > 8) {
							z += to_string(1 + (sum % 9));
							for(int j = 0; j < sum / 9 - 1; ++j)
								z += "9";
							z += "8";
						}
						else
							z += to_string(sum);
					}
					for(int j = 0; j < _n / (9 * (10 - i)); ++j)
						z += "9";
					z += to_string(i);
					// cout << k + i << ' ' << sum <<99 2 ' ' << i << ' ' << z << '\n';
					ans = mx(ans, z);
				}
			}
		}
	}
	
	if (ans == "!")
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}

signed main() {
	setup();
	// SOLVE;
	// for(int i = 0; i <= 150; ++i) {
	// 	cout << i << ':';
	// 	solve(i, 2);
	// }
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		solve(n, k);
	}
	// for(int i = 0; i < 9000; ++i) {
	// 	int sum = 0;
	// 	string c = to_string(i);
	// 	for(auto i: c)
	// 		sum += i - '0';
	// 	c = to_string(i + 1);
	// 	for(auto i: c)
	// 		sum += i - '0';
	// 	if (sum == 44) {
	// 		cout << i << '\n';
	// 		return 0;
	// 	}
	// }

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}

// 39
// (R(RaR)R(RRRaLaa)LRaa(aR))(LaRR(a(a)La

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