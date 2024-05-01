#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(const string& name, const string& description = "none", int price = 0, int quantity = 0);

    void SetName(const string& name);
    void SetPrice(int price);
    void SetQuantity(int quantity);
    void SetDescription(const string& description);

    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    string GetDescription() const;

    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;

};

#endif
