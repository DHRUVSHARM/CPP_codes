#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void zfunction(string str , int * z){
	
	int n=str.size();

	int l=0;int r=0;int i=1;

	z[0]=0;

	while(i<n){

		if(i>r){
			l=i;r=i;
			while(r<n && str[r-l]==str[r]){r++;}
			z[i]=r-l;
			r--;
		}
		else{
			int k=i-l;
			if(z[k]+i <= r){
				//inbound, can use previous result
				z[i]=z[k];
			}
			else{
				//out of bound , cannot use previous result
				l=i;
				while(r<n && str[r-l]==str[r]){r++;}
				z[i]=r-l;
				r--;
			}
		}

		i++;
	}

}

vector<int> solve(string str , string pattern , string text , int * z){

	int n=str.size();
	int pattern_size=pattern.size();int text_size=text.size();

	vector<int> indices;

	for(int i=pattern_size+1;i<n;i++){
		if(z[i]==pattern_size){
			//patetrn found 
			indices.push_back(i-pattern_size-1);
		}
	}

	return indices;
}

int main(){

	string pattern , text;
	cin>>pattern>>text;

	string str=pattern + '$' + text;

	//cout<<str;

	int * z=new int[str.size()]();

	zfunction(str , z); //to get the z values

	//cout<<endl;for(int i=0;i<str.size();i++){cout<<z[i]<<endl;}
	cout<<endl;

	vector<int> indices=solve(str , pattern , text , z);

	if(indices.size()==0){cout<<"pattern not found"<<endl;}
	else{
		cout<<"pattern found , indices of occurence are:"<<endl;
		for(int i=0;i<indices.size();i++){
			cout<<indices[i]<<" ";
		}
	}

	delete[] z;

	return 0;
}