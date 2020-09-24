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
	string b;
	cin >> b;
	bool f1 = 1;
	int a = 1;
	for(int i = 0; i < b.size(); i++){
		if(b[i] == '1'){
			if(f1){
				f1 = 0;
				cout << "1" << " " << "1" << endl;
			}
			else{
				f1 = 1;
				cout << "1" << " " << "3" << endl;
			}
		}
		else{
			cout << 3 << " " << a << endl;
			if(a == 4){
				a = 1;	
			}
			else{
				a++;
			}	
		}
	}
		
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
