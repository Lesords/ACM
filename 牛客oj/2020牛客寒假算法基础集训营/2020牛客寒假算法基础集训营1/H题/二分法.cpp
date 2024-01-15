//���볤�ȣ�683 ����ʱ�䣺 7 ms ռ���ڴ棺1260K

#include <stdio.h>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
typedef long long ll;
char s[N];
int pre[N] = {0};
int len, k;
bool check(int val)
{
    for(int i = val; i <= len; i++)
    {
        int tmp = pre[i] - pre[i-val];
    //  printf("%d --- %d --- %d\n", val, i, tmp);
        if(tmp <= k || val - tmp <= k) return true;
    }
    return false;
}
int main()
{

    scanf("%d %d %s", &len, &k, s+1);
    for(int i = 1; i <= len; i++)
    {
        pre[i] = pre[i-1] + s[i] - '0';
    }
    int l = 1, r = len, mid;
    while(l<=r)
    {
        mid = (l+r) / 2;
        if(check(mid))
        {
            if(!check(mid+1)) break;
            l = mid + 1;
        }else r = mid - 1;
    }
    printf("%d\n", mid);
}
