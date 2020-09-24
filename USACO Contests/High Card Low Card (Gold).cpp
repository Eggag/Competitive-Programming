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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	int n;
	cin >> n;
	map<int, int> v;
	vi a(n), b;
	rep(i, n) cin >> a[i], v[a[i]] = 1;
	int mx = 0;
	repn(i, 1, (2 * n) + 1) if(!v[i]) b.pb(i), mx = max(mx, i);
	//for the first half, if we can win, use the lowest card to do that,
	//otherwise use a card that will definitely not be used
	vi pos;
	rep(i, (n / 2)) if(a[i] < mx) pos.pb(a[i]);
	sort(all(pos));
	reverse(all(pos));
	int ans = 0;
	rep(i, pos.size()){
		if(b[(int)b.size() - 1] > pos[i]){
			b.pop_back();
			ans++;
		}
	}
	vi sm;
	repn(i, (n / 2), n) sm.pb(a[i]);
	sort(all(sm));
	reverse(all(b));
	rep(i, sm.size()){
		if(b[(int)b.size() - 1] < sm[i]){
			ans++;
			b.pop_back();
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
