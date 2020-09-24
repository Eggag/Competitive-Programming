#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] > 0){
			if(s[i] >= s[k - 1]){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
