#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "myStack.h"

void takeInputAndConvertLines(std::vector<std::string>& passageLines, std::vector<std::string>& passageWords)
{

    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        int currentAscii, pastAscii;
        //add all the words to passageWords
        std::string words;
        for (int i = 0; i < line.length(); i++)
        {
            char c = line[i];
            if (int(c) >= 65 && int(c) <= 90 || int(c) >= 97 && int(c) <= 122)
            {
                words += tolower(c);
            }
            else if (!(int(c) >= 65 && int(c) <= 90 || int(c) >= 97 && int(c) <= 122) && (int(line[i - 1]) >= 65 && int(line[i - 1]) <= 90 || int(line[i - 1]) >= 97 && int(line[i - 1]) <= 122))
            {
                passageWords.push_back(words);
            }
        }
        passageWords.pop_back();
        // Remove spaces from the line
        std::string lineWithoutSpaces;
        for (int i = 0; i < line.length(); i++) {
            char c = line[i];
            //check if alphabet and number and then store in line without space othereise dont store
            if (int(c) >= 65 && int(c) <= 90 || int(c) >= 97 && int(c) <= 122) {
                lineWithoutSpaces += tolower(c);
            }
        }
        if (lineWithoutSpaces == "end") {
            break; // Empty line indicates the end of the passage
        }
        passageLines.push_back(lineWithoutSpaces); // Store each line as a separate string without spaces
    }

}


bool checkPalindrome(std::vector<std::string>& passageLines)
{
    stackType<std::string> stack1;
    stack1.initializeStack();


    for (int i = 0; i < passageLines.size(); i++
            ) // size_t is used for unsigned integers
    {
        stack1.push(passageLines[i]);
    }
    std::cout << endl;
    int i = 0;
    int count = 0;
    while (!stack1.isEmptyStack()) {
        if (passageLines[i] == stack1.top()) {
            count++;
            i++;
            stack1.pop();
        }
        else {
            return false;
        }

        if (count == passageLines.size())
            return true;
    }
}

int main()
{
    std::vector<std::string> passageLines; // Use a vector to store lines
    std::vector<std::string> passageWords; // A vector to store the words in the passage

    while (true)
    {
        std::cout << endl;
        std::cout << "*-------------------------------------*" << endl;
        std::cout << "Hello, Welcome to the Passage Checker" << endl;
        std::cout << "*-------------------------------------*" << endl;
        std::cout << "Enter your passage ---" << endl;
        std::cout << "(press Enter \"end\" to finish): " << endl;
        std::cout << "*-------------------------------------*" << endl;
        takeInputAndConvertLines(passageLines, passageWords);
        if (checkPalindrome(passageLines))
        {
            std::cout << "The passage is a palindrome!" << std::endl;
            std::cout << "\nThe number of Palindromic Lines are: " << passageLines.size() / 2;
            std::cout << "\nThe number of Palindromic Words are: " << passageWords.size() / 2;
        }
        else
        {
            std::cout << "The passage is not a palindrome!" << std::endl;
        }

        char enterAgain;
        std::cout << "\nDo you want to check another passage?" << std::endl;
        std::cout << "Enter ('Y' OR 'y') if you wish to continue)" << std::endl;
        std::cin >> enterAgain;
        std::cin.ignore();
        if (toupper(enterAgain) != 'Y')
        {
            std::cout << "\nThank you for using our program!" << endl;
            break;
        }
        else
        {
            std::cout << "Enter the passage you want to check: " << std::endl;

        }
        passageLines.clear();

    }
    return 0;
}