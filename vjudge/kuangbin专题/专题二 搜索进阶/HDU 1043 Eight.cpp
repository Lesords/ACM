#include<iostream>//ac
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

//��⣺�������࣬��Ҫ����bfs��¼��
//��map<string,string> ans�������Ӧ״̬��Ҫ��·�������������

struct node{
    string state,path;//stateΪ״̬��pathΪ·��
    int x,y,step;//x��yΪ�ַ�'x'������
    friend bool operator < (node a,node b) {
        return a.step > b.step;//���Ȳ����ٵ�
    }
};
char s[4][4];
char dir[4] = {'u','d','l','r'};//�ĸ������Ӧ�ķ��򣨷����յ�����㣩
int nextt[4][2] = {1,0,-1,0,0,1,0,-1};//�ĸ�����
vector<string> a;//��¼���������״̬
set<string> shav;//��¼������Ҫ�����״̬
map<string,string> ans;//������·��
void bfs() {
    priority_queue<node> q;
    set<string> vis;//��¼��������״̬
    node tmp = {"12345678x","",3,3,0};//��ʼ��״̬�������
    int vnum = 0;//�ѻ�ô�·��������
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();q.pop();
        if(vis.count(tmp.state)) continue;//�����ѱ�����
        else {
            if(shav.count(tmp.state)) {//���Ϊ��Ҫ�����״̬
                ans[tmp.state] = tmp.path;//��¼��·��
                vnum++;//��������++
            }
            vis.insert(tmp.state);//����ѱ�������
        }
        if(vnum==a.size()) return ;//������Ҫ�Ķ������ֱ꣬�ӷ���
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>3||ty<1||ty>3) continue;//Խ��
            int fpos = (tmp.x-1)*3+tmp.y-1;//��ά��һά������
            int tpos = (tx-1)*3+ty-1;
            node tt = tmp;
            swap(tt.state[tpos],tt.state[fpos]);//������Ӧ��ֵ
            if(vis.count(tt.state)) continue;//�����ѱ�ǵ�
            tt.step++;//����++
            tt.x = tx,tt.y = ty;//����'x'������ֵ
            tt.path += dir[i];//·������
            q.push(tt);
        }
    }
    return ;
}
int main() {
    char tmp;
    while(cin>>tmp) {
        string svis = "";
        svis += tmp;
        for(int i = 1;i <= 8;i++) cin>>tmp,svis+=tmp;//svisΪ��ǰ�ַ�����״̬
        a.push_back(svis);
        shav.insert(svis);
    }
    bfs();
    for(int i = 0;i < a.size();i++) {//����������Ҫ�����״̬
        if(ans.count(a[i])) {//�������
            for(int j = ans[a[i]].size()-1;j >= 0;j--) cout<<ans[a[i]][j];
            cout<<'\n';
        }
        else cout<<"unsolvable\n";//ans�в����ڣ����޽�
    }
    return 0;
}
