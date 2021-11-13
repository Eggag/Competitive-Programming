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

vi g[26];
vi g1[26][26];
int cnt[26][26];
int g2[26][26][26];

string query(string a){
	cout << "? " << a << endl;
	string ret;
	cin >> ret;
	return ret;
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string t;
	cin >> t;
	int n = (int)(t.size());
	string q = "";
	rep(i, n){
		char c = (char)('a' + (i % 26));
		q += c;
	}
	string r = query(q);
	rep(i, n) g[(int)(r[i] - 'a')].pb(i);
	string q1 = "";
	rep(i, n){
		char c = (char)('a' + (i / 26) % 26);
		q1 += c;
	}
	string r1 = query(q1);
	rep(i, 26){
		for(int p : g[i]){
			g1[i][r1[p] - 'a'].pb(p);
		}
	}
	string q2 = "";
	rep(i, n){
		int nm = cnt[q[i] - 'a'][q1[i] - 'a']++;
		char c = (char)('a' + (nm % 26));
		q2 += c;
	}
	string r2 = query(q2);
	memset(g2, -1, sizeof(g2));
	rep(i, 26) rep(j, 26){
		for(int p : g1[i][j]){
			assert(g2[i][j][r2[p] - 'a'] == -1);
			g2[i][j][r2[p] - 'a'] = p;
		}
	}
	vi m(n, 0);
	rep(i, n){
		int a = (int)(q[i] - 'a'), b = (int)(q1[i] - 'a'), c = (int)(q2[i] - 'a');
		m[g2[a][b][c]] = i;
	}
	string ans = string(n, 'a');
	rep(i, n) ans[m[i]] = t[i];
	cout << "! " << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
