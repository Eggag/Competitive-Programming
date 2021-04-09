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
#define inf 0x3f3f3f3f
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int mn[mxN], mx[mxN], nxt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, x;
	cin >> n >> x;
	vi a(n);
	memset(mn, inf, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	rep(i, n){
		cin >> a[i];
		mn[a[i]] = min(mn[a[i]], i);
		mx[a[i]] = max(mx[a[i]], i);
	}
	ll ans = 1LL;
	int maxL = -1;
	repn(i, 1, x){
		if(mn[i] < maxL) break;
		maxL = max(mx[i], maxL);
		ans++;
	}
	int minR = inf;
	int l = 0;
	mx[0] = -1;
	for(int i = x; i >= 2; i--){
		if(mx[i] > minR) break;
		minR = min(minR, mn[i]);
		ans++;
		if(i == x){
			int mx1 = -1, lst = 0;
			repn(j, 1, x - 1){
				if(mn[j] != inf && (mn[j] < mx1 || mx[j] > minR)) break;
				nxt[j] = lst;
				if(mn[j] != inf) lst = j;
				l++;
				mx1 = max(mx1, mx[j]);
			}
			ans += l;
		}
		else{
			while(l >= 1 && ((mn[l] == inf && mx[nxt[l]] >= minR) || (mn[l] != inf && mx[l] >= minR))) l--;
			while(l >= (i - 1)) l--;
			ans += l;
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
