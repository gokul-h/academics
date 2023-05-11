// Menu Driven Program for implementation of queue
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int choice = 0;
    queue<int> s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(4);
    do {
        cout << "1.Insert the element in the queue\n";
        cout << "2.Delete the element from the queue\n";
        cout << "3.Display size of the queue\n";
        cout << "4.Fetch front element from the queue\n";
        cout << "5.Fetch last element from the queue\n";
        cout << "6.Quit\n";
        cout << "Enter your choice (1-6)\n";
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
                cout << "Size of queue is: " << s.size() << endl;
                break;
            case 4:
                cout << "Front most element is: " << s.front() << endl;
                break;
            case 5:
                cout << "Last most element is: " << s.back() << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Wrong Input!\n\n";
        }
    } while (choice != 0);
    return 0;
}
