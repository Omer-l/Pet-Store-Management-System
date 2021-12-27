# Pet-Store-Management-System


- Developed a pet store management console using C++ that manages products at a pet store.
- Created UML diagrams showing each feature of the system before constructing the application.

<u><b>Utilised:</b></u> C++, Catch2, UML, OOP, GIT

**Software Engineering Coursework, Second Year of Computer Science**

  _Refer to 'Project Report.pptx' in the repository for UML diagrams and more information such as testing and analysis of this project_
  ## Scenario
A pet shop sells pet food, toys, accessories and books. It is in need of a stock management system to maintain stock records with a text (command line) menu with options to allow the user to perform the following functionality:
- sell items
- restock items (increase stock quantity)
- add new items
- update stock quantity (correct stock levels)
- view a listing of all products and current stock levels
- view a report of sales
- option to load/save data to/from a file
All of the products will have a price, but other information will vary by product type.

The program I have designed will load all the products from the text file. Then the user can interact with the system.
 
1. Program presents the User with a recurring console-based menu to interact with the data set. Application consists of some ‘dummy’ data (in the 'Items.txt' file) of products pre-coded into the application. Below I have demonstrated how to run the application.

- Below is how to setup the application and run it.

  &emsp;&emsp; <img src="README_Images/Setup.png" heigh=600 width=700>
  
- Below is the console-based program's prompt.

  &emsp;&emsp; <img src="README_Images/Prompt.png" heigh=300 width=350>
  
2. The User can simply exit the program by entering nine. The eight other menu options allow the User to inspect and edit the information in the data set (note again that this program allows the user to read and write the data).

  Below are images of the necessary interactions of the program with respect to the options mentioned above.
  
- &emsp; Sell an item by it's ID number
  
  &emsp;&emsp; <img src="README_Images/SellingAnItem.png" heigh=600 width=600>

- &emsp; Below is a list of items currently sold to a customer, which will be added to the 'sales report'.
  
  &emsp;&emsp; <img src="README_Images/SellItem.png" heigh=600 width=600>

- The other options work in a similar way with error handling for the user's input.
