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

const int MAXN = 100000;
const long long INF = 1000000000000000000LL;

int v[1 + MAXN];
int Stack[1 + MAXN];
long long best[1 + MAXN], smallest[1 + MAXN];
long long sum[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("aparate.out");
    int n, top = 0;
    cin >> n;
    long long answer = 0;
    smallest[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
        long long current = sum[i - 1];
        while (top > 0 && v[i] >= v[Stack[top]]) {
            current = min(current, best[top]);
            top--;
        }
        top++;
        best[top] = current;
        Stack[top] = i;
        smallest[top] = min(smallest[top - 1], best[top] + v[Stack[top]]);
        answer = max(answer, sum[i] - smallest[top]);
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}