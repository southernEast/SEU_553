#include <iostream>
#include <vector>
using namespace std;

// 插入排序
void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && tmp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}

// 插入排序的递归实现
void insertSort(int a[], int n)
{
    if (n == 0)
        return;
    insertSort(a, n - 1);
    insert(a, n);
}

void insert(int a[], int n)
{
    int temp = a[n];
    int j = n - 1;
    while (j >= 0 && temp < a[j])
    {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = temp;
}

// 二分插入排序
void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int tmp = a[i];
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] < tmp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        for (int k = i - 1; k >= high + 1; ++k)
        {
            a[k + 1] = a[k];
        }
        a[high + 1] = tmp;
    }
}

// 希尔排序(步长为dk的插入排序)
void ShellSort(int a[], int n)
{
    for (int dk = n / 2; dk >= 1; dk = dk / 2)
    {
        for (int i = dk + 1; i <= n; ++i)
        {
            int tmp = a[i];
            int j = i - dk;
            while (j >= 0 && tmp < a[j])
            {
                a[j + dk] = a[j];
                j = j - dk;
            }
            a[j + dk] = tmp;
        }
    }
}

// 冒泡排序
void bubble_sort(int *a, int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i + 1])
            {
                flag = true;
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
}

// 快速排序
int parti(int a[], int low, int high)
{
    int p = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= p)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= p)
            low++;
        a[high] = a[low];
    }
    a[low] = p;
    return low;
}

void QuickSort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int p = parti(a, low, high);
    QuickSort(a, low, p - 1);
    QuickSort(a, p + 1, high);
}

// 冒泡排序 假设数组的大小是 n + 1，冒泡排序从数组下标 1 开始
void bubble_sort(int *a, int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false; // 标记当前回合是否有更改
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i + 1])
            {
                flag = true;
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
}

// 归并排序
void merge(const int *aBegin, const int *aEnd, const int *bBegin, const int *bEnd, int *c)
{
    while (aBegin != aEnd && bBegin != bEnd)
    {
        if (*bBegin < *aBegin)
        {
            *c = *bBegin;
            ++bBegin;
        }
        else
        {
            *c = *aBegin;
            ++aBegin;
        }
        ++c;
    }
    for (; aBegin != aEnd; ++aBegin, ++c)
        *c = *aBegin;
    for (; bBegin != bEnd; ++bBegin, ++c)
        *c = *bBegin;
}

void merge_sort(int *a, int l, int r)
{
    if (r - l <= 1)
        return;
    // 分解
    int mid = l + ((r - l) >> 1);
    merge_sort(a, l, mid), merge_sort(a, mid, r);
    // 合并
    int tmp[1024] = {};                             // 请结合实际情况设置 tmp 数组的长度（与 a 相同），或使用
                                                    // vector；先将合并的结果放在 tmp 里，再返回到数组 a
    merge(a + l, a + mid, a + mid, a + r, tmp + l); // pointer-style merge
    for (int i = l; i < r; ++i)
        a[i] = tmp[i];
}

// 堆排序
void sift_down(int arr[], int start, int end)
{
    // 计算父结点和子结点的下标
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end)
    { // 子结点下标在范围内才做比较
        // 先比较两个子结点大小，选择最大的
        if (child + 1 <= end && arr[child] < arr[child + 1])
            child++;
        // 如果父结点比子结点大，代表调整完毕，直接跳出函数
        if (arr[parent] >= arr[child])
            return;
        else
        { // 否则交换父子内容，子结点再和孙结点比较
            swap(arr[parent], arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len)
{
    // 从最后一个节点的父节点开始 sift down 以完成堆化 (heapify)
    for (int i = (len - 1 - 1) / 2; i >= 0; i--)
        sift_down(arr, i, len - 1);
    // 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        sift_down(arr, 0, i - 1);
    }
}

// 桶排序
const int N = 100010;

int n, w, a[N];
vector<int> bucket[N];

void insertion_sort(vector<int> &A)
{
    for (int i = 1; i < A.size(); ++i)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

void bucket_sort()
{
    int bucket_size = w / n + 1;
    for (int i = 0; i < n; ++i)
    {
        bucket[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        bucket[a[i] / bucket_size].push_back(a[i]);
    }
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        insertion_sort(bucket[i]);
        for (int j = 0; j < bucket[i].size(); ++j)
        {
            a[++p] = bucket[i][j];
        }
    }
}
