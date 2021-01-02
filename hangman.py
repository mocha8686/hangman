#!/usr/bin/env python3
import random
import string

# String to list
def stol(str):
	result = []
	for c in str:
		result.append(c)
	return result

# Print list as string
def printl(arr):
	for c in arr:
		print(c, end='')
	print()

with open('wordlist.txt', 'r') as wordlist:
	words = wordlist.readlines()

for word in words:
	words[words.index(word)] = word.replace('\n', '')

word = words[random.randint(0, len(words) - 1)]
shown = '_' * len(word)
guesses = 7
enum = list(enumerate(word))
guessed = []

word = stol(word)
shown = stol(shown)

print('Guess a letter:')
while (guesses > 0 and shown != word):
	printl(shown)
	try:
		guess = input().lower()
	except KeyboardInterrupt:
		exit()

	if (guess not in string.ascii_lowercase or len(guess) != 1):
		print('Not a letter')
		continue

	if (guess in guessed):
		print('Already guessed')
		continue

	guessed.append(guess)

	if (guess in word):
		for tup in enum:
			if (tup[1] == guess):
				shown[tup[0]] = word[tup[0]]
	else:
		print('Not in word')
		guesses -= 1
		print(f'{guesses} guesses left')

print("The word was: ")
printl(word)
