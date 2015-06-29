#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string inttostring(const int n)
{
    string ret;
    char buf[32];
    sprintf ( buf, "%d", n); // #include <stdlib.h>
    ret.append (buf);
    return ret;
}

void addstring(vector<string>&ret, int left, int right)
{
    if(left == right)
    {
        string s = inttostring(left);
        ret.push_back(s);
        return ;
    }
    string s = inttostring(left)+"->"+ inttostring(right);
    ret.push_back(s);
    return ;
}

bool Ischanged(int curt, int next)
{
    if(curt != next-1)
        return true;
    else
        return false;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    int left, right;

    if(nums.size()<1)
        return ret;

    int dir =0;
    left = nums[0];
    if(nums.size() == 1 || Ischanged(nums[0], nums[1]))
    {
        right = left;
        addstring(ret, left, right);
        if(nums.size()==1)
            return ret;
        dir = 1;
    }

    for(int i=1; i< nums.size()-1; i++)
    {
        if(dir == 1)
        {
            left = nums[i];
            dir = 0;
        }
        if(Ischanged(nums[i], nums[i+1]))
        {
            if(dir ==1 )
            {
                addstring(ret, nums[i] , nums[i] );
            }
            else
            {
                addstring(ret, left , nums[i]);
                dir = 1;
            }
        }
    }

    if(dir == 1)
    {
        addstring(ret, nums[nums.size()-1] , nums[nums.size()-1]);
    }
    else
    {
        addstring(ret, left, nums[nums.size()-1]);
    }

    return ret;
}

int main()
{
    int num[] = {0,1,2,4,5,7};
    vector<int> nums;
    for(int i=0; i<6; i++)
    {
        nums.push_back(num[i]);
    }
    vector<string>ss = summaryRanges(nums);
    for(int i=0; i<ss.size(); i++)
        cout<<ss[i]<<endl;

    return 0;
}
