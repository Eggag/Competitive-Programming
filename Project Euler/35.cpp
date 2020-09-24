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

bool is_prime(string s){
	int h = (int) stoi(s);
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
	int ans = 13;
	repn(i, 100, 1000000){
		string num = to_string(i);
		int n = (int) stoi(num);
		int l = num.length();
		num = num + num;
		int flag = 1;
		rep(i, l){
			if(!is_prime(num.substr(i, l))){
				flag = 0;
				continue;
			}
		} 
		if(flag) ans++;
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
