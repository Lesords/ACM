#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺���ಢ�鼯
//����ֻ�����У�����ÿ�ж���ҪΪȫ���У����������ظ���
//���Կ����ȼ�¼�������ֳ��ִ�������������ֳ��ֲ�Ϊ���εģ����޽�
//����ÿ������˵�����γ��ֵ�λ�ò���Ϊͬ�У���Ϊ��ͬ��
//�����ȿ��Լ�¼ÿ���������γ��ֵ�λ��
//Ϊ�˷�����㣬�ڶ��е�λ��Ϊ����+n������
//����ÿ��ֻ������״̬�����Ͳ���
//���Կ��Ը���ֵ��1~n�����ֵ�λ��������ж�������Ҫ����
//������γ�����ͬһ�У���ѡ����һ�н�������
//�������ж���Ҫ������С�ڵ���n��ʾ����������n��ʾ��������
//�ϲ���Ӧ�����
//������ÿһ�У��ж��Ƿ�����һ�� ���Ͳ��� �غ���
//���û�еĻ���ѡ����������ٵķ�����������
//�൱�ڣ��ϲ�������������Ϊ��ͨ�飬Ȼ���ж���ͨ�����Ƿ������г���ì�ܵ�

const int MAXN = 4e5+10;
int a[MAXN],b[MAXN];
int pos1[MAXN],pos2[MAXN],flag[MAXN],cnt[MAXN];
//pos1��¼Ԫ�ص�һ�γ��ֵ�λ�ã�pos2��¼Ԫ�صڶ��γ��ֵ�λ��
//flag��¼��ǰ���Ƿ���Ҫ��ת��cnt��¼���ֳ��ֵĴ���
int cost[MAXN],fa[MAXN];//costΪ��ǰ�м��ϻ��ѵĲ�������faΪ���Ƚڵ�
vector<int> ans;//��¼�������
void init(int n) {//��ʼ��
    ans.clear();
    for(int i = 1;i <= n*2;i++) {
        if(i<=n) {
            cnt[i] = 0;
            pos1[i] = pos2[i] = 0;              //λ�ó�ʼ��Ϊ0
            cost[i] = 1;                        //С�ڵ���n��Ҫ����
        }
        else cost[i] = 0;                       //����n������
        fa[i] = i;                              //���Ƚڵ�
        flag[i] = 0;
    }
}
int getf(int pos) {//·��ѹ��
    return fa[pos]=(pos==fa[pos])?pos:getf(fa[pos]);
}
void Merge(int a,int b) {
    a = getf(a);                                //ֱ����ԭ�����������¿�����������
    b = getf(b);
    if(a==b) return;
    //����һ���꣡����
    fa[b] = a;                                  //��ѯ�ͺϲ�����ֵ��һ�£�����
    cost[a] += cost[b];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        init(n);
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            cnt[a[i]]++;                        //��¼��ֵ���ִ���
            if(pos1[a[i]]==0) pos1[a[i]] = i;   //��¼��Ӧ���ִ�����λ��
            else pos2[a[i]] = i;
        }
        for(int i = 1;i <= n;i++) {
            cin>>b[i];
            cnt[b[i]]++;                        //��¼��ֵ���ִ���
            //��һ�е�λ��+n
            if(pos1[b[i]]==0) pos1[b[i]] = i+n; //��¼��Ӧ���ִ�����λ��
            else pos2[b[i]] = i+n;
        }
        int mark = 0;
        for(int i = 1;i <= n;i++) {             //��ֵ���ִ���û�����Σ����޽�
            if(cnt[i]!=2) {
                cout<<"-1\n";
                mark = 1;
                break;
            }
        }
        if(mark) continue;                      //�޽�������
        for(int i = 1;i <= n;i++) {
            int p1 = pos1[i],p2 = pos2[i];
            if(p1>n) p1 -= n;                   //p1��p2Ϊʵ�ʵ�����
            if(p2>n) p2 -= n;
            //���Ϊͬ�У��򽻻�һ�����ɣ���������һ�𽻻�
            if((pos1[i]<=n&&pos2[i]<=n)||(pos1[i]>n&&pos2[i]>n)) {
                Merge(p1, p2+n);                //С�ڵ���n��Ϊ��Ҫ����������n�Ĳ���Ҫ����
                Merge(p1+n, p2);
            }
            else {
                Merge(p1, p2);
                Merge(p1+n, p2+n);
            }
        }
        for(int i = 1;i <= n;i++) {             //���������У��ж��Ƿ��з���ì�ܵ�
            int p1 = getf(i);
            int p2 = getf(i+n);
            if(p1==p2) {                        //�������ì���ˣ�˵���޽�
                mark = 1;
                cout<<"-1\n";
                break;
            }
            if(flag[p1]==0) {                   //��δ��������ѡ�����в������ٵ�
                if(cost[p1]<cost[p2]) {
                    flag[p1] = 1;               //1Ϊѡ��-1Ϊ��ѡ
                    flag[p2] = -1;
                }
                else {
                    flag[p1] = -1;
                    flag[p2] = 1;
                }
            }
            if(flag[p1]==1) {                   //�������ķ�����������
                ans.push_back(i);
            }
        }
        if(mark) continue;                      //�޽�������
        cout<<ans.size()<<"\n";
        for(int i = 0;i < ans.size();i++) {     //�����������
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
	return 0;
}
