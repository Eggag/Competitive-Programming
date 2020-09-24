#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	ll w = 0;
	repn(i, 1, s.size()){
		if((s[i] == s[i - 1]) && s[i] == 'v') w++;	
	}
	vi z;
	rep(i, n){
		if(s[i] == 'o') z.pb(i);
	}
	if(!z.size()){
		cout << 0 << endl;
		return 0;
	}
	ll ind = 0;
	ll cur = 0;
	vector<ll> r(z.size(), 0), l(z.size(), 0);
	repn(i, 1, n){
		if(s[i] == 'o'){
			r[ind] = w - cur;
			l[ind] = cur;
			ind++;
		}
		else{
			if(s[i - 1] == s[i] && s[i] == 'v') cur++;
		}
	}
	ll ans = 0;
	rep(i, z.size()){
		ans += r[i] * l[i];
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
