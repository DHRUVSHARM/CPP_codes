#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){

   int t;
   cin>>t;

   while(t--){

      string s;
      cin>>s;

      //we need to find leftmost zero ie; r0
      //we need to find rightmost 1 ie; l1

      int r0=s.size()-1; //is 0 dne at least last one should be zero
      int l1=0; //at least the first one should be 1

      for(int i=0;i<s.size();i++){
         if(s[i]=='1'){l1=i;}
      }
      for(int i=s.size()-1;i>=0;i--){
         if(s[i]=='0'){r0=i;}
      }

      cout<<r0-l1+1<<'\n'; 
   }

   return 0;
}