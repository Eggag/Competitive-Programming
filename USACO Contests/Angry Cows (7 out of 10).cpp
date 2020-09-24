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
const int mxN = 5e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int x[mxN];

bool check(ld g){
	int prev = g - 1;
	vi good(n + 10, 0);
	repn(i, 2, n + 1){
		int dif = min(n - i + 1, max(0, prev - (x[i] - x[i - 1]) + 1));
		if(x[i + 1] == x[i]) dif = n - i + 1;
		good[i + dif]++;
	}
	vi good1(n + 10, 0);
	for(int i = n - 1; i >= 1; i--){
		int dif = min(i, max(-1, prev - (x[i + 1] - x[i])));
		if(x[i + 1] == x[i]) dif = i;
		good1[0]++;
		good1[(i - dif)]--;
	}
	partial_sum(all(good), good.begin());
	partial_sum(all(good1), good1.begin());
	repn(i, 1, n + 1){
		int ad = 2 * g;
		int l = i, r = n;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if((x[mid] - x[i]) <= ad) l = mid;
			else r = mid - 1;
		}
		if(!good[i] && !good1[l]) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> n;
	repn(i, 1, n + 1) cin >> x[i];
	sort(x + 1, x + n + 1);
	ld l = 0, r = 1e14;
	while((r - l) > 0.05){
		ld mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(1) << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
