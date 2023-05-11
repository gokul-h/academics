#include <iostream>
using namespace std;
/*
Algorithm
1. Input the no of request in seqence
2. Enter Sequence
3. Enter the current head position
4. Enter the lower and upper bounds
5. Enter the direction of traversal
6. Process request till boundary is reached
7. Reverse the direction and repeat step 6
8. Repeat step 7 till all request are served
9. Output total no of iterations
*/

/*

*/
int right_to_left(int, int **, int, int, int);
int left_to_right(int, int **, int, int, int);

int main()
{
    int no_of_request;
    cout << "Enter the no of request: ";
    cin >> no_of_request;

    int request[no_of_request][2];
    cout << "Enter the requests: ";
    for (int i = 0; i < no_of_request; i++)
    {
        cin >> request[i][0];
        request[i][1] = 0; // To show that request is not served
    }

    int current_head_position;
    cout << "Enter the current head position: ";
    cin >> current_head_position;

    int lower_bound, upper_bound;
    cout << "Enter the uppper bound: ";
    cin >> upper_bound;
    cout << "Enter the lower bound: ";
    cin >> lower_bound;

    int direction_of_traversal;
    cout << "Enter the direction of traversal";
    cout << "(1 for Left to right and 0 for right to left): ";
    cin >> direction_of_traversal;

    int served_request = 0, no_of_times_travelled = 0;

    if (direction_of_traversal)
        served_request = left_to_right(no_of_request, request, current_head_position, served_request, lower_bound);
    else
        served_request = right_to_left(no_of_request, request, current_head_position, served_request, upper_bound);

    // cout << "Number of times travelled: " << no_of_times_travelled;
    cout << "Program Executed Successfully" << endl;
    return 0;
}
int left_to_right(int no_of_request, int **request, int current_head_position, int served_request, int upper_bound)
{
    for (int j = 0; j < no_of_request; j++)
    {
        if (!request[j][1] && request[j][0] > current_head_position)
        {
            request[j][1] = 1;
            cout << "Request " << request[j][0] << " is served." << endl;
            current_head_position = request[j][0];
            served_request++;
        }
    }
    current_head_position = upper_bound;
    if (served_request != no_of_request)
        served_request = right_to_left(no_of_request, request, current_head_position, served_request, upper_bound);
    return served_request;
}

int right_to_left(int no_of_request, int **request, int current_head_position, int served_request, int lower_bound)
{
    for (int j = 0; j < no_of_request; j++)
    {
        if (!request[j][1] && request[j][0] < current_head_position)
        {
            request[j][1] = 1;
            cout << "Request " << request[j][0] << " is served." << endl;
            current_head_position = request[j][0];
            served_request++;
        }
    }
    current_head_position = lower_bound;
    if (served_request != no_of_request)
        served_request = left_to_right(no_of_request, request, current_head_position, served_request, lower_bound);
    return served_request;
}