/*Algorithm
1. Define each proces as a structure containing size and alloc to check if it is allocated
2. Define memmory as a structure with size and process alocated;
3. Search using brute force and calculate internal fragmentation
*/
#include<stdio.h>
struct process
{
    int size;
    int alloc;
};

struct memory
{
    int size;
    int p_id;
};

void firstFit(struct process *p, struct memory *m, int p_no, int m_no)
{
    for (int i = 0; i < p_no; i++)
    {
        if (p[i].alloc == 0)
        {
            for (int j = 0; j < m_no; j++)
            {
                if (m[j].p_id == -1)
                {
                    if (m[j].size >= p[i].size)
                    {
                        m[j].p_id = i;
                        p[i].alloc = 1;
                        break;
                    }
                }
            }
        }
        else
            break;
    }
}

void result(struct process *p, struct memory *m, int p_no, int m_no)
{
    for (int i = 0; i < p_no; i++)
    {
        if (p[i].alloc == 1)
            printf("Process:%d is allocated\n", i);

        else
            printf("Process:%d is not allocated\n", i);
    }
}

#include <stdio.h>
int main()
{
    // Define the process values
    int p_no = 4;
    struct process p[p_no];
    p[0].size = 10;
    p[1].size = 20;
    p[2].size = 15;
    p[3].size = 75;
    p[0].alloc = p[1].alloc = p[2].alloc = p[3].alloc = 0;

    // Define memory
    int m_no = 7;
    struct memory m[m_no];
    m[0].size = 10;
    m[1].size = 25;
    m[2].size = 40;
    m[3].size = 15;
    m[4].size = 30;
    m[5].size = 40;
    m[6].size = 50;
    m[1].p_id = m[3].p_id = -2;                                     // to show its already occupied
    m[0].p_id = m[2].p_id = m[4].p_id = m[5].p_id = m[6].p_id = -1; //To show its free

    //First fit
    firstFit(p, m, p_no, m_no);
    result(p, m, p_no, m_no);
    return 0;
}