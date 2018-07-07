#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T> vec){
	for(auto i: vec){
		cout << i << " ";
	}
	cout << endl;
}



int main(){
	vector<int> v1 = {1,2,3,4};
	//vector<Car> c2 = {Car(10,"v2",10), Car(1,"v4",10)};
	vector<string> v2 = {"4","3","2","1"};
	vector<float> v3 = {10,20,30,40};
	printVector(v1);
	printVector(v2);
	printVector(v3);
	//printVector(c2);	
}
