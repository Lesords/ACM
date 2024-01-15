#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：只用ab构成字符串
//先输出全a的字符串当成首个字符串，然后用last记录上个字符串
//每个输出last字符串中前a[i]个，剩余的根据第 a[i]+1 个来取反即可

const int MAXN = 105;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        string last(50,'a');//初始化全a为第一个
        cout<<last<<"\n";//输出第一个
        string now = "";
        for(int i = 1;i <= n;i++) {//构造剩余n个
            now = "";
            for(int j = 0;j < a[i];j++) now += last[j];//a[i]个相同
            //下标a[i] 其实就是第 a[i]+1 个！！！（数组从0开始）
            for(int j = 0;j < 50-a[i];j++) now += (last[a[i]]=='a')?'b':'a';//取反
            cout<<now<<"\n";
            last = now;//更新last字符串
        }
    }
    return 0;
}
