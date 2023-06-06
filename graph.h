#include <map>
#include <iostream>
#include <cstring>
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
  bool inGraph(char* char1);


private:
map<char*, map<char*,int>> myMap;
int distance;

};