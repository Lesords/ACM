#include<iostream>//ac
#include<cmath>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺�Ƚ������ַ��������ֵ����С��������
//����ÿ���ַ���ֻ����һ�Σ�������β�ַ�һ�µ��ַ����ſ�������
//�����һ���ַ��������ַ������һ���ַ�����ĩ�ַ����
//��ô����ַ���Ϊ�ֵ�����С���ַ���
//�������ȣ�������β�ַ�����һ���ַ��������ַ������һ���ַ�����ĩ�ַ����ǹ̶���
//��ôѡ��һ������λ�ó��ֵĴ�������ĩλ�õ��ַ�
//����Ѱ�Ұ������ַ����ַ��������ַ���ĩβ��Ӧ��Ϊ Ψһ�����һ���ַ�

const int MAXN = 1e3+5;
string s[MAXN];
vector<string> ans;//������
int st[30],ed[30],len[MAXN],vis[MAXN];//len��¼�ַ������ȣ�vis�жϸ��ַ��Ƿ������
//stΪ�ַ�����λ�ó��ֵĴ�����edΪ�ַ���ĩλ�ó��ֵĴ���
int n,flag;//flag��¼�Ƿ��ҵ��𰸣��ҵ��𰸷���
int idx(char c) {//�ַ�ת����
    return c - 'a';
}
void dfs(int now,int num) {//nowΪ��ǰ������λ�ã�num��ʾ�Ѿ�ȷ�����ַ�������
    if(num==n) {                        //ȷ��n������ֱ�ӽ���
        flag = 1;return;
    }
    if(flag) return;                    //�ҵ������ֱ�ӷ���
    char last = s[now][len[now]-1];     //��һ���ַ�����ĩ�ַ�
    for(int i = 1;i <= n;i++) {
        if(vis[i]) continue;            //�����ѱ�����
        char ch = s[i][0];              //��ǰ�ַ��������ַ�������
        if(ch!=last) continue;          //�����������
        ans.push_back(s[i]);            //��Ӵ�
        vis[i] = 1;                     //���
        dfs(i,num+1);
        if(flag) return;                //����ҵ��𰸣�ֱ�ӷ��أ������к���Ĳ���
        //����
        vis[i] = 0;                     //ȡ�����
        ans.pop_back();                 //�������
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>s[i];
    sort(s+1,s+1+n);                    //���ֵ����С��������
    for(int i = 1;i <= n;i++) {
        len[i] = s[i].size();           //��¼�ַ�������
        st[idx(s[i][0])]++;             //��¼�ַ�����λ�õ��ַ�
        ed[idx(s[i][len[i]-1])]++;      //��¼�ַ���ĩλ�õ��ַ�
    }
    //start��¼��һ���ַ�����λ�ã�oneΪ��һ���ַ���twoΪ���һ���ַ�
    int start = 1,one = -1,two = -1;    //Ĭ�ϵ�һ���ַ���Ϊ�ֵ�����С��
    for(int i = 0;i < 26;i++) {
        if(abs(st[i]-ed[i])==1) {       //�в�ֵ
            if(st[i]>ed[i]) one = i;    //��λ�ö༴Ϊone
            else two = i;               //����Ϊtwo
        }
    }
    if(one!=-1&&two!=-1) {              //�ҵ�one��two��û�ҵ�ֱ��Ĭ���ֵ�����С
        for(int i = 1;i <= n;i++) {
            int s0 = idx(s[i][0]);
            int se = idx(s[i][len[i]-1]);//one��two�����֣��ж��轫�ַ�ת���֣�����
            //���ַ�Ϊone��ĩ�ַ���Ϊtwo��two��������ֹһ��
            if(s0==one&&(se!=two||ed[two]>1)) {
                start = i;break;        //�ҵ���ֱ�ӽ���
            }
        }
    }
    ans.push_back(s[start]);            //���
    vis[start] = 1;                     //������
    dfs(start,1);
    if(!flag) {                         //û�ҵ����***
        cout<<"***";
        return 0;
    }
    for(int i = 0;i < ans.size();i++) {
        if(i) cout<<".";                //�м���Ϊ . ����
        cout<<ans[i];
    }
    return 0;
}

/*
3 ac ca ab
*/
