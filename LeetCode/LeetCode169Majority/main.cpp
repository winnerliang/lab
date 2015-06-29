#include <iostream>
#include <vector>

using namespace std;

/*
int majorityElement(vector<int>& nums) {
    int cnt=1, ele = nums[0];
    for(vector <int>::size_type i= 1; i!= nums.size(); i++)
    {
        if(nums[i] == ele)
            cnt++;
        else
            cnt--;
        if(cnt < 0)
        {
            cnt=1;
            ele=nums[i];
        }
    }
    if (cnt<0)
    {
        cout<<"error"<<endl;
        return -1;
    }
    cnt=0;
    for(vector <int>::size_type i= 1; i!= nums.size(); i++)
    {
        if(nums[i] == ele)
        {
            cnt++;
        }
    }
    if(cnt > nums.size()/2)
        return ele;
    else
    {
        cout<<"eror"<<endl;
        return -1;
    }

}

*/

static int majorityelem(vector<int>& nums, int start, int end, bool & flag) {
    if( end -start ==0)
    {
        flag =1;
        return nums[start];
    }
    int mid = (start + end)/2;
    bool leftf=true, rightf= true;
    int left = majorityelem(nums, start, mid, leftf);
    int right = majorityelem(nums, mid+1, end, rightf);

    flag = leftf | rightf;
    if(left == right)
        return left;
    int leftcnt=0, rightcnt=0;
    for(int i=start; i<= end; i++)
    {
        if(nums[i] == left)
            leftcnt++;
        else if(nums[i] == right)
            rightcnt++;
    }
    int mmax  = (end - start +1)/2;
    if(leftcnt > mmax)
        return left;
    else if(rightcnt >mmax)
        return right;
    flag = false;
    return 0;
}

int majorityElement(vector<int>& nums) {
    bool flag= true;
    int length = nums.size()-1;
    return majorityelem(nums, 0, length, flag);
}



int main()
{
    int data[]={3,3,4,2,4,4,2,4,4};
    vector<int> t;
    for(int i=0; i<9; i++)
        t.push_back(data[i]);

    cout<<majorityElement(t);
    return 0;
}
