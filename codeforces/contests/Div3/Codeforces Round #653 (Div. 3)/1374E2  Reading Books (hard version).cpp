#include<iostream>//ac
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��Ϊ4������У�1��ʣ����У�1����ʹ�ö���
//1.�ж��Ƿ��б����both�鼮����С����ѡ��
//2.�ж�both��alice+bob�ĸ����ֵ��Сֱ��bothΪ��
//3.����alice��bob������鼮�������ࣩ
//4.����ѡ�鼮����������ʱ�ж����������
//5.��bothС��none��alice��bob����ѡ��both�����У�
//6.�� ��ʹ�õ�both +noneС��alice+bob����ѡ��none
//7.������alice��bob��none������ѡ����С��
//8.���������ʣ����鼮�д�С����ѡ����Ҫ���鼮

const int MAXN = 2e5+10;
struct node{
	int val,index;
	friend bool operator < (node a,node b) {
		if(a.val!=b.val) return a.val > b.val;
		return a.index > b.index;
	}
};
struct node1{//�Ѿ�������both����
	int val,index;
	friend bool operator < (node1 a,node1 b) {
		return a.val < b.val;//�������
	}
};
int ans[MAXN],cost;//ans������ţ�costΪ�ܻ���ֵ
int main() {
	int n,m,k,cnt = 0,a_num = 0,b_num = 0;
	priority_queue<node> alice,bob,both,non,rest;
	priority_queue<node1> used;
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++) {
		int t,a,b;
		cin>>t>>a>>b;
		if(a+b==2) both.push(node{t,i});
		if(a+b==0) non.push(node{t,i});
		if(a&&!b) alice.push(node{t,i});
		if(!a&&b) bob.push(node{t,i});
	}
	//both���+�����СֵС��k��Ϊ��������
	if(both.size()+min(alice.size(),bob.size())<k) {
		cout<<"-1";
		return 0;
	}
	node tmp_a,tmp_b,tmp;
	if(2*k>m) {//�϶���Ҫboth�����������
		if(2*k-m>both.size()) {//both��������
			cout<<"-1";
			return 0;
		}
		int num = 2*k-m;//numΪ�����both����
		while(num--) {
			tmp = both.top();
			both.pop();
			cost += tmp.val;//costΪ�ܻ���ֵ
			ans[++cnt] = tmp.index;//�������
			a_num++,b_num++;
		}
	}
	while(a_num<k&&b_num<k) {//�������ж�both����
		if(!both.empty()) {
			tmp_a.val = tmp_b.val = INF;//�ȳ�ʼ������ֹĳ����Ϊ��
			tmp = both.top();
			if(!alice.empty()) tmp_a = alice.top();
			if(!bob.empty()) tmp_b = bob.top();
			if(tmp.val<=tmp_a.val+tmp_b.val) {
				cost += tmp.val;//���ӻ���
				used.push(node1{tmp.val,tmp.index});//ʹ�ù���both���������used����
				both.pop();
				ans[++cnt] = tmp.index;//�������
			}
			else {//ѡ��alice+bob���
				bob.pop(),alice.pop();
				cost += tmp_a.val+tmp_b.val;//���ӻ���
				ans[++cnt] = tmp_a.index;//�������
				ans[++cnt] = tmp_b.index;
			}
			a_num++,b_num++;
		}
		else break;
	}
	while(a_num<k) {//����alice��Ҫ����
		tmp_a = alice.top();
		cost += tmp_a.val;
		ans[++cnt] = tmp_a.index;//�������
		a_num++;
		alice.pop();
	}
	while(b_num<k) {//����bob��Ҫ����
		tmp_b = bob.top();
		cost += tmp_b.val;
		ans[++cnt] = tmp_b.index;//�������
		b_num++;
		bob.pop();
	}
	int num = 0;//numΪ��ɾ�����������
	set<int> mark,del;//mark������Ǳ�ɾ����both���鼮��del��������Ѿ��������
	if(cnt<m) {
		node1 usedd;
		while(1) {//�ж�both+none��alice+bob�����ֵ��С
			usedd.val = tmp.val = tmp_a.val = tmp_b.val = INF;
			if(cnt-num==m) break;//�����ĵ��鹻��ʱ����
			if(!alice.empty()) tmp_a = alice.top();
			if(!bob.empty()) tmp_b = bob.top();
			if(!non.empty()) tmp = non.top();
			if(!used.empty()) usedd = used.top();
			int tt = min(min(tmp_a.val,tmp_b.val),tmp.val);//ȡ��������Сֵ
			node ttmp;
			ttmp.val = INF;
			if(!both.empty()) ttmp = both.top();
			if(ttmp.val < tt) {//����bothΪ��С�����������
				cost += ttmp.val;
				ans[++cnt] = ttmp.index;
				if(mark.count(ttmp.index)) mark.erase(ttmp.index);//ȥ��ɾ�����
				both.pop();
				continue;
			}
			if(tmp.val==tt) {//noneΪ��Сʱ
				if(usedd.val+tt>=tmp_a.val+tmp_b.val) {//both+none����alice+bobʱ
				    //ɾ��both��Ȼ�����alice+bob
					if(usedd.val+tt>=INF) break;//����һ��Ϊ��
					if(alice.empty()||bob.empty()||used.empty()) break;//��������һ��Ϊ�ն�����
					cost -= usedd.val;
					cost += tmp_a.val+tmp_b.val;
					ans[++cnt] = tmp_a.index;
					ans[++cnt] = tmp_b.index;
					alice.pop(),bob.pop(),used.pop();//usedΪʹ�ù���both����ʱ��ɾ�����ֵ
					both.push(node{usedd.val,usedd.index});//��ɾ���������ԭ������
					mark.insert(usedd.index);//���ɾ�����
					num++;
				}
				else {//���none�������С
					if(non.empty()) break;
					cost += tmp.val;
					ans[++cnt] = tmp.index;
					non.pop();
				}
			}
			else {//��ʱ��Ҫ��both��alice��bob֮���ж���Сֵ
				node tmp_both;
				tmp_both.val = INF;
				if(!both.empty()) tmp_both = both.top();//both��ֵ
				if(tmp_a.val<=tmp_b.val&&tmp_a.val<=tmp_both.val) {//alice��С
					if(tmp_a.val==INF) break;//INF˵��Ϊ��
					cost += tmp_a.val;
					ans[++cnt] = tmp_a.index;//��Ӷ�Ӧ��ż�ֵ
					alice.pop();
				}
				else if(tmp_b.val<=tmp_a.val&&tmp_b.val<=tmp_both.val) {//bob��С
					if(tmp_b.val==INF) break;//INF˵��Ϊ��
					cost += tmp_b.val;
					ans[++cnt] = tmp_b.index;//��Ӷ�Ӧ��ż�ֵ
					bob.pop();
				}
				else {//both��С
					if(tmp_both.val==INF) break;//INF˵��Ϊ��
					cost += tmp_both.val;
					ans[++cnt] = tmp_both.index;//��Ӷ�Ӧ��ż�ֵ
					if(mark.count(tmp_both.index)) mark.erase(tmp_both.index);//�Ƴ�ɾ�����
					both.pop();
				}
			}
		}
		//ʣ������������ͬһ�������д�С��������
		while(!both.empty()) rest.push(both.top()),both.pop();
		while(!alice.empty()) rest.push(alice.top()),alice.pop();
		while(!bob.empty()) rest.push(bob.top()),bob.pop();
		while(!non.empty()) rest.push(non.top()),non.pop();
		while(cnt-num<m) {
			tmp = rest.top();rest.pop();
			ans[++cnt] = tmp.index;
			if(mark.count(tmp.index)) mark.erase(tmp.index);//�Ƴ�ɾ�����
			cost += tmp.val;
		}
	}
	cout<<cost<<endl;
	int flag = 0;
	for(int i = 1;i <= cnt;i++) {
		if(mark.count(ans[i])) continue;//������ɾ����both
		if(del.count(ans[i])) continue;//�����Ѿ���������
		if(flag) cout<<' ';
		cout<<ans[i];
		del.insert(ans[i]);//�������������
		flag = 1;
	}
	return 0;
}
