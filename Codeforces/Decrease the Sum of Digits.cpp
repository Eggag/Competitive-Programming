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

string to_st(ll n){
	string ret = "";
	while(n){
		ret += (char)((n % 10) + '0');
		n /= 10;
	}
	return ret;
}

ll to_ll(string s){
	ll ret = 0LL;
	ll mult = 1LL;
	rep(i, s.size()){
		ret += (ll)(s[i] - '0') * mult;
		mult *= 10;
	}
	return ret;
}

void solve(){
	ll n;
	int d;
	cin >> n >> d;
	string s1 = to_st(n);
	int nm = 0;
	rep(i, s1.size()) nm += (s1[i] - '0');
	if(nm <= d){
		cout << 0 << endl;
		return;
	}
	string s2 = s1;
	rep(i, s1.size()){
		nm -= (s1[i] - '0');
		s2[i] = '0';
		if((nm + 1) <= d){
			if(i == (s1.size() - 1)) s2 += '1';
			else{
				int ind = i + 1;
				while(ind < (int)s1.size() && s2[ind] == '9') s2[ind] = '0', ind++;
				if(ind == (int)s1.size()) s2 += '1';
				else s2[ind]++;
			}
			break;
		}
	}
	ll nm1 = to_ll(s2) - n;
	cout << nm1 << endl;
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
