#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<string> solve(){
	int n, k;
	ll v;
	cin >> n >> k >> v;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<string> ans;
	vi vis(n);
	rep(i, n) vis[i] = 0;
	int pos = ((v - 1) * k) % n;
	rep(i, k){
		vis[pos] = 1;
		pos = (pos + 1) % n;
	}
	rep(i, n) if(vis[i]){
		ans.pb(s[i]);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("tourist.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	repn(i, 1, q + 1){
		cout << "Case #" << i << ":";
		vector<string> res = solve();
		for(string s : res){
			cout << " " << s;
		}
		cout << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
