#include <iostream>
#include <string>
using namespace std;
const int size = 20;
class arraystack
{
    int top;

public:
    arraystack()
    {
        top = -1;
    }
    string array[size];
    bool is_empty()
    {
        return top < 0;
    }
    bool is_full()
    {
        return top == size - 1;
    }
    string get_top()
    {
        if (is_empty())
        {
            cout << "Stack is empty...\n";
            return '\0';
        }
        else
            return array[top];
    }
    int get_size()
    {
        return size;
    }
    bool push(string n)
    {
        if (is_full())
        {
            cout << "Stack is full...\n";
            return 0;
        }
        else
        {
            array[++top] = n;
            return 1;
        }
    }
    string pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty...\n";
            return '\0';
        }
        else
            return array[top--];
    }
};
class node
{
public:
    string data;
    node *next;
    node(string n)
    {
        data = n;
        next = nullptr;
    }
};
// class liststack
// {
//     node *top;

// public:
//     liststack()
//     {
//         top = nullptr;
//     }
//     bool is_empty()
//     {
//         return top == nullptr;
//     }
//     char get_top()
//     {
//         if (is_empty())
//         {
//             cout << "Stack is empty...\n";
//             return '\0';
//         }
//         else
//             return top->data;
//     }
//     bool push(int n)
//     {
//         node *mynode = new node(n);
//         mynode->next = top;
//         top = mynode;
//         return 1;
//     }
//     char pop()
//     {
//         if (is_empty())
//         {
//             cout << "Stack is empty...\n";
//             return '\0';
//         }
//         else
//         {
//             node *temp = top;
//             char n = temp->data;
//             top = top->next;
//             delete temp;
//             return n;
//         }
//     }
// };
class singlylist
{
private:
    node *head;

public:
    singlylist()
    {
        head = nullptr;
    }
    node* get_head() {
        return head;
    }
    bool is_empty()
    {
        // this function checks wheather the list is empty or not
        return head == nullptr;
    }
    bool index_valid(int index)
    {
        // this function checks wheather the index is valid or not
        if (index < 1)
        {
            // the linked list starts with index ( 1 )
            return 0;
        }
        else
        {
            int i = 1;
            node *temp = head;
            // this loop find the length of the linked list
            while (temp != nullptr)
            {
                temp = temp->next;
                i++;
            }
            return (index <= i - 1);
        }
    }
    void display()
    {
        // this function displays the whole linked list
        if (!(is_empty()))
        {
            node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
            cout << "Empty list...\n";
    }
    void insert_at_end(string n)
    {
        // this function insert value n at the end
        node *my_node = new node(n);
        if (is_empty()) // if linked list is empty, insert at first
            head = my_node;
        else
        {
            node *temp = head;
            // traverse through the linked list till end
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = my_node;
        }
    }
    void insert_at_start(string n)
    {
        // this function insert value n at the start
        node *my_node = new node(n);
        if (is_empty()) // if linked list is empty insert at first
            head = my_node;
        else
        {
            node *temp = head;
            // update pointers
            head = my_node;
            my_node->next = temp;
        }
    }
    bool insert_at_x(int index, string n)
    {
        // this function insert value n at the index i
        if (index == 1)
        {
            // if index is 1, insert at first
            insert_at_start(n);
            return 1;
        }
        else
        {
            // check validity of index
            if (index_valid(index))
            {
                node *my_node = new node(n);
                int i = 1;
                node *temp = head;
                // traverse through the linked list till index
                while (i < index - 1)
                {
                    temp = temp->next;
                    i++;
                }
                my_node->next = temp->next;
                temp->next = my_node;
                return 1;
            }
            else
            {
                cout << "Invalid index...\n";
                return 0;
            }
        }
    }
    int search_index(string n)
    {
        // this function searches the index of given value
        if (is_empty()) // if linked list is empty, not found
            return -1;
        else
        {
            int i = 0;
            node *temp = head;
            // traverse through the linked list to compare value
            while (temp != nullptr)
            {
                if (temp->data == n)
                    return i + 1;
                else
                {
                    temp = temp->next;
                    i++;
                }
            }
            cout << "Not found...\n";
            return -1;
        }
    }
    bool update(int index, string n)
    {
        // this function updates the value of index i
        if (is_empty())
        {
            // if the linked list is empty, not update
            cout << "Empty list...\n";
            return 0;
        }
        else
        {
            // check validity of index
            if (index_valid(index))
            {
                int i = 1;
                node *temp = head;
                // traverse through the linked list till index
                while (i < index)
                {
                    temp = temp->next;
                    i++;
                }
                temp->data = n;
                return 1;
            }
            else
            {
                cout << "Invalid index...\n";
                return 0;
            }
        }
    }
    void del_at_start()
    {
        // this functon deletes the first node
        if (!(is_empty()))
        {
            // update pointers
            node *temp = head;
            head = temp->next;
            delete temp;
        }
        else
            cout << "Empty list...\n";
    }
    void del_at_end()
    {
        // this function deletes the last node
        if (!(is_empty()))
        {
            node *temp = head;
            node *check = nullptr;
            // traverse through the linked list till end
            while (temp->next != nullptr)
            {
                check = temp;
                temp = temp->next;
            }
            if (temp == head) // first node
                head = temp->next;
            else
                check->next = temp->next;
            delete temp;
        }
        else
            cout << "Empty list...\n";
    }
    bool del_at_x(int index)
    {
        // this function deletes the node at index i
        if (!(is_empty()))
        {
            // check validity of the index
            if (index_valid(index))
            {
                int i = 1;
                node *temp = head;
                node *check = nullptr;
                // traverse through the linked list till index
                while (i < index)
                {
                    check = temp;
                    temp = temp->next;
                    i++;
                }
                if (temp == head) // first node
                    head = temp->next;
                else
                    check->next = temp->next;
                delete temp;
                return 1;
            }
            else
            {
                cout << "Invalid index...\n";
                return 0;
            }
        }
        else
        {
            cout << "Empty list...\n";
            return 0;
        }
    }
};
bool is_operator(string str) {
    return (str == "*" || str == "/" || str == "+" || str == "-" || str == "^");
}
singlylist convert_post(singlylist list) {
    arraystack stack;
    node *temp = list.get_head();
    singlylist postfix;
    while(temp != nullptr) {
        if (is_operator(temp->data)) {
            if (temp->data=="+" || temp->data=="-") {
                if (stack.is_empty())
                    stack.push(temp->data);
                else {
                    while (is_operator(stack.get_top()))
                        postfix.insert_at_end(stack.pop());
                    stack.push(temp->data);
                }
            }
            else if (temp->data=="*" || temp->data=="/") {
                if (stack.is_empty() || temp->data=="+" || temp->data=="-")
                    stack.push(temp->data);
                else {
                    while (stack.get_top()=="*" || stack.get_top()=="/" || stack.get_top()=="^")
                        postfix.insert_at_end(stack.pop());
                    stack.push(temp->data);
                }
            }
            else {
                stack.push(temp->data);
            }
        }
        else if (temp->data=="(") {
            stack.push(temp->data);
        }
        else if (temp->data==")") {
            string temp_ = stack.get_top();
            while (temp_!="(") {
                postfix.insert_at_end(stack.pop());
                temp_ = stack.get_top();
            }
            temp_ = stack.pop();
        }
        else {
            postfix.insert_at_end(temp->data);
        }
        temp = temp->next;
    }
    while (!(stack.is_empty())) {
        postfix.insert_at_end(stack.pop());
    }
    postfix.display();
    return postfix;
}

int main()
{
    string str;
    singlylist list;
    cout << "Enter expression:\nTo stop input enter \'0\'\n";
    do
    {
        cin >> str;
        if (str!="0") {
            list.insert_at_end(str);
        }
    } while (str != "0");
    list.display();
    singlylist postfix = convert_post(list);
    postfix.display();
    return 0;
}