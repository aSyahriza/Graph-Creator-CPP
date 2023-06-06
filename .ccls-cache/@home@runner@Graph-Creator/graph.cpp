#include "graph.h"
#include <map>

void Graph::addVertex(char* char1){
  myMap.insert(make_pair(char1, map<char*,int>()));
  //myMap.insert(char1,map<char*,int>);
}
void Graph::addEdge(char* char1, char* char2, int distance){
  // Returns if one of the vertices isn't in the Graph 
  cout << "EE" << endl;
  if(inGraph(char1)==false||inGraph(char2)==false){
    cout << "Invalid input." << endl;
    return;



  }


  //////////////////////////////////////////////////////////////////////////////////////

  
  cout << "Distance: " << distance << endl;

  // Reason this doesn't work is because it's not an array. The key is not an iindex. 
  // There can be multiple keys with the same value, and so really you are just 
  // creating another key
  // Goal is to insert using iterator
  // Search up how to insert, and how to use make_pair
  // https://www.geeksforgeeks.org/implementing-multidimensional-map-in-c/
  /*
  for(auto i : myMap){
    if(strcmp(i.first,char1)){
      
    }
  }*/
  myMap[char1][char2] = distance;
  cout << myMap[char1][char2] << endl;
}

void Graph::removeVertex(char* char1){
  // First delete char from myMap
  myMap.erase(char1);

  // Go through myMap and delete every vertex's connection with it
  for(auto i : myMap){
    if(connected(i.first,char1)){
      myMap[i.first].erase(char1);
    }
  }
}
void Graph::removeEdge(char* char1, char* char2){
  // Returns if one of the vertices isn't in the Graph 
  if(!connected(char1,char2)){
    cout << "Invalid input." << endl;
    return;
  }
  else{
    myMap[char1].erase(char2);  
  }
  
}
char* Graph::search(char* char1){
}

char* Graph::findShortest(char* char1, char* char2, int &distance){

}
  
void Graph::print(){
  // for each loop
  cout << "\t";
  for(auto i : myMap){
    // cout << myMap[(*(myMap.begin())).first][i.first] << " ";
     cout << i.first << "\t";
  }
  cout << endl;
  for(auto i : myMap){
   // cout << "EEE" << endl;
    cout << i.first << "\t";
    for(auto j: myMap){
      if(connected(i.first,j.first)){
        cout << "T";
      }
      else{
        cout << "F";
      }
      cout << "\t";
    }
    cout << endl;
  }
  /*
  for (auto i = myMap.begin(); i != myMap.end(); i++){
    cout <<  << endl;
  }*/
}

bool Graph::connected(char* char1, char* char2){
   for(auto i : myMap[char1]){
     if(strcmp(i.first,char2)==0){
       return true;
     }
  }
  return false;
}

bool Graph::inGraph(char* char1){
  
  for(auto i : myMap){
    if(strcmp(i.first,char1)==0){
      return true;
    }
  }
  return false;
  /*
  // if(myMap.find(char1)==myMap.end()){
  if(myMap.count(char1)==0){
    cout << char1 << endl;
    return false;
  }
  else{
    return true;
  }
  */
}