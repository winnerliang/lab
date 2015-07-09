#include <iostream>
#include <vector>

using namespace std;

/*
int maxSubArray( vector<int> & nums )
{
    int cursum=0, maxsum=nums[0];
    for( vector<int>::size_type i=0; i!= nums.size(); i++ )
    {
        cursum += nums[i];
        if( cursum > maxsum )
        {
            maxsum = cursum;
        }
        if(cursum <0)
            cursum = 0;
    }

    return maxsum ;
}

*/

static int MaxSubSum( vector<int> & nums  , int left, int right)
{
    int mid=(left +right)/2, maxleft=0, maxright=0;
    int leftsum=0, rightsum=0;
    int maximum =0;

    if(left == right)
    {
        //if(nums[left] >0)
            return nums[left] ;
    }
    maxleft = MaxSubSum(nums, left, mid);
    maxright = MaxSubSum(nums, mid+1, right);

    if(maxleft>maxright)
        maximum = maxleft;
    else
        maximum = maxright;

    maxleft = nums[mid];
    maxright = nums[mid+1];

    for(int i=mid; i>=left; i--)
    {
        leftsum += nums[i];
        if(leftsum > maxleft)
            maxleft = leftsum;
    }

    for(int i= mid+1; i<=right; i++)
    {
        rightsum += nums[i];
        if(rightsum > maxright)
            maxright = rightsum;
    }

    return maximum = ((maxleft + maxright) > maximum)?(maxleft + maxright) : maximum;
}

int maxSubArray( vector<int> & nums )
{
    return MaxSubSum(nums, 0, nums.size()-1);
}

int main()
{
    int pData[8]={4,-3,5,-2,-1,2,6,-2};
    vector<int> nums;
    for(int i=0; i< 8; i++)
    {
        nums.push_back(pData[i]);
    }
    cout << maxSubArray(nums) << endl;

    return 0;
}
