#include <stdio.h>
struct memory
{
    int size;
    int alloc; // if 0 ->  denotes no program is allocated 1->allocated
};
void firstFit(struct memory *m, int m_no)
{
    printf("----------First Fit----------\n");
    int i, size = 0, count = 1;
    printf("Enter the size of process %d: ", count);
    scanf("%d", &size);
    int waste = 0;
    do
    {
        int flag = 0;
        for (i = 0; i < m_no; i++)
        {
            if ((m[i].size - m[i].alloc) >= size)
            {
                m[i].alloc = 1;
                waste += m[i].size - size;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            printf("Process is allocated\n");
        }
        else
        {
            printf("Process is not allocated\n");
        }
        count++;
        // display memory status after each execution
        printf("Current memmory status\n");
        printf("Size\tAllocated\n");
        for (int k = 0; k < m_no; k++)
        {

            printf("%d\t%d\n", m[k].size, m[k].alloc);
        }
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
    } while (size > 0);
    printf("Total internal fragmentation:%d", waste);
}
void bestFit(struct memory *m, int m_no)
{
    printf("----------Best Fit----------\n");
    int i, size = 0, count = 1;
    printf("Enter the size of process %d: ", count);
    scanf("%d", &size);
    int waste = 0;
    do
    {
        int sm = -1, flag = 0;
        // find smallest memory location
        for (int i = 0; i < m_no; i++)
        {
            if (m[i].alloc == 1)
                continue;
            else if (m[i].size >= size)
            {
                sm = i;
                flag = 1;
                break;
            }
        }
        //printf("sm-%d\n", sm);
        for (int j = 0; j < m_no; j++)
        {
            if (m[j].alloc == 0 && (m[j].size <= m[sm].size) && m[j].size >= size)
            {
                sm = j;
            }
        }
        //printf("sm-%d\n", sm);
        // allocate memmory
        if (flag)
        {
            printf("sm-%d\n", sm);
            m[sm].alloc = 1;
            waste += m[sm].size - size;
            printf("Process is allocated\n");
        }
        else
        {
            printf("Process is not allocated\n");
        }
        // display memory status after each execution
        printf("Current memmory status\n");
        printf("Size\tAllocated\n");
        for (int k = 0; k < m_no; k++)
        {
            printf("%d\t%d\n", m[k].size, m[k].alloc);
        }

        count++;
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
    } while (size > 0);
    printf("Total internal fragmentation:%d\n", waste);
}

void worstFit(struct memory *m, int m_no)
{
    printf("----------Worst Fit----------\n");
    int i, size = 0, count = 1;
    printf("Enter the size of process %d: ", count);
    scanf("%d", &size);
    int waste = 0;
    do
    {
        int lr = -1, flag = 0;
        // find largest memory location
        for (int i = 0; i < m_no; i++)
        {
            if (m[i].alloc == 1)
                continue;
            else if (m[i].size >= size)
            {
                lr = i;
                flag = 1;
                break;
            }
        }
        //printf("lr-%d\n", lr);
        for (int j = 0; j < m_no; j++)
        {
            if (m[j].alloc == 0 && (m[j].size >= m[lr].size) && m[j].size >= size)
            {
                lr = j;
            }
        }
        //printf("lr-%d\n", lr);
        // allocate memmory
        if (flag)
        {
            printf("lr-%d\n", lr);
            m[lr].alloc = 1;
            waste += m[lr].size - size;
            printf("Process is allocated\n");
        }
        else
        {
            printf("Process is not allocated\n");
        }
        // display memory status after each execution
        printf("Current memmory status\n");
        printf("Size\tAllocated\n");
        for (int k = 0; k < m_no; k++)
        {
            printf("%d\t%d\n", m[k].size, m[k].alloc);
        }

        count++;
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
    } while (size > 0);
    printf("Total internal fragmentation:%d\n", waste);
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
    m[4].size = 60;
    m[0].alloc = m[1].alloc = m[2].alloc = m[3].alloc = m[4].alloc = 0; // To show its free

    // Menu
    printf("Variable Size memmory allocation\n");
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