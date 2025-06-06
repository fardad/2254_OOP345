#include <iostream>
#include <cstring>
using namespace std;

struct Container {
   int value;
   bool hasMore( const Container& );
};


//template <typename T>
template <class T>
T largest( T a, T b ) {
   return a > b ? a : b;
}

template <>
const char* largest<const char*>( const char* a, const char* b ) {
   return strcmp( a, b ) > 0 ? a : b;
}

template <>
Container largest<Container>( Container C1, Container C2 ) {
   return C1.hasMore( C2 ) ? C1 : C2;
}

int main( ) {
   cout << "OOP345NEE May21" << endl;
   int a, b = 10;
   double c = 11.0;
   char s1[] = "abc";
   char s2[] = "cdefg";
   cout << largest( s1, s2 ) << endl;
   a = largest<int>( b, c ); // resolve template calls manually

   return 0;
}