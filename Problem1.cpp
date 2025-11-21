// Problem Name: Robot bounded in circle
// Time Complexity : O(n)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no

// Your code here along with comments explaining your approach
// 1. We observe that in order to be bounded by a circle, we can perform the
// instruction single time and check if we are at origin, then return true and
// if we are facing another direction then return true otherwise false, it means
// if we start with north and after executing the instruction we end up at north
// again, we will never reach the origin
// 2. We maintain anticlockwise dirs list and incase of L do dir + 1 and incase
// of r do dir - 1 and use modulo to keep everything in bounds
// 3. If after completing each instruction, we check if we have reach the origin
// again, if yes we return true
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isRobotBounded(string instructions) {
    pair<int, int> start = {0, 0};
    int dir = 0;
    // n w s e - anticlockwise
    vector<pair<int, int>> adirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    for (auto ch : instructions) {
      if (ch == 'G') {
        start.first += adirs[dir].first;
        start.second += adirs[dir].second;
      } else if (ch == 'L') {
        dir = (dir + 1) % 4;
      } else {
        dir = (dir - 1 + 4) % 4;
      }
    }
    if (start.first == 0 && start.second == 0) {
      return true;
    }
    if (dir != 0)
      return true;
    return false;
  }
};
