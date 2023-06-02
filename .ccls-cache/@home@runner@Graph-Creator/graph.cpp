#include "graph.h"

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
  if(!connected(char1,char2)){
    cout << "Invalid input." << endl;
    return;
  }
  else{
    map[char1].erase(char2);  
  }
  
}
char* Graph::search(char* char1){
  
}

char* Graph::findShortest(char* char1, char* char2, int &distance){

}
  
void Graph::print(){
  // for each loop
  for(auto i : map){
    // cout << map[(*(map.begin())).first][i.first] << " ";
     cout << map[(*(map.begin())).first][i.first] << " ";
  }
  cout << endl;
  /*
  for (auto i = map.begin(); i != map.end(); i++){
    cout <<  << endl;
  }*/
}

bool Graph::connected(char* char1, char* char2){
  if(map[char1].find(char2)==map[char1].end()){
    return false; 
  }
  else{
    return true;
  }
}

bool Graph::inGraph(char* char1){
  if(map.find(char1)==map.end()){
    return false;
  }
  else{
    return true;
  }
}