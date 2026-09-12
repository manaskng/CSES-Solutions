class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minmoves=0, mini=INT_MAX;
        for(auto n:nums) mini=min(mini,n);
        for(auto num:nums) minmoves+=num-mini;
        return minmoves;
    }
};