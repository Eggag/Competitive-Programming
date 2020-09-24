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
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vi cnt1(100005, 0);
	vi cnt2(100005, 0);
	vi cnt3(100005, 0);
	rep(i, n){
		int x;
		cin >> x;
		if(x == 1) cnt1[i]++;
		if(x == 2) cnt2[i]++;
		if(x == 3) cnt3[i]++;
	}
	rep(i, n) cnt1[i] += cnt1[i - 1];
	rep(i, n) cnt2[i] += cnt2[i - 1];
	rep(i, n) cnt3[i] += cnt3[i - 1];
	rep(i, q){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << cnt1[r] - (l ? cnt1[l - 1] : 0) << " ";
		cout << cnt2[r] - (l ? cnt2[l - 1] : 0) << " ";
		cout << cnt3[r] - (l ? cnt3[l - 1] : 0) << endl;
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
