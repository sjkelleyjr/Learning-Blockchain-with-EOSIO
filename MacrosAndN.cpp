#include <iostream>

#define N(X) string_to_name(#X)
#define TEST(X) printStr(#X)

using namespace std;

static constexpr  char char_to_symbol( char c ) {
      if( c >= 'a' && c <= 'z' )
         return (c - 'a') + 6;
      if( c >= '1' && c <= '5' )
         return (c - '1') + 1;
      return 0;
}

string printStr(const char* str){
	return string(str);
}

static constexpr uint64_t string_to_name( const char* str ) {
      uint32_t len = 0;
			printf("string value passed to string_to_name: ");
      while( str[len] ){
	 			printf("%c",str[len]);
	 			++len;
      } 
      printf("\n");

      uint64_t value = 0;

      for( uint32_t i = 0; i <= 12; ++i ) {
         uint64_t c = 0;
         if( i < len && i <= 12 ) c = uint64_t(char_to_symbol( str[i] ));

         if( i < 12 ) {
            c &= 0x1f;
            c <<= 64-5*(i+1);
         } else {
            c &= 0x0f;
         }
         value |= c;
      }
      return value;
}


int main(){
 	const char* testString = "TEST123123123123";
	cout << "return from the N macro: " << N(testString) << endl;
	cout << "return from string_to_name: " << string_to_name(testString) << endl;
	cout << "simple string conversion: " << printStr(testString) << endl;
	cout << "using a simple string conversion with a macro: " << TEST(testString) << endl;	
 	const int jacksonCoin = 0;
	cout << "test null pointer char*: " << TEST(jacksonCoin) << endl;	
}
