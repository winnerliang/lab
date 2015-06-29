#include <iostream>
#include <vector>

using namespace std;

typedef struct majority3
{
    int ele;
    int cnt;
}M3;

void addele(M3 save[], int num)
{
    int i;
    for( i=0; i< 3; i++)
    {
        if(save[i].ele == num && save[i].cnt != 0)
        {
            save[i].cnt++;
            return;
        }
    }
    for( i=0; i<3; i++)
    {
        if(save[i].cnt == 0)
        {
            break;
        }
    }

    if(i < 3)
    {
        //there is a cnt = 0
        save[i].ele = num;
        save[i].cnt = 1;
        return ;
    }

    for(i=0; i<3; i++)
    {
        save[i].cnt--;
    }
    for( i=0; i<3; i++)
    {
        if(save[i].cnt == 0)
            break;
    }

    save[i].ele = num;
    save[i].cnt = 1;
}

vector<int> majorityElement(vector<int>& nums) {
    //initializing
    vector<int> ret;

    M3 save[3];
    int n = nums.size();
    int limit = n/3;

    //cout<<"limit:" <<limit <<endl;
    int i=0;
    for(; i<3; i++)
    {
        save[i].cnt=0;
    }

    for(i=0; i<nums.size(); i++)
    {
        addele(save, nums[i]);
    }

    for(i=0; i<3; i++)
    {
        if(save[i].cnt >0)
        {
            int ele = save[i].ele;
            int counts=0;
            for(int j=0; j< nums.size(); j++)
            {
                if(nums[j] == ele)
                    counts++;
            }
            if(counts > limit)
                ret.push_back(ele);
            else if(n <3 && counts == n)
                ret.push_back(ele);
        }
    }
    return ret;
}

int main()
{
    int num[]={1,2,2,2,1};

    vector<int> nums;
    for(int i=0; i< 2; i++)
        nums.push_back(num[i]);

    vector <int> dis = majorityElement(nums);

    for(int i=0; i<dis.size(); i++)
        cout<< dis[i] <<", ";
    return 0;
}
