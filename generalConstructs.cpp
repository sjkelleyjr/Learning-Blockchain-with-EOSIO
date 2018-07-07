#include <iostream>

using namespace std;

struct ForLoopControl{
	int numberOfIterations;
	bool isGreaterThanTen;
};


bool parameterizedForLoop(int forLoopLength) {
	for(int i = 0; i < forLoopLength; i++ ){
		if(forLoopLength >= 10){
			return true;
		}
	}
	return false;
}


bool parameterizedForLoop(ForLoopControl fControl) {
	for(int i = 0; i < fControl.numberOfIterations; i++ ){
	}
	return fControl.isGreaterThanTen;
}


int main(){
	ForLoopControl fControl;
	fControl.numberOfIterations = 100;
	fControl.isGreaterThanTen = true; 
	//cout << parameterizedForLoop(11) << endl;
	cout << parameterizedForLoop(fControl) << endl;
}
