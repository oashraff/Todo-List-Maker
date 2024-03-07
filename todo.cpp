//TODO LIST APPLICATION
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "todoitem.h"

using namespace std;

int main()
{
    char input;
    int input_id;
    string input_description;
    string version = "v0.1.0";
    list<TodoItem> todoItems;
    list<TodoItem> :: iterator it;

    srand(time(0));
    todoItems.clear();

    while(1)
    {
        system("clear");
        cout << "Todo List Maker - " << version << endl;
        cout << endl << endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++)
        {
            string completed = it ->isCompleted() ? "done" : "not done";

            cout << it -> getId() << " | " << it -> getDescription () << " | "
                << completed << endl;
        }

        if (todoItems.empty())
        {
            cout << "Add your first todo!" << endl;
        }

        cout << endl << endl;
        cout << "[a]dd a new todo" << endl;
        cout << "[c]omplete a todo" << endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";
        cin >> input;

        if (input == 'q')
        {
            cout << "Dont forget to add some new Todo's soon!" << endl;
            break;
        }
        else if (input == 'a')
        {
            cout << "Add a new description: ";
            cin.ignore();
            getline(cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if (input == 'c')
        {
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if(input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }
return 0;
}
