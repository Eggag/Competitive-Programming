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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool prime(int n){
	if(n == 1) return 0;
	for(int i = 2; (i * i) <= n; i++) if(n % i == 0) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(0);
	rep(j, n){
		queue<int> q1;
		while(!q.empty()){
			int num = q.front();
			q.pop();
			repn(i, 1, 10) if(prime(num * 10 + i)){
				if(!j && !prime(i)) continue;
				q1.push(num * 10 + i);
			}
		}
		q = q1;
	}
	vi pos;
	while(!q.empty()){
		pos.pb(q.front());
		q.pop();
	}
	if(max(n, m) > 5){
		cout << 0 << endl;
		return 0;
	}
	queue<vi> q2;
	rep(i, pos.size()){
		vi nw;
		string s = to_string(pos[i]);
		int f = 1;
		rep(j, s.size()) if(!prime(s[j] - '0')){
			f = 0;
			break;
		}
		if(!f) continue;
		rep(j, s.size()) nw.pb(s[j] - '0');
		q2.push(nw);
	}
	repn(i, 1, m){
		queue<vi> q3;
		while(!q2.empty()){
			vi cur = q2.front();
			rep(j, pos.size()){
				int f = 1;
				vi nxt;
				string s = to_string(pos[j]);
				rep(k, n){
					if(!prime(cur[k] * 10 + (s[k] - '0'))){
						f = 0;
						break;
					}
					else nxt.pb(cur[k] * 10 + (s[k] - '0'));
				}
				if(f) q3.push(nxt);
			}
			q2.pop();
		}
		q2 = q3;
	}
	cout << (int)(q2.size()) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
