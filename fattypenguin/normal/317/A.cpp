#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int main() {
	ll x, y, m;
	cin >> x >> y >> m;
	ll steps = 0;
	while (1) {
		if (x > y) swap(x, y);
		if (x >= m || y >= m) {
			cout << steps << endl;
			return 0;
		}
		if (x <= 0 && y <= 0) {
			cout << -1 << endl;
			return 0;
		}
		if (x < 0) {
			long long speed = (min(m, 0ll) - x) / y;
			steps += speed;
			x += speed * y;
		}
		ll z = x + y;
		if (x > y) {
			y = z;
		} else {
			x = z;
		}
		++steps;
	}
	return 0;
}