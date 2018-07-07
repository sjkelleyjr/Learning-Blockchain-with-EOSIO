#include <boost/tokenizer.hpp>
#include <iostream>
#include <list>

typedef std::list<std::string> text_container;

void printText(text_container tc){
	for(auto i: tc){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main(){
	std::string text=
  	"Alice was beginning to get very tired of sitting by her sister on the "
  	"bank, and of having nothing to do: once or twice she had peeped into the "
  	"book her sister was reading, but it had no pictures or conversations in "
  	"it, 'and what is the use of a book,' thought Alice 'without pictures or "
  	"conversation?'";
	// feed the text into the list
	text_container tc;
	boost::tokenizer<boost::char_separator<char> > tok(text,boost::char_separator<char>(" \t\n.,;:!?'\"-"));
	std::copy(tok.begin(),tok.end(),std::back_inserter(tc));

	std::cout << std::count(tc.begin(), tc.end(), "to") << std::endl;
	printText(tc);

	tc.remove("to");
	std::cout << std::count(tc.begin(), tc.end(), "to") << std::endl;
	printText(tc);
}
