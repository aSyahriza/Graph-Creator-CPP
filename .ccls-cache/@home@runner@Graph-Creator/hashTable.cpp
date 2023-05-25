#include "hashTable.h"

void hashTable::addVertex(char* char1){
  map[char1];  
}
void hashTable::addEdge(char* char1, char* char2, int distance){
  // Returns if one of the vertices isn't in the hashtable 
  if(search(char1)==NULL||search(char2)==NULL){
    cout << "Invalid input." << endl;
    return;
  }

  map[char1][char2] = distance;
  
}
void hashTable::removeVertex(char* char1){
  // First delete char from Map
  map.erase(char1);
  
  
}
void hashTable::removeEdge(char* char1, char* char2){
  // Returns if one of the vertices isn't in the hashtable 
  if(search(char1)==NULL||search(char2)==NULL){
    cout << "Invalid input." << endl;
    return;
  }
  map[char1].erase(char2);
}
char* hashTable::search(char* char1){
  
}
char* hashTable::findShortest(char* char1, char* char2, int &distance){

}
  
void hashTable::print(){
  
}