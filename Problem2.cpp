// Problem Name: Calculate tax amount in brackets
// Time Complexity : O(1) - limited number of tax brackets
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no

// Your code here along with comments explaining your approach
// 1. We calculate tax with min of (currentBracket - prevBracket, income)
// 2. Update our result with the tax
// 3. Reduce the tax from income, and return once income reaches 0
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    double result = 0.0;
    int prev = 0;
    int i = 0;
    while (income > 0) {
      int incomeRange = brackets[i][0];
      int percent = brackets[i][1];
      int tax = min(incomeRange - prev, income);
      result += (tax * percent) / 100.0;
      income -= tax;
      prev = incomeRange;
      i++;
    }
    return result;
  }
};
