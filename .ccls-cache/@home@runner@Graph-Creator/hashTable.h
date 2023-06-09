#include <map>
#include <iostream>
using namespace std;

class Graph {
public:
  void addVertex(char*);
  void addEdge(char*, char*, int);
  void removeVertex(char*);
  void removeEdge(char*, char*);
  char* search(char*);
  char* findShortest(char*, char*, int&);
  void print();
  bool connected(char*, char*);


private:
map<char*, map<char*,int>> map;
int distance;

};