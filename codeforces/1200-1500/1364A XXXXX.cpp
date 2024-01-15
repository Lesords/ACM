#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：如果所有数都可以被整除，则无解
//如果所有数之和不可以被整除，则结果为数组长
//否则找到第一个可以被整除的数（取后面的值）
//和 最后一个不可被整除的数（取前面的值）

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        int flag = 0,sum = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(a[i]%x) flag = 1;//表示出现不可整除的数
            sum += a[i];
        }
        if(!flag) {//没有出现不可整除的数，即无解
            cout<<"-1\n";
            continue;
        }
        if(sum%x) cout<<n<<"\n";//总和不被整除
        else {
            int l = 0,r = n;
            for(int i = 1;i <= n;i++) {//寻找左边点（不被整除）
                if(a[i]%x) {
                    l = i;break;
                }
            }
            for(int i = n;i >= 1;i--) {//寻找右边点（不被整除）
                if(a[i]%x) {
                    r = i;break;
                }
            }
            //不包括点
            cout<<max(n-l,r-1)<<'\n';//取较大值
        }
    }
    return 0;
}
