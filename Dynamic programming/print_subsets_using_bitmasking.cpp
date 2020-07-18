#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	char a[] = {'A', 'B', 'C', 'D'};
	cin>>n;
	int total  = 1 << n;
	for(int i=0;i<total;i++){
	    for (int j = 0; j < n; j++) {
	        /* code */
	        int f = 1 << j;
	        if((i & f) != 0){
	            cout<<a[j]<<" ";
	        }
	    }
	    cout<<"\n";
	}
	
	return 0;
}