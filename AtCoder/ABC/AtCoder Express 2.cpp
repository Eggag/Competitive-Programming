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

int num[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, 505) rep(j, 505) num[i][j] = 0;
	rep(i, m){
		int l, r;
		cin >> l >> r;
		num[l][r]++;
	}
	repn(i, 1, 501){
		repn(j, i + 1, 501){
			num[i][j] += num[i][j - 1];
		}
	}
	repn(i, 1, 501) repn(j, i, 501){
		repn(k, i + 1, j + 1) num[i][j] += num[k][j];
	}
	rep(i, q){
		int l, r;
		cin >> l >> r;
		cout << num[l][r] << endl;
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
