class Solution {
public:
    vector<vector<int>>dp;
    int rec( int i, int j , string s , string t){

        if(j==t.size()){
            // all values matched so 
            return 1;
        }
        if(i==s.size()){
            return 0;// return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=rec(i+1,j+1, s, t) +rec(i+1, j, s, t);
        }
        // does not match so move pointer i only just
        return dp[i][j]= rec(i+1, j, s, t);
    }
    int numDistinct(string s, string t) {
        dp.assign(s.size()+1 , vector<int>(t.size()+1,-1));

        return rec(0,0, s, t);
        
    }
};