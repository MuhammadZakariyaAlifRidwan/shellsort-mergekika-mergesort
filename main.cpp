#include <iostream>

using namespace std;

void printdata(int data[], int size)
{
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void shellsort(int data[], int size)
{
    int h = 1;

    while (h < size / 3)
        h = 3 * h + 1;

    while (h > 0)
    {
        for (int luar = h; luar < size; luar++)
        {
            int temp = data[luar];
            int dalam = luar;

            while ((dalam > h - 1) && (data[dalam - h] >= temp))
            {
                data[dalam] = data[dalam - h];
                dalam = dalam - h;
            }
            data[dalam] = temp;
        }
        h = (h - 1) / 3;
    }
}

void merge(int data[], int poskiri, int poskanan, int akhirkanan)
{
    int temp[akhirkanan - poskiri + 1];
    int akhirkiri = poskanan - 1;
    int postemp = poskiri;
    int jumelemen = akhirkanan - poskiri + 1;

    while ((poskiri <= akhirkiri) && (poskanan <= akhirkanan))
    {
        if (data[poskiri] <= data[poskanan])
        {
            temp[postemp - poskiri] = data[poskiri];
            poskiri++;
        }
        else
        {
            temp[postemp - poskiri] = data[poskanan];
            poskanan++;
        }
        postemp++;
    }

    while (poskiri <= akhirkiri)
    {
        temp[postemp - poskiri] = data[poskiri];
        poskiri++;
        postemp++;
    }

    while (poskanan <= akhirkanan)
    {
        temp[postemp - poskiri] = data[poskanan];
        poskanan++;
        postemp++;
    }

    for (int j = 0; j < jumelemen; j++)
    {
        data[akhirkanan] = temp[akhirkanan - poskiri];
        akhirkanan--;
    }
}

void mergesort(int data[], int kiri, int kanan)
{
    if (kiri == kanan)
        return;

    int tengah = (kiri + kanan) / 2;

    mergesort(data, kiri, tengah);
    mergesort(data, tengah + 1, kanan);

    merge(data, kiri, tengah + 1, kanan);
}

int partition(int data[], int kiri, int kanan)
{
    int pivot = data[kanan];
    int i = kiri - 1;

    for (int j = kiri; j < kanan; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[kanan]);
    return i + 1;
}

void quicksort(int data[], int kiri, int kanan)
{
    if (kiri < kanan)
    {
        int pivot = partition(data, kiri, kanan);
        quicksort(data, kiri, pivot - 1);
        quicksort(data, pivot + 1, kanan);
    }
}

int main()
{
    int size;

    cout << "Masukkan jumlah data: ";
    cin >> size;

    int *data = new int[size];

    cout << "Masukkan data: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    cout << "Data asal: " << endl;
    printdata(data, size);

    int choice;
    cout << "\nMenu Sorting:\n";
    cout << "1. Shell Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Quick Sort\n";
    cout << "Pilih metode sorting: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nProses Sorting Shell Sort:\n";
        shellsort(data, size);
        break;
    case 2:
        cout << "\nProses Sorting Merge Sort:\n";
        mergesort(data, 0, size - 1);
        break;
    case 3:
        cout << "\nProses Sorting Quick Sort:\n";
        quicksort(data, 0, size - 1);
        break;
    default:
        cout << "Pilihan tidak valid.\n";
        return 0;
    }

    cout << "\nData terurut:\n";
    printdata(data, size);

    delete[] data;
    return 0;
}
