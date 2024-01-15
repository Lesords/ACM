#include<iostream>//ac
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺ÿ���һ���߾ͽ���һ����������
//�������дﵽn�㣬˵�������⣨Ϊ��һ�����
//��������û�дﵽ���ֵ��ַ�������˵���л����ڶ��������
//������Ϊ���������
//ע�⣺��Ҫ��������ж��Ƿ�Ϊ��һ���������Ϊ���ܳ����������ཻ�ı�
//�����Ļ��������Ӷ�Ϊ0�����ǲ������л�
//���Կ������������е�������ж��Ƿ�����������

const int MAXN = 30;
vector<int> g[MAXN];//��ͼ
set<int> st;//��¼�Ѿ������˼����ַ�
int in[MAXN],in2[MAXN],dep[MAXN];//inΪ���˼����е��������
//in2Ϊ��¼��ԭ������飬depΪ��Ӧ������
int idx(char cc) {//���ַ�תΪ����
    return cc-'A';
}
char chx(int id) {//������תΪ�ַ�
    return id+'A';
}
int main() {
    int n,m,flag=-1;//flagΪ���
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        char aa,bb,cc;
        cin>>aa>>bb>>cc;
        if(aa==cc) {
            flag = 0;
            cout<<"Inconsistency found after "<<i<<" relations.\n";
        }
        if(flag!=-1) continue;//����Ѿ����ˣ���������ļ������
        st.insert(idx(aa));//��¼���ֵ������ַ�
        st.insert(idx(cc));
        g[idx(aa)].push_back(idx(cc));//����
        in2[idx(cc)]++;//��¼���
        memcpy(in,in2,sizeof(in2));//����������ݵ�����in
        queue<int> q;
        vector<int> ans;//������������
        for(int i = 0;i < n;i++) {
            //��ʼ���Ϊ1
            if(in[i]==0&&st.count(i)) q.push(i),ans.push_back(i),dep[i] = 1;
        }
        int maxd = 0;//��¼������
        while(!q.empty()) {
            int tmp = q.front();q.pop();
            for(int i = 0;i < g[tmp].size();i++) {//��������ָ���
                int now = g[tmp][i];
                in[now]--;//���--
                if(in[now]==0) {//���Ϊ0�����������
                    q.push(now);
                    dep[now] = dep[tmp]+1;//��¼nowλ�õ����
                    maxd = max(maxd, dep[now]);//����������
                    ans.push_back(now);
                }
            }
        }
        if(ans.size()!=st.size()) {//��������������Ϊ�����ַ��Ĵ�С
            flag = 0;
            cout<<"Inconsistency found after "<<i<<" relations.\n";
        }
        else if(maxd==n) {//���Ϊn��˵��ÿ������ֻ��һ��
            flag = 1;
            cout<<"Sorted sequence determined after "<<i<<" relations: ";
            for(int i = 0;i < ans.size();i++) cout<<chx(ans[i]);
            cout<<".\n";
        }
    }
    if(flag==-1) cout<<"Sorted sequence cannot be determined.\n";
    return 0;
}
