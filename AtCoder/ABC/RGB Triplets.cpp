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

int cnt[4005][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0;
	vector<char> cr = {'R', 'G', 'B'};
	rep(i, 4005) rep(j, 3) cnt[i][j] = 0;
	rep(i, n){
		rep(j, i) if(s[i] != s[j]){
			if(s[j] == 'R') cnt[i][0]++;
			if(s[j] == 'G') cnt[i][1]++;
			if(s[j] == 'B') cnt[i][2]++;
			int k = j - (i - j), f = 0;
			int nw = 0;
			rep(m, 3){
				if(s[i] != cr[m] && s[j] != cr[m]){
					nw = m;
					break;
				}
			}
			if(k >= 0 && s[k] != s[j] && s[k] != s[i]) f = 1;
			ans += cnt[j][nw] - f;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
