#include <iostream>
using namespace std;
int main()
{
    cout << "Page replacement algorithm FIFO\n";
    int frame_size, page_size;
    cout << "Enter the no of frames (frame size)\n";
    cin >> frame_size;
    cout << "Enter the page sequence\n";
    String seq;
    cin >> seq

        // Convert input to array
        int page[];
    int frame[];
    for (int i = 0; i < frame_size; i++)
    {
        frame[i] = -1; // initializing
    }
    for(int i=0;i<page_size;i++){
        for(int j=0;j<frame_size;j++){
            if(page exist){
                cout<<"Hit";
            }
            else{
                if(frame[j]==-1){
                frame[j]==i;    //allocate page there
                break;
            }
            }
        }
    }
    return 0;
}