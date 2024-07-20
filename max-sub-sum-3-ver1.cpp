#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const int N = 10;

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> preSum(n + 1, 0);
    preSum[0] = 0;
    FOR(i, 0, n)
    {
        cin >> arr[i];
        preSum[i + 1] = preSum[i] + arr[i];
    }

    vector<ll> f(n);
    f[0] = LLONG_MIN;
    ll minn = preSum[0];
    ll ans = LLONG_MIN;
    ll anss = LLONG_MAX;
    ll ansss = LLONG_MIN;
    preSum.push_back(0);
    FOR(i, 1, n)
    {
        if (minn > preSum[i - 1])
            minn = preSum[i - 1];
        ans = max(ans, preSum[i] - minn);
        anss = min(anss, preSum[i] - ans);
        f[i] = max(f[i - 1], preSum[i + 1] - anss);
    }
    ll s = 0, mi = 0;
    for (int i = n - 1; i > 2; i--)
    {
        s += arr[i];
        ansss = max(ansss, f[i - 1] + s - mi);
        mi = min(mi, s);
    }

    cout << ansss << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}