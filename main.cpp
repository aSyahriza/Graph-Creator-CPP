/*
* Author: Allam Syahriza
* Date: June 7, 2023
* Project: Graph Creator (Data Structures)
* Creates a graph of vertices, utilizing a breadth first search algorithm to 
* Find the shortest path between any two vertices (if any)
*/

#include <iostream>
#include <cstring>

#include "graph.h"

using namespace std;


int main() {
  bool loop = true;
  Graph myGraph;
  char command[20];
  char* fileName = new char[20];
  
  
  cout << "Enter ADD, ADD EDGE, DELETE VERTEX, DELETE EDGE, PRINT, SEARCH, or QUIT" << endl;
  cout << "\n" << endl;


  
  while(loop){
    cin.get(command,20,'\n');
    cin.clear();
    cin.ignore(99999,'\n');
    
    // Checks if the user wants to ADD a single number to the heap
    if(strcmp(command, "ADD") == 0){
      cout << "Enter a name for this vertex: " << endl;
      char* vertexName = new char[20];
       cin.get(vertexName,20,'\n');
      cin.clear();
      cin.ignore(99999,'\n');
      myGraph.addVertex(vertexName);
      cout << "Value has been added." << endl;
    }

    if(strcmp(command, "ADD EDGE") == 0){
      cout << "Enter two vertices: " << endl;
      char* a = new char[20];
      char* b = new char[20];
      cin >> a >> b; 
      int distance;
      cout << "Enter distance: " << endl;
      cin >> distance;
      myGraph.addEdge(a, b, distance);
      
    }

    if(strcmp(command, "DELETE VERTEX") == 0){
      char* a = new char[20];
      cout << "Enter a vertex name: " << endl;
      cin.get(a,20,'\n');
      cin.clear();
      cout << endl;
      myGraph.removeVertex(a);
    }

    if(strcmp(command, "DELETE EDGE") == 0){
      cout << "Enter two names of vertices, seperated by a space: " << endl;
      char* a = new char[20];
      char* b = new char[20];
      cin >> a >> b; 
      
      myGraph.removeEdge(a,b);
    }
    if(strcmp(command, "SEARCH") == 0){
      cout << "Enter two names of vertices, seperated by a space: " << endl;
      char* a = new char[20];
      char* b = new char[20];
      cin >> a >> b; 
      
      myGraph.findShortest(a,b);
    }
    
    
    // Check if the user wants to print the tree
    if(strcmp(command, "PRINT") == 0){
      myGraph.print();
      cout << endl;
    }

    // Quit
    if(strcmp(command, "QUIT") == 0){
      loop = false;
    }
    cout << endl;
  }  
  
  cout << "Program ended. " << endl;
}