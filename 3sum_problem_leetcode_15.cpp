#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> find_3_sum (vector <int> &nums) {
    sort(nums.begin(),nums.end());
    vector <vector <int>> result;
        
    for (int i = 0 ; i < nums.size()-2 ; i++) {
        if (i == 0 or (i > 0 and nums[i] != nums[i-1])) {
            int target = -nums[i];
            int low = i+1;
            int high = nums.size()-1;
            while (low < high) {
                
                if (target == nums[low] + nums[high]) {
                    
                    result.push_back (vector <int> {nums[i] , nums[low] , nums[high]});
                    
                    while (low < high and nums[low] == nums[low+1]) {low++;}
                    while (low < high and nums[high] == nums[high-1]) {high--;}
                    low++;
                    high--;
                }
                else if (target > nums[low]+nums[high]) {low++;}
                else {high--;}
            }
        }
    }
    return result;

}

int main () {
    vector <int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = find_3_sum (arr);
    for (int i = 0 ; i < result.size() ; i++) {
        cout << "(" << result[i][0] << "," << result[i][1] << "," << result[i][2] << ")" << endl;
    }
}
