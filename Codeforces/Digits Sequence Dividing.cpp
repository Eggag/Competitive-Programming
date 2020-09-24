#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	int n;
	cin >> n;
	vector<string> strs;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		string q;
		cin >> q;
		strs.pb(q);
	}
	for(int i = 0; i < n; i++){
		string k = strs[i];
		if(k.size() == 2){
			if(k[0] < k[1]){
				cout << "YES" << endl;
				cout << 2 << endl;
				cout << k[0] << " " << k[1] << endl;
			}
			else{
				cout << "NO" << endl;
			}	
		}
		else{
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << k[0] << " ";
			for(int i = 1; i < k.size(); i++){
				cout << k[i];
			}	
			cout << endl;
		}
	}
	return 0;	
}
