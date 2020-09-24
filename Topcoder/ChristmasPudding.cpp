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

struct ChristmasPudding{
	ll eat(int n, ll Vall, ll Vsweet, vi V1, vi T1, vi S1, ll seed){
        	vector<ll> V, T, S;
        	rep(i, T1.size()) T.pb((ll)T1[i]);
        	rep(i, S1.size()) S.pb((ll)S1[i]);
        	rep(i, V1.size()) V.pb((ll)V1[i]);
		ll state = seed;
		while(V.size() < n){
			state = ((1LL * state * 1103515245 + 12345) % (1LL << 31));
			V.pb(1 + (state % (1000000)));
			state = ((1LL * state * 1103515245 + 12345) % (1LL << 31));
			T.pb(1 + (state % (1000000)));
			state = ((1LL * state * 1103515245 + 12345) % (1LL << 31));
			S.pb((state / 1024) % 2);
		}
        	/*
        	rep(i, V.size()) cout << V[i] << " ";
        	cout << endl;
        	rep(i, T.size()) cout << T[i] << " ";
        	cout << endl;
        	rep(i, S.size()) cout << S[i] << " ";
        	cout << endl;
        	*/
		//first, focus on eating the most tasty ones that have T[i] = 1
		vector<pair<pair<ll, ll>, int>> pos;
		rep(i, n) if(S[i] == 1) pos.pb(mp(mp(T[i], V[i]), i)); //add it if it is sweet
		sort(all(pos));
		reverse(all(pos));
		ll tot = 0;
        	ll tot1 = 0;
		rep(i, pos.size()){
			if(Vsweet > pos[i].fi.se){
				tot += pos[i].fi.fi * pos[i].fi.se;
				V[pos[i].se] = 0;
                		Vsweet -= pos[i].fi.se;
				tot1 += pos[i].fi.se;
			}
			else{
				tot += pos[i].fi.fi * Vsweet;
				V[pos[i].se] -= Vsweet;
				tot1 += Vsweet;
				Vsweet = 0;
                		break;
			}
		}
		vector<pair<ll, ll>> vec;
		rep(i, n) vec.pb(mp(T[i], V[i]));
		sort(all(vec));
		reverse(all(vec));
		Vall -= tot1;
		rep(i, vec.size()){
			if(Vall > vec[i].se){
				Vall -= vec[i].se;
				tot += vec[i].fi * vec[i].se;
			}
			else{
				tot += Vall * vec[i].fi;
				Vall = 0;
				break;
			}
		}
		return tot;
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/