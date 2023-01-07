#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        string ans="";
        if(s.size() > 10){
            int len=(s.size()-2);
            std::string middle=std::to_string(len);
            ans=s[0] + (middle) + s[s.size()-1];
        }
        else{
            ans=s;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}