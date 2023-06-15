//* https://practice.geeksforgeeks.org/problems/binary-search-trees/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search-trees
//* https://youtu.be/p7-9UvDQZ3w

class Solution {
public:
    bool isBSTTraversal(vector<int>& nums) {
        // your code here
        
        int n = nums.size();
        
        if(n == 0 || n == 1){
            return true;
        }
        
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
};