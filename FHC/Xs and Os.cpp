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
	int bst = 1e9, num = 0;
	rep(i, n){
		int cnt = 0, f = 1;
		rep(j, n){
			if(s[i][j] == 'O') f = 0;
			if(s[i][j] == '.') cnt++;
		}
		if(f && cnt == bst) num++;
		if(f && cnt < bst){
			bst = cnt;
			num = 1;
		}
	}
	rep(j, n){
		int cnt = 0, f = 1;
		rep(i, n){
			if(s[i][j] == 'O') f = 0;
			if(s[i][j] == '.') cnt++;
		}
		if(f && cnt == bst) num++;
		if(f && cnt < bst){
			bst = cnt;
			num = 1;
		}
	}
	if(bst == 1){
		vector<vi> v(n, vi(n, 0));
		int num1 = 0;
		rep(i, n){
			int cnt = 0, f = 1, p = -1;
			rep(j, n){
				if(s[i][j] == 'O') f = 0;
				else if(s[i][j] == '.') cnt++, p = j;
			}
			if(cnt == 1 && f){
				num1 += 1 - v[i][p];
				v[i][p] = 1;
			}
		}
		rep(j, n){
			int cnt = 0, f = 1, p = -1;
			rep(i, n){
				if(s[i][j] == 'O') f = 0;
				else if(s[i][j] == '.') cnt++, p = i;
			}
			if(cnt == 1 && f){
				num1 += 1 - v[p][j];
				v[p][j] = 1;
			}
		}
		num = num1;
	}
	if(bst == 1e9) cout << "Impossible\n";
	else cout << bst << ' ' << num << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
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
