#include<iostream>//ac
#include<string>
#include<vector>
using namespace std;
vector<string> v;
int main() {
    string tmp;
    while(cin>>tmp) {
        if(tmp[0]=='.') break;//.Ϊ�����ַ�
        v.push_back(tmp);
    }
    if(v.size()<2) cout<<"Momo... No one is for you ...";//С������
    else if(v.size()<14) cout<<v[1]<<" is the only one for you...";//С��14��
    else cout<<v[1]<<" and "<<v[13]<<" are inviting you to dinner...";
    return 0;
}
