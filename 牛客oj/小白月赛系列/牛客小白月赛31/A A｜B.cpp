#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：a|b = a+b，则对于b来说，a中为1的位置必为0，所以只需要判断a中有多少0即可
//由于b的值不能超过x，所以可将x分段处理，从最大开始计算
//每次碰到1开始计算0的数量，如果a和x的位置都为1，则无解（结束计算）
//因为a中为1的位置应该为0！！！

int val[33],num[33];//val存所有二的次方值，num记录各个位置中0的数量
int main() {
    for(int i = 0;i < 31;i++) val[i] = 1<<i;//预处理所有的二的次方结果
    int t;
    cin>>t;
    while(t--) {
        int a,x;
        cin>>a>>x;
        num[0] = (a&1)==0;
        for(int i = 1;i < 31;i++) {//用前缀和来计算0的数量
            num[i] = num[i-1]+((a&(1<<i))==0);
        }
        int ans = 0;
        for(int i = 30;i >= 0;i--) {//从高位到低位计算结果
            if((x&(1<<i))==0) continue;//跳过为0的位
            if(i==0) ans++;//最低位的话，只有一个结果（当前为值为0）
            else ans += val[num[i-1]];//否则为下一个位置到结束位包含的0的数量
            if(a&(1<<i)) break;//两个位置都为1，则后面无解，结束判断
        }
        if((a+x)==(a|x)) ans++;//特判x是否满足条件
        cout<<ans-1<<"\n";//减去一个0
    }
    return 0;
}
