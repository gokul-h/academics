// Menu Driven Program for implementation of stack
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int choice = 0;
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(4);
    do {
        cout << "1.Insert the element in the stack\n";
        cout << "2.Delete the element from the stack\n";
        cout << "3.Display size of the stack\n";
        cout << "4.Fetch top most element from the stack\n";
        cout << "5.Quit\n";
        cout << "Enter your choice (1-5)\n";
        cin >> choice;
        switch (choice) {
            case 1:
                int temp;
                cout << "Enter the element to be inserted" << endl;
                cin >> temp;
                s.push(temp);
                cout << "Element inserted successfully!" << endl;
                break;
            case 2:
                s.pop();
                cout << "Element deleted successfully!" << endl;
                break;
            case 3:
                cout << "Size of stack is: " << s.size() << endl;
                break;
            case 4:
                cout << "Top most element is: " << s.top() << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Wrong Input!\n\n";
        }
    } while (choice != 0);
    return 0;
}
