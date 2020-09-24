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

int n, k;
int ans = 0;
int sz[10];

void solve(int k1, vector<string> s1){
	if(k1 == 0){
		int f1 = 1;
		rep(i, n) rep(j, n) if(s1[i][j] == 'O') f1 = 0;
		if(f1) ans++;
		return;
	}
	rep(i, n) rep(j, n) rep(o, 2) if(s1[i][j] != 'X' && s1[i][j] != 'A'){
		vector<string> s2 = s1;
		int l = sz[k1 - 1];
		if(o == 1 && i < (l - 1)) continue;
		if(o == 2 && j < (l - 1)) continue;
		if(l == 1 && o == 1) continue;
		int f = 1;
		if(o == 1){
			int i1 = i, j1 = j;
			while(l--){
				if(i1 < 0 || s2[i1][j1] == 'A' || s2[i1][j1] == 'X'){
					f = 0;
					break;
				}
				s2[i1][j1] = 'A';
				i1--;
			}
		}
		else{
			int i1 = i, j1 = j;
			while(l--){
				if(j1 < 0 || s2[i1][j1] == 'A' || s2[i1][j1] == 'X'){
					f = 0;
					break;
				}
				s2[i1][j1] = 'A';
				j1--;
			}
		}
		if(!f) continue;
		solve(k1 - 1, s2);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, k) cin >> sz[i];
	solve(k, s);
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
