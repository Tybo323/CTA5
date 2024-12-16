/*
 * appendtxt.cpp
 *
 *  Created on: Dec 15, 2024
 *      Author: admin
 */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cerrno>
#include <cstring>

// Function to reverse the contents of the file
void reverseFileContents(const std::string &inputFile, const std::string &outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);
    
    if (inFile.is_open() && outFile.is_open()) {
        std::string content((std::istreambuf_iterator<char>(inFile)), (std::istreambuf_iterator<char>()));
        std::reverse(content.begin(), content.end());
        outFile << content;
    } else {
        std::cerr << "Error opening file for reading or writing: " << std::strerror(errno) << std::endl;
    }
    
    inFile.close();
    outFile.close();
}

int main() {
    std::string userInput;
    std::string inputFilePath = "C:\\Users\\admin\\Desktop\\CSC450_CT5_mod5.txt";
    std::string outputFilePath = "C:\\Users\\admin\\Desktop\\CSC450-mod5-reverse.txt";

    // Step 1: Obtain input from the user
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    // Step 2: Append input to the provided text file
    std::ofstream outFile(inputFilePath, std::ios::app);
    if (outFile.is_open()) {
        outFile << userInput << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error opening file for appending: " << std::strerror(errno) << std::endl;
        return 1;
    }

    // Step 3-5: Reverse the contents of the file and store in the reverse file
    reverseFileContents(inputFilePath, outputFilePath);

    std::cout << "Text appended and contents reversed successfully." << std::endl;

    return 0;
}