class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int,int>freq;
        for(auto i:nums1){
            for(auto j:nums2){
                freq[i+j]++;
            }
        }
        int ans=0;
        for(auto k:nums3){
            for( auto l: nums4){
                int need=-(k+l);
                if(freq.find(need)!=freq.end()){
                    ans+=freq[need];
                }
            }
        }
        return ans;
        
    }
};