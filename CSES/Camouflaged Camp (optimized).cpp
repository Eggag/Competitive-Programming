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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN][mxN];
int sum[mxN][mxN];

int sm(int l, int r, int l1, int r1){
	return (sum[l1][r1] - (l ? sum[l - 1][r1] : 0) - (r ? sum[l1][r - 1] : 0) + ((l && r) ? sum[l - 1][r - 1] : 0));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int r, c;
	cin >> r >> c;
	rep(i, r) rep(j, c) cin >> g[i][j];
	rep(i, r){
		sum[i][0] = g[i][0];
		repn(j, 1, c) sum[i][j] = (sum[i][j - 1] + g[i][j]);
	}
	rep(j, c){
		repn(i, 1, r) sum[i][j] += sum[i - 1][j];
	}
	int l, w;
	cin >> l >> w;
	int h;
	cin >> h;
	vector<array<int, 6>> p;
	rep(i, h){
		array<int, 6> a;
		rep(j, 6) cin >> a[j];
		p.pb(a);
	}
	int mx = 0;
	pi bst = {0, 0};
	rep(i, r - l + 1) rep(j, c - w + 1){
		int cnt = 0;
		rep(k, h){
			if((cnt + (h - k)) < mx) break;
			int x = i + p[k][0] - 1, y = j + p[k][1] - 1;
			int l1 = sm(x, y, x + p[k][2] - 1, y + p[k][3] - 1);
			int r1 = 0;
			if(p[k][4]){
				x = i + p[k][0] - 1 + p[k][2], y = j + p[k][1] - 1;
				r1 = sm(x, y, x + p[k][2] - 1, y + p[k][3] - 1);
			}
			else{
				x = i + p[k][0] - 1, y = j + p[k][1] - 1 + p[k][3];
				r1 = sm(x, y, x + p[k][2] - 1, y + p[k][3] - 1);
			}
			if(p[k][5]){
				if(l1 >= r1) cnt++;
			}
			else{
				if(l1 < r1) cnt++;
			}
		}
		if(cnt > mx){
			mx = cnt;
			bst = {i + 1, j + 1};
		}
		if(cnt == h) break;
	}
	cout << bst.fi << " " << bst.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
