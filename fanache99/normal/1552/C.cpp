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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 200;

int x[1 + MAXN], y[1 + MAXN];
bool in[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        n *= 2;
        for (int i = 1; i <= k; i++) {
            cin >> x[i] >> y[i];
            if (x[i] > y[i]) {
                swap(x[i], y[i]);
            }
            in[x[i]] = in[y[i]] = true;
        }
        if (k == 0) {
            cout << (((n / 2) - 1) * (n / 2)) / 2 << "\n";
        } else {
            int ans = 0, already = 0;
            for (int i = 1; i <= k; i++) {
                for (int j = i + 1; j <= k; j++) {
                    if (!((x[i] < x[j] && y[j] < y[i]) || (x[j] < x[i] && y[i] < y[j]) || (y[i] < x[j]) || (y[j] < x[i]))) {
                        already++;
                    }
                }
                int a = 0;
                for (int j = x[i] + 1; j < y[i]; j++) {
                    if (!in[j]) {
                        a++;
                    }
                }
                int b = n - 2 * k - a;
                ans += min(a, b);
            }
            int r = n / 2 - k;
            ans += r * (r - 1) / 2;
            ans += already;
            cout << ans << "\n";
            for (int i = 1; i <= n; i++) {
                in[i] = false;
            }
        }
    }
    return 0;
}