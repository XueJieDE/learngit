#ifndef DIJLSTRA
#define DIJLSTRA
#include<iostream>
#include<string>
using namespace std;
class nod{
public:
	int value;
	int next;
	bool visit;
	nod() {
		value = 0;
		next = 0;
		visit = false;
	}
};
class graph {
public:
	int vexnum;
	int edge;
	int **arc;
	nod *dis;
	graph(int vexnum,int edge);
	~ graph();
	bool check_edge_value(int start, int end, int weigh);
	void creat();
	void dijkstra(int begin);
	void delete_line();
	void delete_point();
	void add_point();
	void add_line();
};
#endif
