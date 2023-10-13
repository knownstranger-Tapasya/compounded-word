# compounded-word
Overview:
This is a C++ program that finds the longest and second-longest compound words from a list of words. It uses a Trie data structure to efficiently determine if a word can be formed by concatenating other words from the list.

Prerequisites:
C++ compiler (e.g., g++)
Input text file containing a list of words (e.g., "Input_01.txt")

Getting Started
1. Clone this repository to your local machine:git clone https://github.com/knownstranger-Tapasya/compounded-word.git
2. Compile the program using a C++ compiler:g++ -o compounded-word main.cpp

   
Usage:
Run the compiled program with the input file as an argument:./compounded-word D:/Input_01.txt or ./compounded-word D:/Input_02.txt

The program will analyze the list of words in the input file and output the longest and second-longest compound words, along with the processing time.
Algorithm:

The program uses a Trie data structure to efficiently check if a word can be formed by concatenating other words. It follows these steps:

1.Read the list of words from the input file and insert them into a Trie.

2.Sort the list of words in descending order of length.

3.For each word in the sorted list, check if it is a compound word by traversing the Trie.

4.Store compound words in a set.

5.Find the longest and second-longest compound words from the set.

Contributing:
Contributions are welcome. If you'd like to improve this program, please follow these steps:

1.Fork the repository.

2.Create a new branch for your feature or bug fix.

3.Make your changes and commit them.

4.Create a pull request.

License:
This project is licensed under the MIT License - see the LICENSE file for details.
