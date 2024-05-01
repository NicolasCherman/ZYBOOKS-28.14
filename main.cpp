#include <iostream>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void PrintMenu(const ShoppingCart& cart);
void ExecuteMenu(char choice, ShoppingCart& cart);

int main() {
    string customerName, currentDate;

    cout << "Enter customer's name:\n";
    getline(cin, customerName);

    cout << "Enter today's date:\n";
    getline(cin, currentDate);

    cout << "\nCustomer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    ShoppingCart cart(customerName, currentDate);

    char menuOption = ' ';
    bool displayMenu = true; // Flag to control menu display
    while (menuOption != 'q') {
        if (displayMenu) {
            PrintMenu(cart);
        }
        cout << "\nChoose an option:";
        cin >> menuOption;
        cin.ignore(); // Ignore newline character left in the input buffer
        if (menuOption != 'a' && menuOption != 'd' && menuOption != 'c' && menuOption != 'i' && menuOption != 'o' && menuOption != 'q') {

            displayMenu = false; // Do not display the menu again
        } else {
            ExecuteMenu(menuOption, cart);
            displayMenu = true; // Display the menu next time
        }
    }

    return 0;
}


void PrintMenu(const ShoppingCart& cart) {
    cout << "\nMENU\n"
         << "a - Add item to cart\n"
         << "d - Remove item from cart\n"
         << "c - Change item quantity\n"
         << "i - Output items' descriptions\n"
         << "o - Output shopping cart\n"
         << "q - Quit\n";
}

void ExecuteMenu(char choice, ShoppingCart& cart) {
    string name, description;
    int price, quantity;

    switch (choice) {
        case 'a': {
            ItemToPurchase item;
            cout << "\nADD ITEM TO CART\n";
            cout << "Enter the item name:\n";
            getline(cin, name);
            item.SetName(name);

            cout << "Enter the item description:\n";
            getline(cin, description);
            item.SetDescription(description);

            cout << "Enter the item price:\n";
            cin >> price;
            item.SetPrice(price);

            cout << "Enter the item quantity:\n";
            cin >> quantity;
            item.SetQuantity(quantity);

            cart.AddItem(item);
            break;
        }
        case 'd': {
            cout << "\nREMOVE ITEM FROM CART\n";
            cout << "Enter name of item to remove:\n";
            getline(cin, name);
            cart.RemoveItem(name);
            break;
        }
        case 'c': {
            cout << "\nCHANGE ITEM QUANTITY\n";
            cout << "Enter the item name:\n";
            getline(cin, name);
            cout << "Enter the new quantity:\n";
            cin >> quantity;

            // Find the item and update the quantity
            ItemToPurchase item;
            item.SetName(name);
            item.SetQuantity(quantity);
            cart.ModifyItem(item);
            break;
        }
        case 'i': {
            cout << "\nOUTPUT ITEMS' DESCRIPTIONS\n";
            cart.PrintDescriptions();
            break;
        }
        case 'o': {
            cout << "\nOUTPUT SHOPPING CART\n";
            cart.PrintTotal();
            break;
        }
        case 'q': {
           cout << endl;
            break;
        }
        default: {
            cout << "Invalid option. Please choose again.\n";
            break;
        }
    }
}