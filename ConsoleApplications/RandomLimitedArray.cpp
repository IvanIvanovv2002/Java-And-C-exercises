

#include <iostream>
using namespace std;

int main()
{
	//Creating a limit for the randoms and then calculating the number for each of them.
	srand(time(NULL));
	int arrayCount;
	cin >> arrayCount;

	int positives = 0;
	int negatives = 0;
	int* array = new int[arrayCount];

	int lowerBound = -100;
	int upperBound = 100;
	for (size_t i = 0; i < arrayCount; i++)
	{
		array[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
		if (array[i] > 0) positives++;
		else negatives++;
	}

	printf("Negatives: %d\n", negatives);
	printf("Positives: %d\n", positives);
}

