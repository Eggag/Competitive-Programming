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

struct rect{
	ll x1, y1, x2, y2;
};

rect cross(rect x, rect y){
	rect ret;
	ret.x1 = max(y.x1, x.x1);
	ret.y1 = max(y.y1, x.y1);
	ret.x2 = min(y.x2, x.x2);
	ret.y2 = min(y.y2, x.y2);
	return ret;
}

bool valid(rect x){
	return ((x.x1 <= x.x2) && (x.y1 <= x.y2));
}

ll area(rect x){
	return ((abs(x.y1 - x.y2) + 1) * (abs(x.x1 - x.x2) + 1));
}
	
ll n1, m1;

ll count_b(rect x){
	if(x.x1 & 1){
		ll b = 0, w = 0;
		ll m = abs(x.x1 - x.x2) + 1, n = abs(x.y1 - x.y2) + 1;
		if(n & 1){
			if(m & 1){
				b = ((n / 2) + 1) * ((m / 2) + 1) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
			else{
				b = ((n / 2) + 1) * (m / 2) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
		}
		else{
			if(m & 1){
				b = (n / 2) * ((m / 2) + 1) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
			else{
				b = ((n / 2) * (m / 2)) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
		}
		if(x.x2 & 1){
			if(x.y2 & 1) return w;
			else return b;
		}
		else{
			if(x.y2 & 1) return b;
			else return w;
		}
	}
	else{
		ll b = 0, w = 0;
		ll m = abs(x.x1 - x.x2) + 1, n = abs(x.y1 - x.y2) + 1;
		if(n & 1){
			if(m & 1){
				b = ((n / 2) + 1) * ((m / 2) + 1) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
			else{
				b = ((n / 2) + 1) * (m / 2) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
		}
		else{
			if(m & 1){
				b = (n / 2) * ((m / 2) + 1) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
			else{
				b = ((n / 2) * (m / 2)) + ((n / 2) * (m / 2));
				w = (n * m) - b;
			}
		}
		if(x.x2 & 1){
			if(x.y2 & 1) return w;
			else return b;
		}
		else{
			if(x.y2 & 1) return b;
			else return w;
		}
	}
}

void solve(){
	cin >> n1 >> m1;
	ll x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	rect r = {x, y, x1, y1};
	cin >> x >> y >> x1 >> y1;
	rect r1 = {x, y, x1, y1};
	ll b1 = 0, w1 = 0; //start with that
	if((n1 * m1) % 2 == 0) b1 = w1 = ((n1 * m1) / 2);
	else{
		if(n1 % 2 == 0){
			w1 = (n1 * m1) / 2;
			b1 = (n1 * m1) - w1;
		}
		else{
			b1 = (n1 * m1) / 2;
			w1 = (n1 * m1) - b1;
		}
	}
	ll w = count_b(r);
	w1 += w;
	ll b = area(r1) - count_b(r1);
	w1 -= b;
	b -= w;
	b1 += b;
	rect r2 = cross(r, r1);
	if(valid(r2)){
		ll x = count_b(r2);
		w1 -= x, b1 += x;
	}
	cout << w1 << " " << b1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
