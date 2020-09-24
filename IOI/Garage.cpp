#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int tk[mxN];

bool cmp(pi a, pi b){
	return a.se > b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi r(n), w(m);
	rep(i, n) cin >> r[i];
	rep(i, m) cin >> w[i];
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq(cmp);
	rep(i, n) pq.push({r[i], i});
	ll tot = 0LL;
	queue<int> q;
	rep(i, 2 * m){
		int cur;
		cin >> cur;
		if(cur > 0){
			int ind1 = cur - 1;
			q.push(ind1);
			if(pq.size()){
				int ind = q.front();
				q.pop();
				pi tp = pq.top();
				pq.pop();
				tot += tp.fi * w[ind];
				tk[ind] = tp.se;
			}
		}
		else{
			int ind1 = abs(cur) - 1;
			pq.push({r[tk[ind1]], tk[ind1]});
			if(q.size()){
				int ind = q.front();
				q.pop();
				pi tp = pq.top();
				pq.pop();
				tot += tp.fi * w[ind];
				tk[ind] = tp.se;
			}
		}
	}
	cout << tot << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
