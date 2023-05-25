#include <map>
#include <iostream>
using namespace std;

class hashTable {
public:
  void addVertex(char*);
  void addEdge(char*, char*, int);
  void removeVertex(char*);
  void removeEdge(char*, char*);
  char* search(char*);
  char* findShortest(char*, char*, int&);
  void print();


private:
map<char*, map<char*,int>> map;
int distance;

};