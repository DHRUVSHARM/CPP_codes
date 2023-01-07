#include<bits/stdc++.h>
#include<iostream>
using namespace std;

  int countPalindromicSubsequences(string s) {
        int n=s.size();
        int dp[n][n];
        
        for(int i=0;i<n;i++){for(int j=0;j<n;j++){dp[i][j]=0;}}
        
        int mod=pow(10 , 9) + 7;
        map<char , int> occurence;
        
        int * next=new int[n]();int * prev=new int[n]();
        for(int i=0;i<n;i++){
            if(occurence.find(s[i]) == occurence.end()){
                prev[i]=-1;
                occurence.insert({s[i] , i});
            }
            else{
                prev[i]=occurence[s[i]];
                occurence[s[i]]=i;
            }
        }
        
        occurence.clear();
        
        for(int i=(n-1);i>=0;i--){
            if(occurence.find(s[i]) == occurence.end()){
                next[i]=n;
                occurence.insert({s[i] , i});
            }
            else{
                next[i]=occurence[s[i]];
                occurence[s[i]]=i;
            }
        }
        
        for(int gap=0;gap<n;gap++){
            int i=0;int j=gap+i;
            while(j<n){
                if(gap == 0){dp[i][j]=1;}
                else if(gap == 1){dp[i][j]=2;}
                else{
                    
                    if(s[i]!=s[j]){
                        dp[i][j]=(dp[i][j-1] + dp[i+1][j])%mod;
                        dp[i][j]=(dp[i][j] - dp[i+1][j-1] + mod)%mod;
                    }
                    else{
                        
                        if(next[i] < prev[j]){
                            dp[i][j]=(2*dp[i+1][j-1])%mod;
                            dp[i][j]=(dp[i][j] - dp[next[i]+1][prev[j]-1] + mod)%mod;
                        }
                        else if(next[i] == prev[j]){
                         dp[i][j]=(2*dp[i+1][j-1])%mod;
                         dp[i][j]+=1;   
                        }
                        else{
                  //          cout<<"i , j:"<<"\t"<<i<<" "<<j<<endl;
                         dp[i][j]=(2*dp[i+1][j-1])%mod;
                         dp[i][j]+=2;
                        }
                    }
                }
                i++;j++;
            }
        }
        delete[] next;delete[] prev;
        return dp[0][n-1];
    }

    int main(){
        string s;
        cin>>s;

        cout<<countPalindromicSubsequences(s);

        return 0;
    }