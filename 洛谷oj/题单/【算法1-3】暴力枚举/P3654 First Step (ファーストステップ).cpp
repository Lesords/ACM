#include<iostream>//ac
#include<algorithm>
using namespace std;
char map[105][105];
int main() {
    int r,c,k;
    cin>>r>>c>>k;//r行c列 k个连续
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++) cin>>map[i][j];
    int ans = 0;
    for(int i = 1;i <= r;i++) {//计算行中可以站位的方式数
        int tmp = 0;
        for(int j = k;j <= c;j++) {//从第k个开始遍历i行的元素
            int flag = 1;
            //判断k个连续是否都为 .
            for(int z = j;z >= j-k+1;z--) if(map[i][z]!='.') {
                flag = 0;break;
            }
            tmp += flag;
        }
        ans += tmp;//添加当前行的方式数
    }
    for(int j = 1;j <= c;j++) {//计算列中可以站位的方式数
        int tmp = 0;
        for(int i = k;i <= r;i++) {//从第k个开始遍历j列的元素
            int flag = 1;
            //判断k个连续是否都为 .
            for(int z = i;z >= i-k+1;z--) if(map[z][j]!='.') {
                flag = 0;break;
            }
            tmp += flag;
        }
        ans += tmp;//添加当前列的方式数
    }
    if(k==1) ans/=2;//如果只需要一个的话，横竖会重复计算，则需除2 ！！！
    cout<<ans<<endl;
    return 0;
}
