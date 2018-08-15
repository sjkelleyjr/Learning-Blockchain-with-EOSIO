#include <iostream>
#include <set>

struct employee
{
  int         id;
  std::string name;

  employee(int id,const std::string& name):id(id),name(name){}

  bool operator<(const employee& e)const{return id<e.id;}
};

class nameComparator{
	public:
		bool operator() (const employee& e1, const employee& e2) const {
			return e1.name < e2.name;
		}
};


int main(){
	std::set<employee> id_set;
	std::set<employee, nameComparator> name_set;
	
	id_set.insert({1,"bob"});
	id_set.insert({2,"susan"});
	id_set.insert({1,"bob"});
	id_set.insert({2,"bob"});
	id_set.insert({4,"bob"});
	id_set.insert({1,"alice"});
	id_set.insert({3,"alice"});

	name_set.insert({1,"bob"});
	name_set.insert({2,"susan"});
	name_set.insert({1,"bob"});
	name_set.insert({2,"bob"});
	name_set.insert({4,"bob"});
	name_set.insert({1,"alice"});
	name_set.insert({3,"alice"});

	std::cout << "printing out employees using the id set..." << std::endl;
	for(auto i : id_set){
		std::cout << i.name << " " << i.id << std::endl;
	}
	
	std::cout << "printing out employees using the name set..." << std::endl;
	for(auto i : name_set){
		std::cout << i.name << " " << i.id << std::endl;
	}
}
