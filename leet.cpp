class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=0;
        int n=s.size();
        
        int ** dp=new long long int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        
        for(int gap=0;gap<n;gap++){
            int i=0;int j=i+gap;
            while(j<n){
                if(gap == 0){
                    dp[i][j]=1;
                    
                }
                else if(gap==1){
                    if(s[i]==s[j]){dp[i][j]=2;}
                    else{dp[i][j]=1;}
                 
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i][j-1] , dp[i+1][j]);
                    }
                }
                            
                len=max(len , dp[i][j]);
                            i++;j++;
            }
        }
                            
            for(int i=0;i<n;i++){delete[] dp[i];delete[] dp;}
                      return len;      
   
    }
};