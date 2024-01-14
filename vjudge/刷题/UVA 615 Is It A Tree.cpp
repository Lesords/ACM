#include<iostream>//ac
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���ڲ������ݹ������Կ���map�����ݶ�Ӧת����
//Ȼ���¼��ȣ����Ϊ0������ֻ����һ�������������򲻳���
//�����Ϊ0��λ�ÿ�ʼdfs�жϻ�������ͳ�ƾ���������

//���������
//û�����Ϊ0�ĵ�˵���Ѿ��л���
//�ж�����Ϊ0�ĵ㣬Ϊɭ��
//�������Ի�
//һ��Ϊ������һ���л�����ֻ�����б�����dfs��¼�����ɽ����������

const int MAXN = 1e5+5;
vector<int> g[MAXN];
map<int,int> to_num;//�����ֵ��С
int in[MAXN],mark[MAXN],dfsnum;
//in������ȣ�mark����dfs��ǣ�dfsnum��¼dfs�����з��ʵĽڵ���
void init(int maxdot) {//���ͼ
    for(int i = 0;i <= maxdot;i++) g[i].clear();
}
int dfs(int sdot) {//dfs�ж��Ƿ��л��ͼ�¼��������
    for(int i = 0;i < g[sdot].size();i++) {
        int now = g[sdot][i];
        if(mark[now]) return 0;//�ѷ���
        mark[now] = 1;
        dfsnum++;//��������++
        if(!dfs(now)) return 0;//�������ã������ý��Ϊ0����ֱ�ӷ��أ�����
    }
    return 1;
}
int main() {
    int a,b,cnt = 1;
    while(cin>>a>>b) {
        if(a<0||b<0) break;//��������Ϊ����
        if(a==0&&b==0) {//ֱ��Ϊ0 0˵��Ϊ����
            cout<<"Case "<<cnt++<<" is a tree."<<endl;
            continue;
        }
        memset(in,0,sizeof(in));
        memset(mark,0,sizeof(mark));
        to_num.clear();//��ʼ������

        int dnum = 1,a_num,b_num,flag = 0;//dnumΪ��ǰ�ڵ�ı��
        //a_num �� b_numΪ�޸ĺ�Ķ�Ӧ�ڵ���
        a_num = to_num[a] = dnum;//��һ������Ϊdnum��ʣ��Ķ���Ҫ�ж��Ƿ����
        if(to_num.find(b)!=to_num.end()) b_num = to_num[b];//����
        else b_num = to_num[b] = ++dnum;//������ʱ��ָ��ֵ
        g[a_num].push_back(b_num);//���
        in[b_num]++;//��¼��ȣ�����ߣ�
        while(cin>>a>>b&&a&&b) {
            if(to_num.find(a)!=to_num.end()) a_num = to_num[a];
            else a_num = to_num[a] = ++dnum;
            if(to_num.find(b)!=to_num.end()) b_num = to_num[b];
            else b_num = to_num[b] = ++dnum;//�ڵ�ת��
            g[a_num].push_back(b_num);//���
            in[b_num]++;//���
            if(a_num==b_num) flag = 1;//�ж��Ƿ��Ի�
        }
        int sdot = 0,num = 0;//sdot��ʾ����numΪ��������
        for(int i = 1;i <= dnum;i++) if(in[i]==0) {//���Ϊ0��Ϊ��
            sdot = i;num++;
        }
        if(flag||num>1||sdot == 0) {//�ж��Ի���ɭ�ֺͻ�
            cout<<"Case "<<cnt++<<" is not a tree."<<endl;
            init(dnum);//��ձ�
            continue;
        }
        dfsnum = mark[sdot] = 1;//��Ǹ�������¼���ʵ���
        //�޻� ���� ���������������нڵ���
        if(dfs(sdot)&&dfsnum==dnum) cout<<"Case "<<cnt++<<" is a tree."<<endl;
        else cout<<"Case "<<cnt++<<" is not a tree."<<endl;
        init(dnum);//��ձ�
    }
    return 0;
}
/*
6 8  5 3  5 2  6 4
5 6  0 0

6 8  5 3  5 2  6 4
5 6  5 3 0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

1 2 3 3 0 0

99006 700002 700002 880002  880002 1000001 1000001 1234567890 1234567890 22 0 0

1 2
2 3
4 3
2 4
0 0

1 2
2 3
4 5
0 0

1 7346537
37542 1
0 0

7 7
0 0

100 1
1 2
9 7
7 3
3 88
88 6
1 9
2 6
0 0

1 2
1 2
0 0

999999 5
0 0

0 0

1 2
2 1
0 0

2 5 5 4 4 3 3 2 2 1
10 11 0 0

-4 -5

*/
