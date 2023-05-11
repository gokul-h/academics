#include <stdio.h>
struct memory
{
    int size;
    int alloc; // if 0 ->  denotes no program is allocated >0->allocated
    // size-alloc denotes available space
};
void firstFit(struct memory *m, int m_no)
{
    printf("----------First Fit----------\n");
    int i, size = 0, count = 1;
    printf("Enter the size of process %d: ", count);
    scanf("%d", &size);
    do
    {
        int flag = 0;
        for (i = 0; i < m_no; i++)
        {
            if ((m[i].size - m[i].alloc) >= size)
            {
                m[i].alloc += size;
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
}
void bestFit(struct memory *m, int m_no)
{
    printf("----------Best Fit----------\n");
    int i, size = 0, count = 1;
    printf("Enter the size of process %d: ", count);
    scanf("%d", &size);
    do
    {
        int flag = 1, smallest_index = 0;
        // initialise array to store compatible values
        int smallest[m_no];
        for (int i = 0; i < m_no; i++)
        {
            smallest[i] = 0;
        }

        // Find and store compatible values
        for (int i = 0; i < m_no; i++)
        {
            int active_size = m[i].size - m[i].alloc;
            if (active_size >= size)
            {
                smallest[i] = active_size;
            }
        }

        // find index of first usable value
        int sm;
        for (int k = 0; k < m_no; k++)
        {
            if (smallest[k] == 0)
                continue;
            else
            {
                sm = k;
                break;
            }
        }

        // find index of smallest value
        // index similar for all arrays
        for (int j = 0; j < m_no; j++)
        {
            if (smallest[j] == 0)
                continue;
            if (smallest[j] < sm)
            {
                sm = j;
            }
        }

        // printf("sm=%d",sm);

        // set flag to 0 if no element is found
        if (smallest[sm] == 0)
        {
            flag == 0;
        }

        // allocate memmory
        if (flag)
        {
            m[sm].alloc += size;
            printf("Memmory allocated - %d and size-%d\n", m[sm].alloc, size);
            printf("Process is allocated\n");
        }
        else
        {
            printf("Process is not allocated\n");
        }
        // display memory status after each execution
        printf("Current memmory status\n");
        printf("Size\tAllocated\tFree\n");
        for (int k = 0; k < m_no; k++)
        {

            printf("%d\t%d\t\t%d\n", m[k].size, m[k].alloc, m[k].size - m[k].alloc);
        }

        count++;
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
    } while (size > 0);
}

void worstFit(struct memory *m, int m_no)
{
    printf("----------Worst Fit----------\n");
    int i, size = 0, count = 1;
    printf("Enter the size of process %d: ", count);
    scanf("%d", &size);
    do
    {
        int flag = 1, largest_index = 0;
        // initialise array to store compatible values
        int largest[m_no];
        for (int i = 0; i < m_no; i++)
        {
            largest[i] = 0;
        }

        // Find and store compatible values
        for (int i = 0; i < m_no; i++)
        {
            int active_size = m[i].size - m[i].alloc;
            if (active_size >= size)
            {
                largest[i] = active_size;
            }
        }

        // find index of first usable value
        int lr;
        for (int k = 0; k < m_no; k++)
        {
            if (largest[k] == 0)
                continue;
            else
            {
                lr = k;
                break;
            }
        }

        // find index of largest value
        // index similar for all arrays
        for (int j = 0; j < m_no; j++)
        {
            if (largest[j] == 0)
                continue;
            if (largest[j] > lr)
            {
                lr = j;
            }
        }

        // printf("lr=%d",lr);

        // set flag to 0 if no element is found
        if (largest[lr] == 0)
        {
            flag == 0;
        }

        // allocate memmory
        if (flag)
        {
            m[lr].alloc += size;
            printf("Memmory allocated - %d and size-%d\n", m[lr].alloc, size);
            printf("Process is allocated\n");
        }
        else
        {
            printf("Process is not allocated\n");
        }
        // display memory status after each execution
        printf("Current memmory status\n");
        printf("Size\tAllocated\tFree\n");
        for (int k = 0; k < m_no; k++)
        {

            printf("%d\t%d\t\t%d\n", m[k].size, m[k].alloc, m[k].size - m[k].alloc);
        }

        count++;
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
    } while (size > 0);
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