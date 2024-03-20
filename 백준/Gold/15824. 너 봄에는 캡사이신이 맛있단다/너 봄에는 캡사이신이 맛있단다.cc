#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    ll arr[300005];
    ll two[300005];
    ll MOD = 1'000'000'007;
    ll temp = 1;
    ll p=0, m=0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n; i++) {
        two[i] = temp-1;
        temp*=2;
        temp%=MOD;
    }

    sort(arr, arr+n);

    for (int i=n-1; i>0; i--) {
        p += two[i] * arr[i];
        m += two[i] * arr[n-1-i];
        p%=MOD;
        m%=MOD;
    }
    cout << (p%MOD + MOD - m%MOD) % MOD << '\n';
}