#include <iostream>
/*
    5 3 1 6

   -3 5 1 6
   -3 1 5 6
   -3 1 5 6

*/
using std::cout;
using std::endl;
using std::size_t;

void displayArray(int *arr, int size_of_arr)
{
    cout << "Array Elements: ";
    for (size_t i = 0; i < size_of_arr; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void swapPositionElement(int *arr, int position1, int position2)
{
    int value_of_position1 = arr[position1];

    arr[position1] = arr[position2];
    arr[position2] = value_of_position1;
}

void bubbleSort(int *arr, int size_of_arr)
{
    int count;
    bool swap;
    // this loop makes algo run n times
    for (int i = size_of_arr - 1; i >= 0; i--)
    {
        swap = false;
        // the first element is assumed largest in each iteration
        for (int j = 0; j < i; j++)
        {
            int selected_largest = arr[j];
            int next_element = arr[j + 1];

            if (selected_largest <= next_element)
            {
                selected_largest = next_element;
                continue;
            }
            else
            {
                // if selected largest > next_element
                swapPositionElement(arr, j, j + 1);
                swap = true;
            }

            count = (i + 1) * (j + 1);
        }

        displayArray(arr, size_of_arr);

        if (!swap)
            break;
    }

    cout << "no of rounds loop ran: " << count << endl;
}

int main()
{
    int unsorted_arr[] = {6, 1, 7, 2, 8, 3, 9, 4, 10, 5};
    int size_of_unsorted_arr = sizeof(unsorted_arr) / sizeof(unsorted_arr[0]);

    int sorted_arr[] = {1, 2, 3, 4, 5};
    int size_of_sorted_arr = sizeof(sorted_arr) / sizeof(sorted_arr[0]);

    cout << "Unsorted Array" << endl;
    displayArray(unsorted_arr, size_of_unsorted_arr);
    bubbleSort(unsorted_arr, size_of_unsorted_arr);
    cout << endl;

    cout << "Sorted Array" << endl;
    displayArray(sorted_arr, size_of_sorted_arr);
    bubbleSort(unsorted_arr, size_of_sorted_arr);
    cout << endl;

    return 0;
}