#include<iostream>//ac
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//题解：由于对同一前缀翻转两次，结果不变
//所以可以从后往前开始判断，如果两者不同的话，可以先翻转当前前缀
//然后翻转第一个，再翻转当前前缀（可使当前位置变化，其他不变）

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string a,b;
        vector<int> ans;//记录翻转的位置
        cin>>n>>a>>b;
        for(int i = n-1;i >= 0;i--) {//从后往前开始计算
            if(a[i]!=b[i]) {//不等
                ans.push_back(i+1);//i+1位置（存储起点为0）
                ans.push_back(1);//当前位置翻转两次，加首位置翻转
                ans.push_back(i+1);
            }
        }
        cout<<ans.size();//输出操作总数和操作数列
        for(int i = 0;i < ans.size();i++) cout<<" "<<ans[i];
        cout<<"\n";
    }
    return 0;
}
