#include<iostream>
#include "CialoNiebieskie.h"
#include "Gwiazda.h"

int main()
{  char a;
   

  
 std::cout << "Solar systems" << std::endl;
    
 Gwiazda Slonce;
    Slonce.HelloG();

    CialoNiebieskie Cialo;
    Cialo.Hello();

  

 std::cin >> a;
 
	return 0;
}