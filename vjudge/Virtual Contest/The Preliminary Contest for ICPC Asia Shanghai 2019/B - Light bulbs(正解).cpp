#include<iostream>//ac ���
#include<algorithm>
using namespace std;

//������֤������������ֲ������䲻�ཻ�����������϶�����
//��������ֲ��������ཻ����ô��һ�������ĩ�ڵ㣨�����䣩�Ḳ�ǵڶ������䣬��Ϊ�µ���������
//�ڶ�������ĳ��ڵ㣨�������������һ�����䣬��Ϊ�µĵ�һ�������ĩ�ڵ㣨��������

const int MAXN = 1e6+6;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++) {
        int n,m,cnt = 0;
        cin>>n>>m;
        for(int j = 1;j <= m;j++) {
            int x,y;
            cin>>x>>y;
            a[++cnt] = x;//��¼Ϊ����ҿ��������ص�ʱ���㣡����
            a[++cnt] = y+1;//a�����¼��Ӧ���λ��
        }
        sort(a+1,a+cnt+1);//Ȼ������
        int ans = 0;
        //����ֱ�Ӽ��� ÿ����λ�� �Ĳ�ֵ���ۼӼ���
        for(int i = 1;i <= cnt;i+=2) {//������������
            ans += a[i+1]-a[i];//����ҿ�
        }
        cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}
