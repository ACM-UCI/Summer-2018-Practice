// Solution 1
// runtime: O(n^2)

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;

    // Sorting helps because we can avoid repeating the same numbers
    // once the data is sorted. We only need to analyze a new pair of
    // numbers when the first one has changed, and the second one has
    // also changed.
    sort(nums.begin(), nums.end());

    // Find the maximum index of the number with each value. Need maximum
    // so that none of the triples can be repeated. We'll simply check if
    // the solution to each pair has an index greater than the index of
    // both numbers; if so, the number comes from later on in the array.
    // This prevents repetition because, for instance if we have [-1, 0, 1],
    // we only put in 1 for the pair [-1, 0], and not -1 for the pair [0, 1].
    unordered_map<int, int> num_to_idx;
    for (int i = 0; i < nums.size(); ++i) {
      num_to_idx[nums[i]] = i;
    }

    // Find the sums
    for (int i = 0; i < nums.size(); ++i) {
      if (!(i == 0 || nums[i] != nums[i - 1])) continue;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (!(j == i + 1 || nums[j] != nums[j - 1])) continue;
        int third = 0 - nums[i] - nums[j];
        if (num_to_idx.find(third) != num_to_idx.end()) {
          // third is guaranteed greater than i, since j > i
          if (num_to_idx[third] > j) {
            res.push_back({third, nums[i], nums[j]});
          }
        }
      }
    }

    return res;
  }
};

// Solution 2
//
// runtime: O(n^2) (but faster than the last one because there is no map access)
// This solution differs from the first because it avoids an unordered map.
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;

    int n = nums.size();
    sort(nums.begin(), nums.end());

    // Find the sums
    // Here, instead of trying to find the third number for each i and j,
    // we set the first number and look for the second and third number
    // (left and right). We gradually move the pointers left and right
    // looking for unique solutions until left and right meet.
    for (int i = 0; i < n - 2; ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int needed = 0 - nums[left] - nums[right];
        if (nums[i] == needed) {
          // If found a solution, add it on and move left and
          // right to be at different locations.
          // We know we need to move both of the pointers because
          // if one of them changes, the other has to change as well
          // to satisfy the equation.
          res.push_back({nums[i], nums[left], nums[right]});
          ++left;
          while (left < right && nums[left] == nums[left - 1]) ++left;
          --right;
          while (left < right && nums[right] == nums[right + 1]) --right;
        } else if (nums[i] > needed) {
          // If nums[i] is too big, needed has to increase.
          // This means that nums[left] + nums[right] has to decrease,
          // so we move the right pointer.
          //
          // No need to keep checking for repeated here because this will
          // be handled by the outer for loop. Putting another nested loop
          // in here (probably?) slows you down.
          --right;
        } else {
          // Otherwise, we move the left one.
          ++left;
        }
      }
    }
    return res;
  }
};
