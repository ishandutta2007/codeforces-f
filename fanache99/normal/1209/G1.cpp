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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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

const int MAXN = 200000;
const int MAXVAL = 200000;

int v[1 + MAXN];
int first[1 + MAXVAL], last[1 + MAXVAL], freq[1 + MAXVAL];
int sum[1 + MAXN];
vector<int> here[1 + MAXN];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    assert(q == 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (first[v[i]] == 0) {
            first[v[i]] = i;
        }
        last[v[i]] = i;
        freq[v[i]]++;
    }
    for (int i = 1; i <= MAXVAL; i++) {
        sum[first[i]]++;
        sum[last[i]]--;
        here[first[i]].push_back(freq[i]);
    }
    int last0 = 0, ans = 0, biggest = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        for (auto it : here[i]) {
            biggest = max(biggest, it);
        }
        if (sum[i] == 0) {
            int len = i - last0;
            last0 = i;
            ans += len - biggest;
            biggest = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}