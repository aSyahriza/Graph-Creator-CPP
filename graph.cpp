#include "graph.h"
#include <map>
#include <limits.h>
#include <set>
#include <stack>

void Graph::addVertex(char* char1){
  myMap.insert(make_pair(char1, map<char*,int>()));
  //myMap.insert(char1,map<char*,int>);
}
void Graph::addEdge(char* char1, char* char2, int distance){
  // Returns if one of the vertices isn't in the Graph 
  char1= inGraph(char1);
  char2 = inGraph(char2);
  if(char1==NULL||char2==NULL){
    cout << "Invalid input." << endl;
    return;
  }

  // Adds connection vertices map
  for(auto &i : myMap){
    if(strcmp(i.first,char1)==0){
      i.second.insert(make_pair(char2,distance));
    }
  }
  cout << "Edge has been added." << endl;
}

void Graph::removeVertex(char* char1P){
  if(inGraph(char1P)==NULL){
    cout << "Invalid input!" << endl;
    return;
  }
  char* char1 = inGraph(char1P);
               
  
  // Go through myMap and delete every vertex's connection with it
  for(auto i : myMap){
    if(connected(i.first,char1)){
      myMap[i.first].erase(char1);
    }
  }
  
 // Delete char from myMap
  myMap.erase(char1);   
  cout << "Edge has been deleted" << endl;
}
void Graph::removeEdge(char* char1P, char* char2P){
  char* char1 = inGraph(char1P);
  char* char2 = inGraph(char2P);
  // Returns if one of the vertices isn't in the Graph 
  if(!connected(char1,char2)){
    cout << "Invalid input." << endl;
    return;
  }
  else{
    cout << "Valid input." << endl;
    myMap[char1].erase(char2);  

  }
  
}

void Graph::findShortest(char* char1, char* char2){
  stack<char*> shortestSequence;
  djikstra(char1,char2);
  
  char* current = inGraph(char2);
  // If the shortest distance hasn't been changed, then vertex2 is 
  // unconnected from vertex1
  if(shortestDistanceMap[current] == INT_MAX){
    cout << "No path exists." << endl;
    return;
  }
  // Add vertices in shortest path to stack
  while(current!=inGraph(char1)){
    shortestSequence.push(current);
    current = prevVertex[current];
  }
  // Repeatedly pop to print the stack in order.
  shortestSequence.push(inGraph(char1));
  shortestDistanceMap[inGraph(char2)];
  while(!shortestSequence.empty()){
    cout << shortestSequence.top() <<" ";
    shortestSequence.pop();
  }
  cout << endl;
  
}

void Graph::djikstra(char* char1P, char* char2P){
  // Made with help from Daren Kostov
  set<char*> unVisited;
  // Initiliaze maps and set
  for(auto i : myMap){
    unVisited.insert(i.first);
    shortestDistanceMap[i.first] = INT_MAX;
    prevVertex[i.first];
  }
  // Go through each vertex, updating the adjacent vertices distance from the origin
  char* current = inGraph(char1P);
  shortestDistanceMap[current] = 0;
  while(unVisited.empty()==false){
    for(auto i : myMap[current]){
      if(unVisited.find(i.first)!=unVisited.end()){
        int totalDistance = shortestDistanceMap[current] + i.second;
        if(totalDistance < shortestDistanceMap[i.first]){
          shortestDistanceMap[i.first] = totalDistance;
          prevVertex[i.first] = current;
        }
      }
    }

    // Update unvisited set
    unVisited.erase(current);
    int nextShortest = INT_MAX;
    if(unVisited.empty()){
      break;
    }

    // Find the next unvisited vertex
    for(auto i : shortestDistanceMap){
      if(unVisited.find(i.first)!=unVisited.end()){        
        if(i.second <= nextShortest && i.second!=0){
          nextShortest = i.second;
          current = i.first;
        }
      }
    }  
  }
}
  
void Graph::print(){
  cout << "\t";
  for(auto i : myMap){
     cout << i.first << "\t";
  }
  cout << endl;
  for(auto i : myMap){
   // Prints T if they are connected, F if not
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
}

bool Graph::connected(char* char1, char* char2){
  // Checks if vertices are connected
  for(auto i : myMap[char1]){
    if(strcmp(i.first,char2)==0){
      return myMap[char1][char2]!=0;
    }
  }
  return false;
}

char* Graph::inGraph(char* char1){
  // Returns the actual pointer for vertex
  for(auto i : myMap){
    if(strcmp(i.first,char1)==0){
      return i.first;
    }
  }
  return NULL;

}

