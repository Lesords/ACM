//005 ������λ��
#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
struct info{
    string id;//׼��֤��
    int num;//������λ��
}data[1005];
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string s;
        int a,b;
        cin>>s>>a>>b;//�����±�洢���ݣ�Ȼ��ֱ�ӻ�ȡ����
        data[a].id = s;//aΪ�Ի�����
        data[a].num = b;
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int op;cin>>op;//�Ի�����
        cout<<data[op].id<<" "<<data[op].num<<"\n";
    }
    return 0;
}
