#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	ll n, m;
	cin >> n >> m;
	if(m > n){
		cout << 0 << endl;
		return;
	}
	vi cnt(10, 0);
	int end = 0;
	ll p = 0;
	ll cur = 0;
	ll sum = 0;
	while((cur + m) <= n){
		cur += m;
		end = cur % 10;
		if(cnt[end]) break;
		cnt[end] = 1;
		p++;
		sum += end;
	}
	ll ans = (n / (m * p)) * sum;
	if((n % (m * p)) != 0){
		ll st = n / (m * p);
		st *= (m * p);
		while((st + m) <= n){
			ans += (st + m) % 10;
			st += m;
		}
	}
	cout << ans << endl;
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
