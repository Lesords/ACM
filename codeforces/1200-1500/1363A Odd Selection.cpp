#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ͳ������������ż�������������ڽ��Ϊ����������������������Ϊ����
//Ȼ��ö������������������ö��1,3,5��������
//�ж�ʣ������Ƿ�Ϊ����������С��ż��������
//�������򲻳���

const int MAXN = 1005;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        int odd = 0,even = 0,flag = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            a[i]%2==0?even++:odd++;//ͳ����ż����
        }
        for(int i = 1;i <= odd;i+=2) {//ö����������������������
            int rest = x-i;//ʣ�������������Ϊ����������
            if(even>=rest&&rest>=0) {//ʣ���ż�����ڲ�ֵ����������
                flag = 1;break;
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
