#include <iostream>
#include "rational.h"
using namespace std;

//Emily Koh

int main() {
	int numerator, denominator, choice, findTheInverseOf;
    Rational answer;

	cout << "What is the numerator of the first rational?" << endl;
	cin >> numerator;
	cout << "What is the denominator of the first rational?" << endl;
	cin >> denominator;
	while( denominator == 0 ) { 
		cout << "The denominator's not valid - please put in a non-zero value." << endl;
		cout << "What is the denominator of the first rational?" << endl;
		cin >> denominator;
	}

	Rational fraction1( numerator, denominator ); //instantiate object of Rational class
    cout << "The given rational has been stored in its simplest form, which is: " << fraction1 << endl;

	cout << "What is the numerator of the second rational?" << endl;
	cin >> numerator;
	cout << "What is the denominator of the second rational?" << endl;
	cin >> denominator;
	while( denominator == 0 ) { 
		cout << "The denominator's not valid - please put in a non-zero value." << endl;
		cout << "What is the denominator of the first rational?" << endl;
		cin >> denominator;
	}

	Rational fraction2( numerator, denominator ); //instantiate object of Rational class
    cout << "The given rational has been stored in its simplest form, which is: " << fraction2 << endl;
    
    cout << "What would you like to do with the rational numbers that you've made?" << endl;
    
    int loop = 1;
    
    while( loop ) {
        cout << "1. Add 2. Subtract 3. Multiply 4. Divide 5. Find the inverse 6. Quit" << endl;
        cin >> choice; //get user input about which action they'd like to perform
        switch( choice ) {
            case 1: //add
                answer = fraction1+fraction2;
                cout << "The sum of the two rationals is: " << answer << endl;
                break;
            case 2: //subtract
                answer = fraction1-fraction2;
                cout << "The difference of the two rationals is: " << answer << endl;
                break;
            case 3: //multiply
                answer = fraction1*fraction2;
                cout << "The product of the two rationals is: " << answer << endl;
                break;
            case 4: //divide
                answer = fraction1/fraction2;
                cout << "The quotient of the two rationals is: " << answer << endl;
                break;
            case 5: //inverse
                cout << "Which rational would you like to find the inverse of? Rational 1 or 2? (please put in just the number of the rational)" << endl;
                cin >> findTheInverseOf;
                if ( findTheInverseOf == 1 ) {
                    Rational temp = fraction1;
                    !temp;
                } else {
                    Rational temp = fraction2;
                    !temp;
                }
                break;
            case 6: //quit
                loop = 0;
                break;
        }
        
    }

	return 0;
}


