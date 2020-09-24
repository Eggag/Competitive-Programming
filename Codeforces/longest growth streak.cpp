#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int inc[n];
	for(int i = 0; i < n; i++){
		cin >> inc[i];
	}
	vector<int> op;
	int cur = 1;
	if(n > 1){
		for(int i = 1; i < n; i++){
			if(inc[i] >= inc[i - 1]){
				cur++;
				if(i == (n - 1)){
					op.push_back(cur);
				}
			}
			else{
				op.push_back(cur);
				cur = 1;
			}
		}
		sort(op.begin(), op.end());
		cout << op[op.size() - 1] << endl;
	}
	else{
		cout << 1 << endl;
	}
	return 0;
}
