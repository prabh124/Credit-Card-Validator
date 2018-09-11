#include <iostream>
#include <string>
using namespace std;


bool cardValidator(int cardNumber[], int sum);
int sumOfEvenNumbers(int cardNumber[], int length);
int sumOfOddNumbers(int cardNumber[], int length);

int main()
{
	int total;
	string input;
	bool redo;
	char restart;

    cout << "--------------------------------" << endl;
    cout << "Credit Card Validator" << endl;
    cout << "--------------------------------" << endl;

	do
	
	{

        cout << "\nPlease enter your credit card number: " << endl;
		cin >> input;
                
                // if the input length is greater than 16 or less than 13, then prompt the user to input again
				while ((input.length() > 16) || (input.length() < 13))
				{
					cout << "\nInvalid input, try again! ";
					cin >> input;
				}
		
				int p = input.length();
		
				const int length(16);
				int card[length];

				for (int i = 0; i < input.size(); i++)
				{

					card[i] = input[i] - '0';

				}

		total = sumOfEvenNumbers(card, p) + sumOfOddNumbers(card, p);

        // if the card is valid, check which companies card it is
		if (cardValidator(card, total))
		
		{
			
			if (card[0] == 4)
				cout << "Is a valid Credit Card number! [Visa]";

			if (card[0] == 5)
				cout << "Is a valid Credit Card number! [Master Card]";
			
			if ((card[0] == 3) && (card[1] == 7))
				cout << "Is a valid Credit Card number! [American Express Card]";
			
			if (card[0] == 6)
				cout << "Is a valid Credit Card number! [Discovery Card]";

            // prompt the user to run the program again

			cout << "\nWould you like to try again? (Y/N) ";
			cin >> restart;
			restart = tolower(restart);
			
			if (restart == 'y')
				redo = true;
			
			else
				redo = false;
		}
		
		else
	
		{
			cout << "\nInvalid Card Number!" << endl;
			redo = true;
		}
	}

	while (redo);
}

	int sumOfEvenNumbers(int cardNumber[], int length)
	{
		int evenSum = 0;
	
		for (int i = length - 2; i >= 0; i -= 2)
		{
		
			int num = cardNumber[i];

				num *= 2;

				if (num > 9)
				{
					num -= 9;
				}
				evenSum += num;
	
		}

		return evenSum;
	}

	int sumOfOddNumbers(int cardNumber[], int length)

	{
		int oddSum = 0;
	
		for (int i = length - 1; i >= 0; i -= 2)
		{
		
			int num = cardNumber[i];

				if (num > 9)
				{
					num -= 9;
				}
				oddSum += num;

		}
	
		return oddSum;
	}

	bool cardValidator(int cardNumber[], int sum)
	{
			if (sum % 10)
            {
				return false;
			}
			else
			{
				return true;
			}
	
	}
