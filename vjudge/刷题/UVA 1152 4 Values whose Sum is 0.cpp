#include<iostream>//ac  ��ϣ��
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

//��⣺���ù�ϣ�洢A+B���������ֵ��Ȼ�����-C-D���������ۼӼ�Ϊ��

const int MAXN = 4e3+5;
const int hashsize = 1e6+3;
struct node{
    int a,b,c,d;
}val[MAXN];//�洢��Ӧ�ĸ�ֵ
int head[hashsize],nextt[MAXN*MAXN+10],res[MAXN*MAXN+10],num[MAXN*MAXN+10],cnt;
//head�洢��Ӧֵ�ĵı�ͷ�±�, nextt�洢������һ��λ�õ�ֵ���±�
//res��ʾ�洢ֵ�Ĵ�С��num�洢��Ӧֵ���ֵ�������cntΪ��Ӧ���±�
int Hash(int val) {//ȡģֵ
    return (val+hashsize)%hashsize;
}
void hash_insert(int val) {//��Ӳ���
    int h = Hash(val);//ȡ��ϣֵ
    int to = head[h];//ȡ��ͷֵ�������±꣩
    while(to) {//0Ϊ��������
        if(res[to]==val) {//���뵱ǰֵһ�£������
            num[to]++;
            return ;
        }
        to = nextt[to];//ָ����һ��λ��
    }
    nextt[cnt] = head[h];//��������
    head[h] = cnt;//���±�ͷ
    res[cnt] = val;//�����ڵ�ǰֵ�������
    num[cnt++] = 1;//�µ�����Ϊ1
}
int hash_find(int val) {//��ѯ����
    int h = Hash(val);//ȡ��ϣֵ
    int to = head[h];//��Ӧ��ͷ
    while(to) {
        if(res[to]==val) return num[to];//��ֵ
        to = nextt[to];
    }
    return 0;//�����ڼ�Ϊ0
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,flag = 0;
    cin>>t;
    while(t--) {
        int n,ans = 0;cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>val[i].a>>val[i].b>>val[i].c>>val[i].d;
        }
        memset(head,0,sizeof(head));//��ʼ����������
        memset(nextt,0,sizeof(nextt));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++)
                hash_insert(val[i].a+val[j].b);//�������
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                //ֱ�ӿɲ�ѯ���
                ans += hash_find(-val[i].c-val[j].d);
            }
        }
        if(flag) cout<<"\n";
        flag = 1;
        cout<<ans<<"\n";
    }
    return 0;
}
