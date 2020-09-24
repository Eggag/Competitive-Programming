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

int ex[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n);
	memset(ex, 0, sizeof(ex));
	int mn = 1e9, mx = 0;
	rep(i, n){
		cin >> a[i];
		mn = min(a[i], mn);
		mx = max(a[i], mx);
		ex[a[i]]++;
	}
	int cur = 0;
	int cnt = 0;
	for(int i = mx; i > mn; i--){
		cnt++;
		cur += ex[i]; //they are just going to add
		assert(cur < k);
		if(i == mn) break;
		int pos = i;
		int now = cur + cur + ex[i - 1];
		cur += ex[i - 1];
		int j = i - 1;
		while(j > mn && now <= k){
			pos = j;
			j--;
			cur += ex[j];
			now += cur;
		}
		if(now > k){
			cur -= ex[pos - 1];
		}
		i = pos;
	}
	cout << cnt << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
