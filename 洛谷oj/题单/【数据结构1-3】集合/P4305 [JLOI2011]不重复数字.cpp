#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺��ϣ�� + �����������ϣ��ͻ

const int MAXN = 5e4+5;
const int MOD = 9999991;//����
int a[MAXN],h[MOD+100],nextt[MAXN],val[MAXN],id;
//hΪ��Ӧ��ϣֵָ��ĵ�һ����ţ�nexttΪ��һ����ţ�valΪ��ǰ��ŵ�ֵ
bool check(int tmp) {
    //����tmp�и�����������Ҫ��ģ
    int num = (tmp%MOD+MOD)%MOD,hu;
    hu = num;//��¼ԭ��ϣֵ
    num = h[num];//��һ�����
    while(num) {//��Ŵ���
        if(val[num]==tmp) return false;//tmpֵ���ڣ�����������
        num = nextt[num];//�Ƶ���һ�����
    }
    //��tmp�����ڣ������µı��
    nextt[++id] = h[hu];//ͷ�巨
    h[hu] = id;//����hu�ĵ�һ�����
    val[id] = tmp;//��¼id��ֵ������
    return true;
}
int main() {
    ios::sync_with_stdio(0);//����
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(val,0,sizeof(val));//��ʼ����������Ϊ0
        memset(h,0,sizeof(h));
        memset(nextt,0,sizeof(nextt));
        id = 0;//��ʼ��idΪ0
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(check(a[i])) cout<<a[i]<<" ";//û�д��������
        }
        cout<<"\n";
    }
    return 0;
}
