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

void solve() {
	int n, m;
	cin >> n >> m;
	int p;
	cin >> p;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	int ans = 0;
	for(int i = n - 1; i >= 0; --i) {
		if (a[i] % p != 0) {
			ans += i;
			break;
		}
	}
	for(int i = m - 1; i >= 0; --i) {
		if (b[i] % p != 0) {
			ans += i;
			break;
		}
	}
	cout << ans << '\n';
}

signed main() {
	setup();
	// SOLVE;
	solve();


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