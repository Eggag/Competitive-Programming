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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	ll ans = 0;
	vector<ll> cnt(h, 0), cnt1(w, 0);
	for(int i = h - 1; i >= 0; i--){
		for(int j = w - 1; j >= 0; j--){
			if(s[i][j] == 'O') cnt[i]++;
			if(s[i][j] == 'I') cnt1[j]++;
			if(s[i][j] == 'J') ans += (ll)(cnt[i] * cnt1[j]);
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