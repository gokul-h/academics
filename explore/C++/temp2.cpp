#include<iostream>
using namespace std;
class coach
{
private:
    char coachNo[5];
    char coachClass[10];
    bool ac;
    int capacity;
    int num_of_seat_occ;
    static int total_pass;
public:
    void initialize();
    void get();
    void put()const;
    bool isFull();
    void incrementSeat(int);
    void decrementSeat(int);
    static void addPassangers(int);
};
int coach::total_pass = 0;

