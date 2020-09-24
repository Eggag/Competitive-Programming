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

bool cmp(pi a, pi b){
	return a.fi < b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vi p(a), q(b), r(c);
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq(cmp);
	rep(i, a) cin >> p[i], pq.push({p[i], 0});
	rep(i, b) cin >> q[i], pq.push({q[i], 1});
	rep(i, c) cin >> r[i], pq.push({r[i], 2});
	sort(all(p));
	sort(all(q));
	reverse(all(p));
	reverse(all(q));
	vector<ll> sum(a), sum1(b);
	sum[0] = p[0];
	repn(i, 1, a) sum[i] = sum[i - 1] + p[i];
	sum1[0] = q[0];
	repn(i, 1, b) sum1[i] = sum1[i - 1] + q[i];
	ll ans = 0;
	int x1 = 0, y1 = 0;
	while(pq.size()){
		if(!x && !y) break;
		pi cur = pq.top();
		pq.pop();
		if(cur.se == 0){
			if(x) ans += cur.fi, x--, x1++;
		}
		else if(cur.se == 1){
			if(y) ans += cur.fi, y--, y1++;
		}
		else{
			if(y && !x) ans += cur.fi, y--;
			else if(x && !y) ans += cur.fi, x--;
			else if(x && y){
				//if((sum[min(a - 1, (x - 1) + x1)] - (x1? sum[x1 - 1] : 0)) > (sum1[min(b - 1, (y - 1) + y1)] - (y1? sum1[y1 - 1] : 0))) y--;
				//else x--;
				if(p[x1 + x - 1] > q[y1 + y - 1]) y--;
				else x--;
				ans += cur.fi;
			}
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
