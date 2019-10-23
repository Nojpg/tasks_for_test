#include "memory.h"
#include <cstdio>

struct range
{
    int start, finish;
};

int ABS(int N)
{
    return (N<0)?(-N):(N);
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for(int i = 0; i < n; ++i)
        arr[i] = 0;
    range used[n];
    used[0] = {0, n-1};
    int used_size = 1;
    int sum = 0;
    for(int i = 0; i < m; ++i)
    {
        int status, id;
        scanf("%d %d", &status, &id);
        if(status == 1)
        {
            if(used_size == 1 && used[0].start == 0)
            {

                used[0].start = 1;
                sum += (0 + 1);
                arr[0] = id;
            }
            else if(used_size == 1 && used[0].finish == n - 1)
            {
                used[0].finish = n - 2;
                sum += ((n - 1) + 1);
                arr[n-1] = id;
            }
            else
            {
                int min = -1;
                int min_ind = -1;
                for(int j = 0; j < used_size; ++j)
                {
                    if(ABS(used[j].finish - used[j].start) > min)
                    {
                        if(ABS(used[j].finish - used[j].start) == min + 1)
                        {
                            if(ABS(used[j].finish - used[j].start) % 2 == 0 || used[j].finish == n - 1)
                            {
                                min_ind = j;
                                min =ABS(used[j].finish - used[j].start);
                            }
                        }
                        else
                        {
                            min_ind = j;
                            min =ABS(used[j].finish - used[j].start);
                        }
                    }
                }
                int middle;
                if(used[min_ind].finish + 1 == n)
                    middle = used[min_ind].finish;
                else
                    middle = (used[min_ind].start + used[min_ind].finish)/2;
                arr[middle] = id;
                sum += (middle + 1);
                range new_visitor = {middle, middle};
                int state = -1, index = -1;
                for(int j = 0; j < used_size; ++j)
                {
                    if(new_visitor.start == used[j].start && new_visitor.finish == used[j].finish)
                    {
                        state = 0;
                        index = j;
                        break;
                    }
                    else if(new_visitor.start > used[j].start && new_visitor.finish < used[j].finish)
                    {
                        state = 1;
                        index = j;
                        break;
                    }
                    else if(new_visitor.start == used[j].start)
                    {
                        state = 2;
                        index = j;
                        break;
                    }
                }
                switch(state)
                {
                case 0: // remove range
                {
                    for(int j = index; j < used_size - 1; ++j)
                        used[j] = used[j + 1];
                    used_size--;
                    break;
                }
                case 1: //slice range
                {
                    int temp = used[index].finish;
                    used[index].finish = new_visitor.start - 1;
                    used_size++;
                    for(int j = used_size - 1; j >= index + 2; --j)
                        used[j] = used[j-1];
                    used[index + 1] = range{new_visitor.finish + 1, temp};
                    break;
                }
                case 2: //start merge
                {
                    used[index].start = new_visitor.finish + 1;
                    break;
                }

                }
            }
        }
        else
        {
            int find_index = -1;
            for(int j = 0; j < n; ++j)
                if(arr[j] == id)
                {
                    find_index = j;
                    arr[j] = 0;
                    break;
                }
            range new_free = {find_index, find_index};
            find_index = -1;
            for(int j = 0; j < used_size; ++j)
                if(new_free.finish < used[j].start)
                    break;
                else
                    find_index = j;
            if(find_index == -1)
            {
                used_size++;
                for(int j = used_size - 1; j >= 1; --j)
                    used[j] = used[j-1];
                used[0] = new_free;
            }
            else
            {
                if(used[find_index].finish + 1 == new_free.start)
                {
                    used[find_index].finish = new_free.start;
                    if(find_index < used_size - 1)
                    {
                        if((used[find_index + 1].start - 1) == used[find_index].finish)
                        {
                            used[find_index].finish = used[find_index + 1].finish;
                            used_size--;
                            for(int j = find_index + 1; j < used_size; j++)
                                used[j] = used[j + 1];
                        }
                    }
                }
                else if(find_index < used_size - 1)
                {
                    if(used[find_index + 1].start - 1 == new_free.finish)
                        used[find_index + 1].start = new_free.finish;
                    else
                    {
                        used_size++;
                        for(int j = used_size - 1; j >= find_index + 2; j++)
                            used[j] = used[j-1];
                        used[find_index + 1] = new_free;
                    }
                }
                else
                {
                    used[used_size] = new_free;
                    used_size++;
                }
            }
        }
    }

    printf("%d", sum);
    return 0;
}
