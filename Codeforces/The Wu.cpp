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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int num[mxN];
int ans[mxN][105];
int val[mxN][mxN];

int to_int(string s){
	int tot = 0;
	rep(i, s.size()) if(s[i] == '1') tot += (1 << i);
	return tot;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	vi w(n);
	rep(i, n) cin >> w[i];
	rep(i, m){
		string s;
		cin >> s;
		num[to_int(s)]++;
	}
	rep(i, (1 << n)){
		repn(j, i, (1 << n)){
			int nm = 0;
			rep(k, n) nm += ((i & (1 << k)) == (j & (1 << k)) ? w[k] : 0);
			val[i][j] = val[j][i] = nm;
		}
	}
	rep(i, (1 << n)){
		rep(j, (1 << n)) if(num[j]){
			if(val[i][j] <= 100){
				ans[i][val[i][j]] += num[j];
			}
		}
	}
	rep(i, (1 << n)) repn(j, 1, 105) ans[i][j] += ans[i][j - 1];
	rep(i, q){
		string t;
		int k;
		cin >> t >> k;
		int cr = to_int(t);
		cout << ans[cr][k] << "\n";
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
