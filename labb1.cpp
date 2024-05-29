#include <iostream>
#include <string>

using namespace std;


struct Item {
    string name;
    int number;
    double value;
    Item* next;
    Item* prev;
};


void addToTop(Item** head, string name, int number, double value) {
    Item* newItem = new Item;
    newItem->name = name;
    newItem->number = number;
    newItem->value = value;
    newItem->prev = nullptr;
    newItem->next = *head;
    if (*head != nullptr) {
        (*head)->prev = newItem;
    }
    *head = newItem;
}


void addToEnd(Item** head, string name, int number, double value) {
    Item* newItem = new Item;
    newItem->name = name;
    newItem->number = number;
    newItem->value = value;
    newItem->next = nullptr;
    if (*head == nullptr) {
        newItem->prev = nullptr;
        *head = newItem;
        return;
    }
    Item* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newItem;
    newItem->prev = last;
}


void removeItem(Item** head, string name) {
    Item* temp = *head;
    if (temp != nullptr && temp->name == name) {
        *head = temp->next;
        if (*head != nullptr) {
            (*head)->prev = nullptr;
        }
        delete temp;
        cout << "Item '" << name << "' removed from the list." << endl;
        return;
    }
    while (temp != nullptr && temp->name != name) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Error: Item with name '" << name << "' not found in the list" << endl;
        return;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    cout << "Item '" << name << "' removed from the list." << endl;
}


void addBetween(Item** head, string name, int number, double value) {
    string prevItemName, nextItemName;

    cout << "Enter the name of the previous item: ";
    cin >> prevItemName;

    cout << "Enter the name of the next item: ";
    cin >> nextItemName;

    Item* prevItem = nullptr;
    Item* nextItem = *head;


    while (nextItem != nullptr && nextItem->name != prevItemName) {
        prevItem = nextItem;
        nextItem = nextItem->next;
    }

    if (nextItem == nullptr) {
        cout << "Error: Previous item with name '" << prevItemName << "' not found in the list" << endl;
        return;
    }

    Item* newItem = new Item;
    newItem->name = name;
    newItem->number = number;
    newItem->value = value;


    newItem->prev = prevItem;
    newItem->next = nextItem;


    if (prevItem != nullptr) {
        prevItem->next = newItem;
    }
    else {

        *head = newItem;
    }

    if (nextItem != nullptr) {
        nextItem->prev = newItem;
    }

    cout << "Item '" << name << "' added between '" << prevItemName << "' and '" << nextItemName << "'." << endl;
}



void displayList(Item* node) {
    if (node == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    while (node != nullptr) {
        cout << "Name: " << node->name << ", Number: " << node->number << ", Value: " << node->value << endl;
        node = node->next;
    }
}


int main() {
    Item* head = nullptr;

    char choice;
    do {
        cout << "\nMenu: " << endl;
        cout << "1. Add an item to the top of the list" << endl;
        cout << "2. Add an item to the end of the list" << endl;
        cout << "3. Remove an item from the list" << endl;
        cout << "4. Add an item between two items in the list" << endl;
        cout << "5. Display the list" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string name;
            int number;
            double value;
            cout << "Enter item details:" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Number: ";
            cin >> number;
            cout << "Value: ";
            cin >> value;
            addToTop(&head, name, number, value);
            break;
        }
        case '2': {
            string name;
            int number;
            double value;
            cout << "Enter item details:" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Number: ";
            cin >> number;
            cout << "Value: ";
            cin >> value;
            addToEnd(&head, name, number, value);
            break;
        }
        case '3': {
            string name;
            cout << "Enter the name of the item to remove: ";
            cin >> name;
            removeItem(&head, name);
            break;
        }
        case '4': {
            string name;
            int number;
            double value;
            cout << "Enter item details:" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Number: ";
            cin >> number;
            cout << "Value: ";
            cin >> value;
            addBetween(&head, name, number, value);
            break;
        }
        case '5':
            displayList(head);
            break;
        case '6':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != '6');

    return 0;
}
