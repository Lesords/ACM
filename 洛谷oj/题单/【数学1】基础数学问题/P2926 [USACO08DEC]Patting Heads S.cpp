#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ͳ���������ֵĳ��ִ��������ð�ʽ����˼��
//��ÿ��������󷭱��ۼ�������ע�Ȿ����-1��
//ע�⣺�߽���Ҫ��ȣ���:�߽�Ϊ12��ԭ��Ϊ5��12/5 = 2
//�������� 2*5 �Ļ�����ô����10��˵������һ�����


const int MAXN = 1e5+5;
const int MAXV = 1e6;
int num[MAXV+1],ans[MAXV+1],a[MAXN];//aΪԭ����
//num��¼���ֳ��ִ�����ansΪÿ��������������
void solve() {
    for(int i = 1;i <= MAXV;i++) {              //������������
        if(num[i]==0) continue;                 //����δ���ֵ�����
        //������1��ʼ����Ϊ��Ҫ��������
        for(int j = 1;j <= MAXV/i;j++) {        //��Ҫ��ȣ�����
            ans[i*j] += num[i];                 //�ۼ� i*j ������i
            if(i*j==i) ans[i]--;                //������-1
        }
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        num[a[i]]++;                            //ͳ�����ֵĳ��ִ���
    }
    solve();
    for(int i = 1;i <= n;i++) cout<<ans[a[i]]<<"\n";
    return 0;
}
