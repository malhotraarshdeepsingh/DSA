#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <deque>
#include <list>

using namespace std;

struct Product
{
    int id;
    string name;
    double price;
    string category;
};

struct Customer
{
    string id;
    string name;
    string email;
};

struct Order
{
    int id;
    string customerId;
    vector<Product> products;
    double totalPrice;
    time_t orderTime;
};

int main()
{
    
    // Vector to store products
    vector<Product> products = {
        {101, "Laptop", 999.99},
        {102, "Smartphone", 499.99},
        {103, "Tablet", 299.99}
    };
    
    // Map to store customers with customer ID as key
    map<int, Customer> customers = {
        {1, {"C001", "Alice", "envkt@example.com"}},
        {2, {"C002", "Bob", "hzdkv@example.com"}},
        {3, {"C003", "Charlie", "dfytn@example.com"}}
    };
    
    // List to store orders history
    list <Order> orderHistory;

    // Create and add orders to the order history
    orderHistory.push_back({1, "C001", products, 1499.98, time(0)});
    orderHistory.push_back({2, "C002", products, 1299.97, time(0)});
    orderHistory.push_back({3, "C003", products, 999.99, time(0)});

    // Display order history
    for (const auto& order : orderHistory)
    {
        cout << "Order ID: " << order.id << ", Customer ID: " << order.customerId << ", Total Price: $" << order.totalPrice << endl;
    }

    // Set to store categories of products
    set<string> productCategories;
    for (const auto& product : products)
    {
        productCategories.insert(product.category);
    }

    // Map to store stock information
    map<int, int> stock = {
        {101, 10},
        {102, 20},
        {103, 15}
    };

    // Multimap to store customer orders
    multimap<string, Order> customerOrders;
    for (const auto& order : orderHistory)
    {
        customerOrders.insert({order.customerId, order});
    }

    // Unordered map to store customer data
    unordered_map<string, string> customerData = {
        {"C001", "Alice"},
        {"C002", "Bob"},
        {"C003", "Charlie"}
    }; 

    // Unordered set to store unique product ids
    unordered_set<int> uniqueProductIds;
    for (const auto& product : products)
    {
        uniqueProductIds.insert(product.id);
    }

    return 0;
}