#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of track: ";
    cin >> n;
    cout << "Enter the track position: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int current_position = 0;
    int seek_time = 0;
    int diff_between_tracks;
    cout << "Tracks Traversed\tDifference between tracks"<<endl;
    for (int i = 0; i < n; i++)
    {
        diff_between_tracks = abs(current_position - arr[i]);
        seek_time += diff_between_tracks;
        cout<<arr[i]<<"\t\t\t\t"<<diff_between_tracks<<endl;
        current_position = arr[i];
    }
    //cout << "\n Total Seek time: " << seek_time << endl;
    return 0;
}