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
	vector<vi> ans;
	while(true){
		vi suf((int)s.size(), 0);
		suf[(int)s.size() - 1] = (s[(int)s.size() - 1] == ')');
		for(int i = (int)s.size() - 2; i >= 0; i--) suf[i] = suf[i + 1] + (s[i] == ')');
		vi cur;
		vi v((int)s.size(), 0);
		int mx = 0;
		rep(i, s.size()){
			if(s[i] == '(' && suf[i] >= ((int)cur.size() + 1)) cur.pb(i), v[i] = 1, mx = max(mx, i);
		}
		int k = (int)cur.size();
		for(int i = (int)s.size() - 1; i > mx; i--){
			if(!k) break;
			if(s[i] == ')') v[i] = 1, k--, cur.pb(i);
		}
		string s1 = "";
		rep(i, s.size()) if(!v[i]) s1 += s[i];
		s = s1;
		if((int)cur.size()) ans.pb(cur);
		else break;
		if(!s.size()) break;
	}
	cout << (int)ans.size() << endl;
	rep(i, ans.size()){
		cout << (int)ans[i].size() << endl;
		sort(all(ans[i]));
		rep(j, ans[i].size()) cout << ans[i][j] + 1 << " ";
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
