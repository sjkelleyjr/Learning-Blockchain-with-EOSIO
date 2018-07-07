#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>

using namespace boost::multi_index;

struct list{};

typedef multi_index_container<
  std::string,
  indexed_by<
    sequenced<tag<list>>, // list-like index
    ordered_non_unique<identity<std::string> > // words by alphabetical order
  >
> text_container;

void printText(text_container tc){
	for(auto i: tc){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

std::string text=
  "Alice was beginning to get very tired of sitting by her sister on the "
  "bank, and of having nothing to do: once or twice she had peeped into the "
  "book her sister was reading, but it had no pictures or conversations in "
  "it, 'and what is the use of a book,' thought Alice 'without pictures or "
  "conversation?'";

// feed the text into the list
int main() {
	text_container tc;
	boost::tokenizer<boost::char_separator<char> > tok(text,boost::char_separator<char>(" \t\n.,;:!?'\"-"));
	std::copy(tok.begin(),tok.end(),std::back_inserter(tc));
	text_container::nth_index<1>::type& sorted_index=tc.get<1>();
	text_container::index<list>::type::iterator it = tc.get<list>().begin();
	
	std::cout << sorted_index.count("to") << " " << std::endl;
	
	sorted_index.erase("to");
	printText(tc);

	std::cout << sorted_index.count("to") << " " << std::endl;

	for(auto i = it; i != it.end(); i++){
		std::cout << i << " ";
	}
	std::cout << std::endl;

}
