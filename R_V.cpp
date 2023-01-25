#include <iostream>

// разделяй и властвуй
// нахождение max элемента

static int maxElement(int vals[], int left, int right)
{
    if (right - left == 1)
        return vals[left];

    int mid = (left + right) / 2;
    int max1 = maxElement(vals, left, mid);
    int max2 = maxElement(vals, mid, right);

    if (max1 > max2)
        return max1;

    return max2;
}

static int maxElement(int vals[], int size)
{
    // int size = sizeof(vals) / sizeof(vals[0]);
    if (size == 0)
    {
        std::cout << "Massive is empty" << std::endl;
    }
    return maxElement(vals, 0, size);
}

int main()
{

    int vals[] = {1, 5, 7, -3, 67, 11, 7, 89, 55, 32};
    int size = sizeof(vals) / sizeof(vals[0]);
    int max = maxElement(vals, size);
    std::cout << max;
    return 0;
}