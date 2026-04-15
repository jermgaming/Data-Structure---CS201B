#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		int count=0;
		for(int j=i;j>=0;j--){
			if(arr[j]<=arr[i]){
				count++;
			}else {
				break;
			}
		}
		cout<<count<<" "; 
		//ans.push_back(count);
	}

	// for(auto x:ans){
	// 	cout<<x<<" ";
	// }
	return 0;
}