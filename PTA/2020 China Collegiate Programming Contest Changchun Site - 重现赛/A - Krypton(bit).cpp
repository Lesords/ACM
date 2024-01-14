#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：利用二进制判断选取的所有方案，然后计算最大值即可

int num[] = {1,6,28,88,198,328,648};
int siz[] = {8,18,28,58,128,198,388};
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i < (1<<7);i++) {//每个优惠券占一个位置
        int tmp = 0,val = 0;//tmp计算选择券之后的RMB，val计算券的值
        for(int j = 0;j < 7;j++) {//1表示选，0表示不选
            if(i&(1<<j)) {
                tmp += num[j];
                val += siz[j]+num[j]*10;
            }
            if(tmp>n) break;//RMB多了
        }
        if(tmp>n) continue;//RMB多了
        ans = max(ans,val+(n-tmp)*10);//取大值
        //  (n-tmp)为剩余的
    }
    cout<<ans;
    return 0;
}
