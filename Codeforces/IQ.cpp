#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	int ans;
	int eo[2] = {0, 0};
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			eo[0]++;
		}
		else{
			eo[1]++;
		}
	}
	if(eo[0] == 1){
		for(int i = 0; i < n; i++){
			if(a[i] % 2 == 0){
				ans = i + 1;
				break;
			}
		}
	}
	if(eo[1] == 1){
		for(int i = 0; i < n; i++){
                        if(a[i] % 2 != 0){
                                ans = i + 1;
                                break;
                        }
                }
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
