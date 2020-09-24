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
const int maxn = 5e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[maxn];
ll sum[maxn];

bool check(int len){
	for(int j = len; j <= n; j++){
		if((sum[j] - sum[j - len]) % 7 == 0) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	cin >> n;
	repn(i, 1, n + 1) cin >> a[i];
	sum[0] = 0;
	repn(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
