#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int left= 0, right = nums.size()-1;
    int mid = (left + right )/2;
    int flag=0;

    while(left < right-1)
    {
        mid = (left + right)/2;
        if(nums[mid] > nums[left] && nums[left] > nums[right])
        {
            left = mid;
        }
        else if(nums[mid] < nums[right] && nums[right] < nums[left])
        {
            right = mid;
        }
        else
        {
            flag =1;
            break;
        }
    }
    int mix = (nums[left] < nums[mid])?nums[left]:nums[mid];
    return mix = (nums[right] < mix)?nums[right]:mix;
}

int main()
{
    int num[] ={6,0,1,2,3,4,5};
    vector<int> nums;

    for(int i=0; i< 7; i++)
        nums.push_back(num[i]);

    cout<<findMin(nums);

    return 0;
}
