#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll mn = 1e9;
	rep(i, n) cin >> a[i], mn = min(mn, a[i]);
	vi pos;
	rep(i, n) if(a[i] == mn) pos.pb(i);
	sort(all(pos));
	ll bst = 0LL;
	rep(i, n){
		ll cur = n * mn;
		if(pos[pos.size() - 1] >= i){
			auto it = lb(all(pos), i);
			cur += *it - i;
		}
		else{
			cur += n - i;
			cur += pos[0];
		}
		bst = max(bst, cur);
	}
	cout << bst << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
