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

void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int ans = 0;
	repn(i, 1, n) if(s[i].size() <= s[i - 1].size()){
		int f = 2;
		rep(j, s[i].size()){
			if(s[i][j] < s[i - 1][j]){
				f = 0;
				break;
			}
			if(s[i][j] > s[i - 1][j]){
				f = 1;
				break;
			}
		}
		if(f == 2){
			if(s[i].size() < s[i - 1].size()){
				int m = s[i - 1].size();
				int f1 = 0, lst = 0;
				for(int j = (int)(s[i].size()); j < m; j++){
					if(s[i - 1][j] != '9'){
						f1 = 1;
						lst = j;
					}
				}
				if(f1){
					for(int j = (int)(s[i].size()); j < m; j++){
						if(j < lst) s[i] += s[i - 1][j];
						else if(j == lst) s[i] += (char)(s[i - 1][j] + 1);
						else s[i] += '0';
						ans++;
					}
					goto en;
				}
			}
		}
		if(f != 1) while(s[i].size() < (s[i - 1].size() + 1)) s[i] += '0', ans++;
		else{
			while(s[i].size() < s[i - 1].size()) s[i] += '0', ans++;
		}
		en:;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
