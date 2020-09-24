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

ll dp[105][105];

struct AvoidRoads{
        ll numWays(int w, int h, vector<string> v){
                ios_base::sync_with_stdio(false);
                cin.tie(0);
            	set<string> s;
            	rep(i, v.size()){
                	s.insert(v[i]);
                }
               	rep(i, h + 1) rep(j, w + 1) dp[i][j] = 0;
                dp[0][0] = 1;
                rep(i, h + 1) rep(j, w + 1){
                    	if(i){
                            	string p1 = to_string(j) + " " + to_string(i - 1) + " " + to_string(j) + " " + to_string(i);
                            	string p2 = to_string(j) + " " + to_string(i) + " " + to_string(j) + " " + to_string(i - 1);
                        	if(!(s.count(p1)) && !(s.count(p2))) dp[i][j] += dp[i - 1][j];
                    	}
                    	if(j){
                            	string p1 = to_string(j - 1) + " " + to_string(i) + " " + to_string(j) + " " + to_string(i);
                            	string p2 = to_string(j) + " " + to_string(i) + " " + to_string(j - 1) + " " + to_string(i);
                        	if(!(s.count(p1)) && !(s.count(p2))) dp[i][j] += dp[i][j - 1];
                        }
                }
                return dp[h][w];
        }
};

/*
Things to look out for:
        - Integer overflows
		- Array bounds
        - Special cases
Be careful!
*/
