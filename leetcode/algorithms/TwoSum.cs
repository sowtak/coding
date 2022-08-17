using System;
using System.Collections.Generic;
class Solution 
{
  public int[] TwoSum(int[] nums, int target) 
  {
    Dictionary<int, int> TargetMinusNumsElement = new Dictionary<int, int>();
    for (int i = 0; i < nums.Length; i++)
    {
      if(!TargetMinusNumsElement.ContainsKey(nums[i]))
        TargetMinusNumsElement[target-nums[i]] = i; 
      else
      {
        return new int[2] {i, TargetMinusNumsElement[nums[i]]};
      }
    }
  }
}
