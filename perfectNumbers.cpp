// Copyright (c) 2022 Immaculata HS All rights reserved.
// Created by: Marcus Wehbi
// Date : Nov 11, 2022
// This program asks the user for a minimum and a maximum as a range
// It then displays all of the perfect numbers that are within that range

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int powerOf(int num, int exp) {
    int sum = 1;
    for (int pIndex = 0; pIndex < exp; pIndex++) {
        sum = sum * num;
    }
    return sum;
}

bool isPerfect(int pNum) {
    int pSum = 0;
    for (int pIndex = 1; pIndex < pNum; pIndex++) {
        if (pNum % pIndex == 0) {
            pSum += pIndex;
        }
    }
    return pNum == pSum;
}

bool isArmstrong(int aNum) {
    int aSum = 0;
    int aNod = 0;
    int aCounter = aNum;
    while (aCounter != 0) {
        aNod++;
        aCounter = static_cast<int>(aCounter / 10);
    }
    aCounter = aNum;
    while (aCounter != 0) {
        int aDigit = aCounter % 10;
        aSum += powerOf(aDigit, aNod);
        aCounter = static_cast<int>(aCounter / 10);
    }
    return aNum == aSum;
}

int main() {
    std::string perMinStr, perMaxStr;
    int perMin, perMax;
    float perFMin, perFMax;

    std::cout << "Input the perfect number identifications starting range: ";
    std::cin >> perMinStr;

    std::cout << "Input the starting range identification : ";
    std::cin >> perMaxStr;



    try {
        // Convert the parameters to integers
        perMin = stoi(perMinStr);
        perMax = stoi(perMaxStr);

        perFMin = stof(perMinStr);
        perFMax = stof(perMaxStr);

        if (perMin != perFMin || perMax != perFMax) {
            std::cout << "Please do not enter decimals." << std::endl;
            exit(1);
        }

        // Make sure the start isn't greater than the max
        if (perMin > perMax) {
            std::cout << "The start of the range must be less than the end."
            << std::endl;
        } else if (perMin < 0 || perMax < 0) {
            std::cout << "Negative numbers are not accepted." << std::endl;
        } else {
            std::cout << "The Perfect numbers in the range "
            << perMinStr << " to " << perMaxStr << " are :" << std::endl;
            // For when the counter is less than or equal to the range max
            for (int perCounter = perMin; perCounter < perMax; perCounter++) {
                // Get the boolean expression from the isPerfect function
                if (isPerfect(perCounter)) {
                    // Print if the numbers are perfect
                    std::cout << perCounter << std::endl;
                }
            }
        }
    } catch (std::invalid_argument) {
        std::cout << "Strings are not accepted by the program." << std::endl;
    }

    std::string armMinStr, armMaxStr;
    int armMin, armMax;
    float armFMin, armFMax;

    std::cout << "Input the starting range or number : ";
    std::cin >> armMinStr;

    std::cout << "Input the starting range or number : ";
    std::cin >> armMaxStr;

    try {
        // Convert the parameters to integers
        armMin = stoi(armMinStr);
        armMax = stoi(armMaxStr);

        armFMin = stof(armMinStr);
        armFMax = stof(armMaxStr);

        if (armMin != armFMin || armMax != armFMax) {
            std::cout << "Please do not enter decimals." << std::endl;
            exit(1);
        }

        // Make sure the start isn't greater than the max
        if (armMin > armMax) {
            std::cout << "The start of the range must be less than the end."
            << std::endl;
        } else if (armMin < 0 || armMax < 0) {
            std::cout << "Negative numbers are not accepted." << std::endl;
        } else {
            std::cout << "The Armstrong numbers in the range "
            << armMinStr << " to " << armMaxStr << " are :" << std::endl;
            // For when the counter is less than or equal to the range max
            for (int armCounter = armMin; armCounter < armMax; armCounter++) {
                // Get the boolean expression from the isPerfect function
                if (isArmstrong(armCounter)) {
                    // Print if the numbers are perfect
                    std::cout << armCounter << std::endl;
                }
            }
        }
    } catch (std::invalid_argument) {
        std::cout << "Strings are not accepted by the program." << std::endl;
    }
}
