public class Combination_Sum_IV {

    class Solution {
        public int combinationSum4(int[] nums, int target) {

            // dp[i] meaning for value i, how many combination count
            int[] dp = new int[target + 1];
            dp[0] = 1;
            for (int targetValue = 1; targetValue <= target; targetValue++) {

                for (int i = 0; i < nums.length; i++) {

                    if (nums[i] <= targetValue) {
                        // @note: not dp[targetValue]=dp[targetValue-a]+dp[a]
                        //          becasue both will be added in below line for dp[a] and dp[targetValue-a]
                        dp[targetValue] += dp[targetValue - nums[i]];
                    }
                }
            }

            return dp[target];
        }
    }
}

//////

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
}