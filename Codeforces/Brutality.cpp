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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	string s;
	cin >> s;
	ll ans = 0;
	vi cur1 = {a[0]};
	repn(i, 1, n){
		if(s[i] == s[i - 1]){
			cur1.pb(a[i]);
		}
		else{
			sort(all(cur1));
			reverse(all(cur1));
			rep(i, min(k, (int)cur1.size())) ans += cur1[i];
			cur1.clear();
			cur1.pb(a[i]);
		}
	}
	sort(all(cur1));
	reverse(all(cur1));
	rep(i, min(k, (int)cur1.size())) ans += cur1[i];
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
