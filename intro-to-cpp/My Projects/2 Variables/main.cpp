#include <iostream>
    

int main()
{

	// main.cpp/main()
    // ...
    //A) My guess was 9
    // answer was 14


	int numberA = 5;

	numberA = 9;
	numberA = 11;
	numberA = 14;


	std::cout << "A)" << numberA << std::endl;

	//...

	
	{
		//B)
		// My guess is 22
		// Answer was 9
		int numberB = 10;
		numberB = 9;

		int thingB = 55;
		thingB = 22,

			std::cout << "B)" << numberB << std::endl;
	}

	{
		//C)
		// My guess is 1
		// Answer was 21
		int numberC = 3;
		numberC = 7;
		numberC = 1;

		int somethingC = 23;
			somethingC = 21;

			numberC = somethingC;

			std::cout << "C)" << numberC << std::endl;

	}
	{
		//D
		// My guess is 3
		// Answer was 3
		int numberD = 1;
		int somethingD = 3;

		numberD = somethingD;

		std::cout << "D)" << somethingD << std::endl;

	}
	 
	{
	 // E)
     // My guess is 6.5
     // Answer was 6
		int x = 13;
		
		x = x / 2;

		std::cout << "E)" << x << std::endl;
	}

	{
		// F)
		//My guess is 6
		//Answer is 2 
		float y = 13;
		
		y = y = 2;
		
		std::cout << "F)" << y << std::endl;

	}
}   


