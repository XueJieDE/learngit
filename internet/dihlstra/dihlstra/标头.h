#ifndef DIJLSTRA
#define DIJLSTRA
#include<iostream>
#include<string>
using namespace std;
class nod{
public:
	int value;
	bool visit;
	nod() {
		value = 0;
		visit = false;
	}
};
class graph {
	int vexnum;
	int edge;
	int **arc;
	nod *dis;
public:
	graph(int vexnum,int edge);
	~graph();
	bool check_edge_value(int start, int end, int weigh);
	void creat();
	void dijkstra(int begin);
	void delete_line(int begin, int end);
	void delete_point(int point);
	void add_point();
	void add_line();
};
#endif
