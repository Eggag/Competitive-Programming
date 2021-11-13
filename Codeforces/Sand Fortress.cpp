#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool ok(ll a, ll b){
	if(b & 1){
		return (((b + 1) / 2) < ((a + b - 1) / b));
	}
	else{
		return ((b / 2) < ((a + b) / (b + 1)));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, h;
	cin >> n >> h;
	ll l = 1, r = n;
	while(l < r){
		ll mid = (l + r) / 2;
		int f = 0;
		if(mid <= h){
			if(!ok(n, mid)) f = 1;
		}
		else{
			if(!ok(n, h)) f = 1;
			else{
				ll h1 = n - (h * (h + 1) / 2);
				ll ad = (mid - h);
				ad--;
				h1 -= h + ad;
				if(ad % 2 == 0){
					if(ok(h1, ad / 2)){
						h1 = h1 - ((ad / 2) * ((ad / 2) + 1) / 2);
						if(ok(h1, ad / 2)){
							h1 = h1 - ((ad / 2) * ((ad / 2) + 1) / 2);
							if(h1 <= ad * (h - 1)) f = 1;
						}
						else f = 1;
					}	
					else f = 1;
				}
				else{
					if(ok(h1, ad / 2)){
						h1 = h1 - ((ad / 2) * ((ad / 2) + 1) / 2);
						if(ok(h1, (ad / 2) + 1)){
							h1 = h1 - (((ad / 2) + 2) * ((ad / 2) + 1) / 2);
							if(h1 <= ad * (h - 1)) f = 1;
						}
						else f = 1;
					}
					else f = 1;
				}
			}
		}
		if(f) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
