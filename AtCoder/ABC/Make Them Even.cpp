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

int a[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<vi> moves;
	vi gd(h, 0);
	rep(i, h){
		int cr = 0;
		rep(j, w){
			if(!cr){
				if(a[i][j] & 1) cr = 1;					
			}
			else{
				moves.pb({i, j - 1, i, j});
				if(a[i][j] & 1) cr = 0;
			}
		}
		if(cr) gd[i] = 1;
	}
	int cr1 = 0;
	rep(i, h){
		if(!cr1){
			if(gd[i]) cr1 = 1;
		}
		else{
			moves.pb({i - 1, w - 1, i, w - 1});
			if(gd[i] & 1) cr1 = 0;
		}
	}
	cout << moves.size() << endl;
	rep(i, moves.size()){
		rep(j, moves[i].size()){
			cout << moves[i][j] + 1;
			if(j == (moves[i].size() - 1)) cout << endl;
			else cout << " ";
		}
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
