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
#define endl '\n'

struct rect{
	int x1, y1, x2, y2;
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
	return ((x.x1 < x.x2) && (x.y1 < x.y2));
}

int n;
int ans = 0;
rect a[55];

void dfs(rect cur, int ind, int cnt){
	if(ind == n){
		ans = max(ans, cnt);
		return;
	}
	dfs(cur, ind + 1, cnt);
	rect tmp = cross(cur, a[ind]);
	if(!valid(tmp)) return;
	else dfs(tmp, ind + 1, cnt + 1);
}

struct SoManyRectangles{
	int maxOverlap(vi x, vi y, vi x1, vi y1){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		n = (int)(x.size());
		rep(i, n){
			a[i] = (rect){x[i], y[i], x1[i], y1[i]};
		}
		dfs({-1e9, -1e9, 1e9, 1e9}, 0, 0);
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
