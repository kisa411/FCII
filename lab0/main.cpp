#include <iostream>
#include "mortgage.h"
using namespace std;

int main() {
	Mortgage first(10000, 5.0, 500);	//uses non-default initialization constructor
	Mortgage second;	//uses default constructor

	second.credit(10000);
	cout << "Current balance after crediting second mortgage 10K: " << second.getPrincipal() << endl;
	cout << "Amortization schedule for first mortgage: \n" << endl;
	first.amortize();

}