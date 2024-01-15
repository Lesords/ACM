#include<iostream>//ac
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#define fi first
#define se second
#define pci pair<char, int>
#define INF 0x3f3f3f3f
using namespace std;

//题解：由于最优解肯定为 中间一串字符加上首尾两个不同字符
//所以可以按照顺序存储对应字符出现的次数
//然后以任意字符为中间点判断前后两个字符是否不一样，若不一样则更新答案
//当前答案为 中间字符数量+2

vector<pci> v;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        v.clear();//清空
        for(int i = 0;i < s.size();i++) {
            if(v.empty()||v.back().fi!=s[i]) {//记录为空或字符与前面不同
                v.push_back({s[i],1});
            }
            else v.back().se++;//否则字符数++
        }
        int ans = INF;
        for(int i = 1;i < v.size()-1;i++) {
            //前面不一样（满足三个字符条件）
            if(v[i-1].fi!=v[i+1].fi) ans = min(ans,v[i].se+2);//更新值
        }
        if(ans==INF) cout<<"0\n";//无解的情况
        else cout<<ans<<"\n";
    }
    return 0;
}
