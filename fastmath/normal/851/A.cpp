#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define prev _prev
#define hash _hash;
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k, t;
	cin >> n >> k >> t;
	if (t <= k){
		cout << t << '\n';
	}
	else if (t > n){
		cout << max((ll)0, k - (t - n)) << '\n';
	}
	else{
		cout << k << '\n';
	}

	return 0;
}