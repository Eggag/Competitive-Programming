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

//use those to create the prefix sums
int up[1005][1005]; //if we are at (1, 11) -> all trees from (1, 0) to(1, 11)
int le[1005][1005]; //same but for left
int rect[1005][1005];
char s[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	//fun problem!!!
	//I think I can do prefix sums (2D lol)
	memset(up, 0, sizeof(up));
	memset(le, 0, sizeof(le));
	memset(rect, 0, sizeof(rect));
	repn(i, 1, n + 1) repn(j, 1, n + 1) cin >> s[i][j];
	up[1][1] = (s[1][1] == '*');
	le[1][1] = (s[1][1] == '*');
	repn(i, 1, n + 1) repn(j, 1, n + 1){
		if(i == 1 && j == 1) continue;
		up[i][j] = up[i - 1][j] + (s[i][j] == '*');
		le[i][j] = le[i][j - 1] + (s[i][j] == '*');
	}
	rect[1][1] = up[1][1] + le[1][1] - (s[1][1] == '*');
	repn(i, 1, n + 1) repn(j, 1, n + 1){
		if(i == 1 && j == 1) continue;
		if(i != 1 && j != 1) rect[i][j] = rect[i - 1][j - 1] + le[i][j] + up[i][j] - (s[i][j] == '*'); //take care of double counting
		else if(i != 1) rect[i][j] = rect[i - 1][j] + le[i][j];
		else rect[i][j] = rect[i][j - 1] + up[i][j];
	}
	rep(i, q){
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		//x--, y--, x1--, y1--;
		int ans = rect[x1][y1] - (rect[x1][y - 1] + rect[x - 1][y1]) + rect[x - 1][y - 1];
		cout << ans << endl;
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
