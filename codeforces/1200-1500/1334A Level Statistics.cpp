#include<iostream>//ac
#include<algorithm>
using namespace std;
int p[105], c[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int flag = 0,pp,cc;
        for(int i = 1;i <= n;i++) {
            cin>>p[i]>>c[i];
            if(flag) continue;
            if(i==1) {//��ʼ�ɹ��������ܴ��ڳ�������
                if(c[i]>p[i]) flag = 1;
            }
            pp = p[i]-p[i-1], cc = c[i]-c[i-1];
            //����ĳ��������ͳɹ�����������С��ǰ���
            //�ɹ������Ĳ�ֵҲ���ܴ��ڳ��������Ĳ�ֵ
            if(p[i]<p[i-1]||c[i]<c[i-1]||pp<cc) flag = 1;
        }
        cout<<(flag?"NO\n":"YES\n");
    }
    return 0;
}
