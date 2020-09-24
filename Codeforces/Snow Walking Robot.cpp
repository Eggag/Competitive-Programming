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
	int l = 0, r = 0, u = 0, d = 0;
	rep(i, s.size()){
		if(s[i] == 'L') l++;
		if(s[i] == 'R') r++;
		if(s[i] == 'U') u++;
		if(s[i] == 'D') d++;
	}
	int l1 = min(l, r), r1 = l1;
	int u1 = min(u, d), d1 = u1;
	string ans = "";
	if(!l1){
		if(u1){
			cout << "2" << endl;
			cout << "UD" << endl;
			return;
		}
		cout << 0 << endl;
		return;
	}
	if(!u1){
		if(l1){
			cout << "2" << endl;
			cout << "LR" << endl;
			return;
		}
		cout << 0 << endl;
		return;
		
	}
	rep(i, u1) ans += 'U';
	rep(i, r1) ans += 'R';
	rep(i, d1) ans += 'D';
	rep(i, l1) ans += 'L';
	cout << ans.size() << endl;
	cout << ans << endl;
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
