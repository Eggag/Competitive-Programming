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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int trie[mxN][30], cnt = 0;
int a[mxN], b[mxN];

void addWord(string s, int f){
	int rt = 0;
	int n = s.size();
	rep(i, n){
		int cur = s[i] - 'a';
		if(!trie[rt][cur]) trie[rt][cur] = ++cnt;
		rt = trie[rt][cur];
	}
	if(!f) a[rt]++;
	else b[rt]++;
}

int dp[mxN];
int d[mxN], d1[mxN];

void dfs(int cur, int f){
	if(a[cur]) d[cur]++;
	if(b[cur]) d1[cur]++;
	rep(i, 26) if(trie[cur][i]){
		dfs(trie[cur][i], f ^ 1);
		d[cur] += d[trie[cur][i]];
		d1[cur] += d1[trie[cur][i]];
	}
	if(d[cur] && !d1[cur]){
		dp[cur] = 1;
		return;
	}
	if(!d[cur] && d1[cur]){
		dp[cur] = 2;
		return;
	}
	int dr = 0;
	rep(i, 26) if(trie[cur][i]){
		int x = trie[cur][i];
		if(!f){
			if((d[x] && !d1[x]) || dp[x] == 1){
				dp[cur] = 1;
				return;
			}
		}
		else{
			if((!d[x] && d1[x]) || dp[x] == 2){
				dp[cur] = 2;
				return;
			}
		}
		if(!dp[x]) dr++;
	}
	if(!f && !dr) dp[cur] = 2;
	if(f && !dr) dp[cur] = 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n){
		cin >> s[i];
		addWord(s[i], 0);
	}
	int m;
	cin >> m;
	vector<string> t(m);
	rep(i, m){
		cin >> t[i];
		addWord(t[i], 1);
	}
	dfs(0, 0);
	if(!dp[0]) cout << "Draw" << '\n';
	if(dp[0] == 1) cout << "Nina" << '\n';
	if(dp[0] == 2) cout << "Emilija" << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
