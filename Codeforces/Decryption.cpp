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
const int logn = 21;
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN], mn[logn][mxN], mx[logn][mxN];
 
int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}
 
int maxQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return max(mx[t][l], mx[t][r - (1 << t)]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i];
	memcpy(mx[0], a, sizeof a);
	memcpy(mn[0], a, sizeof a);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
			mx[l + 1][i] = max(mx[l][i], mx[l][i + (1 << l)]);
		}
	}
	int ans = 0;
	int st = 0;
	while(st < n){
		if(st == n - 1){
			ans++;
			break;
		}
		if(a[st + 1] < a[st]){
			ans++, st++;
			continue;
		}
		int l = st, r = n - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(minQ(st, mid + 1) == a[st]) l = mid;
			else r = mid - 1;
		}
		if(maxQ(st + 1, l + 1) < a[st]){
			ans++;
			st++;
			continue;
		}
		int l1 = st, r1 = l;
		while(l1 < r1){
			int mid1 = (l1 + r1 + 1) / 2;
			if(maxQ(st, l + 1) == maxQ(mid1, l + 1)) l1 = mid1;
			else r1 = mid1 - 1;
		}
		st = l1 + 1;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
