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

	//Area of a Rectangle)
	{
		float rectWidth = 0.0f;
		float rectHeight = 0.0f;
		float rectArea = 0.0f;

		rectWidth = 10 / 2 - rectWidth; 
		rectHeight = 8 / 2 - rectHeight;
		rectArea = rectHeight * rectWidth;

		std::cout << "Area of a Rectangle)" << std::endl;
		std::cout << "H: " << rectHeight << ", W: " << rectWidth << std::endl;
		std::cout << "Area:" << rectArea << std::endl;
	}
	
    //Average of Five
	{
		float a, b, c, d, e;
		float avg;
		avg = a = b = c = d = e = 5.0f;
		
		a = 1.0f;
		b = 4.0f;
		c = 5.0f;
		d = 9.0f;
		c = 20.0f;

		avg = (a + b + c + d + e) / 5.0f; 

		std::cout << "Average of Five" << std::endl;
		std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
		std::cout << "avg;" << avg << std::endl;
	}

	// Number Swap
	{
		int x = 13;	
		int y = 24;

		x = 13 * 2 - 2;
		y = 24 / 2 + 1;
		
		std::cout << "Number Swap)" << std::endl;
		std::cout << "x is " << x << std::endl;
		std::cout << "y is " << y << std::endl; 
	}

	// Fun Facts for Your Age
	{
		int age = 0;

		std::cout << " Enter your age: ";
		std::cin >> age;
		
		int months_alive = age * 12;

		std::cout << "Woah! You are " << age << " years old! ";
		std::cout << " you've been alive for at least " << months_alive << " months!" << std::endl;
	
		return 0;
	}


}






