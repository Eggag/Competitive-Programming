#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

vector<string> w1, w2;
int mindist = 1e9;
int v[25];
int d1 = 0, d2 = 0;

struct DoubleWeights{
	void dfs(int c){
    		if(c == 1){
			mindist = min(mindist, d1 * d2);
			return;
		}
		if(d1 * d2 > mindist) return;
		rep(i, w1[c].size()) if(!v[i] && w1[c][i] != '.'){
			v[i] = 1;
			d1 += w1[c][i] - '0';
			d2 += w2[c][i] - '0';
			dfs(i);
			v[i] = 0;
			d1 -= w1[c][i] - '0';
			d2 -= w2[c][i] - '0';
		}
    	}
	int minimalCost(vector<string> we1, vector<string> we2){
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		w1 = we1;
		w2 = we2;
		dfs(0);
		return ((mindist == 1e9) ? -1 : mindist);
	}
};
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/