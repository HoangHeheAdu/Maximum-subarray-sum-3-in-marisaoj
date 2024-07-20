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

const ll inf = 2e18;
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

    ll minn = preSum[0];
    ll ans = LLONG_MIN;
    ll anss = LLONG_MAX;
    ll ansss = LLONG_MIN;
    ll anssss = LLONG_MAX;
    ll ansssss = LLONG_MIN;
    preSum.push_back(0);
    FOR(i, 1, n - 1)
    {
        minn = min(minn, preSum[i - 1]);
        ans = max(ans, preSum[i] - minn);
        anss = min(anss, preSum[i] - ans);
        ansss = max(ansss, preSum[i + 1] - anss);
        anssss = min(anssss, preSum[i + 1] - ansss);
        ansssss = max(ansssss, preSum[i + 2] - anssss);
    }
    cout << ansssss << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}