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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> s(n), s1(n);
	map<string, int> vis;
	rep(i, n) cin >> s[i] >> s1[i];
	vector<string> ans(n);
	rep(i, n){
		string res = "";
		for(int j = s[i].size() - 1; j >= 0; j--){
			for(int j1 = s1[i].size() - 1; j1 >= 0; j1--){
				string cur = s[i].substr(0, j + 1);
				string cur1 = s1[i].substr(0, j1 + 1);
				string cur2 = cur + cur1;
				if(cur2.size() > res.size() && !vis[cur2]){
					res = cur2;
				}
			}
		}
		if(!res.size()){
			cout << "No solution" << endl;
			return 0;
		}
		ans[i] = res;
		vis[res] = 1;
	}
	rep(i, n) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
