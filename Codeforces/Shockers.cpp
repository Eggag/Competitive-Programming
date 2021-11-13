#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
	int ans = 0, cnt = 26;
	vi gd(26, 0), bd(26, 0);
	int f = 0, nm = 0;
	rep(i, n){
		if(!f){
			if(cnt == 1) f = 1;
			int cnt1 = 0;
			rep(j, 26) if(bd[j] == nm && !gd[j]) cnt1++;
			if(cnt1 == 1) f = 1;
		}
		char c;
		cin >> c;
		if(c == '.'){
			string w;
			cin >> w;
			rep(j, w.size()) if(!gd[w[j] - 'a']) gd[w[j] - 'a'] = 1, cnt--;
		}
		else if(c == '!'){
			string w;
			cin >> w;
			vi bd1(26, 0);
			rep(j, w.size()) bd1[w[j] - 'a'] = 1;
			rep(j, 26) bd[j] += bd1[j];
			nm++;
			if(f) ans++;
		}
		else{
			char c1;
			cin >> c1;
			if(i == (n - 1)) continue;
			if(!gd[c1 - 'a']){
				gd[c1 - 'a'] = 1;
				cnt--;
			}
			if(f) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
