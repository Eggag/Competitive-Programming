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

string to_base(int a, int c){ 
        string e = ""; 
        while(a > 0){ 
                e += a % c;
                a /= c;
        }
        reverse(e.begin(), e.end());
        return e;
}

bool palindrome(string b){ 
        for(int i = 0; i < (b.size()/2); i++){
                if(b[i] != b[b.size() - i - 1]){
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
	ll ans = 0;
	repn(i, 1, 1000001){
		if(palindrome(to_string(i)) && palindrome(to_base(i, 2))) ans += i;
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
