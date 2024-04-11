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

const int MAXN = 1000;

int p[1 + MAXN], l[1 + MAXN], r[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        l[1] = 1;
        for (int i = 2 ; i <= n; i++) {
            if (p[i] < p[l[i - 1]]) {
                l[i] = i;
            } else {
                l[i] = l[i - 1];
            }
        }
        r[n] = n;
        for (int i = n - 1; i >= 1; i--) {
            if (p[i] < p[r[i + 1]]) {
                r[i] = i;
            } else {
                r[i] = r[i + 1];
            }
        }
        bool found = false;
        for (int i = 2; i < n; i++) {
            if (p[i] > p[l[i - 1]] && p[i] > p[r[i + 1]]) {
                found = true;
                cout << "YES\n" << l[i - 1] << " " << i << " " << r[i + 1] << "\n";
                break;
            }
        }
        if (!found) {
            cout << "NO\n";
        }
    }
    //timeDuration();
    return 0;
}