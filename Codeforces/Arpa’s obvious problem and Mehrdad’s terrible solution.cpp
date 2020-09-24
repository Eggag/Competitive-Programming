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

ll cnt[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, x;
	cin >> n >> x;
	vi a(n);
	rep(i, n){
		cin >> a[i];
		cnt[a[i]]++;
	}
	ll ans = 0;
	rep(i, n) if(cnt[a[i]]){
		int sn = 0; //the number in which we will set bits
		rep(j, 20){
			if(x & (1 << j)){
				if(!(a[i] & (1 << j))){
					sn |= (1 << j);
				}
			}
			else{
				if((a[i] & (1 << j))){
					sn |= (1 << j);
				}
			}
		}
		if(sn > 100000) continue;
		ll b = cnt[a[i]];
		ll c = cnt[sn];
		ll add;
		if(a[i] == sn) add = b * (c - 1) / 2;
		else add = b * c;
		ans += add;
		cnt[a[i]] = 0, cnt[sn] = 0;
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
