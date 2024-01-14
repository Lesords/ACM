#include<iostream>//ac
#include<string>
#include<map>
using namespace std;
map<string,string> mp;
int main() {
    int k,cnt = 0;//cnt记录赢的次数
    mp["ChuiZi"] = "Bu";
    mp["JianDao"] = "ChuiZi";
    mp["Bu"] = "JianDao";//映射
    string tmp;
    cin>>k;
    while(cin>>tmp) {
        if(tmp=="End") break;//End结束
        cnt++;
        if(cnt>k) cout<<tmp<<"\n",cnt = 0;//赢的数量不能连续多于k次
        else cout<<mp[tmp]<<"\n";
    }
    return 0;
}
