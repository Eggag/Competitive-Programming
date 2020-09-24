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

int n;
vector<string> s(2);
int f;

void dfs(int i, int j, int prev){
	if(i == 1 && j == (n - 1)){
		if(!f){
			int f1 = 0;
			if(prev == 1) if(s[i][j] == '1' || s[i][j] == '2') f1 = 1;
			if(prev == 4) if(!(s[i][j] == '1' || s[i][j] == '2')) f1 = 1;
			if(f1){
				cout << "YES" << endl;
				f = 1;
			}
		}
		return;
	}
	if(prev == 1){
		if(s[i][j] == '1' || s[i][j] == '2') dfs(i, j + 1, 1);
		else{
			if(!i) dfs(i + 1, j, 4);
			else dfs(i - 1, j, 5);
		}
	}
	if(prev == 4){
		if(!(s[i][j] == '1' || s[i][j] == '2')) dfs(i, j + 1, 1);
	}
	if(prev == 5){
		if(!(s[i][j] == '1' || s[i][j] == '2')) dfs(i, j + 1, 1);	
	}
}

void solve(){
	cin >> n;
	f = 0;
	rep(i, 2) cin >> s[i];
	dfs(0, 0, 1);
	if(!f) cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
