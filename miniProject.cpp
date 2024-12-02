#include <iostream>
#include <string>
#include <cctype> 
#include <limits>
#include <limits>
//TODO: Make an option for the user if they want to count their vowel/s or consonant/s in their name

int countCharacters(bool isVowel, std::string username, const char vowels[5]) {
    int total = username.size();

    for (int i = 0; i < total; i++) {
        for (int j = 0; j < 5; j++) {
            if (tolower(username[i]) == vowels[j]) { 
                total -= 1;
                break;
            }
        }
    }

    if (isVowel) {
        total = username.size() - total;
    }

    return total;
}

std::string toLowerCase(const std::string& input) {
    std::string result;
    for (char ch : input) {
        result += tolower(ch);
    }
    return result;
}


constexpr char VOWELS[] = {'a', 'e', 'i', 'o', 'u'}; 

int main() {
    int userInput;
    std::string username;

    do {
        std::cout << "1. Display the total vowel/s from my name" << std::endl;
        std::cout << "2. Display the total consonant/s from my name" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter a chosen number: ";
        std::cin >> userInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n" << std::endl;
            continue;
        }

        if (userInput < 1 || userInput > 3) {
            std::cout << "Invalid choice. Please try again.\n" << std::endl;
            continue;
        }

        if (userInput == 3) {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        }

        std::cout << "Enter your name: ";
        std::cin >> username;

        std::string lowercaseName = toLowerCase(username);

        int vowelResult = countCharacters(true, lowercaseName, VOWELS);
        int consonantResult = countCharacters(false, lowercaseName, VOWELS);

        if (userInput == 1) {
            std::cout << "Total vowels in your name: " << vowelResult << "\n" << std::endl;
        } else {
            std::cout << "Total consonants in your name: " << consonantResult << "\n" << std::endl;
        }
    } while (true);

    return 0;
}


