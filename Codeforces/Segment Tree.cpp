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

struct DSU{
	int S;
        struct node{
		int parent; ll sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	int root(int u){
		if(dsu[u].parent == u) return u;
		dsu[u].parent = root(dsu[u].parent);
		return dsu[u].parent;
	}
	void merge(int u, int v){
		u = root(u); v = root(v);
		if(u == v) return;
		if(getsum(u) < getsum(v)) swap(u, v);
		dsu[v].parent = u;
		dsu[u].sum += dsu[v].sum;
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}	
	ll getsum(int u){
        	return dsu[root(u)].sum;
        }
};

bool cmp(array<int, 3> a, array<int, 3> b){
        return a[0] < b[0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
        int n;
        cin >> n;
        vector<pi> s(n);
        vector<array<int, 3>> ev;
        vi deg(n, 0);
        rep(i, n){
                cin >> s[i].fi >> s[i].se;
                ev.pb({s[i].fi, i, 1});
                ev.pb({s[i].se, i, 0});
        }
        sort(all(ev), cmp);
        DSU dsu(n);
        set<pi> st;
        int num = 0;
        rep(i, 2 * n){
                if(num > (n - 1)){
                        cout << "NO" << endl;
                        return 0;
                }
                if(!ev[i][2]){
                        auto it = st.lb(mp(s[ev[i][1]].fi + 1, 0));
                        while(true){
                                if(it == st.end()) break;
                                pi cur = *it;
                                int y = cur.se;
                                dsu.merge(y, ev[i][1]);
                                deg[y]++, deg[ev[i][1]]++;
                                num++;
                                if(num > (n - 1)){
                                        cout << "NO" << endl;
                                        return 0;
                                }
                                it++;
                        }
                        if(!deg[ev[i][1]] && n > 1){
                                cout << "NO" << endl;
                                return 0;
                        }
                        st.erase(st.find(mp(s[ev[i][1]].fi, ev[i][1])));
                }
                else st.insert({ev[i][0], ev[i][1]});
        }
        if(num == (n - 1) && dsu.getsum(0) == n) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
