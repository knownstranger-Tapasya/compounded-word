#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

struct TrieNode
{
    bool isEOF;
    std::unordered_map<char, TrieNode*> child;

    TrieNode() : isEOF(false) {}
};

void insert(TrieNode* root, const std::string& word)
{
    TrieNode* current = root;
    for (char c : word) {
        if (!current->child.count(c))
        {
            current->child[c] = new TrieNode();
        }
        current = current->child[c];
    }
    current->isEOF = true;
}

bool compound(TrieNode* root, const std::string& word, int start, int length, int count)
{
    TrieNode* current = root;
    for (int i = start; i < length; ++i)
    {
        char c = word[i];
        if (!current->child.count(c))
        {
            return false;
        }
        current = current->child[c];
        if (current->isEOF)
        {
            if (i == length - 1)
            {
                return count >= 2;
            }
            if (compound(root, word, i + 1, length, count + 1))
            {
                return true;
            }
        }
    }
    return false;
}

void longest(std::ifstream& inputFile, std::string& first, std::string& second)
{
    TrieNode* root = new TrieNode();
    first = "";
    second = "";

    std::vector<std::string> wordList;
    std::set<std::string> compoundWords;

    std::string word;
    while (inputFile >> word)
    {
        insert(root, word);
        wordList.push_back(word);
    }

    std::sort(wordList.begin(), wordList.end(), [](const std::string& a, const std::string& b)
    {
        return a.size() > b.size();
    });

    for (const std::string& word : wordList)
    {
        if (compound(root, word, 0, word.length(), 0))
        {
            compoundWords.insert(word);
        }
    }

    for (const std::string& word : wordList)
    {
        if (compoundWords.find(word) != compoundWords.end())
        {
            if (first.empty() || word.size() > first.size())
            {
                second = first;
                first = word;
            }
            else if (word.size() > second.size())
            {
                second = word;
            }
        }
    }
}

int main()
{
    std::ifstream file("D:/Input_02.txt");
    if (!file)
    {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    std::string first, second;
    auto startTime = std::chrono::high_resolution_clock::now();
    longest(file, first, second);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto processingTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    if (!first.empty())
    {
        std::cout << "Answer:" << std::endl;
        std::cout << "1. Longest Compound Word: " << first << std::endl;
    } else
    {
        std::cout << "No compounded words found in the list." << std::endl;
    }

    if (!second.empty())
    {
        std::cout << "2. Second Longest Compound Word: " << second << std::endl;
    }
    else
    {
        std::cout << "No second longest compounded word found." << std::endl;
    }

    std::cout << "Time taken to process the input file: " << processingTime.count() / 1000.0 << " seconds" << std::endl;

    return 0;
}
