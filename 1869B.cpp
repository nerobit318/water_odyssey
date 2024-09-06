#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
#define int long long
#define sp " "
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, k, a, b;
const int INF = 1e18;
struct coordinate
{
    int ox, oy;
} x[N];
int f(int i, int j)
{
    return abs(x[i].ox - x[j].ox) + abs(x[i].oy - x[j].oy);
}
void Input()
{
    cin >> n >> k >> a >> b;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x[i].ox >> x[i].oy;
    }
}
void Solve()
{
    ll vt, vp;
    vt = vp = INF;
    for(int i = 1; i <= k; ++i)
    {
        vt = min(vt, f(i, a));
        vp = min(vp, f(i, b));
    }
    cout << min(f(a, b), vt + vp);
}
int32_t main()
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
