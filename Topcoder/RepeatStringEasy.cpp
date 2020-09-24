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

int dp[55][55];

struct RepeatStringEasy{
	int maximalLength(string s){
                ios_base::sync_with_stdio(false);
        	cin.tie(0);
                int n = s.size();
                int ans = 0;
                memset(dp, 0, sizeof(dp));
                repn(k, 1, n){
                        string s1 = " ", s2 = " ";
        	        rep(j, k) s1 += s[j];
                        repn(j, k, n) s2 += s[j];
         	        repn(i, 1, s1.size()) repn(j, 1, s2.size()){
                                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                                if(s1[i] == s2[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
	                }
                    	ans = max(ans, dp[s1.size() - 1][s2.size() - 1]);
                }
                return ans * 2;
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/       
