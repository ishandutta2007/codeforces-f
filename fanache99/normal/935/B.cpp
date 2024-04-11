#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 100000;

char s[1 + MAXN + 1];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, answer = 0;
    scanf("%d\n%s", &n, s + 1);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U')
            y++;
        else
            x++;
        if (x == y)
            if (s[i] == s[i + 1])
                answer++;
    }
    printf("%d\n", answer);
    return 0;
}