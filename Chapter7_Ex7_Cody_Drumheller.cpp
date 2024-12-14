/*
Title: Chapter 7 Exercise 7 Number Analysis
File Name: Chapter7_Ex7_Cody_Drumheller.cpp
Programmer: Cody Drumheller
Date: 20241213
Requirements:
Write a program that asks the user for a file name. Assume the file contains a series of numbers, each written on a separate line. 
The program should read the contents of the file into an array then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file. Make sure the file exists and try again." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    if (numbers.empty()) {
        cout << "The file is empty." << endl;
        return 0;
    }


    int lowest = numeric_limits<int>::max();
    int highest = numeric_limits<int>::min();
    int total = 0;

    for (int n : numbers) {
        if (n < lowest) lowest = n;
        if (n > highest) highest = n;
        total += n;
    }

    double average = static_cast<double>(total) / numbers.size();


    cout << "Lowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Total of numbers: " << total << endl;
    cout << "Average of numbers: " << average << endl;

    return 0;
}






