#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,int> num;//ͳ��ÿ���ַ������ֵĴ���
int main() {
    int n;
    cin>>n;
    while(n--) {
        string tmp;
        cin>>tmp;
        if(num.count(tmp)) {//�����ֹ�
            //���ԭ�ַ����ͳ��ִ���
            cout<<tmp<<num[tmp]<<"\n";
        }
        else cout<<"OK\n";
        num[tmp]++;//����++
    }
    return 0;
}
