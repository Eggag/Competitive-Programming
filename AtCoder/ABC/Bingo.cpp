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

int g[5][5];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 3) rep(j, 3) cin >> g[i][j];	
	int n;
	cin >> n;
	map<int, int> v;
	rep(i, n){
		int x;
		cin >> x;
		v[x] = 1;
	}
	rep(i, 3){
		if(v[g[i][0]] && v[g[i][1]] && v[g[i][2]]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	rep(i, 3){
		if(v[g[0][i]] && v[g[1][i]] && v[g[2][i]]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	if(v[g[0][0]] && v[g[1][1]] && v[g[2][2]]){
		cout << "Yes" << endl;
		return 0;
	}
	if(v[g[0][2]] && v[g[1][1]] && v[g[2][0]]){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
