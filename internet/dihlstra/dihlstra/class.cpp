#include "标头.h"
#include<fstream>
graph ::graph(int vexnum ,int edge) {
	this->vexnum = vexnum;
	this->edge = edge;
	arc = new int*[this->vexnum];
	dis = new nod[this->vexnum];
	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {
			arc[i][k] = INT_MAX;
		}
	}
}
graph::~graph() {
	for (int i =0; i<this->vexnum; i++) {
		delete this->arc[i];
	}
	delete arc;
//	delete dis;
}
bool graph::check_edge_value(int start,int end,int weight) {
	if (start <= vexnum && end <= vexnum && start > 0 && end > 0&&weight>=0)return true;
	else return false;
}
void graph::creat() {
	int start = 0, end = 0, weight = 0;
	int count = 0;
	ifstream file("data.txt",ios::out);
	if (file){
		while (count <= this->edge) {
			file>> start >> end >> weight;
			//while (!check_edge_value(start, end, weight))cin >> start >> end >> weight;
			arc[start - 1][end - 1] = weight;
			arc[end - 1][start - 1] = weight;
			count++;
		}
	}
	file.close();
}
void graph::dijkstra(int begin) {
	int count = 0;
	for (int i = 0; i < this->vexnum; ++i) {
		dis[i].value=arc[begin-1][i];
		dis[i].next = i;
		dis->visit = false;
	}
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	while(count!=this->vexnum){
		int min = INT_MAX;
		for (int i = 0; i < this->vexnum; ++i) {
			if (dis[i].value < dis[min].value&&dis[i].visit == false)min = i;
		}
		dis[min].visit = true;
		++count;
		for (int i = 0; i < this->vexnum; ++i) {
			if (min<this->vexnum&&dis[i].visit == false&& arc[min][i]!=INT_MAX&&dis[i].value > dis[min].value + arc[min][i]) {
				dis[i].value = dis[min].value + arc[min][i];
				arc[begin - 1][i] = dis[i].value;
				arc[i][begin - 1] = dis[i].value;
				dis[i].next = dis[min].next;
			}
		}
	}
}
void graph::delete_line(){
	int begin = 0, end = 0;
	cout << "请输入所删边的起点终点" << endl;
	cin >> begin >> end;
	while (!(begin>0&&begin<=vexnum&&end>0&&end<=vexnum)) {
		cin >> begin >> end;
	}
	arc[begin - 1][end - 1] = INT_MAX;
	arc[end - 1][begin - 1] = INT_MAX;
	this->edge -= 1;
}
void graph::delete_point() {
	int point = 0;
	cout << "请输入所删节点的编号" << endl;
	cin >> point;
	while (!(point > 0 && point <= vexnum))cin >> point;
	for (int i = 0; i < vexnum; ++i) { 
		if (arc[point - 1][i] != INT_MAX) {
			arc[point - 1][i] = INT_MAX;
			arc[i][point - 1] = INT_MAX;
			this->edge --;
		}
	}

}
void graph::add_line() {
	int begin = 0, end = 0,weight=0;
	cout << "请输入所添加边的起点终点" << endl;
	cin >> begin >> end>>weight;
	while (!(begin > 0 && begin <= vexnum && end > 0 && end <= vexnum&&weight>=0)) {
		cin >> begin >> end;
	}
	arc[begin-1][end-1] = weight;
	arc[end-1][begin-1] = weight;
	this->edge += 1;
}
void graph::add_point() {
	int point = 0, num = 0,weight=0;
	cout << "输入添加节点编号和边数" << endl;
	cin >> point >> num;
	while (!(point > 0 && num >= 0 && point <= vexnum && num < vexnum*vexnum-this->edge))cin >> point >> num;
	int count = 0, end = 0;
	while (count != num) {
		cout << "输入所连节点编号" << endl;
		cin >> end;
		while (!(end!=point&&end > 0 && end < vexnum&&arc[point - 1][end - 1] == INT_MAX))cin >> end;
		count++;
		cout << "输入其跳数" << endl;
		cin >> weight;
		while (weight < 0)cin >> weight;
		arc[point - 1][end - 1] = weight;
		arc[end - 1][point-1] = weight;
		this->edge += 1;
	}
}