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
const int mxN = 3e5 + 5;
const int logn = 23;

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

int dp[mxN];

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
	rep(i, n) dp[i] = 1e9;
	dp[0] = 0;
	rep(i, n - 1){
		int l = i + 1, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(maxQ(i + 1, mid + 1) >= a[i]) r = mid;
			else l = mid + 1;
		}
		int mx = maxQ(i + 1, l + 1);
		if(a[l] == mx && a[l] >= a[i]) dp[l] = min(dp[l], dp[i] + 1);
		l = i + 1, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(minQ(i + 1, mid + 1) <= a[i]) r = mid;
			else l = mid + 1;
		}
		int mn = minQ(i + 1, l + 1);
		if(a[l] <= a[i] && a[l] == mn) dp[l] = min(dp[l], dp[i] + 1);
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
	}
	repn(i, 1, n){
		int l = 1, r = i;
		while(l < r){
			int mid = (l + r) / 2;
			if(maxQ(i - mid, i) >= a[i]) r = mid;
			else l = mid + 1;
		}
		if(i >= l){
			int mx = maxQ(i - l, i);
			if(a[i - l] == mx && a[i] <= a[i - l]) dp[i] = min(dp[i], dp[i - l] + 1);
		}
		l = 1, r = i;
		while(l < r){
			int mid = (l + r) / 2;
			if(minQ(i - mid, i) <= a[i]) r = mid;
			else l = mid + 1;
		}
		if(i >= l){
			int mn = minQ(i - l, i);
			if(a[i - l] == mn && a[i] >= a[i - l]) dp[i] = min(dp[i], dp[i - l] + 1);
		}
	}
	rep(i, n - 1){
		int l = i + 1, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(maxQ(i + 1, mid + 1) >= a[i]) r = mid;
			else l = mid + 1;
		}
		int mx = maxQ(i + 1, l + 1);
		if(a[l] == mx && a[l] >= a[i]) dp[l] = min(dp[l], dp[i] + 1);
		l = i + 1, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(minQ(i + 1, mid + 1) <= a[i]) r = mid;
			else l = mid + 1;
		}
		int mn = minQ(i + 1, l + 1);
		if(a[l] <= a[i] && a[l] == mn) dp[l] = min(dp[l], dp[i] + 1);
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
	}
	repn(i, 1, n){
		int l = 1, r = i;
		while(l < r){
			int mid = (l + r) / 2;
			if(maxQ(i - mid, i) >= a[i]) r = mid;
			else l = mid + 1;
		}
		if(i >= l){
			int mx = maxQ(i - l, i);
			if(a[i - l] == mx && a[i] <= a[i - l]) dp[i] = min(dp[i], dp[i - l] + 1);
		}
		l = 1, r = i;
		while(l < r){
			int mid = (l + r) / 2;
			if(minQ(i - mid, i) <= a[i]) r = mid;
			else l = mid + 1;
		}
		if(i >= l){
			int mn = minQ(i - l, i);
			if(a[i - l] == mn && a[i] >= a[i - l]) dp[i] = min(dp[i], dp[i - l] + 1);
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
