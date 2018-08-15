#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <iostream>
#include <set>
#include <list>
#include <map>

using namespace boost::multi_index;


struct employee
{
  int         id;
  std::string name;

  employee(int id,const std::string& name):id(id),name(name){}

  bool operator<(const employee& e)const{return id<e.id;}
};

void printEmployee(employee e){
	std::cout << e.name << ": " << e.id << " ";
}

void compareSetAndMultiIndex(){
	typedef multi_index_container<employee> employeeMI;
	std::set<employee> employeeSet;
	employeeMI employeeMultiIndex;

  const employeeMI::nth_index<0>::type& idIndex = employeeMultiIndex.get<0>();
		
	employeeMultiIndex.insert({1,"bob"});
	employeeMultiIndex.insert({2,"susan"});
	employeeMultiIndex.insert({1,"bob"});
	employeeMultiIndex.insert({2,"bob"});
	employeeMultiIndex.insert({4,"bob"});
	employeeMultiIndex.insert({1,"alice"});
	employeeMultiIndex.insert({3,"alice"});

	employeeSet.insert({1,"bob"});
	employeeSet.insert({2,"susan"});
	employeeSet.insert({1,"bob"});
	employeeSet.insert({2,"bob"});
	employeeSet.insert({4,"bob"});
	employeeSet.insert({1,"alice"});
	employeeSet.insert({3,"alice"});
	
	std::cout << "printing multiIndex contents..." << std::endl;
	std::for_each(idIndex.begin(), idIndex.end(),[](employee e){printEmployee(e);});
	std::cout << std::endl;
	std::cout << "printing set contents..." << std::endl;
	std::for_each(employeeSet.begin(), employeeSet.end(),[](employee e){printEmployee(e);});
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
}


void compareMultiSetAndMultiIndex(){
	std::multiset<employee> employeeMultiSet;
	typedef multi_index_container<employee,
		indexed_by<
  	  ordered_non_unique<member<employee,int,&employee::id> >
		>
	> employeeMI;
	employeeMI employeeMultiIndex;
  const employeeMI::nth_index<0>::type& idIndex = employeeMultiIndex.get<0>();
	
	employeeMultiIndex.insert({1,"bob"});
	employeeMultiIndex.insert({2,"susan"});
	employeeMultiIndex.insert({1,"bob"});
	employeeMultiIndex.insert({2,"bob"});
	employeeMultiIndex.insert({4,"bob"});
	employeeMultiIndex.insert({1,"alice"});
	employeeMultiIndex.insert({3,"alice"});

	employeeMultiSet.insert({1,"bob"});
	employeeMultiSet.insert({2,"susan"});
	employeeMultiSet.insert({1,"bob"});
	employeeMultiSet.insert({2,"bob"});
	employeeMultiSet.insert({4,"bob"});
	employeeMultiSet.insert({1,"alice"});
	employeeMultiSet.insert({3,"alice"});
	
	std::cout << "printing multiIndex contents..." << std::endl;
	std::for_each(idIndex.begin(), idIndex.end(),[](employee e){printEmployee(e);});
	std::cout << std::endl;
	std::cout << "printing multiset contents..." << std::endl;
	std::for_each(employeeMultiSet.begin(), employeeMultiSet.end(),[](employee e){printEmployee(e);});
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
}

void compareListAndMultiIndex(){
	std::list<employee> employeeList;
	typedef multi_index_container<employee,
		indexed_by<
			sequenced<>	
		>
	> employeeMI;
	employeeMI employeeMultiIndex;
  const employeeMI::nth_index<0>::type& sequentialIndex = employeeMultiIndex.get<0>();
	
	employeeMultiIndex.push_back({1,"bob"});
	employeeMultiIndex.push_back({2,"susan"});
	employeeMultiIndex.push_back({1,"bob"});
	employeeMultiIndex.push_back({2,"bob"});
	employeeMultiIndex.push_back({4,"bob"});
	employeeMultiIndex.push_back({1,"alice"});
	employeeMultiIndex.push_back({3,"alice"});

	employeeList.push_back({1,"bob"});
	employeeList.push_back({2,"susan"});
	employeeList.push_back({1,"bob"});
	employeeList.push_back({2,"bob"});
	employeeList.push_back({4,"bob"});
	employeeList.push_back({1,"alice"});
	employeeList.push_back({3,"alice"});
	
	std::cout << "printing multiIndex contents..." << std::endl;
	std::for_each(sequentialIndex.begin(), sequentialIndex.end(),[](employee e){printEmployee(e);});
	std::cout << std::endl;
	std::cout << "printing list contents..." << std::endl;
	std::for_each(employeeList.begin(), employeeList.end(),[](employee e){printEmployee(e);});
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
}

template <typename T1,typename T2>
struct mutable_pair
{
  typedef T1 first_type;
  typedef T2 second_type;

  mutable_pair():first(T1()),second(T2()){}
  mutable_pair(const T1& f,const T2& s):first(f),second(s){}
  mutable_pair(const std::pair<T1,T2>& p):first(p.first),second(p.second){}

  T1         first;
  mutable T2 second;
};

void compareMapAndMultiIndex(){
	typedef mutable_pair<int, employee> idEmployeePair;
	std::map<int, employee> employeeMap;
	typedef multi_index_container<idEmployeePair,
		indexed_by<
			ordered_unique<member<idEmployeePair,int,&idEmployeePair::first> >
		>
	> employeeMI;
	employeeMI employeeMultiIndex;
  const employeeMI::nth_index<0>::type& mapIndex = employeeMultiIndex.get<0>();
		
	idEmployeePair p1(1,employee(1,"bob"));
	idEmployeePair p2(2,employee(2,"susan"));
	idEmployeePair p3(2,employee(1,"bob"));
	idEmployeePair p4(4,employee(4,"bob"));
	idEmployeePair p5(1,employee(1,"alice"));
	idEmployeePair p6(3,employee(3,"alice"));
	employeeMultiIndex.insert(p1);
	employeeMultiIndex.insert(p2);
	employeeMultiIndex.insert(p3);
	employeeMultiIndex.insert(p4);
	employeeMultiIndex.insert(p5);
	employeeMultiIndex.insert(p6);

	employeeMap.insert({1,{1,"bob"}});
	employeeMap.insert({2,{2,"susan"}});
	employeeMap.insert({1,{1,"bob"}});
	employeeMap.insert({2,{2,"bob"}});
	employeeMap.insert({4,{4,"bob"}});
	employeeMap.insert({1,{1,"alice"}});
	employeeMap.insert({3,{3,"alice"}});
	
	std::cout << "printing multiIndex contents..." << std::endl;
	std::for_each(mapIndex.begin(), mapIndex.end(),[](mutable_pair<int,employee> p){printEmployee(p.second);});
	std::cout << std::endl;
	std::cout << "printing map contents..." << std::endl;
	std::for_each(employeeMap.begin(), employeeMap.end(),[](std::pair<int,employee> p){printEmployee(p.second);});
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
}

void compareMapAgainAndMultiIndex(){
	typedef mutable_pair<int, std::list<std::string>> idAliasPair;
	std::map<int, std::list<std::string>> aliasMap;
	typedef multi_index_container<idAliasPair,
		indexed_by<
			ordered_unique<member<idAliasPair,int,&idAliasPair::first> >
		>
	> employeeMI;
	employeeMI employeeMultiIndex;
  const employeeMI::nth_index<0>::type& mapIndex = employeeMultiIndex.get<0>();
		
	idAliasPair p1(1,{"bob","bobby","bobORama"});
	idAliasPair p2(2,{"susan","suzie","suzieQ"});
	idAliasPair p3(2,{"bob2"});
	idAliasPair p4(4,{"bob","robert","bob4"});
	idAliasPair p5(1,{"alice"});
	idAliasPair p6(3,{"alice","al","big al","ally cat"});
	employeeMultiIndex.insert(p1);
	employeeMultiIndex.insert(p2);
	employeeMultiIndex.insert(p3);
	employeeMultiIndex.insert(p4);
	employeeMultiIndex.insert(p5);
	employeeMultiIndex.insert(p6);

	aliasMap.insert({1,{"bob","bobby","bobORama"}});
	aliasMap.insert({2,{"susan","suzie","suzieQ"}});
	aliasMap.insert({2,{"bob2"}});
	aliasMap.insert({4,{"bob","robert","bob4"}});
	aliasMap.insert({1,{"alice"}});
	aliasMap.insert({3,{"alice","al","big al","ally cat"}});
	
	std::cout << "printing multiIndex contents..." << std::endl;
	std::for_each(mapIndex.begin(), mapIndex.end(),[](mutable_pair<int,std::list<std::string> > p){
		std::cout << "printing " << p.first << "'s aliases..." << std::endl;
		for(auto i: p.second){
			std::cout << i << " ";
		}
		std::cout << std::endl;
	});
	std::cout << std::endl;
	std::cout << "printing map contents..." << std::endl;
	std::for_each(aliasMap.begin(), aliasMap.end(),[](std::pair<int,std::list<std::string>> p){
		std::cout << "printing " << p.first << "'s aliases..." << std::endl;
		for(auto i: p.second){
			std::cout << i << " ";
		}
		std::cout << std::endl;
	});
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
}


int main(){
	//compareSetAndMultiIndex();	
	//compareMultiSetAndMultiIndex();	
	//compareListAndMultiIndex();	
	//compareMapAndMultiIndex();
	//compareMapAgainAndMultiIndex();
}
