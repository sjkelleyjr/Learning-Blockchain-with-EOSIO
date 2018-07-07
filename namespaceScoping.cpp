#include <iostream>

using namespace std;

namespace Tree{
	class Trunk{
		int externalWater;
		int internalWater;
	public:
		Trunk(int externalWater){
			this->externalWater = externalWater;
			this->internalWater = 0;
		}
		bool drinkWater(){
			if(externalWater > 0){
				externalWater -= 10;
				internalWater += 10;
				return true;
			}
			return false;
		}
		int getExternalWater(){
			return this->externalWater;
		}
	};

	void RandomFunction(){
		for(int i = 0; i < 10; i++){
			cout << i << " ";
		}
		cout << endl;
	}
	int leaves;
	int amountOfSunshine;
	int numberOfBirds;
};

using namespace Tree;

int main(){
	leaves = 10;
	cout << leaves << endl;
	Tree::Trunk t = Tree::Trunk(100);
	t.drinkWater();
	cout << t.getExternalWater() << endl;
	Tree::RandomFunction();
}

