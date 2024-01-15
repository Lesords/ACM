#include<iostream>//ac
using namespace std;

//题解：直接模拟即可

const int MAXN = 1005;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        //num为回合数，sum_a为a的总和，sum_b为b的总和，flag为是否提前结束
        int num = 0, sum_a = 0, sum_b = 0,flag = 0;
        int l = 1, r = n, last_a = 0, last_b = 0;
        //左右边界，a的上一个值，b的上一个值
        while(l<=r) {
            int tmp = 0;
            num++;//回合++
            for(int i = l;i <= r;i++) {//从左到右累加值
                tmp += a[i];
                if(tmp>last_b) {//大于b的值即可结束
                    l = i+1;//移动左边界（当前已使用，后移）
                    break;
                }
                if(i==r) flag = 1;//到达边界，则提前结束
            }
            sum_a += last_a = tmp;//累加并处理上一个值
            if(flag||l>r) break;//特判提前结束条件！！！
            tmp = 0;//初始化
            num++;//另外一个回合
            for(int i = r;i >= l;i--) {//从右到左累加值
                tmp += a[i];
                if(tmp>last_a) {//大于a的值即可结束
                    r = i-1;//移动右边界
                    break;
                }
                if(i==l) flag = 1;//提前结束的条件
            }
            sum_b += last_b = tmp;//累加并更新上一个值
            if(flag) break;//特判提前结束条件
        }
        cout<<num<<" "<<sum_a<<" "<<sum_b<<"\n";
    }
    return 0;
}
