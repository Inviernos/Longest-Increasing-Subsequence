//Programmer: Anthony Golubski-Allen
//Date: 4/18/16
//Program: Finds the longest increasing subsequence of a sequence given input from a file 
//called incseq.txt

#include <iostream>
#include <fstream>

using namespace std;

#define MAX 15

int main()
{
	//Declaring Variables
	ifstream myFile;
	int number;
	int Sequence[MAX];
	int Table[MAX];
	int subSequence[MAX];
	int increment = 0;
	int cur_size = 0;
	bool once = true;
	int maxlength = 0;
	int max;
	int maxindex = 0;

	Table[0] = 1;

	//Open the file
	myFile.open("incseq.txt");

	//Go through the file until it is empty
	while (myFile >> number)
	{
		if (once)
		{
			cur_size = number;

			//If there is more than 15 elements
			if (cur_size > MAX)
			{
				cout << "You have exceeded the limit";
			}
			once = false;
		}
		else
		{
			Sequence[increment] = number;
			increment++;
		}

	}

	//close the file
	myFile.close();

	cout << "The Input Sequence\n";

	//output the input sequence
	for (int i = 0; i < cur_size; i++)
	{
		cout << Sequence[i] << " ";
	}


	//start the algorithm
	for (int i = 1; i < cur_size; i++)
	{
		for (int j = i; j > -1; j--)
		{

			max = Sequence[i];

			// The number is a predecessor 
			if (Sequence[j] < max)
			{
				//its length is higher than the others
				if (Table[j] > maxlength)
				{
					maxlength = Table[j];
				}
			}

			//Reached the end of the sequence to add length to table
			if (j == 0)
			{
				Table[i] = maxlength + 1;
				maxlength = 0;
			}
		}

	}

	//find the max length
	for (int n = cur_size-1; n >=0 ; n--)
	{
		max = Table[n];

		//
		if (maxlength == 0)
		{
			maxlength = max;
			maxindex = n;
			cur_size = maxlength;
		}
		else
		{
			if (max > maxlength)
			{
				maxlength = max;
				maxindex = n;
				cur_size = maxlength;
			}
		}
		
	}

	cout << "\n\nThe Max length of the longest increasing subsequence is " << maxlength << endl;

	//input the max input in the subsequence
	subSequence[Table[maxindex]-1] = Sequence[maxindex];
	increment = 1;

	//find the sequence
	for (int i = maxindex; i >= 0; i--)
	{
		maxlength = Table[i];

		if (maxlength == Table[maxindex] - increment)
		{
			maxlength = i;
			subSequence[Table[maxlength]-1] = Sequence[maxlength];
			increment++;
		}
	}

	cout << "\nThe longest subsequence\n";
	
	//print the subsequence
	for (int j = 0; j < cur_size; j++)
	{
		cout << subSequence[j] << " ";
	}

	cout << endl;

	return 0;
	
}