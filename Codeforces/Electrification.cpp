#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

void solve(){
	int n, k;
	cin >> n >> k;
	ll a[n];
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	ll res = 0;
	ll mini = 1e18;
	rep(i, n - k){
		ll cur = (a[i + k] - a[i] + 1) / 2;
		if(cur < mini){
			mini = cur;
			res = (a[i + k] + a[i]) / 2;
		}
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
