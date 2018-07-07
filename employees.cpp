#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>

using namespace boost::multi_index;

struct employee
{
  int         id;
  std::string name;

  employee(int id,const std::string& name):id(id),name(name){}

  bool operator<(const employee& e)const{return id<e.id;}
};

// define a multiply indexed set with indices by id and name
typedef multi_index_container<
  employee,
  indexed_by<
    // sort by employee::operator<
    ordered_unique<identity<employee> >,
    
    // sort by less<string> on name
    ordered_non_unique<member<employee,std::string,&employee::name> >
  > 
> employee_set;

void print_out_by_name(const employee_set& es)
{
	std::cout << "printing out employees using the name index..." << std::endl;
  // get a view to index #1 (name)
  const employee_set::nth_index<1>::type& name_index=es.get<1>();
  // use name_index as a regular std::set
  for(auto i : name_index){
		std::cout << i.name << " " << i.id << std::endl;
	}
}

void print_out_by_id(const employee_set& es)
{
	std::cout << "printing out employees using the id index..." << std::endl;
  // get a view to index #0 (id)
  const employee_set::nth_index<0>::type& name_index=es.get<0>();
  
	for(auto i : name_index){
		std::cout << i.name << " " << i.id << std::endl;
	}
}


struct change_name
{
  change_name(const std::string& new_name):new_name(new_name){}

  void operator()(employee& e)
  {
    e.name=new_name;
  }
  
	void operator()(std::string& name)
  {
    name = new_name;
  }


private:
  std::string new_name;
};



int main(){
	employee_set employees;

	employees.insert({1,"bob"});
	employees.insert({2,"susan"});
	employees.insert({1,"bob"});
	employees.insert({2,"bob"});
	employees.insert({4,"bob"});
	employees.insert({1,"alice"});
	employees.insert({3,"alice"});

	//print_out_by_name(employees);
	//print_out_by_id(employees);
	employee_set::nth_index<1>::type& name_index = employees.get<1>();
	const employee_set::nth_index<0>::type& id_index = employees.get<0>();
	
	employee_set::nth_index<1>::type::iterator bob = name_index.find("bob");
	

	employee notBob = *bob;
	notBob.name = "not bob";
	name_index.replace(bob, notBob);
	std::cout << bob->name <<  std::endl;
	// object to modify, how to modify, how to roll back in the event of an exception
	name_index.modify(bob, change_name("back to bob"), change_name("bob"));
	
	std::cout << bob->name <<  std::endl;

	name_index.modify_key(bob, change_name("KEY"), change_name("bob"));

	std::cout << bob->name <<  std::endl;
}
