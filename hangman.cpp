#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	string letters = "abcdefghijklmnopqrstuvwxyz";

	// Get wordlist
	ifstream file("wordlist.txt");
	string line;
	vector<string> words;
	while (getline(file, line))
	{
		words.push_back(line);
	}
	file.close();

	// Get random word from wordlist
	srand((unsigned int)time(NULL));
	string ans = words[rand() % 100 + 1];

	// Shown initialization
	char shown[ans.size() + 1];
	for (int i = 0; i < ans.size(); i++)
	{
		shown[i] = '_';
	}

	// Main loop
	string in;
	int guesses = 7;
	vector<char> guessed;

	cout << "Guess a letter: \n";
	while (shown != ans && guesses > 0)
	{
		// Guess prompt
		cout << shown << "\n";
		cin >> in;
		
		// Check if guess is character
		char guess = tolower(in[0]);
		if (letters.find(guess) == string::npos)
		{
			cout << "Not a letter\n";
			continue;
		}
		
		// Check if already guessed
		if (count(guessed.begin(), guessed.end(), guess))
		{
			cout << "Already guessed\n";
			continue;
		}

		// Check if guess is in ans
		if (ans.find(guess) != string::npos)
		{
			// In
			for (int i = 0; i < ans.length(); i++)
			{
				if (ans[i] == guess)
				{
					shown[i] = guess;
				}
			}
		}
		else
		{
			guesses--;
			cout << "Not in word" << "\n" << guesses << " guesses left\n";
		}

		// Add to already guessed
		guessed.push_back(guess);
	}
	cout << "The word was: " << ans << "\n";
	return 0;
}
