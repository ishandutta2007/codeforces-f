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
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 200000;
const int MOD = 1000000009;

char s[1 + MAXN];
int zeros[1 + MAXN], toLeft[1 + MAXN], toRight[1 + MAXN + 1];
int h[1 + MAXN], p2[1 + MAXN];

void precompute(int n) {
    toLeft[0] = 0;
    p2[0] = 1;
    for (int i = 1, parity = 1; i <= n; i++) {
        p2[i] = 2 * p2[i - 1] % MOD;
        zeros[i] = zeros[i - 1] + (s[i] == '0');
        toLeft[i] = (s[i] == '0' ? i : toLeft[i - 1]);
        h[i] = (s[i] == '0' ? 2 * h[i - 1] % MOD : (h[i - 1] + parity + MOD) % MOD);
        parity = (s[i] == '0' ? 1 : (parity * -1));
    }
    toRight[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        toRight[i] = (s[i] == '0' ? i : toRight[i + 1]);
    }
}

int getRange(int a, int b) {
    int z = zeros[b] - zeros[a - 1];
    int ans = (h[b] - (1LL * h[a] * p2[z - 1]) % MOD + MOD) % MOD;
    return ans;
}

unsigned long long getHash(int a, int b) {
    int a0 = toRight[a], b0 = toLeft[b], z = zeros[b] - zeros[a - 1];
    int ans = ((((a0 - a) % 2) * p2[z] + getRange(a0, b0)) % MOD + (b - b0) % 2) % MOD;
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> (s + 1);
    precompute(n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a1, a2, l;
        cin >> a1 >> a2 >> l;
        int b1 = a1 + l - 1, b2 = a2 + l - 1;
        if (zeros[b1] - zeros[a1 - 1] == zeros[b2] - zeros[a2 - 1] &&
            (zeros[b1] - zeros[a1 - 1] == 0 || getHash(a1, b1) == getHash(a2, b2))) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    //timeDuration();
    return 0;
}