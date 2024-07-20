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
    vector<ll> arr(n + 1, 0);
    FOR(i, 1, n + 1) cin >> arr[i];
    partial_sum(arr.begin(), arr.end(), arr.begin());

    vector<ll> min_Value(3, inf);
    vector<ll> max_Value(4, -inf); max_Value[0] = 0;

    FOR(i, 1, n - 1) {
        FOR(j, 0, 3) {
            min_Value[j] = min(min_Value[j], arr[i + j - 1] - max_Value[j]);
            max_Value[j + 1] = max(max_Value[j + 1], arr[i + j] - min_Value[j]);
        }
    }
    cout << max_Value[3] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}