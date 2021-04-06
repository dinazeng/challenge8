// challenge_8.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

//
// ... add any helper functions (write them yourself!) here ...
//

int findRes5(string fileName){
    ifstream fin(fileName);
    if (fin.fail()){cmpt::error("invalid file please try again");}
    int counter = 0;
    int pos = 1;
    while (true){
        string fileStr;
        getline(fin, fileStr);
        if(fin.fail()){break;}
        else if (fileStr.find(' ') == string::npos){if (stoi(fileStr) % 5 == 0){counter++;}}
        else{
            int first = stoi(fileStr.substr(0, fileStr.find(' ')));
		    int result;
		    fileStr = fileStr.substr(fileStr.find(' ') + 1);
		    char strSymbol = fileStr.at(0);
		    fileStr = fileStr.substr(fileStr.find(' ') + 1);
		    int second = stoi(fileStr.substr(0, fileStr.find(' ')));
		    int stop = 0;
		    while (stop < 2){
		    	if (strSymbol == '@'){
                    if (first < 0){first*= -1;}
                    if (second < 0){second*= -1;}
                    result = first % second;}
		    	else if (strSymbol == '*'){result = first * second;}
		    	else if (strSymbol == '+'){result = first + second;}
		    	else if (strSymbol == '-'){result = first - second;}
		    	first = result;
		    	if (fileStr.find(' ') == string::npos){
		    		stop++;
		    		if (stop == 2){break;}}
		    	fileStr = fileStr.substr(fileStr.find(' ') + 1);
		    	strSymbol = fileStr.at(0);
		    	fileStr = fileStr.substr(fileStr.find(' ') + 1);
		    	second = stoi(fileStr.substr(0, fileStr.find(' ')));}
		    if (result % 5 == 0){counter++;}}}
    fin.close();
    return counter;}

int main() {
	cout << "Challenge 8 ...\n";
	// ...
	cout << findRes5("expr1000.txt");
}