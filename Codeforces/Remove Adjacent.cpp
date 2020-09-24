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

int mn = 1e9;

void dfs(string s, char cur){
	//debug2(s, cur);
	if(cur == 'a'){
		mn = s.size();
		return;
	}
	int n = (int)s.size();
	vi vis(n, 0);
	string s1 = s;
	int f = 1;
	while(f){
		int nm = 0;
		vi vis(n, 0);
		rep(i, s1.size()) if(s1[i] == cur){
			if(i > 0 && (s1[i - 1]) == (s1[i] - 1)){
				vis[i] = 1, nm++;
				break;
			}
			if(i < (n - 1) && (s1[i + 1]) == (s1[i] - 1)){
				vis[i] = 1, nm++;
				break;
			}
		}
		if(!nm) break;
		string s2 = "";
		rep(i, s1.size()) if(!vis[i]) s2 += s1[i];
		s1 = s2;
	}
	dfs(s1, cur - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	dfs(s, 'z');
	cout << n - mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
