#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
#define taskname ""
#define sp " "
#define endl '\n'
using namespace std;
using ll = long long;
int a, b, c;
void Input()
{
    cin >> a >> b >> c;
}
void Solve()
{
    if(a < b) swap(a, b);
    if(a == b) cout << 0;
    else
    {
        int ans = 0;
        while(a > b)
        {
            a -= c;
            b += c;
            ans++;
        }
        cout << ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen(taskname".INP", "r", stdin);
//    freopen(taskname".OUT", "w", stdout);
    int t; cin >> t;
    while(t--) { Input(); Solve(); cout << endl; };
//    Input();
//    Solve();
}
