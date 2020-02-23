///////////////////////////////////////////////////////////////////////////////
//
// Author:           Landen Jones & Terry
// Email:            LandenSJones@yahoo.com
// Title:            main.cpp
//
// Description:
//          This program takes a json file filled with key words and definitinos and reads
//          into a linked list containing both the word and definition. Using the getch function
//          you can access all of the words in the linked list that begin with certain characters
//          that you designate.
//
//
// Usage:
//
//      J = new JsonFacade("file_to_read");
//
//
// Files:
//      json.hpp
//      JsonFacade.hpp
//      Timer.hpp
//      Dict.cpp
//      mygetch.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;


struct Node{
  string word;
  string def;
  Node* Next;
  Node(string w, string d){
    word = w;
	def = d;
    Next = NULL;
  }
};

class Dictionary {
private:
  Node* Start;
  Node* ResultList;
  Node* ResultCursor;
  string LowerCase(string input){
    for(int i=0;i<input.length();i++){
      if((int)input[i] < 96){
        input[i] += 32;
      }
    }
    return input;
  }


public:
	vector<string> results;
  Dictionary(){
    Start = NULL;
  }

  ~Dictionary(){
    cout<< "Dictionary destructor called";
  }

  void Add(string word, string def){

    word = LowerCase(word);
    // create new memory
    Node* temp = new Node(word, def);
  
    // if list is empty hook in new Node
    if(Start == NULL){
      Start = temp;
    }else{
      // get ready to walk the list
      Node* traverse = Start;
      while(traverse->Next != NULL){
        // walks the list
        traverse = traverse->Next;
      }
      // now at proper place to link in new memory
      traverse->Next = temp;
    }
  }

  void Print(ofstream& outfile){
    Node* temp = Start;
    while(temp){
      outfile<<temp->word;
      if(temp->Next){
        outfile<<"->";
      }
      temp = temp->Next;
    }
    outfile<<endl;
  }
  int sizeOfVec()
  {
	  return results.size();
  }
  void FindWord(string search, int c){
	  Node* Temp = Start;
	  int check = 0;

	  while(Temp!=NULL){
		  for(int i = 0; i < c; i++){
			  if(Temp->word[i] == search[i]){
				  check++;
			  }
		  }
		  if(check==c){
			  results.push_back(Temp->word);
		  	}
			Temp = Temp->Next;
			check = 0;
		  }  
	  }	  
};

/////////////////////////////////////////////////////
