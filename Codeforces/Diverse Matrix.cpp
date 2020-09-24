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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int r, c;
	cin >> r >> c;
	if(r == 1 && c == 1){
		cout << 0 << endl;
		return 0;
	}
	int sw = 0;
	if(r < c) swap(r, c), sw = 1;
	int ans[r + 5][c + 5];
	int cnt = 2;
	rep(i, r){
		ans[i][0] = cnt;
		cnt++;
	}
	int num = r + 2;
	rep(i, r){
		int num1 = num;
		repn(j, 1, c){
			ans[i][j] = ans[i][0] * num1;
			num1++;
		}
	}
	if(sw){
		rep(j, c){
			rep(i, r) cout << ans[i][j] << " ";
			cout << endl;
		}
	}
	else{
		rep(i, r){
			rep(j, c) cout << ans[i][j] << " ";
			cout << endl;
		}
	}
	/*
	rep(i, r){
		int g = 0;
		rep(j, c) g = gcd(g, ans[i][j]);
		debug(g);
	}
	rep(j, c){
		int g = 0;
		rep(i, r) g = gcd(g, ans[i][j]);
		debug(g);
	}
	*/
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
