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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string model = "";
	rep(i, k - 1) model += "()";
	rep(i, (n - ((k - 1) * 2)) / 2) model += '(';
	rep(i, (n - ((k - 1) * 2)) / 2) model += ')';
	vector<pi> ans;
	rep(i, n){
		if(s[i] != model[i]){
			int r = i;
			repn(j, i + 1, n) if(s[j] == model[i]){
				r = j;
				break;
			}
			reverse(s.begin() + i, s.begin() + r + 1);
			ans.pb(mp(i, r));
		}
	}
	cout << (int)(ans.size()) << endl;
	for(pi x : ans) cout << x.fi + 1 << " " << x.se + 1 << endl;
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
