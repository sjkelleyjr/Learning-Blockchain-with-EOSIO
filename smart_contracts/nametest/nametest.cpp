#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>


class nametest : public eosio::contract {
	using contract::contract;


	public:	
		nametest(account_name self):contract(self){}
		
		void test(account_name sender){
			eosio::print("Hello from ", eosio::name{sender});
		}
};


EOSIO_ABI(nametest, (test));
