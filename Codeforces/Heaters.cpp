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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, r;
	cin >> n >> r;
	r--;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi cnt(n + 1);
	int num = 0;
	rep(i, n) if(a[i]){
		cnt[max(0, i - r)]++;
		cnt[min(n, i + r + 1)]--;
		num++;
	}
	partial_sum(all(cnt), cnt.begin());
	rep(i, n) if(!cnt[i]){
		cout << -1 << endl;
		return 0;
	}
	int ans = num;
	rep(i, n) if(a[i]){
		int f = 1;
		repn(j, max(0, i - r), min(n, i + r + 1)){
			if(cnt[j] <= 1){
				f = 0;
				break;
			}
		}
		if(f){
			repn(j, max(0, i - r), min(n, i + r + 1)) cnt[j]--;
			ans--;
		}
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
