#include <bits/stdc++.h>
#define task ""
#define int ll
#define ff first
#define ss second
using namespace std;
using ld = long double;
using ull = unsigned long long;
using ll = long long;
using pll = pair <ll, ll>;
using pii = pair <int, int>;
const char el = '\n';
const char sp = ' ';
const ll inf = 1e9; //1e18;
const ll maxN = 1e5 + 5;
const ll logA = 22;
int n;

struct Tsegmentree
{
    struct Tnode
    {
        int cnt0, cnt1, lazy;

        Tnode()
        {
            cnt0 = 1;
            cnt1 = lazy = 0;
        }
    } st[4 * maxN];

    void push(int id)
    {
        if (!st[id].lazy) return;
        st[id].lazy = 0;
        swap(st[id << 1].cnt0, st[id << 1].cnt1);
        st[id << 1].lazy ^= 1;
        swap(st[id << 1 | 1].cnt0, st[id << 1 | 1].cnt1);
        st[id << 1 | 1].lazy ^= 1;
    }

    void build(int id = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            st[id].cnt0 = 1;
            return;
        }
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id].cnt0 = st[id << 1].cnt0 + st[id << 1 | 1].cnt0;
    }

    void update(int u, int v, int id = 1, int l = 1, int r = n)
    {
        if (l > r || l > v || r < u) return;
        if (u <= l && r <= v)
        {
            swap(st[id].cnt0, st[id].cnt1);
            st[id].lazy ^= 1;
            return;
        }
        push(id);
        int mid = l + r >> 1;
        update(u, v, id << 1, l, mid);
        update(u, v, id << 1 | 1, mid + 1, r);
        st[id].cnt0 = st[id << 1].cnt0 + st[id << 1 | 1].cnt0;
        st[id].cnt1 = st[id << 1].cnt1 + st[id << 1 | 1].cnt1;
    }

    int get(int u, int v, int id = 1, int l = 1, int r = n)
    {
        if (l > r || l > v || r < u) return 0;
        if (u <= l && r <= v) return st[id].cnt1;
        push(id);
        int mid = l + r >> 1;
        return get(u, v, id << 1, l, mid) + get(u, v, id << 1 | 1, mid + 1, r);
    }
} st[logA];

void add(int l, int r, int x)
{
    for (int i = 0;i < logA;++i)
        if (x >> i & 1) st[i].update(l, r);
}

ll get(int l, int r)
{
    ll res = 0;
    for (int i = 0;i < logA;++i)
        res += (1 << i) * st[i].get(l, r);
    return res;
}

int32_t main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 0;i < logA;++i)
        st[i].build();
    for (int i = 1;i <= n;++i)
    {
        ll x;
        cin >> x;
        add(i, i, x);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int type, l, r, x;
        cin >> type;
        if (type == 2)
        {
            cin >> l >> r >> x;
            add(l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << get(l, r) << el;
        }
    }
}
