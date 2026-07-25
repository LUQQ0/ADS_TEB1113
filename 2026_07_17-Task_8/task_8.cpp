#include <iostream>
using namespace std;

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    // Merge the temporary arrays
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    // bubble sort
    cout << "Bubble sort" << endl;
    int bub[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (bub[j] > bub[j + 1])
            {
                int temp = bub[j];
                bub[j] = bub[j + 1];
                bub[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << bub[i] << " ";
    }

    cout << endl;

    // insertion sort
    cout << "Insertion sort" << endl;
    int ins[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (ins[j] < ins[j - 1])
            {
                int temp = ins[j];
                ins[j] = ins[j - 1];
                ins[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << ins[i] << " ";
    }

    cout << endl;

    //merge sort
    cout << "Merge sort" << endl;
    int mer[] = {38, 27, 43, 3, 9, 82, 10};
    int a = sizeof(mer) / sizeof(mer[0]);

    cout << "Original array: ";
    for (int i = 0; i < a; i++)
        cout << mer[i] << " ";

    mergeSort(mer, 0, a - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < a; i++)
        cout << mer[i] << " ";

    cout << endl;

    //quick sort
    cout << "Quick sort" << endl;
    int qui[] = {10, 7, 8, 9, 1, 5};
    int b = sizeof(qui) / sizeof(qui[0]);

    cout << "Original array: ";
    for (int i = 0; i < b; i++)
        cout << qui[i] << " ";

    quickSort(qui, 0, b - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < b; i++)
        cout << qui[i] << " ";

    cout << endl;

    //selection sort
    cout << "Selection sort" << endl;
     int sel[] = {64, 25, 12, 22, 11};
    int c = sizeof(sel) / sizeof(sel[0]);

    for (int i = 0; i < c - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < c; j++)
        {
            if (sel[j] < sel[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = sel[i];
        sel[i] = sel[minIndex];
        sel[minIndex] = temp;
        }
    cout << "Sorted array: ";
    for (int i = 0; i < c; i++)
    {
        cout << sel[i] << " ";
    }
    cout << endl;

    return 0;
}