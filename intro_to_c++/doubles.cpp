#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/lambda/lambda.hpp>
#include <iostream>

using namespace boost::multi_index;
typedef multi_index_container<double> double_set;


int main(){
	double_set ds;
	ds.insert(100.00);
	ds.insert(10.00);
	ds.insert(3.75);
	ds.insert(80.00);
	ds.insert(100.00);

	std::pair<double_set::iterator,double_set::iterator> p = ds.range(50.0<=boost::lambda::_1,boost::lambda::_1<=200);
	for_each(p.first, p.second, [](double d){std::cout << d << " ";});
}
