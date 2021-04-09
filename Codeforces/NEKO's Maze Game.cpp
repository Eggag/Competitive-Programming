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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char c[2][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	set<int> bd;
	rep(i, 2) rep(j, n) c[i][j] = '.';
	rep(i, q){
		int x, y;
		cin >> x >> y;
		x--, y--;
		if(!x){
			if(c[x][y] == '.'){
				if(y && c[x + 1][y - 1] == '#') bd.insert(y);
				if(c[x + 1][y] == '#') bd.insert(y);
				if(y < (n - 1) && c[x + 1][y + 1] == '#') bd.insert(y);
				c[x][y] = '#';
			}
			else{
				c[x][y] = '.';
				auto it = bd.find(y);
				if(it != bd.end()) bd.erase(it);
			}
		}
		else{
			if(c[x][y] == '.'){
				if(y && c[x - 1][y - 1] == '#') bd.insert(y - 1);
				if(c[x - 1][y] == '#') bd.insert(y);
				if(y < (n - 1) && c[x - 1][y + 1] == '#') bd.insert(y + 1);
				c[x][y] = '#';
			}
			else{
				c[x][y] = '.';
				for(int j = -1; j <= 1; j++){
					int y1 = y + j;
					if(y1 >= 0 && y1 < n){
						int cnt = (!y1) + (y1 == (n - 1));
						if(y1 && c[x][y1 - 1] == '.') cnt++;
						if(c[x][y1] == '.') cnt++;
						if(y1 < (n - 1) && c[x][y1 + 1] == '.') cnt++;
						if(cnt == 3){
							auto it = bd.find(y1);
							if(it != bd.end()) bd.erase(it);
						}
					}
				}
			}
		}
		cout << (bd.size() ? "No" : "Yes") << '\n';
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
