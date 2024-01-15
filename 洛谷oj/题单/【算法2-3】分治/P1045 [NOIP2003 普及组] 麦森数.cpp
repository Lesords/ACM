#include<iostream>//ac
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

//题解：题目分成两个部分，一个是计算结果的位数、一个是计算结果的后500值
//对于一个数我们可以根据10^x中x的值来判断这个数有多少位数（值为x+1）
//例如：10^2 = 100 有三位
//那么对于2^p-1来说，由于是2的次方所有后面不会有0（需要有因子2和5才有0）
//所以 2^p-1的位数 = 2^p的位数
//那么对于2 = 10^(log_10 2) => 2^p = (10^(log_10 2))^p = 10^((log_10 2) * p)
//则位数 = (log_10 2) * p + 1
//对于后500直接高精度快速幂即可

const int MAXN = 501;
int a[MAXN],val[MAXN],c[MAXN];//c用来存储中间运算结果，val为最终结果
int main() {
    int p;
    cin>>p;
    int num = log10(2)*p+1;//位数
    val[1] = 1;//初始化为1
    a[1] = 2;//底为2
    while(p) {                                      //快速幂求 2^p后500位的值
        if(p&1) {
            for(int i = 1;i < MAXN;i++) {           //遍历所有的a
                for(int j = 1;j < MAXN;j++) {       //遍历所有的val
                    int tmp = a[i]*val[j];          //当前位置的计算结果
                    if(i+j-1>=MAXN) continue;       //不能超过500位
                    tmp += c[i+j-1];                //累加！！！
                    c[i+j-1] = tmp%10;              //个位数即为当前的值
                    if(i+j<MAXN) c[i+j] += tmp/10;  //十位数为下一位的值，需要判断不能超过500位
                }
            }
            for(int i = 1;i < MAXN;i++) {
                val[i] = c[i];                      //计算结果转移到val数组
                c[i] = 0;                           //需要初始化为0，因为当前位需要累加！！！
            }
        }
        for(int i = 1;i < MAXN;i++) {               //遍历所有的a
            for(int j = 1;j < MAXN;j++) {           //遍历所有的a
                int tmp = a[i]*a[j];                //计算当前位置的值
                if(i+j-1>=MAXN) continue;           //不能超过500位
                tmp += c[i+j-1];                    //累加！！！
                c[i+j-1] = tmp%10;                  //个位数即为当前的值
                if(i+j<MAXN) c[i+j] += tmp/10;      //十位数为下一位的值，需要判断不能超过500位
            }
        }
        //c[i]需要初始化为0，因为当前位需要累加！！！
        for(int i = 1;i < MAXN;i++) a[i] = c[i],c[i] = 0;
        p >>= 1;
    }
    //-1
    if(val[1]>=1) {//低位满足
        val[1] -= 1;
    }
    else {
        for(int i = 2;i < MAXN;i++) {               //不满足找高位有值的借位
            if(val[i]>=1) {
                for(int j = i-1;j >= 1;j--) val[i] = 9;//那么前面所有的低位值都为9
                break;                              //借宿
            }
        }
    }
    cout<<num<<"\n";
    for(int i = 1,j = 500;i <= 500;i++,j--) {
        cout<<val[j];
        if(i%50==0) cout<<"\n";                     //每50个换行
    }
    return 0;
}
