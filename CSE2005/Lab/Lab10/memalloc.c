//  Fixed Size memmory allocation
// First Fit - Best Fit - Worst Fit
// Enter -1 to exit
#include <stdio.h>

struct memory
{
    int size;
    int alloc; // if 0 ->  denotes no program is allocated 1->allocated
};

void firstFit(struct memory *m, int m_no)
{
    // Define the process values
    printf("----------First Fit----------\n");
    int count = 1;
    int size = 1;
    int waste = 0;
    int i, j;
    for (j = 0; j < m_no; j++)
    {
        int flagi = 0;
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
        int flag = 0;
        for (i = 0; i < m_no; i++)
        {
            if (m[i].alloc == 0)
            {
                flag = 1;
                if (m[i].size >= size)
                {
                    m[i].alloc = 1;
                    printf("Process is allocated\n");
                    waste += m[i].size - size;
                    flagi = 1;
                    break;
                }
            }
        }
        if (flagi == 0)
        {
            printf("Process is not alloacted\n");
        }
        if (flag == 0)
        {
            printf("All memmory blocks occupied\n");
            break;
        }
        count++;
    }
    printf("Internal fragmentation waste: %d\n", waste);
}

void bestFit(struct memory *m, int m_no)
{
    // Define the process values
    printf("----------Best Fit----------\n");
    int count = 1;
    int size = 1;
    int waste = 0;
    int i,j;
    for (j = 0; j < m_no; j++)
    {

        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
        int flag = 0;
        int small = m[0].size;
        int small_i = 0;
        int flagi = 0;
        for (i = 1; i < m_no; i++)
        {
            if (m[i].size < small && m[i].size >= size)
            {
                small = m[i].size;
                small_i = i;
                flagi = 1;
            }
        }
        for (i = 0; i < m_no; i++)
        {
            if (m[i].alloc == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("All memmory blocks occupied\n");
            break;
        }
        else
        {

            if (flagi == 0)
            {
                printf("Process is not alloacted\n");
            }
            else
            {
                if (small_i > -1)
                {
                    m[small].alloc = 1;
                    waste += m[small].size - size;
                    printf("Process is alloacted\n");
                }
            }
        }
        count++;
    }
    printf("Internal fragmentation waste: %d\n", waste);
}

void worstFit(struct memory *m, int m_no)
{
    // Define the process values
    printf("----------Worst Fit----------\n");
    int count = 1;
    int size = 1;
    int waste = 0;
        int i,j;
    for (j = 0; j < m_no; j++)
    {

        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
        int flag = 0;
        int flagi = 0;
        int large = m[0].size;
        int large_i = 0;
        int i;
        for (i = 1; i < m_no; i++)
        {
            if (m[i].size > large && m[i].size >= size)
            {
                large = m[i].size;
                large_i = i;
                flagi = 1;
            }
        }
        for (i = 0; i < m_no; i++)
        {
            if (m[i].alloc == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("All memmory blocks occupied\n");
            break;
        }
        else
        {
            if (flagi == 0)
            {
                printf("Process is not alloacted\n");
            }
            else
            {
                if (large > -1)
                {
                    m[large].alloc = 1;
                    waste += m[large].size - size;
                    printf("Process is alloacted\n");
                }
            }
        }
        count++;
    } while (size > 0);
    printf("Internal fragmentation waste: %d\n", waste);
}
int main()
{
    int m_no = 5;
    // Define memory
    struct memory m[m_no];
    m[0].size = 50;
    m[1].size = 100;
    m[2].size = 90;
    m[3].size = 200;
    m[4].size = 50;
    m[0].alloc = m[1].alloc = m[2].alloc = m[3].alloc = m[4].alloc = 0; // To show its free

    // Menu
    printf("Fixed Size memmory allocation\n");
    printf("Enter any below choices\n");
    printf("1.First Fit\n");
    printf("2.Best Fit\n");
    printf("3.Worst Fit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        firstFit(m, m_no);
        break;
    case 2:
        bestFit(m, m_no);
        break;
    case 3:
        worstFit(m, m_no);
        break;
    default:
        printf("Wrong input!\nProgram Terminated...\n");
    }

    return 0;
}