#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>
#include <stdexcept>

using namespace std;  

class DuplicateItemException : public runtime_error {
public:
    DuplicateItemException(const string& msg)
        : runtime_error(msg) {}
};

class ItemNotFoundException : public runtime_error {
public:
    ItemNotFoundException(const string& msg)
        : runtime_error(msg) {}
};

class StoredItem {
private:
    string id;
    string description;
    string location;

public:
    StoredItem(string id, string desc, string loc)
        : id(id), description(desc), location(loc) {}

    string getId() const { return id; }
    string getDescription() const { return description; }
    string getLocation() const { return location; }
};

class StorageManager {
private:
    unordered_map<string, shared_ptr<StoredItem>> itemById;
    map<string, shared_ptr<StoredItem>> itemByDescription;

public:
    void addItem(const shared_ptr<StoredItem>& item) {
        // store item and print message
        const auto& id = item->getId();
        if (itemById.count(id)) throw DuplicateItemException("Item with ID " + id + " already exists!");
        itemById[id] = item;
        itemByDescription[item->getDescription()] = item;
        cout << "Adding item: " << id << " - " << item->getDescription() << '\n';
    }

    shared_ptr<StoredItem> findById(const string& id) const {
        // retrieve item and print result
        cout << "Retrieving " << id << "...\n";
        auto it = itemById.find(id);
        if (it == itemById.end()) throw ItemNotFoundException("Item with ID " + id + " not found!");
        auto item = it->second;
        cout << "Found: " << item->getDescription() << " at " << item->getLocation() << '\n';
        return item;
    }

    void removeItem(const string& id) {
        // remove item and handle errors
        cout << "Removing " << id << "...\n";
        auto it = itemById.find(id);
        if (it == itemById.end()) throw ItemNotFoundException("Item with ID " + id + " not found!");
        itemByDescription.erase(it->second->getDescription());
        itemById.erase(it);
    }

    void listItemsByDescription() const {
        // list all items sorted by description
        cout << "Items in Description Order:" << '\n';
        for (const auto& pair : itemByDescription) {
            const auto& item = pair.second;
            cout << "- " << item->getDescription() << ": " << item->getLocation() << '\n';
        }
    }
};

int main() {
    StorageManager mgr;

    // sample use, swap items to test
    auto item1 = make_shared<StoredItem>("ITEM001", "LED Light", "Aisle 3, Shelf 1");
    auto item2 = make_shared<StoredItem>("ITEM002", "Fan Motor", "Aisle 2, Shelf 5");
    mgr.addItem(item1);
    mgr.addItem(item2);

    cout << "Attempting to add " << item1->getId() << " again...\n";
    try { mgr.addItem(item1); } catch (const DuplicateItemException& e) { cout << "Error: " << e.what() << '\n'; }

    try { mgr.findById(item2->getId()); } catch (const ItemNotFoundException& e) { cout << "Error: " << e.what() << '\n'; }

    string missingId = "ITEM003";
    try { mgr.removeItem(missingId); } catch (const ItemNotFoundException& e) { cout << "Error: " << e.what() << '\n'; }

    mgr.listItemsByDescription();
    return 0;
}
