#include "Graph.h"

void Graph::addVertex(char* char1){
  map[char1];  
}
void Graph::addEdge(char* char1, char* char2, int distance){
  // Returns if one of the vertices isn't in the Graph 
  if(search(char1)==NULL||search(char2)==NULL){
    cout << "Invalid input." << endl;
    return;
  }

  map[char1][char2] = distance;
  
}
void Graph::removeVertex(char* char1){
  // First delete char from Map
  map.erase(char1);
  
  
}
void Graph::removeEdge(char* char1, char* char2){
  // Returns if one of the vertices isn't in the Graph 
  if(search(char1)==NULL||search(char2)==NULL){
    cout << "Invalid input." << endl;
    return;
  }
  map[char1].erase(char2);
}
char* Graph::search(char* char1){
  
}

char* Graph::findShortest(char* char1, char* char2, int &distance){

}
  
void Graph::print(){
  
}
bool Graph::connected(char*, char*){
  
}