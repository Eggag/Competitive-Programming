#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl;
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

int n;
ld s;
ld x[20], y[20], vx[20], vy[20];
int vis[20];

bool check(ld g, int h, ld nw, ld tr){
	ld us = nw + (ld)(s * g * (h ? 1 : -1));
	rep(j, n) if(!vis[j]){
		ld them = x[j] + (ld)((tr + g) * vx[j]);
		ld pr = x[j] + tr * vx[j];
		if((us - them) >= 1e-8 != (nw - pr) >= 1e-8){
			return 1;
		}
	}
	return 0;
}

void check2(ld g, int h, ld nw, ld tr){
	ld us = nw + (ld)(s * g * (h ? 1 : -1));
	rep(j, n) if(!vis[j]){
		ld them = x[j] + (ld)((tr + g) * vx[j]);
		ld pr = x[j] + tr * vx[j];
		if((us - them) >= 1e-8 != (nw - pr) >= 1e-8){
			vis[j] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> s;
	int subtask = 1;
	rep(i, n){
		cin >> x[i] >> y[i] >> vx[i] >> vy[i];
		if(y[i] != 0 || vy[i] != 0) subtask = 2;
	}
	cout << fixed << setprecision(20);
	if(subtask == 1){
		ld ans = 1e18;
		rep(i, (1 << n)){
			//debug(bitset<2>(i));
			ld cur = 0; //our location
			ld tot = 0; //how much we travelled
			memset(vis, 0, sizeof(vis));
			rep(j, n){
				int h = (i & (1 << j)) ? 1 : 0;
				ld l = 0, r = 1e16;
				ld bst = 1e18;
				while((r - l) > 1e-8){
					ld mid = (l + r) / 2;
					int f = check(mid, h, cur, tot);
					if(f) bst = min(bst, mid);
					if(f) r = mid;
					else l = mid;
				}
				l = bst;
				if(abs(l - 1e16) > 1e-8 && bst != 1e18){
					check2(l, h, cur, tot); //with mod
					cur += (h ? 1 : -1) * l * s;
					tot += l;
				}
			}
			int cnt = 0;
			rep(j, n) if(vis[j]) cnt++;
			if(cnt == n) ans = min(ans, tot);
		}
		cout << ans << endl;
	}
	else{
		//next_permutation
		//we need the fastest way to reach it hmmm
		//:O too hard :(
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
