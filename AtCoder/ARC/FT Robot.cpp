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

int dpH[8005], dpV[8005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	while(s[0] == 'F') x--, s = s.substr(1, (int)(s.size() - 1));
	//first we need to get the segments
	int totH = 0, totV = 0;
	vi hor, vert;
	int ori = 1;
	int sz = 0;
	rep(i, s.size()){
		if(s[i] == 'T'){
			if(ori && sz) hor.pb(sz), totH += sz;
			else if(sz) vert.pb(sz), totV += sz;
			sz = 0;
			ori ^= 1;
		}
		else sz++;
	}
	if(ori && sz) hor.pb(sz), totH += sz;
	else if(sz) vert.pb(sz), totV += sz;
	memset(dpH, 0, sizeof(dpH));
	memset(dpV, 0, sizeof(dpV));
	dpH[0] = 1;
	rep(i, hor.size()) for(int j = 8000 - hor[i]; j >= 0; j--) dpH[j + hor[i]] |= dpH[j];
	dpV[0] = 1;
	rep(i, vert.size()) for(int j = 8000 - vert[i]; j >= 0; j--) dpV[j + vert[i]] |= dpV[j];
	int cnt = 0, cnt1 = 0;
	rep(i, 8001){
		if(dpH[i] && (i - (totH - i)) == x) cnt = 1;
		if(dpV[i] && (i - (totV - i)) == y) cnt1 = 1;
	}
	if((cnt + cnt1) == 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
