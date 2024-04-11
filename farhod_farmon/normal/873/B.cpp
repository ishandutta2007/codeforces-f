#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
map < int, int > used;

void solve()
{
        cin >> n;
        int cnt = 0, ans = 0;
        used[0] = 0;
        for(int i = 1; i <= n; i++){
                char c;
                int x;
                cin >> c;
                if(c == '1'){
                        x = 1;
                }
                else{
                        x = -1;
                }
                cnt += x;
                if(used.find(cnt) != used.end()){
                        ans = max(ans, i - used[cnt]);
                }
                else{
                        used[cnt] = i;
                }
        }
        cout << ans << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}