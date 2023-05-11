#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of track: ";
    cin >> n;
    cout << "Enter the track position: ";
    // 0-> value 1->traversed/not
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = 0;
    }
    int current_position = 0;
    cout << "Enter current head position:";
    cin >> current_position;
    int seek_time = 0;
    int diff_between_tracks;
    cout << "Tracks Traversed\tDifference between tracks" << endl;
    /*
     * Find tracking postion closer to current position
     * mark it as served
     */
    for (int i = 0; i < n; i++)
    { // to serve all track position
        if (!arr[i][1])
        {
            int closest = abs(current_position-arr[i][0]);
            int closest_index = i;
            for (int j = 0; j < n; j++)
            { // to find closest position for each iteration
                if (!arr[j][1])
                {
                    diff_between_tracks = abs(current_position - arr[j][0]);
                    if (diff_between_tracks < closest)
                    {
                        closest_index = j;
                        closest = arr[j][0];
                        arr[j][1] = 1;
                    }
                }
            }
            diff_between_tracks = abs(current_position - arr[closest_index][0]);
            seek_time += diff_between_tracks;
            cout << arr[closest_index][0] << "\t\t\t\t" << diff_between_tracks << endl;
            current_position = arr[closest_index][0];
        }
    }

    cout << "\n Total Seek time: " << seek_time << endl;
    return 0;
}