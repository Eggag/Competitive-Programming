#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> v(n + 1), t(n + 1);
	repn(i, 1, n + 1) cin >> v[i];
	repn(i, 1, n + 1) cin >> t[i];
	vector<ll> sum(n + 1, 0);
	repn(i, 1, n + 1){
		sum[i] = sum[i - 1] + t[i];
	}
	vi cnt(n + 2, 0);
	vector<ll> add(n + 2, 0);
	repn(i, 1, n + 1){
		int pos = upper_bound(all(sum), (v[i] + sum[i - 1])) - sum.begin();	
		if((sum[pos - 1] - sum[i - 1]) < v[i] && (pos - 1) < n) add[pos] += v[i] - (sum[pos - 1] - sum[i - 1]);
		cnt[i]++, cnt[pos]--;
	}
	repn(i, 1, n + 1) cnt[i] += cnt[i - 1];
	repn(i, 1, n + 1) cout << (ll)(add[i] + (ll)(cnt[i] * (t[i]))) << " \n"[i == n];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
