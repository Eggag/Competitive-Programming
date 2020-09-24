#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[6][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 6){
		rep(j, 4) cin >> a[i][j];
	}
	vi s(6, 0);
	rep(i, 6){
		int col = a[i][0];
		s[i] = 1;
		repn(j, 1, 4) if(a[i][j] != col){
			s[i] = 0;
			break;
		}
	}
	if(!((s[0] && s[2]) || (s[3] && s[4]) || (s[0] && s[2] && s[3] && s[4] && s[5] && s[6]) || (s[1] && s[5]))){
		cout << "NO" << endl;
		return 0;
	}
	if(s[0] && s[2]){
		int f = 0;
		if(a[3][2] == a[1][0] && a[3][3] == a[1][1] && a[1][2] == a[4][0] &&
			a[1][3] == a[4][1] && a[4][2] == a[5][0] && a[4][3] == a[5][1] && 
			a[5][2] == a[3][0] && a[5][3] == a[3][1]) f = 1;
		if(a[3][0] == a[1][2] && a[3][1] == a[1][3] && a[1][0] == a[4][2] && 
			a[1][1] == a[4][3] && a[4][0] == a[5][2] && a[4][1] == a[5][3] &&
			a[5][0] == a[3][2] && a[5][1] == a[3][3]) f = 1;
		if(f){
			cout << "YES" << endl;
			return 0;
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	if(s[3] && s[4]){
		int f = 0;
		if(a[0][0] == a[1][1] && a[0][2] == a[1][3] && a[1][0] == a[2][1] &&
			a[1][2] == a[2][3] && a[2][0] == a[5][0] && a[2][2] == a[5][2] &&
			a[0][1] == a[5][1] && a[0][3] == a[5][3]) f = 1;
		if(a[0][1] == a[1][0] && a[0][3] == a[1][2] && a[1][1] == a[2][0] &&
			a[1][3] == a[2][2] && a[2][1] == a[5][1] && a[2][3] == a[5][3] &&
			a[0][0] == a[5][0] && a[0][2] == a[5][2]) f = 1;
		if(f){
			cout << "YES" << endl;
			return 0;
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	if(s[1] && s[5]){
		int f = 0;
		if(a[4][0] == a[0][0] && a[4][2] == a[0][1] && a[0][2] == a[3][0] &&
			a[0][3] == a[3][2] && a[3][1] == a[2][2] && a[3][3] == a[2][3] &&
			a[2][0] == a[4][1] && a[2][1] == a[4][3]) f = 1;
		if(a[4][1] == a[0][2] && a[4][3] == a[0][3] && a[0][0] == a[3][1] &&
			a[0][1] == a[3][3] && a[3][0] == a[2][0] && a[3][2] == a[2][1] &&
			a[2][2] == a[4][0] && a[2][3] == a[4][2]) f = 1;
		if(f){
			cout << "YES" << endl;
			return 0;
		}
		else{
			cout << "NO" << endl;
			return 0;
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
