#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Extract numbers

int main ()
{
	char input;
	char numbers[110000]="\"";
	char text[110000]="\"";

	int numbersIndex=0, lastNumber=1;
	int textIndex=0, lastText = 1;

	bool isNumber = true;
	bool hasLeadingZero = false;


	while (scanf("%c", &input))
	{
		
		if(input== ',' || input == ';' || input=='\n')
		{
			//Is a valid number
			if (isNumber && ( numbersIndex == 1 || (numbersIndex > 1 && !hasLeadingZero)))
			{
				numbers[lastNumber+numbersIndex++] = ',';
				lastNumber += numbersIndex;
			}
			else
			{
				text[lastText+textIndex++] = ',';
				lastText += textIndex;
			}

			isNumber = true;
			hasLeadingZero = false;
			numbersIndex = 0;
			textIndex = 0;

			if (input == '\n')
			{
				if (lastNumber == 1)
				{
					numbers[0]='-';
					numbers[1]='\0';
				}
				else
				{
					numbers[lastNumber-1]='\"';
					numbers[lastNumber]='\0';
				}


				if(lastText == 1)
				{
					text[0]='-';
					text[1]='\0';
				}
				else
				{
					text[lastText-1]='\"';
					text[lastText]='\0';
				}
				break;
			}
		}
		else if (input >= '0' && input<='9')
		{
			if (input == '0' && numbersIndex == 0)
			{
				hasLeadingZero = true;
			}

			if (isNumber)
			{
				numbers[lastNumber+numbersIndex++] = input;
			}

			text[lastText+textIndex++] = input;

		}
		else
		{
			isNumber = false;
			text[lastText+textIndex++] = input;

		}
	}

	printf("%s\n", numbers);
	printf("%s\n", text);

	return 0;

}