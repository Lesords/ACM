#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：先从小到大排序，然后根据双指针来更新l和r数组
//l[i]是以i为终点不超过k的最大长度
//r[i]是以i为起点不超过k的最大长度
//最后遍历一遍，取两段和的最大值即可

const int MAXN = 5e4+5;
int a[MAXN], l[MAXN], r[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//从小到大排序
    l[1] = 1;
    for(int i = 2,j = 1;i <= n;i++) {
        while(a[i]-a[j]>k) j++;
        l[i] = max(l[i-1], i-j+1);
    }
    r[n] = 1;
    for(int i = n-1,j = n;i >= 1;i--) {
        while(a[j]-a[i]>k) j--;
        r[i] = max(r[i-1], j-i+1);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans, l[i-1]+r[i]);
    }
    cout<<ans;
    return 0;
}
