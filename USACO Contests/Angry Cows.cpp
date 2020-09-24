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

int n, k;
int x[maxn];

bool check(int num){
	int last = -1;
	int ret = 0;
	rep(i, n){
		if(last == -1 || last < x[i]){
			ret++;
			last = x[i] + (2 * num);
		}
	}
	return (ret <= k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> x[i];
	sort(x, x + n);
	if(k >= n){
		cout << 0 << endl;
		return 0;
	}
	int l = 0, r = 1e7;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
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
