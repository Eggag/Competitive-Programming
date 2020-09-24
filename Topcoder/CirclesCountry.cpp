#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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


struct CirclesCountry{
	ld dist(int x, int y, int x1, int y1){
		return sqrtl(sq(x1 - x) + sq(y1 - y));
	}
	int leastBorders(vi x, vi y, vi r, int x1, int y1, int x2, int y2){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		int ans = 0;
		rep(i, x.size()){
			//if one is inside and not both, increment ans
			int cnt = 0;
			if(dist(x1, y1, x[i], y[i]) < r[i]) cnt++;
			if(dist(x2, y2, x[i], y[i]) < r[i]) cnt++;
			if(cnt == 1) ans++;
		}
		return ans;
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/              
