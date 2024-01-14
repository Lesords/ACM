#include<iostream>//ac
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    //���Ľ��ֻ��Ҫ��ǰ�ĵ�ַ�ͽ��
    //��һ����ַ����ֱ��ȡ����һ���ĵ�ַ
    string name;
    int val;
};
map<string,int> data;//�洢��Ӧ��ַ��ֵ
map<string,string> nextt;//�洢��Ӧ��ַ����һ����ַ
set<int> st;//��¼�ѳ��ֵ�ֵ���ظ����Ծ���ֵΪ�жϱ�׼��
int main() {
    string head;//��ʾ���
    int n;
    ios::sync_with_stdio(0);//���ٶ���
    cin.tie(0),cout.tie(0);
    cin>>head>>n;
    for(int i = 1;i <= n;i++) {
        string a,b;
        int val;
        cin>>a>>val>>b;
        nextt[a] = b;//��¼a����һ����ַb
        data[a] = val;//��¼a��ַ��ֵval
    }
    queue<node> ans,del;//ans����ȥ�غ�����del���汻ɾ��������
    while(nextt.count(head)) {//���һ���ĵ�ַ����Ϊ-1
        //�����ڴ�֮ǰ�����е�ַ������һ����ַ
        if(st.count(abs(data[head]))) {//����Ӧֵ�Ѵ��ڹ�����ɾ��
            del.push(node{head,data[head]});//�����Ӧ��ɾ��������
            head = nextt[head];//ָ����һ����ַ
            continue;
        }
        st.insert(abs(data[head]));//���뵱ǰֵ
        ans.push(node{head,data[head]});//������б��浱ǰ ��ַ��ֵ
        head = nextt[head];//ָ����һ����ַ
    }
    while(!ans.empty()) {//�����������
        cout<<ans.front().name<<" "<<ans.front().val<<" ";//��ǰ�ڵ���Ϣ
        ans.pop();//����
        if(ans.size()) cout<<ans.front().name<<"\n";//��������һ����������˽ڵ�ĵ�ַ
        else cout<<"-1\n";//����Ϊ-1
    }
    while(!del.empty()) {//�����������
        cout<<del.front().name<<" "<<del.front().val<<" ";//��ǰ�ڵ���Ϣ
        del.pop();//����
        if(del.size()) cout<<del.front().name<<"\n";//��������һ����������˽ڵ�ĵ�ַ
        else cout<<"-1\n";//����Ϊ-1
    }
    return 0;
}
