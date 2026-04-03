// Checklist Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
#include <ctime>
using namespace std;
class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        //generates random int 0-100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed;  }

    void setCompleted(bool val) { completed = val;  }
};

int main()
{
    char input_option;
    int input_ID;
    string input_Description;
    std::string version = "v0.2.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;
    
    srand(time(NULL));

    todoItems.clear();

    //TodoItem test;
    //test.create("this is a test");
   // todoItems.push_back(test);


    while (1) {
        system("cls");
        std:cout << "Todo List Maker - " << version << std::endl;
        std::cout<<std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << std::endl;
        }
        if (todoItems.empty()) {
            std::cout << "Add your first todo item." << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q') {
        std::cout << "Have a great day!" << std::endl;
            break;
        }
        else if (input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_Description);

            TodoItem newItem;
            newItem.create(input_Description);
            todoItems.push_back(newItem);
        }
        else if (input_option == 'c') {
            std::cout << "Enter task ID to mark done: " << std::endl;
            std::cin >> input_ID;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_ID == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }

        }

    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
