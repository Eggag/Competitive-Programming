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
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	ll l = 0; //left pointer
	ll ans = 1;
	vi cnt(22, 0);
	rep(j, 22) if(a[0] & (1 << j)) cnt[j]++;
	repn(i, 1, n){
		//keep deleting from the back?
		rep(j, 22) if(a[i] & (1 << j)){
			if(cnt[j]){
				int f = 1;
				while(f){
					rep(k, 22){
						if(a[l] & (1 << k)) cnt[k]--;
					}		
					if(!cnt[j]) f = 0;
					l++;
				}
			}
			cnt[j]++;
		}
		ans += (ll)(i - l + 1);
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
