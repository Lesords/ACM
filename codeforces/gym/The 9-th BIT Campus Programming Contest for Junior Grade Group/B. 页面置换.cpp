#include<iostream>//ac
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����OPT�㷨�����ŵģ�����ֱ��ʹ��OPT�㷨���㼴��
//OPT�㷨�У�����vector�洢��Ӧ������Ҫ���ʵĽ�����Է����жϣ�����
//�������Ա�������vector�ж���Զ�����ʵĽ���
//ֱ������cnt��vis��¼�ڴ��еĽ�����������ֹset��TLE

const int MAXN = 1e5+5;
const int MAXM = 1e3+5;
int n,m,k;
int a[MAXN],vis[MAXM],num[MAXM];
//vis��¼�����Ƿ����ڴ��У�num��¼��Ӧ������Ҫ���ʵĴ���
vector<int> vec[MAXM];//vec�洢��Ӧ������ʵ�λ��
int OPT() {
    int ans = 0,cnt = 0;
    for(int i = 1;i <= n;i++) {
        num[a[i]]++;//��¼���н�����Ҫ���ʵĴ���
    }
    for(int i = n;i >= 1;i--) {//�����¼������ֵ�λ��
        vec[a[i]].push_back(i);//����ʹ��pop_front()Ϊ�����λ��
    }
    for(int i = 1;i <= n;i++) {
        int now = a[i];
        if(vis[now]==0) {//û�е�ǰ����
            while(cnt>=k) {//�ڴ��еĽ����������ڵ���k
                int index = -1;
                for(int j = 1;j <= m;j++) {//��Ѱ���������ʵĽ���
                    if(num[j]==0&&vis[j]) {//numΪ0��ʾ��������
                        index = j;break;//vis����Ϊ1��ʾ���ڴ���
                    }
                }
                if(index==-1) {//����Ѱ����ò����ʵĽ���
                    int max_time = 0;
                    for(int j = 1;j <= m;j++) {
                        //����j�����������ʵ����
                        //����j�����ڵ�ǰ�ڴ��У�����
                        if(vec[j].empty()||!vis[j]) continue;
                        if(vec[j][vec[j].size()-1]>max_time) {
                            max_time = vec[j][vec[j].size()-1];
                            index = j;
                        }//Ѱ����Զ�����ʵĽ���
                    }
                }
                vis[index] = 0;//ɾ��index���棬�����¶�Ӧ����
                cnt--;
            }
            ans++;//��������++
            cnt++;//��������++
            vis[now] = 1;//��ǵ�ǰ����
        }
        num[now]--;//��ǰ����ķ��ʴ���--
        vec[now].pop_back();//ɾ����ǰ����ĵ�ǰ����λ��
    }
    return ans;//���������
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    cout<<"OPT\n"<<OPT();
    return 0;
}
/*
12 8 12
1 3 3 4 4 5 5 5 5 5 5 5
5 2 1
1 2 2 2 2
5 2 1
2 1 2 2 2
*/
