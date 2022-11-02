// MergeSortedArrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <functional>
#include <fstream>

void merge(int* arr, int* arr1, int* arr2, size_t size1, size_t size2, const std::function<bool(int a, int b)>& compare) {
    size_t i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (compare(arr1[i], arr2[j])) {
            arr[i + j] = arr1[i];
            i++;
        }
        else {
            arr[i + j] = arr2[j];
            j++;
        }
    }
    while (i < size1) {
        arr[i + j] = arr1[i];
        ++i;
    }
    while (j < size2) {
        arr[i + j] = arr2[j];
        ++j;
    }

}

int* separation(int** arr, size_t line, size_t cols, const std::function<bool(int a, int b)>& compare) {
    int* result;
    if (line > 1) {
        result = new int[line * cols];
        merge(result, separation(arr, line / 2, cols, compare), separation(arr + line / 2, line - line / 2, cols, compare), line / 2 * cols, (line - line / 2) * cols, compare);
    }
    else {
        result = arr[0];
    }

    return result;
}

int** memory_alloc(size_t n, size_t m)
{
    int** res = new int*[n];
    for (size_t i = 0; i < n; i++)
    {
        res[i] = new int[m];
    }
    return res;
}

using std::cin;
using std::cout;

int main()
{
    std::ifstream file("data.txt");
    if (file)
    {
        size_t n, m; // lines, columns
        file >> n >> m;
        int** arr = memory_alloc(n, m);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                file>>arr[i][j];
            }
        }
        auto cmp = [](int a, int b) {return a < b; };
        int* result = separation(arr, n, m, cmp);

        for (size_t i = 0; i < n*m; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }
    else
        cout << "this file wasn`t find\n";
}

