#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int arr[N] = {0};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    


    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        for (int j = 0; j < size -1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\n";
    }
    
    return 0;
}
