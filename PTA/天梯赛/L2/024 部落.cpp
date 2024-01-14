#include<iostream>//ac  ���鼯
#include<set>
#include<algorithm>
using namespace std;

//��⣺set����������������
//ÿ�����������鼯���������еĵ�һ���˺������˺ϲ���
//����һ���˿������죬��ֻ��Ҫ�ж����������ܹ��ж��ٸ����죬���ж��ٸ����ཻ�Ĳ�����

const int MAXN = 1e4+5;
int fa[MAXN];
set<int> st;//��¼��������
int getf(int a) {//·��ѹ��
    return a==fa[a]?a:fa[a] = getf(fa[a]);
}
void Merge(int a,int b) {//�ϲ�
    a = getf(a),b = getf(b);
    if(a!=b) fa[b] = a;//����ϲ�
}
int main() {
    for(int i = 1;i < MAXN;i++) fa[i] = i;//��ʼ��������
    int n,q,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int k;cin>>k;
        int first = 0;//��¼��ǰ�����һ���˵ı��
        for(int j = 1;j <= k;j++) {
            int tmp;cin>>tmp;
            st.insert(tmp);
            if(j==1) {//�����һ���˵ı��
                first = tmp;continue;
            }
            Merge(first,tmp);//ʣ��Ķ���Ҫ�ϲ�
        }
    }
    for(int i = 1;i <= st.size();i++) ans += fa[i]==i;//����Ϊ����ļ�Ϊһ����������
    cout<<st.size()<<" "<<ans<<"\n";
    cin>>q;
    while(q--) {
        int a,b;
        cin>>a>>b;
        if(getf(a)==getf(b)) cout<<"Y\n";//�ж϶�Ӧ�������Ƿ�һ��
        else cout<<"N\n";
    }
    return 0;
}
