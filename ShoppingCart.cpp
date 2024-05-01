#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

ShoppingCart::ShoppingCart(const string& name, const string& date) : customerName(name), currentDate(date) {}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(const string& itemName) {
    for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
        if (it->GetName() == itemName) {
            cartItems.erase(it);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
    bool found = false;
    for (auto& cartItem : cartItems) {
        if (cartItem.GetName() == item.GetName()) {
            found = true;
            if (item.GetDescription() != "none") cartItem.SetDescription(item.GetDescription());
            if (item.GetPrice() != 0) cartItem.SetPrice(item.GetPrice());
            if (item.GetQuantity() != 0) cartItem.SetQuantity(item.GetQuantity());
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() const {
    int totalQuantity = 0;
    for (const auto& item : cartItems) {
        totalQuantity += item.GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::GetCostOfCart() const {
    double totalCost = 0;
    for (const auto& item : cartItems) {
        totalCost += item.GetQuantity() * item.GetPrice();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        for (const auto& item : cartItems) {
            item.PrintItemCost();
        }
    }

    cout << "\nTotal: $" << GetCostOfCart() << endl;  
} 

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "\nItem Descriptions" << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        for (const auto& item : cartItems) {
            item.PrintItemDescription();
        }
    }
}

