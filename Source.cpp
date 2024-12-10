/*
* Joseph Dumke
 * CS 210
 * Project 3
 * 12-12-2024
 * This code will be a grocery management that checks the frequency of each item.
 */

#include <iostream>
#include "groceryItem.h"

using namespace std;

int main() {
    // Load inventory from input file
    const std::string inputFile = "CS210_Project_Three_Input_File.txt";
    const std::string backupFile = "frequency.dat";

    try {
        groceryItem::loadInventory(inputFile);
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    int choice;
    // loop will loop through each question and ask for input for each one.
    do {
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Display all item frequencies\n";
        cout << "3. Display histogram\n";
        cout << "4. Exit\n";
        cout << "5. Delete an item from inventory\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string itemName;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << itemName << " frequency: " << groceryItem::getItemFrequency(itemName) << endl;
            break;
        }
        case 2:
            groceryItem::displayAllFrequencies();
            break;
        case 3:
            groceryItem::printHistogram();
            break;
        case 4:
            try {
                groceryItem::saveBackup(backupFile);
                cout << "Backup saved to " << backupFile << ". Exiting...\n";
            }
            catch (const std::exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 5: {
            string itemName;
            cout << "Enter item name to delete: ";
            cin >> itemName;
            groceryItem::deleteItem(itemName);
            break;
        }
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
