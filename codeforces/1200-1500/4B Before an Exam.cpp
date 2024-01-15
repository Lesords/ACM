#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：先判断 目的总时间 是否在 总共最小时间 和 总共最大时间 的范围内
//然后从前往后遍历，在最小时间的基础上添加还可添加的时间，直到所有时间都用完

int minT[50],maxT[50];
int main() {
    int n,sumTime,sumMin = 0,sumMax = 0;
    cin>>n>>sumTime;
    for(int i = 1;i <= n;i++) {
        cin>>minT[i]>>maxT[i];
        sumMin += minT[i];//总共最小时间
        sumMax += maxT[i];//总共最大时间
    }
    if(sumTime>sumMax||sumTime<sumMin) {//不在范围内，则无解
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        for(int i = 1;i <= n;i++) {
            int cha = maxT[i] - minT[i];//差值（可添加的值）
            if(cha<=sumTime-sumMin) {//剩余时间充足
                sumMin += cha;
                minT[i] = maxT[i];//直接为最大使用时间
            }
            else {//补其剩余时间即可
                cha  = sumTime-sumMin;
                sumMin += cha;//所剩余的时间
                minT[i] += cha;
                break;//结束
            }
        }
        for(int i = 1;i <= n;i++) cout<<minT[i]<<" ";//输出结果即可
    }
    return 0;
}
