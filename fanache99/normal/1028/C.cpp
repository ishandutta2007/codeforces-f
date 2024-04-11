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

const int MAXN = 132674;
const int INF = 2000000000;

struct Rectangle {
    int x1, y1, x2, y2;
};

Rectangle v[1 + MAXN], p[1 + MAXN], s[1 + MAXN];

Rectangle intersect(Rectangle a, Rectangle b) {
    return {max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}

bool nonEmpty(Rectangle a) {
    return (a.x1 <= a.x2 && a.y1 <= a.y2);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    }
    p[0] = s[n + 1] = {-INF, -INF, INF, INF};
    for (int i = 1; i <= n; i++) {
        p[i] = intersect(p[i - 1], v[i]);
    }
    for (int i = n; i >= 1; i--) {
        s[i] = intersect(s[i + 1], v[i]);
    }
    if (nonEmpty(p[n])) {
        cout << p[n].x1 << " " << p[n].y1 << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            Rectangle temp = intersect(p[i - 1], s[i + 1]);
            if (nonEmpty(temp)) {
                cout << temp.x1 << " " << temp.y1 << "\n";
                return 0;
            }
        }
    }
    return 0;
}