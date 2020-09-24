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

bool good(ll nm){
	string cr = "";
	ll n1 = nm;
	while(n1){
		cr += (char)((n1 % 10) + '0');
		n1 /= 10;
	}
	reverse(all(cr));
	int n = cr.size();
	rep(i, n) repn(j, i + 1, n){
		if(cr[j] < cr[i]) return 0;
	}
	return 1;
}

string solve(){
	ll n;
	cin >> n;
	string s = "";
	ll n1 = n;
	while(n1){
		s += (char)((n1 % 10) + '0');
		n1 /= 10;
	}
	reverse(all(s));
	int f = 1;
	int cn1 = 0;
	rep(i, s.size()){
		if(s[i] == '0' && !cn1){
			f = 0;
			break;
		}
		if(s[i] > '1') cn1 = 1;
	}
	string ans = "";
	if(!f){
		rep(i, s.size() - 1) ans += '9';
	}
	else{
		if(good(n)) return s;
		int mx = 0;
		repn(i, 1, s.size()){
			if(s[i - 1] > '1'){
				int ps = 1;
				rep(j, i + 1) repn(k, j + 1, i + 1){
					if(s[k] < s[j]) ps = 0;
				}
				if(!ps){
					mx = i - 1;
					break;
				}
			}
		}
		int cr = mx;
		while(cr >= 0 && s[cr] == s[mx]) cr--;
		cr++;
		mx = cr;
		rep(i, s.size()){
			if(i == mx) s[i]--;
			if(i > mx) s[i] = '9';
		}
		return s;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1) cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
