#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	stack<int> st;
	vector<int> v(n,-1);
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v[i]=temp;
	}
	vector<int> ans;
	
	for(auto x:v){
		while(!st.empty() && x>=st.top()){
			st.pop();
		}
		if(st.empty()){
			ans.push_back(-1);
		}else{
			ans.push_back(st.top());
		}
		st.push(x);
	}

	for(auto x:ans){
		cout<<x<<" ";
	}
	return 0;
}