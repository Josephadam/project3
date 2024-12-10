/*
* Joseph Dumke
 * CS 210
 * Project 3
 */

#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip> // For formatted output

class groceryItem {
public:
    // Constructors
    groceryItem(); // Default constructor
    groceryItem(const std::string& name, int quantity = 1);

    // Accessors
    std::string getName() const;
    int getQuantity() const;

    // Mutators
    void addItem();
    void removeItem();

    // Static methods for inventory management
    static void loadInventory(const std::string& inputFile);
    static int getItemFrequency(const std::string& itemName);
    static void displayAllFrequencies();
    static void printHistogram();
    static void saveBackup(const std::string& outputFile);
    static void deleteItem(const std::string& itemName);

private:
    std::string name_;
    int quantity_;

    // Static inventory map (shared by all instances)
    static std::map<std::string, groceryItem> inventory_;
};

#endif // GROCERYITEM_H
