#include <iostream>
#include <math.h>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void print_array(int *arr, int array_size)
{
    for (int i = 0; i < array_size; i++)
        cout << arr[i];
    cout << endl;
}

int bubble_sort(int *arr, int array_size)
{
    int swaps = 0;
    for (int i = 0; i < array_size - 1; i++)
        for (int j = 0; j < array_size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
    return swaps;
}

int *create_and_fill_array(int size)
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    return arr;
}

int number_of_permutations(int array_size)
{
    int num = 1;
    for (int i = 2; i <= array_size; i++)
        num *= i;
    return num;
}

void reverse_array(int *arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

bool next_permutation(int *arr, int array_size)
{
    int k, l;
    // #1
    k = -1;
    for (int i = 0; i < array_size - 1; i++)
        if (arr[i] < arr[i + 1])
            k = i;
    if (k == -1)
        return false;
    // #2
    for (int i = k + 1; i < array_size; i++)
        if (arr[k] < arr[i])
            l = i;
    // #3
    swap(arr[k], arr[l]);
    // #4
    reverse_array(arr, k + 1, array_size - 1);
    return true;
    //The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.
    //1.Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    //2.Find the largest index l greater than k such that a[k] < a[l].
    //3.Swap the value of a[k] with that of a[l].
    //4.Reverse the sequence from a[k + 1] up to and including the final element a[n].

    // źródło: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
}

int *copy_array(int size, int *origin)
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = origin[i];
    return arr;
}

int main(int argc, char const *argv[])
{
    double results[9][3];
    for (int i = 2; i <= 10; i++)
    {
        int *arr = create_and_fill_array(i);
        int sum_of_swaps = 0;
        do
        {
            int *array_to_sort = copy_array(i, arr);
            sum_of_swaps += bubble_sort(array_to_sort, i);
            delete array_to_sort;
        } while (next_permutation(arr, i));
        delete arr;
        double average = (double)sum_of_swaps / (double)number_of_permutations(i);
        results[i - 2][0] = i;                         // Length of set
        results[i - 2][1] = average;                   // Average swaps
        results[i - 2][2] = number_of_permutations(i); // Number of possible permutations of set
    }

    // Printing results
    for (int i = 0; i < 9; i++)
    {
        cout << "Length of set: " << results[i][0] << endl;
        cout << "Average swaps: " << results[i][1] << endl;
        cout << "Number of possible permutations of set: " << results[i][2] << endl;
        cout << "============================" << endl;
    }

    return 0;
}
