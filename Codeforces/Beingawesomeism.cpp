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

void solve(){
	int r, c;
	cin >> r >> c;
	vector<string> s(r);
	rep(i, r) cin >> s[i];
	int f = 1;
	rep(i, r) rep(j, c) if(s[i][j] == 'A'){
		f = 0;
		break;
	}
	if(f){
		cout << "MORTAL" << endl;
		return;
	}
	int f1 = 1;
	rep(i, r) rep(j, c) if(s[i][j] == 'P'){
		f1 = 0;
	}
	if(f1){
		cout << 0 << endl;
		return;
	}
	//it is at most 4
	vi hor(r, 0);
	rep(i, r) rep(j, c){
		hor[i] += (s[i][j] == 'A');
	}
	vi ver(c, 0);
	rep(i, c) rep(j, r){
		ver[i] += (s[j][i] == 'A');
	}
	if((hor[0] == c) || (hor[r - 1] == c) || (ver[0] == r) || (ver[c - 1] == r)){
		cout << "1" << endl;
		return;
	}
	rep(i, r) if(hor[i] == c){
		cout << "2" << endl;
		return;
	}
	rep(i, c) if(ver[i] == r){
		cout << "2" << endl;
		return;
	}
	if(s[0][0] == 'A' || s[0][c - 1] == 'A' || s[r - 1][0] == 'A' || s[r - 1][c - 1] == 'A'){
		cout << "2" << endl;
		return;
	}
	rep(i, r){
		if(s[i][0] == 'A' || s[i][c - 1] == 'A'){
			cout << "3" << endl;
			return;
		}
	}
	rep(j, c){
		if(s[r - 1][j] == 'A' || s[0][j] == 'A'){
			cout << "3" << endl;
			return;
		}
	}
	cout << "4" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
