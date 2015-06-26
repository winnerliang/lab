#include <iostream>
#include <vector>

using namespace std;

void matchingother(const int N, int &times)
{
    unsigned long limit = 1<<(N<<1);
    cout<<limit<<endl;
    for(unsigned long i = 0; i<limit; i++)
    {
        int sum=0;
        int t=1;
        for(int j=0; j<(N<<1) && sum>=0; ++j, t=t<<1)
        {
            if( (i & t) != 0)
            {
                sum+=1;
            }
            else
            {
                sum-=1;
            }

        }
        if(sum==0)
        {
            //display
            times++;
        }
    }
}

void matching(int left, int right, vector<char> & src, int sum, const int N, int &cnt)
{
    int t = N<<1;
    if(left < right)
        return;
    if(sum == t)
    {
        for(int i=0; i< t; i++)
            cout<<src[i];
        cout<<endl;
        cnt++;
    }
    if(left < N)
    {
        src.push_back('(');
        left++;
        sum++;

        matching(left, right, src, sum, N,cnt);

        src.pop_back();
        left--;
        sum--;
    }
    if(right < N)
    {
        src.push_back(')');
        right++;
        sum++;

        matching(left, right, src, sum, N, cnt);

        src.pop_back();
        right--;
        sum--;
    }
}

int main()
{
    vector<char>src;
    int cnt=0;
    //matching(0,0,  src, 0, 4, cnt);
    matchingother(4, cnt);
    cout<<"cnt:"<<cnt;
    return 0;
}
