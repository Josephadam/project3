/*
* Joseph Dumke
 * CS 210
 * Project 3
 */

#include "groceryItem.h"

 // Initialize static member
std::map<std::string, groceryItem> groceryItem::inventory_;

// Default constructor
groceryItem::groceryItem() : name_(""), quantity_(0) {}

// Parameterized constructor
groceryItem::groceryItem(const std::string& name, int quantity) : name_(name), quantity_(quantity) {}

// Accessors
std::string groceryItem::getName() const {
    return name_;
}

int groceryItem::getQuantity() const {
    return quantity_;
}

// Mutators
void groceryItem::addItem() {
    quantity_++;
}

void groceryItem::removeItem() {
    if (quantity_ > 0) quantity_--;
}

// Static method to load inventory from file
void groceryItem::loadInventory(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file) {
        throw std::runtime_error("Unable to open input file");
    }

    std::string itemName;
    while (file >> itemName) {
        if (inventory_.count(itemName) > 0) {
            inventory_[itemName].addItem();
        }
        else {
            inventory_[itemName] = groceryItem(itemName);
        }
    }

    file.close();
}

// Static method to get frequency of a specific item
int groceryItem::getItemFrequency(const std::string& itemName) {
    auto it = inventory_.find(itemName);
    if (it != inventory_.end()) {
        return it->second.getQuantity();
    }
    return 0;
}

// Static method to display all frequencies
void groceryItem::displayAllFrequencies() {
    for (const auto& [name, item] : inventory_) {
        std::cout << std::left << std::setw(15) << name << item.getQuantity() << std::endl;
    }
}

// Static method to print histogram
void groceryItem::printHistogram() {
    for (const auto& [name, item] : inventory_) {
        std::cout << std::left << std::setw(15) << name << std::string(item.getQuantity(), '*') << std::endl;
    }
}

// Static method to save inventory to a backup file
void groceryItem::saveBackup(const std::string& outputFile) {
    std::ofstream file(outputFile);
    if (!file) {
        throw std::runtime_error("Unable to open backup file");
    }

    for (const auto& [name, item] : inventory_) {
        file << name << " " << item.getQuantity() << std::endl;
    }

    file.close();
}

// Add this implementation to groceryItem.cpp
void groceryItem::deleteItem(const std::string& itemName) {
    auto it = inventory_.find(itemName);
    if (it != inventory_.end()) {
        inventory_.erase(it);
        std::cout << "Item \"" << itemName << "\" has been removed from the inventory." << std::endl;
    }
    else {
        std::cout << "Item \"" << itemName << "\" not found in the inventory." << std::endl;
    }
}

