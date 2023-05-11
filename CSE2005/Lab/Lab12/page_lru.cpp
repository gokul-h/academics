#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Page replacement algorithm LRU\n";
    int frame_size, page_size;
    cout << "Enter the no of frames (frame size)\n";
    cin >> frame_size;
    cout << "Enter the page sequence(Without spaces)\n";
    string seq;
    cin >> seq;
    int hit = 0, miss = 0;
    // Intialize frames to -1
    int frame[frame_size];
    // intialize usage array to -1
    int usage[frame_size];
    for (int i = 0; i < frame_size; i++)
    {
        frame[i] = -1;
        usage[i] = -1;
    }

    // Convert string to integer array
    int arr[seq.length()];
    for (int i = 0; i < seq.length(); i++)
    {
        // Ascii to int
        arr[i] = (seq[i] - 48);
    }
    // To implement FIFO
    // To keep track of oldest page
    int current = 0;
    for (int i = 0; i < seq.length(); i++)
    {
        int flag = 1;
        cout << "------------" << endl;
        cout << "Page: " << arr[i] << endl;
        for (int j = 0; j < frame_size; j++)
        {
            if (arr[i] == frame[j])
            {
                cout << "Hit" << endl;
                hit++;
                flag = 0;
                // Swap the elemnt in usage array with first element
                int temp = frame[0];
                frame[0] = frame[j];
                frame[j] = temp;
            }
        }
        if (flag)
        {
            cout << "Page Fault" << endl;
            miss++;
            frame[current] = arr[i];
            current++;
            current %= frame_size;
            // In array usage
            // Remove elemant at last postion
            // Shift elements
            // add new element to index position
            for (int k = frame_size - 1; k > 0; k--)
            {
                frame[k + 1] = frame[k];
            }
            frame[0] = arr[i];
        }
        // Print Frame for Each iteration
        cout << "Frame status:" << endl;
        for (int k = 0; k < frame_size; k++)
        {
            cout << frame[k] << endl;
        }
        cout << "------------" << endl;
    }
    int ratio = (hit / hit +  miss) * 100;
    cout << "Total hits: " << hit << endl;
    cout << "Total miss: " << miss << endl;
    cout << "Hit ratio: " << ratio <<"%"<< endl;
    return 0;
}