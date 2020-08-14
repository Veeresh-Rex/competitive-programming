#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 


cpp_int boost_factorial(int num) 
{ 
	cpp_int fact = 1; 
	for (int i=num; i>1; --i)	 
		fact *= i; 
	return fact; 
} 

int main() 
{ 
    int t;
    std::cin >> t;
    while(t--){
    
	int n;
	std::cin>>n;
	std::cout 	<< boost_factorial(n) <<std::endl;
 
    }
	return 0; 
} 
