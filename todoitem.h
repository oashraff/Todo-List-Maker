#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class TodoItem
{
    private:
    int id;
    string description;
    bool completed;

    public:
    TodoItem(): id(0), description(""), completed(false){}
    ~TodoItem() = default;

    bool create(string new_description)
    {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }
    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }
    void setCompleted(bool val) {completed = val; }
};