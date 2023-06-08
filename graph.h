#include <map>
#include <unordered_map>
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
  void djikstra(char*, char*);
  void findShortest(char*,char*);
  void print();
  bool connected(char*, char*);
  char* inGraph(char* char1);


private:
map<char*, map<char*,int>> myMap;
unordered_map<char*,int> shortestDistanceMap;
unordered_map<char*,char*> prevVertex;

int distance;


};