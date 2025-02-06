#include <iostream>
    

int main()
{

	// A)

	{int numberA = 5;


	 numberA = 9;
     numberA = 11;
	 numberA = 14;


	std::cout << "A) " << numberA << std::endl;
}
	

	// B)
	{

		int numberB = 10;
		numberB = 9;

		int thingB = 55;
		thingB = 22;

		numberB = thingB;


		std::cout << "B) " << numberB << std::endl;  
	}

	// C)
	{
	
		int numberC = 3;
		numberC = 7;
		numberC = 1;

		int somethingC = 23;
		somethingC = 21;

		numberC = somethingC;

		std::cout << "C) " << numberC << std::endl;

	}

     // D)
	{
		
		int numberD = 1;
		numberD = 8;

		int somethingD = 3;
		somethingD = 10;
		
		numberD = somethingD;

		std::cout << "D) " << somethingD << std::endl;

	}
	 // E)
	{
		
		int x = 13;

		
		x = x / 2;


		std::cout << "E)" << x << std::endl;
	}

	{
		
		float y = 13;

		y = y = 2;

		std::cout << "F)" << y << std::endl;

	}
	{
		//Celsius to Fahrenheit)

		

		float degCelsius = 78.0f;
		float degFahrenheit = 0.0f; // modify this variable below

		degFahrenheit = (degCelsius * 9.f / 5.f + 32.f);


		std::cout << "Celsius to Fahrenheit)" << std::endl; 
		std::cout << "Celsius: " << degCelsius << std::endl;
		std::cout << "Fahrenheit: " << degFahrenheit << std::endl;
	}

}   



