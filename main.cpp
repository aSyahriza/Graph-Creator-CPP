#include <iostream>
#include <cstring>

#include "graph.h"

using namespace std;


int main() {
  bool loop = true;
  Graph myGraph;
  char command[20];
  char* fileName = new char[20];
  
  
  cout << "Enter ADD, ADD EDGE, DELETE, PRINT, SEARCH, or QUIT" << endl;
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
      // BE ABLE TO READ IN MULTIPLE INPUTS FROM SAME LINE
      /*
        std::cin >> a;
std::cin.ignore(1, ',')
        */
    
      myGraph.addVertex(vertexName);
      cout << "Value has been added." << endl;
      cout << "\n";
    }

    if(strcmp(command, "ADD EDGE") == 0){
      cout << "Enter two vertexses: " << endl;
      char* a = new char[20];
      char* b = new char[20];
      cin >> a >> b; 
      int distance;
      cout << "Enter distance: " << endl;
      cin >> distance;
      myGraph.addEdge(a, b, distance);
      cout << "added added" << endl;
      
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
  }  
  
  cout << "Program ended. " << endl;
}