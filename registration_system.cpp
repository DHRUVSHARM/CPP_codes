#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	map<string , int> names;

	for(int i=0;i<n;i++){
		string request;
		cin>>request;

		if( names.find(request) == names.end() ){
			//not found
			names.insert({request , 1});
			cout<<"OK"<<endl;
		}
		else{
			//already present
			string append_num=std::to_string(names[request]);
			cout<<request + append_num<<endl;
			names[request]++;
		}

	}

	return 0;
}