#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    float cgpa;

    Student() {}

    Student(string n, int r, float c)
    {
        name = n;
        roll = r;
        cgpa = c;
    }

    bool operator<(const Student &other) const
    {
        return this->cgpa < other.cgpa;
    }

    bool operator>(const Student &other) const
    {
        return this->cgpa > other.cgpa;
    }
};

template <typename T>
class heap
{
public:
    T *data;
    int height;
    int noofelements;
    int sizee;

    heap(int h)
    {
        height = h;
        noofelements = 0;
        sizee = pow(2, height) - 1;
        data = new T[sizee];
    }

    void insert_heapifydown(T val)
    {
        if (noofelements < sizee)
        {
            data[noofelements] = val;
            noofelements++;
        }

        int i = noofelements - 1;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (data[i] < data[parent])
            {
                swap(data[i], data[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapifydown(int index)
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int minimum = index;

            if (left < noofelements && data[left] < data[minimum])
                minimum = left;
            if (right < noofelements && data[right] < data[minimum])
                minimum = right;

            if (minimum != index)
            {
                swap(data[index], data[minimum]);
                index = minimum;
            }
            else
                break;
        }
    }

    void heapifyup(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (data[i] < data[parent])
            {
                swap(data[i], data[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    int search(T value)
    {
        for (int i = 0; i < noofelements; i++)
        {
            if (data[i].roll == value.roll) // compare roll
                return i;
        }
        return -1;
    }

    void delete_element(T value)
    {
        if (noofelements == 0)
            return;

        int index = search(value);
        if (index == -1)
            return;

        swap(data[index], data[noofelements - 1]);
        noofelements--;

        if (index < noofelements)
        {
            heapifydown(index);
            heapifyup(index);
        }
    }

    void display()
    {
        for (int i = 0; i < noofelements; i++)
        {
            cout << data[i].name << " | Roll: " << data[i].roll
                 << " | CGPA: " << data[i].cgpa << endl;
        }
    }
};


int main()
{
    heap<Student> h(4);

    h.insert_heapifydown(Student("Ali", 101, 3.5));
    h.insert_heapifydown(Student("Bilal", 102, 2.9));
    h.insert_heapifydown(Student("Hamza", 103, 3.9));
    h.insert_heapifydown(Student("Usman", 104, 3.2));

    cout << "Heap (based on CGPA):\n";
    h.display();
    cout << endl;

    cout << "Deleting roll 103...\n";
    h.delete_element(Student("X", 103, 0)); // only roll matters
    h.display();

    return 0;
}
