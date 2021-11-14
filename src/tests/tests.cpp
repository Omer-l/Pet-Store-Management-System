#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Application.hpp"

TEST_CASE("test isDigit", "[isInputDigit]")
{
    REQUIRE(!isInputDigit("-1"));
    REQUIRE(isInputDigit("91283743182398912383924"));
    REQUIRE(!isInputDigit("43.2"));
    REQUIRE(!isInputDigit("æ…≥≈“«≥÷«æ"));
    REQUIRE(isInputDigit("5"));
}

TEST_CASE("test price is 2 decimal places", "[isPriceValid]")
{
    REQUIRE(isPriceValid("91283743182398912383924.32"));
    REQUIRE(!isPriceValid("32.232"));
    REQUIRE(!isPriceValid(""));
    REQUIRE(!isPriceValid("-2"));
    REQUIRE(isPriceValid("32.23"));
}

TEST_CASE("test Item is added to sales report")
{
    Pet_Food itemSold("Dog Food", "23", "5.99", "Dogs");
    Sales salesReport;
    SECTION( "Test selling 1 item" ) 
    {
        salesReport.addItem(itemSold, 1);
        REQUIRE( salesReport.purchaseHistory() == "\nItem Name: " + itemSold.getName()
            + " | Quantity purchased: " + "1 | Total: £5.99" + "\n---" + "\nGRAND TOTAL: £5.99");
    }
    SECTION( "Test selling 3 item" ) 
    {
        salesReport.addItem(itemSold, 3);
        REQUIRE( salesReport.purchaseHistory() == "\nItem Name: " + itemSold.getName()
            + " | Quantity purchased: " + "3 | Total: £17.97" + "\n---" + "\nGRAND TOTAL: £17.97");
    }
}

TEST_CASE("test data written to file when saving or loading")
{
    SECTION( "Test string given to file, pet food" ) 
    {
        Pet_Food petFood("Hamster Food", "23", "3.99", "Hamster");
        REQUIRE(petFood.stringForFile() == "Hamster Food;Pet_Food,Hamster;3.99;23");
    }
    SECTION( "Test string given to file, toy" ) 
    {
        Toy toy("Cat nip", "7", "6.99", "Cat");
        REQUIRE(toy.stringForFile() == "Cat nip;Toy,Cat;6.99;7");
    }
}

