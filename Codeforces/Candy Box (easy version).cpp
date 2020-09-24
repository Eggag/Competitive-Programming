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

void solve(){
	int n;
	cin >> n;
	vi cnt(n + 1);
	for(auto& x : cnt) x = 0;
	rep(i, n){
		int y;
		cin >> y;
		cnt[y]++;
	}
	vi ans;
	repn(i, 1, n + 1) if(cnt[i] != 0) ans.pb(cnt[i]);
	sort(all(ans));
	int ret = 0;
	int prev = ans[ans.size() - 1];
	ret += prev;
	for(int i = ans.size() - 2; i >= 0; i--){
		int c = min(ans[i], prev - 1);
		prev = c;
		ret += c;
		if(prev <= 0) break;
	}
	cout << ret << endl;
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
