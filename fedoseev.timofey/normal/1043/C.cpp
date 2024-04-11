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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    vector <int> mem(n);
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'a') {
            mem[i] ^= 1;
            mem[i - 1] ^= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << mem[i] << ' ';
    }
}