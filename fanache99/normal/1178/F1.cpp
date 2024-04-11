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

const int MAXN = 500;
const int MAXM = 500;
const int MOD = 998244353;

int v[1 + MAXM];
int dp[1 + MAXM + 1][1 + MAXM + 1];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    for (int i = n + 1; i >= 1; i--) {
        dp[i][i - 1] = 1;
        for (int j = i; j <= n; j++) {
            int smallest = n + 1, x;
            for (int k = i; k <= j; k++) {
                if (v[k] < smallest) {
                    smallest = v[k];
                    x = k;
                }
            }
            int left = 0, right = 0;
            for (int k = x; k >= i; k--) {
                left = (1LL * dp[i][k - 1] * dp[k][x - 1] + left) % MOD;
            }
            for (int k = x; k <= j; k++) {
                right = (1LL * dp[x + 1][k] * dp[k + 1][j] + right) % MOD;
            }
            dp[i][j] = 1LL * left * right % MOD;
        }
    }
    cout << dp[1][n] << "\n";
    //timeDuration();
    return 0;
}