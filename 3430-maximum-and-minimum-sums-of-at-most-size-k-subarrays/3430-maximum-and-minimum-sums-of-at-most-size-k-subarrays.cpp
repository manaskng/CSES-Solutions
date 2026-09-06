class Solution {
public:

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        return minOrMaxSum(nums, k, true)
             + minOrMaxSum(nums, k, false);
    }

private:

    long long minOrMaxSum(vector<int>& nums, int k, bool isMin) {

        long long sum = 0;
        int n = nums.size();

        // Monotonic stack of indices
        stack<int> st;
        st.push(-1);

        for (int i = 0; i <= n; i++) {

            while (st.top() != -1 &&
                   (i == n ||
                    (isMin && nums[st.top()] >= nums[i]) ||
                    (!isMin && nums[st.top()] <= nums[i]))) {

                int middle = st.top();
                st.pop();

                int left = st.top() + 1;
                int right = i - 1;

                int minLeft = max(left, middle - k + 1);
                int maxRight = min(middle + k - 1, right);

                long long subArrayCount = 0;

                if (maxRight - minLeft < k) {

                    // Length restriction is automatically satisfied.
                    subArrayCount =
                        1LL * (middle - minLeft + 1) *
                        (maxRight - middle + 1);

                } else {

                    // Choose the side having fewer possibilities
                    // to reduce the amount of iteration.

                    if (middle - minLeft < maxRight - middle) {

                        // Fix left boundary
                        for (int l = minLeft; l <= middle; l++) {

                            int maxR = min(right, l + k - 1);

                            subArrayCount +=
                                max(maxR - middle + 1, 0);

                        }

                    } else {

                        // Fix right boundary
                        for (int r = middle; r <= maxRight; r++) {

                            int minL = max(r - k + 1, left);

                            subArrayCount +=
                                max(middle - minL + 1, 0);
                        }
                    }
                }

                sum += subArrayCount * nums[middle];
            }

            st.push(i);
        }

        return sum;
    }
};