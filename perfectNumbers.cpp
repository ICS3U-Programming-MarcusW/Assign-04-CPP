// Copyright (c) 2022 Immaculata HS All rights reserved.
// Created by: Marcus Wehbi
// Date : Nov 11, 2022
// This program asks the user for a minimum and a maximum to create a range
// It then displays all of the perfect numbers that are within that range
// Then it asks the user for a second range
// It then displays all of the Armstrong numbers that are within that range

// Include the libraries
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

// Function to calculate the power of two numbers passed through from the
// isArmstrong function
// The number is raised to the number of digits in that number
int powerOf(int num, int exp) {
    // Set sum to 1
    int sum = 1;
    // Use a for loop to calculate the power
    for (int pIndex = 0; pIndex < exp; pIndex++) {
        sum = sum * num;
    }
    // Return the sum to the Armstrong function
    return sum;
}

// Function(calculator) to se if a number is perfect
// It will return a boolean expression to the if statement in the main function
bool isPerfect(int pNum) {
    // set the perfect number sum to 0
    int pSum = 0;
    // As long as index is less than num, execute the code inside loop
    for (int pIndex = 1; pIndex < pNum; pIndex++) {
        // If the remainder of the current number modulus p_index
        // (number that finds all proper divisors)
        // Is equal to zero, add it to the sum
        if (pNum % pIndex == 0) {
            pSum += pIndex;
        }
    }
    // Return the boolean expression back to the if statement in
    // The isPerfect function
    return pNum == pSum;
}

// Function(calculator) to se if a number is an Armstrong number
// It will return a boolean expression to the if statement in the main function
bool isArmstrong(int aNum) {
    // Set the sum and number of all proper divisors to 0
    int aSum = 0;
    int aNod = 0;
    // Set the Armstrong counter to the number passed through the function
    int aCounter = aNum;
    // While loop to find the quantity of digits in a number
    // While the counter is not 0
    while (aCounter != 0) {
        // Increment the number of divisors by 1
        aNod++;
        // Divide counter by 10 (get rid of endmost digit)
        aCounter = static_cast<int>(aCounter / 10);
    }
    // While loop to Calculate sum of all digits raised to number of base
    // digits
    // While the counter is not 0
    // Reset the counter to the num
    aCounter = aNum;
    while (aCounter != 0) {
        // Add the endmost digit raised to the power of
        // how many base digits there are, to the sum
        int aDigit = aCounter % 10;
        // Use the power function to calculate
        aSum += powerOf(aDigit, aNod);
        // Divide the counter by 10 to git rid of the endmost digit
        aCounter = static_cast<int>(aCounter / 10);
    }
    // Return the boolean expression back to the if statement in
    // The isArmstrong function
    return aNum == aSum;
}

int main() {
    // Initialize the range inputs as strings and integers
    std::string perMinStr, perMaxStr;
    int perMin, perMax;
    // Initialize float type of input in order ot check if they are decimals
    float perFMin, perFMax;

    // Explain what a perfect number is
    std::cout << "In Mathematics, a perfect number is a positive integer that";
    std::cout << " is equal to the sum of its proper divisors." << std::endl;

    // Get the start of the range for the perfect numbers identifier
    std::cout <<
    "Input the starting number for the perfect number identification: ";
    std::cin >> perMinStr;

    // Get the end of the range for the perfect numbers identifier
    std::cout << "Input the ending number for the perfect number";
    std::cout << " identification: ";
    std::cin >> perMaxStr;

    // Use try catch for any erroneous input
    try {
        // Convert the parameters (start/end of range) to integers
        perMin = stoi(perMinStr);
        perMax = stoi(perMaxStr);

        // Convert them to floats to check if the user inputted decimals
        // **Error check
        perFMin = stof(perMinStr);
        perFMax = stof(perMaxStr);

        // Check if either of the inputs are decimals
        if (perMin != perFMin || perMax != perFMax) {
            // If they are, tell the user they cannot input decimals
            // And end the program
            std::cout << "Please do not enter decimals." << std::endl;
            exit(1);
        }

        // Make sure the start isn't greater than the max
        if (perMin > perMax) {
            // If the start is greater than the end, tell the user it must be
            // the opposite
            std::cout << "The start of the range must be less than the end."
            << std::endl;
        } else if (perMin < 0 || perMax < 0) {
            // If either of the inputs are negative, tell they user
            // They cannot be
            std::cout << "Negative numbers are not accepted." << std::endl;
        } else {
            // Otherwise continue with the program
            std::cout << "The Perfect numbers in the range "
            << perMinStr << " to " << perMaxStr << " are :" << std::endl;
            // For when the counter is less than or equal to the range max
            for (int perCounter = perMin; perCounter < perMax; perCounter++) {
                // Get the boolean expression from the isPerfect function
                if (isPerfect(perCounter)) {
                    // Print all the numbers that are perfect
                    std::cout << perCounter << std::endl;
                }
            }
        }
    } catch (std::invalid_argument) {
        // Message for invalid input
        std::cout << "Strings are not accepted by the program." << std::endl;
    }

    // Explain what an Armstrong number is
    std::cout << "An Armstrong number is a narcissistic number that is equal ";
    std::cout << "to the sum of its own digits raised to the power of the";
    std::cout << " number of digits." << std::endl;

    // Convert the parameters (start/end of range) to integers
    std::string armMinStr, armMaxStr;
    int armMin, armMax;

    // Initialize float type of input in order ot check if they are decimals
    float armFMin, armFMax;

    // Get the start of the range for the Armstrong numbers identifier
    std::cout << "Input the starting number for the Armstrong number ";
    std::cout << "identification: ";
    std::cin >> armMinStr;

    // Get the end of the range for the Armstrong numbers identifier
    std::cout << "Input the ending number for the Armstrong number ";
    std::cout << "identification: ";
    std::cin >> armMaxStr;

    // Use try catch for any erroneous input
    try {
        // Convert the parameters (start/end of range) to integers
        armMin = stoi(armMinStr);
        armMax = stoi(armMaxStr);

        // Convert them to floats to check if the user inputted decimals
        // **Error check
        armFMin = stof(armMinStr);
        armFMax = stof(armMaxStr);

        // Check if either of the inputs are decimals
        if (armMin != armFMin || armMax != armFMax) {
            // If they are, tell the user they cannot input decimals
            // And end the program
            std::cout << "Please do not enter decimals." << std::endl;
            exit(1);
        }

        // Make sure the start isn't greater than the max
        if (armMin > armMax) {
            // If the start is greater than the end, tell the user it must be
            // the opposite
            std::cout << "The start of the range must be less than the end."
            << std::endl;
        } else if (armMin < 0 || armMax < 0) {
            // If either of the inputs are negative, tell they user
            // They cannot be
            std::cout << "Negative numbers are not accepted." << std::endl;
        } else {
            // Otherwise, continue with the program
            std::cout << "The Armstrong numbers in the range "
            << armMinStr << " to " << armMaxStr << " are :" << std::endl;
            // For when the counter is less than or equal to the range max
            for (int armCounter = armMin; armCounter < armMax; armCounter++) {
                // Get the boolean expression from the isArmstrong function
                if (isArmstrong(armCounter)) {
                    // Print all the numbers that are Armstrong numbers
                    std::cout << armCounter << std::endl;
                }
            }
        }
    } catch (std::invalid_argument) {
        // Message for invalid input
        std::cout << "Strings are not accepted by the program." << std::endl;
    }
}
