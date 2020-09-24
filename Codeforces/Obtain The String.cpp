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
	string s, t;
	cin >> s >> t;
	vi cnt(30, 0);
	vi pos[30];
	rep(i, s.size()){
		cnt[s[i] - 'a']++;
		pos[s[i] - 'a'].pb(i);
	}
	rep(i, t.size()) if(!cnt[t[i] - 'a']){
		cout << -1 << endl;
		return;
	}
	string z = "";
	int cur = -1;
	int ans = 1;
	while(z.size() != t.size()){
		int ind = (int)z.size();
		char c = t[ind];
		auto next = lb(all(pos[c - 'a']), cur + 1);
		if(next == pos[c - 'a'].end()){
			cur = -1;
			ans++;
			continue;
		}
		int curInd = (int)(next - pos[c - 'a'].begin());
		cur = pos[c - 'a'][curInd];
		z += c;
	}
	cout << ans << endl;
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
