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
	string s;
	cin >> s;
	vi p;
	int prev = 0;
	int cnt = 0;
	rep(i, s.size()){
		if(s[i] == 'R'){
			cnt++;
			p.pb(i + 1 - prev);
			prev = i + 1;
		}
	}
	p.pb((int)s.size() - prev + 1);
	sort(all(p));
	reverse(all(p));
	int mx = p[0];
	int l = 0, r = 2e5 + 10;
	while(l < r){
		int mid = (l + r) / 2;
		if(mid >= mx) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
