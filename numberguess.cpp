#include <iostream>

int main()
{
	int numbers[100];
	int middle;
	char Input;
	bool gameOver = true;
	int min = 0,max = 100;
	int numberOfGuess = 0;
	gameOver = false;

	for(int i = 0; i < 100; i++)
	{
		numbers[i] = i + 1;
	}
	
	while(!gameOver)
	{
		numberOfGuess++;
		middle = (min + max) / 2;
		std::cout << "Is your number " << numbers[middle-1] << "? (Y == yes, L == min, H == higher)" << std::endl;
		std::cin >> Input;
		bool validInput = Input == 'Y' || Input == 'y' || Input == 'L' || Input == 'l' || Input == 'H' || Input == 'h' ? true : false;

		if(validInput)
		{
			if(Input == 'L' || Input == 'l')
			{
				max = middle;
			}
			else if(Input == 'H' || Input == 'h') 
			{
				min = middle;
			}
			else
			{
				break;
			}
		}
		else 
		{
			std::cout << "Input not valid. Try again." << std::endl;
		}
		
		if(numberOfGuess >= 7)
		{
			std::cout << "You either lied or entered the wrong input, try again.\n";
			system("pause");
			return 0;
		}
	
	}
	std::cout << "Your number was " << numbers[middle-1] << ".\n";
	std::cout << "It was guessed in " << numberOfGuess << " tries.\n";
	

	system("pause");
    return 0;
}
