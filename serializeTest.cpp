#include <iostream>
#include "serializeTest.hpp"


using namespace std;



class test{
	public:
		struct testStruct{
			int i;
			EOSLIB_SERIALIZE(testStruct,(i));
  	} t;
};

int main(){
	test TEST;
	TEST.t.i = 10;
	TEST.t.EOSLIB_SERIALIZE;

}
