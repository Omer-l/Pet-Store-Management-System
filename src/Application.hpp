#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_
#include <iostream>
#include <ostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <memory>
#include <iomanip>
#include "Item.h"

std::vector<Item*> items;
Sales sales;

void printItems()
{
    for (std::string::size_type i = 0; i < items.size(); i++)
    {
        std::cout << "\n-\nID: " << i + 1;
        items[i]->toString();
        std::cout << "\n";
    }
}

bool isInputDigit(std::string qty_available)
{
    if (qty_available.empty())
        return false;

    for (char &c : qty_available)
    {
        if (std::isdigit(c) == 0 || qty_available.empty())
        {
            return false;
        }
    }
    return true;
}

bool isPriceValid(std::string price)
{

    if (price[price.length() - 3] != '.')
    {
        return false;
    }

    for (std::string::size_type i = 0; i < price.length(); i++)
    {
        char c = price[i];
        if (c == '.' && i == price.length() - 3)
            continue;

        if (std::isdigit(c) == 0 || price.empty())
        {
            std::cout << "\nEnsure price is correct";
            return false;
        }
    }
    return true;
}
//splits string by specific character
std::vector<std::string> splitBySpecialChar(std::string str, std::vector<std::string> &result, std::string specialChar)
{
    //handles last part of string
    if (str.find(specialChar) == std::string::npos)
    {
        result.push_back(str.substr(0, str.find(specialChar)));
        return result;
    }
    //pushes up to next semi colon
    result.push_back(str.substr(0, str.find(specialChar)));
    str = str.substr(str.find(specialChar) + 1);         //new string, after semi colon
    return splitBySpecialChar(str, result, specialChar); //recursively function, separates words/phrases by specialChar
}

void restock()
{
    printItems();

    std::string qty;
    std::string itemID;
    std::string::size_type index = 0;

    std::cout << "\nPlease enter item ID: ";
    std::cin >> itemID;

    std::cin.ignore(256, '\n');

    //loops until index is correct
    while (!isInputDigit(itemID))
    {
        std::cout << "\nQuantity entered must be an integer!\n";
        std::cout << "\nPlease enter item ID: ";
        std::getline(std::cin, itemID);
    }
    index = stoi(itemID) - 1; //index for qty adding

    if (index < items.size())
    {
        std::cout << "\nEnter quantity to add: ";
        std::cin >> qty;
        std::cin.ignore(256, '\n');
        //loops until input is a digit
        while (!isInputDigit(qty))
        {
            std::cout << "\nQuantity entered must be an integer!\n";
            std::cout << "\nEnter quantity to add: ";
            std::getline(std::cin, qty);
        }
        items[index]->addQty(stoi(qty));
    }
    else
    {
        std::cout << "That item ID does not exist.";
    }
}

void updateQty()
{
    printItems();

    std::string qty;
    std::string itemID;
    std::string::size_type index = 0;

    std::cout << "\nPlease enter item ID: ";
    std::cin >> itemID;

    std::cin.ignore(256, '\n');

    //loops until index is correct
    while (!isInputDigit(itemID))
    {
        std::cout << "\nQuantity entered must be an integer!\n";
        std::cout << "\nPlease enter item ID: ";
        std::getline(std::cin, itemID);
    }
    index = stoi(itemID) - 1; //index for qty updating

    if (index < items.size())
    {
        std::cout << "\nEnter quantity to update to: ";
        std::cin >> qty;
        std::cin.ignore(256, '\n');
        //loops until input is a digit
        while (!isInputDigit(qty))
        {
            std::cout << "\nQuantity entered must be an integer!\n";
            std::cout << "\nEnter quantity to update: ";
            std::getline(std::cin, qty);
        }
        items[index]->setQty(stoi(qty));
    }
    else
    {
        std::cout << "That item ID does not exist.";
    }
}

void addItem()
{
    //item object's attributes
    std::string name;
    std::string qty_available;
    std::string type;
    std::string price;
    std::cin.ignore(256, '\n');

    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter quantity: ";
    std::cin >> qty_available;
    std::cin.ignore(256, '\n');
    //loops until input is a digit
    while (!isInputDigit(qty_available))
    {
        std::cout << "\nQuantity entered must be an integer!\n";
        std::cout << "\nEnter quantity: ";
        std::getline(std::cin, qty_available);
    }

    std::cout << "Enter price: ";
    std::cin >> price;
    std::cin.ignore(256, '\n');
    //loops until input is a digit
    while (!isPriceValid(price))
    {
        std::cout << "\nPlease ensure that the price has 2 decimal places (example: 23.00)";
        std::cout << "\nEnter price: ";
        std::getline(std::cin, price);
    }

    std::cout << "\n1 => Pet Food\n2 => Accessory\n3 => Toy\n4 => Book\n5 => Other\nEnter Category of Item: ";
    std::getline(std::cin, type);

    int typeToInt = atoi(type.c_str());

    switch (typeToInt)
    {
    case 1:
    {

        std::string pet;
        std::cout << "\n1 => Dogs\n2 => Cats\n3 => Fish\n4 => Hamsters\nEnter which pet animal this is for: ";

        std::cin >> pet;
        int petChoice = atoi(pet.c_str());

        switch (petChoice)
        {
        case 1:
        {
            pet = "Dog";
            break;
        }
        case 2:
        {
            pet = "Cat";
            break;
        }
        case 3:
        {
            pet = "Fish";
            break;
        }
        case 4:
        {
            pet = "Hamster";
            break;
        }
        default:
        {
            std::cerr << "\n***\nPlease Enter One of The Options ( 1 - 4 )\n***\n";
            std::cout << "\nPress Enter to continue...\n";
            std::cin.ignore(256, '\n');
            addItem();
        }
        }

        items.emplace_back(new Pet_Food(name, qty_available, price, pet));
        break;
    }
    case 2:
    {
        std::string accessoryMaterial;
        std::cout << "Enter material of accessory: ";
        std::cin >> accessoryMaterial;
        items.emplace_back(new Accessory(name, qty_available, price, accessoryMaterial));
        break;
    }
    case 3:
    {
        std::string toyForWho;
        std::cout << "Toy is for: ";
        std::cin >> toyForWho;
        items.emplace_back(new Toy(name, qty_available, price, toyForWho));
        break;
    }
    case 4:
    {
        std::string description;
        std::cout << "Enter description of book: ";
        std::cin >> description;

        std::cin.ignore(256, '\n');
        std::string author;
        std::cout << "Enter author of book: ";
        std::cin >> author;

        std::string fictionOrNonFiction;
        std::cout << "\n1 => Fiction\n2 => Non_Fiction\n3 => Other\nEnter Category of Book: ";

        std::cin.ignore(256, '\n');
        std::cin >> fictionOrNonFiction;
        int fictionOrNonFictionToInt = atoi(fictionOrNonFiction.c_str());

        switch (fictionOrNonFictionToInt)
        {
        case 1:
        {
            Fiction newBook(name, qty_available, price, author, description);
            items.emplace_back(new Fiction(name, qty_available, price, author, description));
            break;
        }
        case 2:
        {
            Non_Fiction newBook(name, qty_available, price, author, description);
            items.emplace_back(new Non_Fiction(name, qty_available, price, author, description));
            break;
        }
        case 3:
        {
            items.emplace_back(new Book(name, qty_available, price, author, description));
            break;
        }
        default:
        {
            std::cerr << "\n***\nPlease Enter One of The Options ( 1 - 3 )\n***\n";
            std::cout << "\nPress Enter to continue...\n";
            std::cin.ignore(256, '\n');
            addItem();
        }
        }
        break;
    }
    case 5:
    {
        items.emplace_back(new Item(name, qty_available, price));
        break;
    }
    default:
    {
        std::cerr << "\n***\nPlease Enter One of The Options ( 1 - 5 )\n***\n";
        std::cout << "\nPress Enter to continue...\n";
        std::cin.ignore(256, '\n');
        addItem();
    }
    }
}

//needs file name as parameter
void saveData(char *filename)
{
    std::ofstream fileToSaveTo;    //file to write on

    fileToSaveTo.open(filename); // opens/creates the file
    if (!fileToSaveTo)
    { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    for (std::string::size_type i = 0; i < items.size(); i++)
        fileToSaveTo << items[i]->stringForFile() << "\n";
    fileToSaveTo.close();
}

void sellItems()
{
    bool stillShopping = true;
    std::string itemID;
    std::string qtyToSell;

    std::cin.ignore(256, '\n');

    while (stillShopping)
    {
        printItems();
        std::cout << "\n****************\nITEMS PURCHASED:\n----------------" << sales.purchaseHistory() << "\n****************";
        std::cout << "\nType:"
                  << "\nback -> to view main menu again."
                  << ".\nPlease enter item ID: ";
        std::cin >> itemID;

        if (itemID == "back")
        {
            break;
        }

        std::cin.ignore(256, '\n');
        //loops until input is a digit
        while (!isInputDigit(itemID))
        {
            std::cout << "\nInput must be an integer!\n";
            std::cout << "\nEnter item ID: ";
            std::getline(std::cin, itemID);

            if (itemID == "back")
            {
                break;
            }
        }
        if (itemID == "back")
        {
            break;
        }
        std::string::size_type index = stoi(itemID) - 1;

        if (index < items.size())
        {
            std::cout << "\nType:\nback -> to view main menu again.\nPlease enter quantity to sell: ";
            std::cin >> qtyToSell;

            if (qtyToSell == "back")
                break;

            std::cin.ignore(256, '\n');
            //loops until input is a digit
            while (!isInputDigit(qtyToSell))
            {
                std::cout << "\nInput must be an integer!\n";
                std::cout << "\nEnter quantity to sell: ";
                std::getline(std::cin, qtyToSell);
            }

            if (items[index]->getQty() - stoi(qtyToSell) < 0)
            {
                std::cout << "**************\nThe quantity you entered is more than what is left!\n**************";
                std::cout << "\nPress Enter to continue...\n";
                std::cin.ignore(256, '\n');
                continue;
            }
            sales.addItem(*(items.at(index)), stoi(qtyToSell));
            items[index]->setQty(items[index]->getQty() - stoi(qtyToSell));
        }
        else
        {
            std::cout << "That item ID does not exist.";
            std::cout << "\nPress Enter to continue...\n";
            std::cin.ignore(256, '\n');
        }
    }
}

void loadData(char *filename)
{
    items.clear(); //for new data load items
    //************************ LOAD DATA **************************
    std::ifstream file(filename);
    std::string newLine;

    if (file.is_open())
    {
        while (std::getline(file, newLine))
        {
            std::vector<std::string> results;
            splitBySpecialChar(newLine, results, ";");

            if (results.at(1).find(",") != std::string::npos)
            {
                std::vector<std::string> details;
                splitBySpecialChar(results.at(1), details, ",");

                if (details.at(0) == "Pet_Food")
                {

                    items.emplace_back(new Pet_Food(results.at(0), results.at(3), results.at(2), details.at(1)));
                }
                else if (details.at(0) == "Accessory")
                {
                    items.emplace_back(new Accessory(results.at(0), results.at(3), results.at(2), details.at(1)));
                }
                else if (details.at(0) == "Book")
                {
                    if (details.at(1) == "Fiction")
                    {
                        items.emplace_back(new Fiction(results.at(0), results.at(3), results.at(2), details.at(2), details.at(3)));
                    }
                    else if (details.at(1) == "Non_Fiction")
                    {
                        items.emplace_back(new Non_Fiction(results.at(0), results.at(3), results.at(2), details.at(2), details.at(3)));
                    }
                }
                else if (details.at(0) == "Toy")
                {
                    items.emplace_back(new Toy(results.at(0), results.at(3), results.at(2), details.at(1)));
                }
            }
        }
        file.close();
    }
}

//******************* END OF LOAD DATA **************************

void prompt()
{
    std::cout << "\nPress Enter to continue...\n";
    std::cin.ignore(256, '\n');
    printItems();
    std::string userInput;

    std::cout
        << "\n-------------\n"
        << "THE PET SHOP"
        << "\n-------------";

    std::cout << "\nEnter one of the following options:"
              << "\n1 to Sell items"
              << "\n2 to Restock items"
              << "\n3 to Add new item"
              << "\n4 to Update stock quantity"
              << "\n5 to View all products and stock levels"
              << "\n6 to Load"
              << "\n7 to Save"
              << "\n8 to View sales report."
              << "\n9 to Exit"
              << "\n>_ ";
    std::cin >> userInput;

    //turn user input into int
    int userInputToInt = atoi(userInput.c_str());
    switch (userInputToInt)
    {
    case 1:
    {
        sellItems();
        prompt();
        break;
    }
    case 2:
    {
        restock();
        prompt();
        break;
    }
    case 3:
    {
        addItem();
        prompt();
        break;
    }
    case 4:
    {
        updateQty();
        prompt();
        break;
    }
    case 5:
    {
        printItems();
        prompt();
        break;
    }
    case 6:
    {
        std::cin.ignore(256, '\n');
        char filename[100];
        std::cout << "Enter file name to load: ";
        std::cin >> filename;
        loadData(filename);
        prompt();
        break;
    }
    case 7:
    {
        std::cin.ignore(256, '\n');
        char filename[100];
        std::cout << "Enter file name to save as: ";
        std::cin >> filename;
        saveData(filename);
        prompt();
        break;
    }
    case 8:
    {
        std::cout << "*************\nSALES REPORT\n*************";
        std::cout << sales.purchaseHistory();
        std::cin.ignore(256, '\n');
        prompt();
        break;
    }
    case 9:
    {
        items.clear();
        exit(0);
        break;
    }
    default:
    {
        std::cerr << "\n***\nPlease Enter One of The Options ( 1 - 6 )\n***\n";
        prompt();
    }
    }
}
#endif
