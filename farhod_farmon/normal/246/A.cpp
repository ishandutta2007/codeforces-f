#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n < 3){
        cout << -1 << endl;
        return 0;
    }
    for(int i = n; i >= 1; i--)
        cout << i << " ";
}