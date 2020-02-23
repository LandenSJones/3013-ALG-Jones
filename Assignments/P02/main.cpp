#include <iostream>
#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            // need to grab a copy from resources folder
#include "Dict.cpp"
#include "mygetch.hpp"

using namespace std;

int main(){
	double s; long m;					//variables used for timer
	Timer T;							//timer declared
    ofstream outfile;					//outfile declared
    outfile.open("output.txt");			//outfile opened for debugging and printing linked list
	Dictionary D;						//Created Dictionary
    JsonFacade J("dict_w_defs.json");   // create instance of json class
    string key;                         // key variable to access json object, accesses individual node
    vector<string> keys = J.getKeys();	//gets number of keys
    cout << "Keys: " << keys.size()<<endl; //number of words and defs
	T.Start();								//Timer started
	for(int i = 0; i < keys.size(); i++){		//places all the values into the linked list
		key = J.getKey(i);
		D.Add(key, J.getValue(key));	//adds node with correct values for corresponding defs
	}
	T.End();									//end timer for filling linked list
	s = T.Seconds();
    m = T.MilliSeconds();
	cout << "Time to fill linked list: ";
    cout <<s << " seconds and " <<endl;
    cout <<m << " milli" <<endl;

    char k;             // holder for character being typed
    string word = "";   // var to concatenate letters to with getch

    cout<<"Type keys and watch what happens. Type capital Z to quit."<<endl;
	int index = 0;	//used to keep track of how many letters are in the word
    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {
        word += k;          // append char to word

        if((int)k != 10){   // if k is not a space print it
			while(word[index] != '\0'){		//counts how many letters are found in the word
				cout << "'" << word << "'\n";
				index++;
			}
		T.Start();	//timer for calculating suggested words
		D.FindWord(word, index);		//called from dictionary class to see if there are matching words and what tehy are
		T.End();	//timer ends for word suggestion
		s = T.Seconds();
		//pretty output to show for each search
		cout << D.sizeOfVec() << " found in " << s << " seconds\n";
		if(D.results.size() >= 10){		//prints results of the found suggested words
			cout << word << " -> ";
			for(int i = 0; i < 10;i++){	//if the results are more than 10
				cout << '[' << D.results[i] << "] -> ";
			}
		}
		else{
			for(int i = 0; i < D.results.size() ;i++){	//if the results are less tahn 10
				cout <<'[' << D.results[i] << "] -> ";
			}
		}
		D.results.clear();		//erases values for each new
    }

        // hitting enter sets word back to empty
        if((int)k == 10 ){
            cout<<"Enter pressed ... Word is empty\nWord: "<<endl;
			cout << "index: " << index << endl;
			index = 0;
            word = "";
        }
    }
}
