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

bool is_prime(int h){ 
        for(int i = 2; i <= sqrt(h); i++){
                if(h % i == 0){ 
                        return false;
                }
        }
        return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vi pr;
	repn(i, 2, 2000001){
		if(is_prime(i)) pr.pb(i);
	}	
	ll ans = 0;
	rep(i, pr.size()){
		ans += pr[i];
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
