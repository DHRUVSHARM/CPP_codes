#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void getlps(int * lps , string pattern){
	lps[0]=0;
	if(pattern.size()==1){return;}
	int i=1;int j=0;

	while(i<pattern.size()){

		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			j++; i++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				lps[i]=0;i++;
			}
		}
	}

	return;
}

bool kmp(string text , string pattern , int * lps){

	int i=0;int j=0;

	while(i<text.size() && j<pattern.size()){
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}

	if(j==pattern.size()){return true;}
	else{return false;}
}

vector<int> kmpi(string text , string pattern , int * lps){

	vector<int> indices;

	int i=0;int j=0;

	while(i<text.size()){

		if(j==pattern.size()){
			//found pattern , have to add the index to the indices
			indices.push_back(i-pattern.size());
			j=lps[j-1];
		}

		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}

			else{
				i++;
			}
		}
	}

	if(j==pattern.size()){
		indices.push_back(i-pattern.size());
	}

	return indices;

}

int main(){

	string text,pattern;
	cin>>text>>pattern;

	int * lps=new int[pattern.size()]();
	getlps(lps , pattern);

//	cout<<endl;for(int i=0;i<pattern.size();i++){cout<<lps[i]<<" ";}

	bool ans=kmp(text , pattern , lps);
	if(ans){cout<<"match"<<endl;}
	else{cout<<"unmatch"<<endl;}

	vector<int> indices=kmpi(text , pattern , lps);
	cout<<endl;
	for(int i=0;i<indices.size();i++){
		cout<<indices[i]<<" ";
	}

	delete[] lps;

	return 0;
}