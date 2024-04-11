#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	string res = "AA";
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			string cur(1, 'A' + i);
			cur += 'A' + j;
			int t = 0;
			for (int k = 0; k + 1 < n; ++k)  {
				if (s.substr(k, 2) == cur) ++t;
			}
			if (t > ans) {
				ans = t;
				res = cur;
			}
		}
	}
	cout << res << '\n';
}