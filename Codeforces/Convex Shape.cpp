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

int vert[55][55], hor[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, n){
		hor[i][0] = (s[i][0] == 'B');
		repn(j, 1, m){
			if(s[i][j] == 'B') hor[i][j] = hor[i][j - 1] + 1;
			else hor[i][j] = 0;
		}
	}
	rep(j, m){
		vert[j][0] = (s[0][j] == 'B');
		repn(i, 1, n){
			if(s[i][j] == 'B') vert[j][i] = vert[j][i - 1] + 1;
			else vert[j][i] = 0;
		}
	}
	rep(i, n) rep(j, m) rep(k, n) rep(l, m) if(s[i][j] == 'B' && s[k][l] == 'B'){
		int f = 0;
		if(j < l){
			if(i > k){
				if(hor[k][l] >= (l - j + 1) && vert[j][i] >= (i - k + 1)) f = 1;
				if(hor[i][l] >= (l - j + 1) && vert[l][i] >= (i - k + 1)) f = 1;
			}
			else{
				if(hor[i][l] >= (l - j + 1) && vert[l][k] >= (k - i + 1)) f = 1;
				if(hor[k][l] >= (l - j + 1) && vert[j][k] >= (k - i + 1)) f = 1;
			}
		}
		else{
			if(i > k){
				if(hor[k][j] >= (j - l + 1) && vert[j][i] >= (i - k + 1)) f = 1;
				if(hor[i][j] >= (j - l + 1) && vert[l][i] >= (i - k + 1)) f = 1;
			}
			else{
				if(hor[i][j] >= (j - l + 1) && vert[l][k] >= (k - i + 1)) f = 1;
				if(hor[k][j] >= (j - l + 1) && vert[j][k] >= (k - i + 1)) f = 1;
			}
		}
		if(!f){
			//debug2(i, j);
			//debug2(k, l);
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
