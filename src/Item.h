#ifndef ITEM_H_
#define ITEM_H_
//********************** This file contains the Item class and all of it's sub-classes *******************

//Base class Item
class Item
{
private:
    std::string name;
    int qty_available;
    std::string price;

public:
    Item()
    {
    }
    virtual ~Item() {}

    Item(std::string name, std::string qty_available, std::string price)
    {
        this->name = name;
        this->qty_available = atoi(qty_available.c_str());
        this->price = price;
    }

    std::string getName()
    {
        return this->name;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    int getQty()
    {
        return this->qty_available;
    }

    void setQty(int qty_available)
    {
        this->qty_available = qty_available;
    }

    void addQty(int qty)
    {
        this->qty_available += qty;
    }

    std::string getPrice()
    {
        return this->price;
    }

    void setPrice(std::string price)
    {
        this->price = price;
    }

    virtual void toString()
    {
        if (getName() != "")
        {
            std::cout << std::endl
                      << "NAME:          " << this->name << std::endl
                      << "PRICE:         £" << this->price << std::endl
                      << "QTY:           " << std::to_string(this->getQty());
        }
    }

    virtual std::string stringForFile()
    {
        return  this->name + ";"
                + this->price + ";"
                + std::to_string(this->getQty());
    }
};

class Sales : public Item
{
private:
    double total;
    std::vector<Item*> items;
public:
    void addItem(Item item, int qty)
    {
        item.setQty(qty);
        double price = stod(item.getPrice()) * 100;
        double tot = price * item.getQty();
        std::stringstream totalStream;
        totalStream << std::fixed << std::setprecision(2) << tot/100;
        
        items.emplace_back(new Item(item.getName(), std::to_string(item.getQty()), totalStream.str()));
    }

    std::string purchaseHistory()
    {
        std::string salesReport;
        total = 0;
        for(std::string::size_type i = 0; i < items.size(); i++)
        {
            salesReport += "\nItem Name: " + items[i]->getName()
            + " | Quantity purchased: " + std::to_string(items[i]->getQty()) + " | Total: £" + items[i]->getPrice() +"\n---";
            total += stod(items[i]->getPrice()) * 100;
        }
        std::stringstream totalStream;
        totalStream << "\nGRAND TOTAL: £" << std::fixed << std::setprecision(2) << total/100;
        return salesReport += totalStream.str();
    }
};

//Pet_Food class inherits Item
class Pet_Food : public Item
{
private:
    std::string forAnimal;

public:
    Pet_Food(std::string name, std::string qty_available, std::string price, std::string forAnimal)
    {
        this->setName(name);
        this->setQty(atoi(qty_available.c_str()));
        this->setPrice(price);
        this->forAnimal = forAnimal;
    }

    std::string getforAnimal()
    {
        return this->forAnimal;
    }

    void toString()
    {
        std::cout << std::endl
                  << "NAME:          " << this->getName() << std::endl
                  << "PRICE:         £" << this->getPrice() << std::endl
                  << "QTY:           " << this->getQty() << std::endl
                  << "FOR:           " << this->forAnimal;
    }

    std::string stringForFile()
    {
        return this->getName() 
            + ";Pet_Food," + this->forAnimal + ";"
            + this->getPrice() + ";"
            + std::to_string(this->getQty());
    }
};

//Accessory class inherits Item
class Accessory : public Item
{
private:
    std::string material;

public:
    Accessory(std::string name, std::string qty_available, std::string price, std::string material)
    {
        this->setName(name);
        this->setQty(atoi(qty_available.c_str()));
        this->setPrice(price);
        this->material = material;
    }

    std::string getMaterial()
    {
        return this->material;
    }

    void toString()
    {
        std::cout << std::endl
                  << "NAME:          " << this->getName() << std::endl
                  << "PRICE:         £" << this->getPrice() << std::endl
                  << "QTY:           " << this->getQty() << std::endl
                  << "MATERIAL:      " << this->material ;
    }

    std::string stringForFile()
    {
        return this->getName() 
            + ";Accessory," + this->material + ";"
            + this->getPrice() + ";"
            + std::to_string(this->getQty());
    }
};

//Book class inherits Item
class Book : public Item
{
private:
    std::string description;
    std::string author;
    std::string type;

public:
    Book()
    {
    }
    Book(std::string name, std::string qty_available, std::string price, std::string author, std::string description)
    {
        this->setName(name);
        this->setQty(atoi(qty_available.c_str()));
        this->setPrice(price);
        this->author = author;
        this->type = "Unspecified";
        this->description = description;
    }

    std::string getType()
    {
        return this->type;
    }

    void setType(std::string type)
    {
        this->type = type;
    }

    std::string getAuthor()
    {
        return this->author;
    }

    void setAuthor(std::string author)
    {
        this->author = author;
    }

    std::string getDescription()
    {
        return this->description;
    }

    void setDescription(std::string description)
    {
        this->description = description;
    }

    void toString()
    {
        std::cout << std::endl
                  << "NAME:          " << this->getName() << std::endl
                  << "PRICE:         £" << this->getPrice() << std::endl
                  << "QTY:           " << this->getQty() << std::endl
                  << "BOOK TYPE:     " << this->getType() << std::endl
                  << "AUTHOR:        " << this->getAuthor() << std::endl
                  << "DESCRIPTION:   " << this->getDescription();
    }

    std::string stringForFile()
    {
        return this->getName() 
            + ";Book," + this->type + "," + this->getAuthor() + "," + this->getDescription() + ";"
            + this->getPrice() + ";"
            + std::to_string(this->getQty());
    }
};

//Fiction inherits Book
class Fiction : public Book
{
private:
public:
    Fiction(std::string name, std::string qty_available, std::string price, std::string author, std::string description)
    {
        this->setName(name);
        this->setQty(atoi(qty_available.c_str()));
        this->setPrice(price);
        this->setType("Fiction");
        this->setAuthor(author);
        this->setDescription(description);
    }
};

//Non_fiction inherits Book
class Non_Fiction : public Book
{
private:
public:
    Non_Fiction(std::string name, std::string qty_available, std::string price, std::string author, std::string description)
    {
        this->setName(name);
        this->setQty(atoi(qty_available.c_str()));
        this->setPrice(price);
        this->setType("Non_Fiction");
        this->setAuthor(author);
        this->setDescription(description);
    }
};

//Pet class inherits Item
class Toy : public Item
{
private:
    std::string forWho;

public:
    Toy(std::string name, std::string qty_available, std::string price, std::string forWho)
    {
        this->setName(name);
        this->setQty(atoi(qty_available.c_str()));
        this->setPrice(price);
        this->forWho = forWho;
    }

    std::string getForWho()
    {
        return forWho;
    }

    void toString()
    {
        std::cout << std::endl
                  << "NAME:          " << this->getName() << std::endl
                  << "PRICE:         £" << this->getPrice() << std::endl
                  << "QTY:           " << this->getQty() << std::endl
                  << "FOR:           " << this->forWho;
    }

    std::string stringForFile()
    {
        return this->getName() 
            + ";Toy," + this->forWho + ";"
            + this->getPrice() + ";"
            + std::to_string(this->getQty());
    }
};
#endif
