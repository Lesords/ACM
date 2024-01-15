#include<iostream>//ac
#include<string>
using namespace std;
int main() {
    string s;
    int k;
    cin>>s>>k;
    if(k>=s.size()) {//如果删除的数大于原数的位数
        cout<<""<<endl;
        return 0;
    }
    while(k--) {//共删除k次
        for(int i = 0;i < s.size();i++) {//每次都从前开始找，且只找一个
            if(s[i]>s[i+1]) {//找到一个值高的点
                s.erase(i,1);break;//删除并结束
            }
        }
    }
    while(s.size()>1&&s[0]=='0') s.erase(0,1);//去掉前导零
    cout<<s<<endl;
    return 0;
}
