#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k, r;
int a[mxN], req[mxN];

bool check(int g){
	vi cnt(n, 0);
	int num = 0; //the number of ones that need fixing (good if it is 0 at some point)
	rep(i, n) if(cnt[i] < req[i]) num++;
	rep(i, g){
		cnt[a[i]]++;
		if(cnt[a[i]] == req[a[i]]) num--; //we fixed it :)
	}
	if(!num) return 1;
	repn(i, g, n){
		cnt[a[i]]++;
		if(cnt[a[i]] == req[a[i]]) num--; //we fixed it :)
		cnt[a[i - g]]--;
		if(cnt[a[i - g]] == (req[a[i - g]] - 1)) num++;
		if(!num) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k >> r;
	rep(i, n) cin >> a[i];
	rep(i, r){
		int c, b;
		cin >> c >> b;
		req[c] = b;
	}
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l)) cout << "impossible" << endl;
	else cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
