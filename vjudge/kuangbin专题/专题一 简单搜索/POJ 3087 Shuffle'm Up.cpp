#include<iostream>//ac  ֱ��ģ��
#include<cstring>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 105;
int main() {
    int t;
    cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        int n,ans = 0,flag = 0;
        string a,b,c;
        set<string> st;//��¼�Ѳ��������ƶѣ��ж��Ƿ��޽�
        cin>>n>>a>>b>>c;
        while(1) {
            string d = "";//��ʼ��Ϊ��
            ++ans;//��¼��������
            //�������������Ǵ������ϸ��ģ����Բ���Ҳ�������ϲ���
            for(int i = 0;i < n;i++) {//�����ƶѺ�����
                d += b[i];
                d += a[i];
            }
            if(st.count(d)==1) break;//�Ѳ����������޽�
            else st.insert(d);
            a = b = "";//a��b�ƶѸ�ȡһ��
            for(int i = 0;i < n;i++) {//���Ϊa��������b
                a += d[i];
            }
            for(int i = n;i < n*2;i++) {
                b += d[i];
            }
            if(d==c) {//������������������
                cout<<cas<<" "<<ans<<"\n";
                flag = 1;break;
            }
        }
        if(!flag) cout<<cas<<" "<<"-1\n";//�����޽�����
    }
    return 0;
}
