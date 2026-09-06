class Solution {
public:
    // numbers between layers work
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;

        int ops=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                st=stack<int>();
                continue;// skip 0 
            }
            while(!st.empty()&& st.top()>nums[i]) st.pop();//keep poping elements

            if(st.empty() || st.top()<nums[i]){ // is lesser that means layer not covered already 
                //new layer so increment it
                ops++;
                st.push(nums[i]);

            }
        }
        return ops;

        
    }
};