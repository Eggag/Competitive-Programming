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
	int n;
	cin >> n;
	vi p(n);
	rep(i, n) cin >> p[i];
	if(n < 6){
		cout << "0 0 0" << endl;
		return;
	}
	vi pos;
	int mx = n / 2; //the max of medals we can give
	repn(i, 1, n){
		if(i >= (mx + 1)) break;
		if(p[i] != p[i - 1]) pos.pb(i);
	}
	if(pos.size() < 3){
		cout << "0 0 0" << endl;
		return;
	}
	vi s;
	rep(i, pos.size()){
		int cur = (pos[i] - (i ? pos[i - 1] : 0));
		s.pb(cur);
	}
	int gol = s[0];
	int sil = 0;
	int ind = 1;
	while(ind < (int)s.size() && sil <= gol){
		sil += s[ind];
		ind++;
	}
	int br = 0;
	while(ind < (int)s.size()){
		br += s[ind];
		ind++;
	}
	if(br <= gol || sil <= gol){
		cout << "0 0 0" << endl;
		return;
	}
	cout << gol << " " << sil << " " << br << endl;
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
