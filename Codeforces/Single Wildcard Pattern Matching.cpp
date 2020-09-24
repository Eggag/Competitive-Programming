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
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int f = 0;
	rep(i, a.size()){
		if(a[i] == '*'){
			f = 1;
			break;
		}
	}
	if(!f){
		cout << (a == b ? "YES" : "NO") << endl;
		return 0;
	}
	vi vis(m, 0);
	rep(i, a.size()){
		if(a[i] == '*') break;
		if(a[i] != b[i]){
			cout << "NO" << endl;
			return 0;
		}
		vis[i] = 1;
	}
	for(int i = a.size() - 1; i >= 0; i--){
		if(a[i] == '*') break;
		if(vis[m - (a.size() - i)] || a[i] != b[m - (a.size() - i)]){
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
