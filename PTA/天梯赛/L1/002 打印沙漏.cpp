//002 ��ӡɳ©
#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int n;
    char ch;
    cin>>n>>ch;
    int cnt = 1;
    n -= 1;//�м�һ��
    for(int i = 3;;i += 2) {//���������ÿ���2��
        if(n>(i*2)) n -= (i*2),cnt++;
        else break;
    }
    for(int i = cnt;i >= 1;i--) {//����һ��
        for(int j = cnt;j > i;j--) cout<<" ";//�ո�
        for(int j = 1;j <= 1+(i-1)*2;j++) cout<<ch;//�ַ�
        cout<<'\n';
    }
    for(int i = 2,siz = (cnt-1);i <= cnt;i++,siz--) {//�°벿��
        for(int j = 1;j < siz;j++) cout<<" ";//�ո�
        for(int j = 1;j <= 1+(i-1)*2;j++) cout<<ch;//�ַ�
        cout<<'\n';
    }
    cout<<n<<'\n';
    return 0;
}
