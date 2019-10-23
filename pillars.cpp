#include "cstdio"

int* data;

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


class Map
{
public:
    int** arr;
    int row;
    Map(int n)
    {
        arr = new int*[n];
        for(int i = 0; i < n; i++){
            arr[i] = new int[2];
            arr[i][1] = -1;
        }
        row = n;
    }

    void add(int s1, int s2)
    {
        if (s1>s2)
        {
            int temp = s1;
            s1 = s2;
            s2 = temp;
        }
        int d = s2-s1;
        if (exsist(d))
        {
            arr[d][1] = max( arr[d][1], s1 );
        }
        else
            arr[d][1] = s1;
        }

    ~Map()
    {
        for(int i = 0; i < row; i++)
            delete[] arr[i];
        delete[] arr;
    }

    bool exsist(int d)
    {
        if(arr[d][1] != -1)
            return true;
        return false;
    }
};


int main()
{
    int n;
    scanf("%d", &n);
    data = new int[n];
    int sum = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &data[i]);
        sum += data[i];
    }
    Map A(sum+1);
    A.arr[0][1] = 0;
    for(int i = 0; i < n; ++i)
    {
        Map A2(sum+1);
        for(int j = 0; j < A.row; ++j)
            if(A.arr[j][1] != -1)
        {
            int diff = j;
            int sum1 = A.arr[j][1];
            int sum2 = sum1+diff;
            A2.add(sum1, sum2);
            A2.add(sum1 + data[i], sum2);
            A2.add(sum1, sum2 + data[i]);
        }
        for(int j = 0; j < A.row; ++j){
            A.arr[j][1] = A2.arr[j][1];
            //if(A.arr[j][1] != -1)
              //  printf("%d: %d, ", j, A.arr[j][1]);
        }
        //printf("\n");
    }
    printf("%d", A.arr[0][1]);
}
