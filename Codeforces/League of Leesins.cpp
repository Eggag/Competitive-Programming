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

int v[100005];
vi cnt[100005];
int n;

bool check(vi a){
	int cnt1[100005];
	memset(cnt1, 0, sizeof(cnt1));
	rep(i, a.size()) cnt1[a[i]]++;
	repn(i, 1, n + 1) if(cnt1[i] != 1) return 0;
	rep(i, a.size()) cout << a[i] << " ";
	cout << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	vector<pair<int, pi>> p;
	memset(v, 0, sizeof(v));
	map<pi, vi> m;
	rep(i, n - 2){
		int a, b, c;
		cin >> a >> b >> c;
		cnt[a].pb(i), cnt[b].pb(i), cnt[c].pb(i);
		m[mp(a, b)].pb(i);
		m[mp(b, a)].pb(i);
		m[mp(a, c)].pb(i);
		m[mp(c, a)].pb(i);
		m[mp(c, b)].pb(i);
		m[mp(b, c)].pb(i);
		p.pb({a, {b, c}});
	}
	vi pos;
	repn(i, 1, n + 1) if(cnt[i].size() == 1) pos.pb(i);
	int one, two, ind;
	rep(i, n - 2){
		if(p[i].fi == pos[0]){
			ind = i;
			one = p[i].se.fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.fi == pos[0]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.se == pos[0]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.fi;
			break;
		}

	}
	vi ans = {pos[0], one, two};
	v[ind] = 1;
	repn(i, 1, n - 2){
		vi cur = m[mp(one, two)];
		int next;
		rep(j, cur.size()) if(!v[cur[j]]){
			if(p[cur[j]].fi != one && p[cur[j]].fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].fi;	
				break;
			}
			if(p[cur[j]].se.se != one && p[cur[j]].se.se != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.se;	
				break;
			}
			if(p[cur[j]].se.fi != one && p[cur[j]].se.fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.fi;	
				break;
			}
		}
		ans.pb(next);
		one = two;
		two = next;
	}
	check(ans);
	rep(i, n - 2){
		if(p[i].fi == pos[0]){
			ind = i;
			one = p[i].se.fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.fi == pos[0]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.se == pos[0]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.fi;
			break;
		}

	}
	swap(one, two);
	ans = {pos[0], one, two};
	memset(v, 0, sizeof(v));
	v[ind] = 1;
	repn(i, 1, n - 2){
		vi cur = m[mp(one, two)];
		int next;
		rep(j, cur.size()) if(!v[cur[j]]){
			if(p[cur[j]].fi != one && p[cur[j]].fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].fi;	
				break;
			}
			if(p[cur[j]].se.se != one && p[cur[j]].se.se != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.se;	
				break;
			}
			if(p[cur[j]].se.fi != one && p[cur[j]].se.fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.fi;	
				break;
			}
		}
		ans.pb(next);
		one = two;
		two = next;
	}
	check(ans);
	rep(i, n - 2){
		if(p[i].fi == pos[1]){
			ind = i;
			one = p[i].se.fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.fi == pos[1]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.se == pos[1]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.fi;
			break;
		}

	}
	ans = {pos[1], one, two};
	memset(v, 0, sizeof(v));
	v[ind] = 1;
	repn(i, 1, n - 2){
		vi cur = m[mp(one, two)];
		int next;
		rep(j, cur.size()) if(!v[cur[j]]){
			if(p[cur[j]].fi != one && p[cur[j]].fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].fi;	
				break;
			}
			if(p[cur[j]].se.se != one && p[cur[j]].se.se != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.se;	
				break;
			}
			if(p[cur[j]].se.fi != one && p[cur[j]].se.fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.fi;	
				break;
			}
		}
		ans.pb(next);
		one = two;
		two = next;
	}
	check(ans);
	rep(i, n - 2){
		if(p[i].fi == pos[1]){
			ind = i;
			one = p[i].se.fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.fi == pos[1]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.se;
			break;
		}
		if(p[i].se.se == pos[1]){
			ind = i;
			one = p[i].fi;
			two = p[i].se.fi;
			break;
		}

	}
	swap(one, two);
	ans = {pos[1], one, two};
	memset(v, 0, sizeof(v));
	v[ind] = 1;
	repn(i, 1, n - 2){
		vi cur = m[mp(one, two)];
		int next;
		rep(j, cur.size()) if(!v[cur[j]]){
			if(p[cur[j]].fi != one && p[cur[j]].fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].fi;	
				break;
			}
			if(p[cur[j]].se.se != one && p[cur[j]].se.se != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.se;	
				break;
			}
			if(p[cur[j]].se.fi != one && p[cur[j]].se.fi != two){
				v[cur[j]] = 1;
				next = p[cur[j]].se.fi;	
				break;
			}
		}
		ans.pb(next);
		one = two;
		two = next;
	}
	check(ans);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
