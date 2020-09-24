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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

unordered_map<int, int> m[mxN];
int ans[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	rep(i, k){
		int pos, l, d;
		cin >> pos >> l >> d;
		pos--;
		if(l > 5e3){
			m[pos][d]++, ans[pos]++;
			m[pos + (l - 1) * d][d]--;
		}
		else{
			for(int j = pos; j <= (pos + (l - 1) * d); j += d) ans[j]++;
		}
	}
	rep(i, n){
		for(pi x : m[i]) if(x.se){
			m[x.fi + i][x.fi] += x.se;
			ans[x.fi + i] += x.se;
		}
		m[i].clear();
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
