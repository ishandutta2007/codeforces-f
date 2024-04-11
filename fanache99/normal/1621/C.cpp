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

const int MAXN = 10000;

int p[1 + MAXN], queries;
bool seen[1 + MAXN];

int ask(int i, int n) {
    queries++;
    assert(queries <= 2 * n && i >= 1 && i <= n);
    cout << "? " << i << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void answer(int n) {
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << p[i];
    }
    cout << "\n";
    cout.flush();
}

int main() {
    timeBegin();
//     ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        queries = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = -1;
            seen[i] = false;
        }
        int x = 1;
        while (x <= n) {
            vector<int> v;
            int pos = -1;
            int y = ask(x, n);
            while (!seen[y]) {
                if (y == x) {
                    pos = queries - 1;
                }
                v.push_back(y);
                seen[y] = true;
                y = ask(x, n);
            }
            assert(pos != -1);
            for (int i = 0; i < v.size(); i++) {
                p[v[i]] = v[(i + 1) % v.size()];
            }
            while (x <= n && p[x] != -1) {
                x++;
            }
        }
        answer(n);
    }
    return 0;
}