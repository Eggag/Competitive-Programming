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
	vector<ll> cnt(30, 0);
	ll ans = 0;
	rep(i, s.size()){
		int ind = (int)(s[i] - 'a');
		cnt[ind]++;
		ans = max(cnt[ind], ans);
	}
	for(char i = 'a'; i <= 'z'; i++){
		for(char j = 'a'; j <= 'z'; j++){
			ll cur = 0;
			ll cnt1 = 0;
			rep(k, s.size()){
				if(s[k] == i) cnt1++;
				if(s[k] == j) cur += cnt1 - (i == j);
			}		
			ans = max(ans, cur); 
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
