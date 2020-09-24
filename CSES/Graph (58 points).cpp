#define __AVX__ 1
#define __AVX2__ 1
#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSSE3__ 1
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#include<x86intrin.h>
using namespace std;
typedef long long ll;
typedef float ld;
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
const int mxN = 1e5 + 5;
const ld eps = 1e-4;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];

int vis[mxN];
vi con[mxN];
ld col[mxN], colFinal[mxN];
ld ans[mxN], bst[mxN], tot[mxN];
int rt[mxN];
int cmp = 0;
int f = 0;

ll xtime(){
	return clock()*1000/CLOCKS_PER_SEC;
}

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

void dfs(int cur){
	if(!f) return;
	if(tot[rt[cur]] > ans[rt[cur]]) return;
	vis[cur] = 1;
	for(pi x : g[cur]){
		if(!vis[x.fi]){
			col[x.fi] = 2.0 - col[cur];
			if(x.se == 1) col[x.fi] -= 1.0;
			tot[rt[x.fi]] += abs(col[x.fi]);
			dfs(x.fi);
		}
		else{
			if(x.se == 1){
				if((col[cur] + col[x.fi]) != 1){
					f = 0;
					return;
				}
			}
			else{
				if((col[cur] + col[x.fi])!= 2){
					f = 0;
					return;
				}
			}
		}
	}
}

void dfs1(int cur){
	vis[cur] = 1;
	for(pi x : g[cur]){
		if(!vis[x.fi]){
			colFinal[x.fi] = 2.0 - colFinal[cur];
			if(x.se == 1) colFinal[x.fi] -= 1.0;
			dfs1(x.fi);
		}
	}
}

int vis1[mxN];

void dfs0(int cur){
	vis[cur] = 1;
	rt[cur] = cmp;
	for(pi x : g[cur]){
		if(!vis[x.fi]){
			dfs0(x.fi);
		}
	}
}

int num[mxN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, m){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	rep(i, n) if(!vis[i]){
		cmp++;
		dfs0(i);
	}
	memset(vis, 0, sizeof(vis));
	vi cn;
	rep(i, n){
		con[rt[i]].pb(i);
		if(!vis1[rt[i]]) cn.pb(rt[i]);
		vis1[rt[i]] = 1;
	}
	vector<ld> val;
	rep(j, 160){
		val.pb(-90 + (j * 0.5));
		//if(rng() % 2) j++;
	}
	rep(j, 160){
		val.pb(90 - (j * 0.5));
		//if(rng() % 2) j++;
	}
	random_shuffle(all(val));
	rep(j, 42) val.pb(-10 + (j * 0.5));
	reverse(all(val));
	for(int i : cn) ans[i] = 1e9, num[i] = rng() % ((int)con[i].size());
	rep(j, val.size()){
		memset(vis, 0, sizeof(vis));
		for(int i : cn){
			f = 1;
			col[con[i][num[i]]] = val[j];
			tot[i] = abs(val[j]);
			dfs(con[i][num[i]]);
			if(f){
				if(tot[i] < ans[i]){
					ans[i] = tot[i];
					bst[i] = val[j];
				}
			}
		}
		if(xtime() >= 980) break;
	}
	for(int i : cn) if(ans[i] == 1e9){
		puts("NO");
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	for(int i : cn){
		ld val1 = bst[i];
		colFinal[con[i][num[i]]] = val1;
		dfs1(con[i][num[i]]);
	}
	puts("YES");
	rep(i, n) printf("%f ", colFinal[i]);
	printf("\n");
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
