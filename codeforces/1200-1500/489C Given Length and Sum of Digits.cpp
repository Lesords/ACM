#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：直接构造长m的数即可，特判长为1和为0的情况
//和的范围需要大于1并且小于 m*9 因为最小值为第一位为1其他为0，最大值为全9
//初始化第一位都为1，最小值从最低位到最高位开始构造
//最大值从最高位到最低位开始构造

const int MAXN = 105;
int a[MAXN];
int main() {
    int m,s;
    scanf("%d%d", &m,&s);
    if(m==1&&s==0) {//特判长为1和为0的情况
        puts("0 0");
        return 0;
    }
    if(s>=1&&s<=m*9) {//m长的和的范围
        int tmp = s-1;
        a[1] = 1;//初始化高位为1
        for(int i = m;i >= 1&&tmp;i--) {//第低位到高位开始构造
            while(a[i]<9) {//每个位置不能超过9
                a[i]++;
                tmp--;
                if(tmp==0) break;//值满了，则结束
            }
        }
        for(int i = 1;i <= m;i++) printf("%d", a[i]),a[i] = 0;
        printf(" ");
        tmp = s-1;
        a[1] = 1;//初始化高位为1
        for(int i = 1;i <= m&&tmp;i++) {//从高位到低位开始构造
            while(a[i]<9) {//每个位置不能超过9
                a[i]++;
                if(--tmp==0) break;//值满了，则结束
            }
        }
        for(int i = 1;i <= m;i++) printf("%d", a[i]);
    }
    else puts("-1 -1");
    return 0;
}
