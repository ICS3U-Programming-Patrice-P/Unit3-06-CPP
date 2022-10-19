// Copyright (c) 2022 Patrice Pat-Odita All rights reserved.
//
// Created by: Patrice Pat-Odita
// Created on: Oct 18,  2022
// This program asks the user to guess a
// number and if they get it wrong they are told so.

#include <iostream>
#include <random>

int main() {
// Generates random number
    int someRandomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());

// mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);

// [0,100]
    someRandomNumber = idist(rgen);

// std::cout << someRandomNumber << std::endl;
// local available
    std::string numberGuessedAsString;
    int numberGuessedAsInt;

    // gets input from user
    std::cout << "Guess my favorite number from 0-9: ";
    std::cin >> numberGuessedAsString;
    std::cout << "" << std::endl;

    // try catch
    try {
// convert the user's guess to an int
    numberGuessedAsInt = std::stoi(numberGuessedAsString);
    std::cout << "\033[1;35;38mYou entered an integer correctly\n";
    std::cout << "" << std::endl;

// check if the guess is correct
    if (numberGuessedAsInt == someRandomNumber) {
// Prints if they got it right
    std::cout << "\033[1;3;39mYOU GOT IT RIGHT!";
    } else {
    std::cout << "\033[1;35;39mYou got it wrong ";
    std::cout << "\033[1;35;34mMy favorite number is "
    << someRandomNumber << "\n";
}

// Tells the user that they didn't input an integer
    }
    catch (std::invalid_argument) {
    // The user did not enter an integer
    std::cout << numberGuessedAsString
    << " \033[1;35;38mis " "not an integer.\n";
    std::cout << "" << std::endl;
    std::cout << "\033[1;35;38mThanks for Playing.";
    }
}
