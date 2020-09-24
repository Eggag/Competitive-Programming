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
	int n;
	ll k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll cnt = 0;
	vector<pair<int, ll>> pos;
	rep(i, n){
		if(s[i] == '0'){
			pos.pb(mp(i, cnt));
		}
		else cnt++;
	}
	rep(i, pos.size()){
		if(!k) break;
		if(k >= pos[i].se){
			if(pos[i].fi != i) swap(s[pos[i].fi], s[i]); //end of pref
			k -= pos[i].se;
		}
		else{
			if(k) swap(s[pos[i].fi], s[pos[i].fi - k]);
			break;
		}
	}
	cout << s << endl;

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
