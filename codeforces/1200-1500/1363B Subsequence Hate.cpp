#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：满足条件要么为前面1后面0，要么为前面0后面1（例1100,0011）
//那么可以先记录一下1的数量和0的数量
//然后在遍历一遍字符串，以总数量为01的后缀数量，并再记录一遍前缀数量
//然后计算10和01两种情况的最小值（任何一个位置都可为01的分割点）

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int one = 0,zero = 0;
        for(int i = 0;i < s.size();i++) {//计算01的数量
            if(s[i]=='1') one++;
            else zero++;
        }
        int ans = INF,pre1 = 0,pre0 = 0;//答案，01的前缀数量
        for(int i = 0;i < s.size();i++) {
            if(s[i]=='1') pre1++,one--;//当前为1，1的前缀增加，后缀减少
            if(s[i]=='0') pre0++,zero--;//当前为0，0的前缀增加，后缀减少
            ans = min(ans, pre0+one);//10
            ans = min(ans, pre1+zero);//01
        }
        cout<<ans<<"\n";
    }
    return 0;
}
