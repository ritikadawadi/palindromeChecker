#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "myStack.h"

void takeInputAndConvert(std::vector<std::string> &passageLines)
{

    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            break; // Empty line indicates the end of the passage
        }
        // Remove spaces from the line
        std::string lineWithoutSpaces;
        for (int i = 0; i < line.length(); i++) {
            char c = line[i];
            if ((c != ' ') && (c != '!') && (c != '?') && (c != '.') && (c != ',') && (c != '*') && (c != '&') &&
                (c != '$')) {
                lineWithoutSpaces += tolower(c);
            }
        }

        passageLines.push_back(lineWithoutSpaces); // Store each line as a separate string without spaces
    }

}

bool checkPalindrome(std::vector<std::string> &passageLines)
{
    stackType<std::string> stack1;
    stack1.initializeStack();


    for (size_t i = 0; i < passageLines.size(); ++i) // size_t is used for unsigned integers
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
        } else {
            return false;
        }

        if (count == passageLines.size())
            return true;
    }
}

int main()
{
    std::vector<std::string> passageLines; // Use a vector to store lines

    while(true)
    {
    std::cout<<endl;
    std::cout<<"*-------------------------------------*" <<endl;
    std::cout<<"Hello, Welcome to the Passage Checker" <<endl;
    std::cout<<"*-------------------------------------*" <<endl;
    std::cout << "Enter your passage ---" <<endl;
    std::cout << "(press Enter twice to finish): " <<endl;
    std::cout<<"*-------------------------------------*" <<endl;
    takeInputAndConvert(passageLines);

    if (checkPalindrome(passageLines))
    {
        std::cout << "The passage is a palindrome!" << std::endl;
    }
    else
    {
        std::cout<<"The passage is not a palindrome!" <<std::endl;
    }

        char enterAgain;
        std::cout <<"\nDo you want to check another passage?" <<std::endl;
        std::cout<<"Enter ('Y' OR 'y') if you wish to continue)" <<std::endl;
        std::cin >> enterAgain;
        std::cin.ignore();
        if (toupper(enterAgain) !='Y')
        {
            std::cout<<"\nThank you for using our program!" <<endl;
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

