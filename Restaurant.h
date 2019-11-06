#ifndef AEDA_UGHEATS_RESTAURANT_H
#define AEDA_UGHEATS_RESTAURANT_H

#include <string>
#include <vector>
#include "Base.h"
#include "Order.h"
#include "Product.h"
#include "Address.h"

using namespace std;

class Restaurant{
private:
    Address address;
    vector<string> cuisine;
    vector<Product> products;
    vector<Order> orders;
    Base base;
public:
    Restaurant(Address address, vector<string> cuisine, vector<Product> products, vector<Order> orders, Base base);
    //Metodos Set
    void setRestaurantAddress(Address address);
    void setRestaurantCuisine(vector<string> cuisine);
    void setRestaurantProducts(vector<Product> products);
    void setRestaurantOrders(vector<Order> orders);
    void setRestaurantBase(Base base);
    //Metodos Get
    Address getRestaurantAddress() const;
    vector<string> getRestaurantCuisine() const;
    vector<Product> getRestaurantProducts() const;
    vector<Order> getRestaurantOrders() const;
    Base getRestaurantBase() const;
    //Other Methods

};


#endif //AEDA_UGHEATS_RESTAURANT_H
