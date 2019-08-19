#include <iostream>
#include <string>

using namespace std;

int main()
{
	int highscore = 0;
	string newName;
	int quit = 0;
	int newScore;
	int entries = 0;
	const int MAX_ENTRIES = 5;

	string name[MAX_ENTRIES];
	int score[MAX_ENTRIES];

	do {
		for (int i = 0; i < MAX_ENTRIES; i++)
		{
			cout << "Enter your name: ";
			cin >> newName;
			cout << "Enter your score: ";
			cin >> newScore;
			name[i] = newName;
			score[i] = newScore;
			entries++;
		}

		cout << "\tHIGH SCORE TABLE" << endl << endl;
		cout << name[0] << " " << score[0] << endl;
		cout << name[1] << " " << score[1] << endl;
		cout << name[2] << " " << score[2] << endl;
		cout << name[3] << " " << score[3] << endl;
		cout << name[4] << " " << score[4] << endl;
	} while (entries != 5);

	if (entries == 5)
	{
		entries = 0;
		do
		{
			for (int i = 0; i < 1; i++)
			{
				cout << "Enter your name: ";
				cin >> newName;
				cout << "Enter your new score: ";
				cin >> newScore;
				name[i] = newName;
				score[i] = newScore;
				if (newScore > score[0] && newScore > highscore)
				{
					newScore = score[0];
					highscore = score[0];
					newName = name[0];
				}
				else if (newScore > score[1] && newScore < score[0])
				{
					newScore = score[1];
					newName = name[1];
				}
				else if (newScore > score[2] && newScore < score[1])
				{
					newScore = score[2];
					newName = name[2];
				}
				else if (newScore > score[3] && newScore < score[2])
				{
					newScore = score[3];
					newName = name[3];
				}
				else if (newScore < score[4])
				{
					cout << "Not good enough for the scoreboards.";
				}
				else if (newScore > score[4] && newScore < score[3]);
				{
					newScore = score[4];
					newName = name[4];
				}
				if (newName == "quit")
				{
					quit = 1;
					if (quit == 1)
					{
						cout << "Thanks! Have a good'n, pudd'n!";
						return 0;
					}
				}
				entries += 5;
			}

			cout << "\tHIGH SCORE TABLE" << endl << endl;
			cout << name[0] << " " << highscore << endl;
			cout << name[1] << " " << score[1] << endl;
			cout << name[2] << " " << score[2] << endl;
			cout << name[3] << " " << score[3] << endl;
			cout << name[4] << " " << score[4] << endl;
			entries = 0;
		} while (entries != 5);
	}
}