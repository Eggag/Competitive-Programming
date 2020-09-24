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
	string s;
	cin >> s;
	int cnt = 1;
	vector<pair<char, int>> seg;
	repn(i, 1, s.size()){
		if(s[i] == s[i - 1]) cnt++;
		else{
			seg.pb(mp(s[i - 1], cnt));
			cnt = 1;
		}
	}
	seg.pb(mp(s[(int)s.size() - 1], cnt));
	if(seg.size() % 2 == 0){
		cout << 0 << endl;
		return 0;
	}
	int n = seg.size();
	rep(i, n / 2){
		if(seg[i].fi != seg[n - i - 1].fi || (seg[i].se + seg[n - i - 1].se) < 3){
			cout << 0 << endl;
			return 0;
		}
	}
	if(seg[n / 2].se >= 2) cout << seg[n / 2].se + 1 << endl;
	else cout << 0 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
