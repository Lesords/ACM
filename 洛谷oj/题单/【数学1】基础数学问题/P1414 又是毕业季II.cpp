#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//题解：由于最大公约数其实就是各个数的共同因子
//所以直接统计所有数字的因子，判断对应因子的数字是否满足当前个数
//若不满足，则判断下一个值较小的数字
//注意：若一个因子在n数量下满足条件，那么对于所有小于n的数量也满足条件
//可理解为只取n中的部分数量

const int MAXN = 1e6+6;
int num[MAXN];//记录因子出现的次数
int main() {
    int n,maxx = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;cin>>tmp;
        maxx = max(maxx,tmp);//记录最大值
        for(int j = 1;j <= sqrt(tmp);j++) {//计算tmp的所有的因子
            if(tmp%j) continue;//不为因子，跳过
            num[j]++;//记录因子数量
            if(j*j!=tmp) num[tmp/j]++;//不为平方数，则另一个因子也记录
        }
    }
    int pos = maxx;//从最大值开始向下寻找符合条件的值
    for(int i = 1;i <= n;i++) {
        while(num[pos]<i) pos--;//pos出现的次数不满足条件，则值--
        cout<<pos<<"\n";//pos即为所需要的因子
    }
    return 0;
}
