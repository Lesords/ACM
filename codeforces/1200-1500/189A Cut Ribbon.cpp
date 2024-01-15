#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：题目可化为：n = ai+bj+cz，求(i+j+z)的最大值
//由于数据较小，则可以直接遍历i和j然后求z，最后取最大值即可

int main() {
    int n,a,b,c,ans = 0;
    cin>>n>>a>>b>>c;
    for(int i = 0;i <= n/a;i++) {//遍历所有i和j
        for(int j = 0;j <= n/b;j++) {
            int sum = i*a+j*b;
            int rest = n-sum;//剩余值
            if(rest<0||rest%c) continue;//不能为负数，且需要被整除
            ans = max(ans,i+j+rest/c);//取最大值
        }
    }
    cout<<ans;
    return 0;
}
