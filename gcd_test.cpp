#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
{


   "cmd": ["g++.exe", "-std=c++17", "${file}",
            "-o", "${file_base_name}.exe",
            "&&", "${file_base_name}.exe<inputf.in>outputf.out"],
    "shell":true,
    "working_dir":"$file_path",
    "selector":"source.cpp"
}
*/

int gcd(int a  , int b){
//complexity O(log(min(a , b)))
	while(b){
		a%=b;
		swap(a,  b);
	}
	return a;
}

int main(){

	int t;
	cin>>t;

	while(t--){
		int x;int y;
		cin>>x>>y;

		cout<<gcd(12 , 144)<<endl;

		if(x>y){
			cout<<gcd(x , y)<<endl;
		}
		else{
			cout<<gcd(y , x)<<endl;
		}
	}

	return 0;
}