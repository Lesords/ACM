#include<iostream>//ac
#include<string>
#include<map>
using namespace std;
map<string,string> mp;
int main() {
    int k,cnt = 0;//cnt��¼Ӯ�Ĵ���
    mp["ChuiZi"] = "Bu";
    mp["JianDao"] = "ChuiZi";
    mp["Bu"] = "JianDao";//ӳ��
    string tmp;
    cin>>k;
    while(cin>>tmp) {
        if(tmp=="End") break;//End����
        cnt++;
        if(cnt>k) cout<<tmp<<"\n",cnt = 0;//Ӯ������������������k��
        else cout<<mp[tmp]<<"\n";
    }
    return 0;
}
