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
	cin >> n;
	string s;
	cin >> s;
	//find the best first letter, if there is an a, choose it
	//there can be several options
	string best = "";
	int mx = -1;
	rep(i, n){
		string bg = s.substr(i, n - i);
		string en = s.substr(0, i);
		if(((n - i)) % 2 != 0) reverse(all(en));
		string cur = bg + en;
		if(mx == -1 || cur < best){
			best = cur;
			mx = i;
		}
	}
	cout << best << endl;
	cout << mx + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	/*
	string s;
	cin >> s;
	repn(k, 1, 6){
		rep(i, s.size() - k + 1){
			reverse(s.begin() + i, s.begin() + i + k);
		}
		debug2(k, s);
	}
	*/
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
