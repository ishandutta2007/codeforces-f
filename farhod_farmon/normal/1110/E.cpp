#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        if(a[1] != b[1] || a[n] != b[n]){
                cout << "No" << "\n";
                return 0;
        }
        for(int i = 1; i < n; i++){
                a[i] = a[i + 1] - a[i];
                b[i] = b[i + 1] - b[i];
        }
        sort(a + 1, a + n);
        sort(b + 1, b + n);
        for(int i = 1; i < n; i++){
                if(a[i] != b[i]){
                        cout << "No" << "\n";
                        return 0;
                }
        }
        cout << "Yes" << "\n";
}