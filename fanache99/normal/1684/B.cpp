#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long x = a + b + c, y = b + c, z = c;
        assert(x % y == a && y % z == b && z % x == c);
        cout << x << " " << y << " " << z << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}