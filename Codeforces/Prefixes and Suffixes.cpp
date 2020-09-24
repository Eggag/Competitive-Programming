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

bool cmp(pair<string, int> a, pair<string, int> b){
	return a.fi.size() < b.fi.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<string, int>> s(2 * n - 2);
	rep(i, 2 * n - 2) cin >> s[i].fi, s[i].se = i;
	sort(all(s), cmp);
	rep(i, 2){
		string pref = s[2 * n - 3].fi;
		string suf = s[2 * n - 4].fi;
		if(i == 1) swap(pref, suf);
		reverse(all(suf));
		vector<char> ans(2 * n - 2);
		map<string, int> vis;
		int f = 1;
		rep(j, 2 * n - 2){
			string ltl = pref.substr(0, s[j].fi.size());
			string sm = suf.substr(0, s[j].fi.size());
			string cur = s[j].fi;
			reverse(all(cur));
			if(ltl == s[j].fi && !vis[ltl]){
				ans[s[j].se] = 'P';
				vis[ltl] = 1;
			}
			else if(sm == cur){
				ans[s[j].se] = 'S';
			}
			else f = 0;
		}
		if(f){
			rep(k, ans.size()) cout << ans[k];
			cout << endl;
			return 0;
		}
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
