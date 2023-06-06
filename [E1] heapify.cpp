#include <iostream>
using namespace std;

class ExamMarks {
    private:
    int *heap;
    int heapSize;

    public:
    ExamMarks(int* marksArr,int arr_size) {
        heapSize = arr_size;
        heap = new int[arr_size];

        for (auto i = 0; i < arr_size; i++)
        {
            heap[i] = marksArr[i];
        }
    }

    void buildMaxHeap() {
        for (auto i = (heapSize/2)-1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;

        if(leftChild < heapSize && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if(rightChild < heapSize && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if(index != largest) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void buildMinHeap() {
        for (int i = (heapSize/2) - 1; i >= 0; i--)
        {
            heapifyUp(i);
        }
    }

    void heapifyUp(int index) {
        int smallest = index;
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;

        if(leftChild < heapSize && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if(rightChild < heapSize && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if(index != smallest) {
            swap(heap[index],heap[smallest]);
            heapifyUp(smallest);
        }
    }

    int max() {
        return heap[0];
    }

    int min() {
        return heap[0];
    }
};


int main() {

    int choice,arrSize;
    cout << "Enter the size of the arr: "; cin >> arrSize;

    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    ExamMarks exam(arr,arrSize);

    do
    {
        cout << "\n1) Build Max Heap" << endl;
        cout << "2) Extract maximum" << endl;
        cout << "3) Build Min Heap" << endl;
        cout << "4) Extract minimum" << endl;
        cout << "5) Exit" << endl;

        cout << "Enter your choice: "; cin >> choice;

        switch (choice)
        {
        case 1:
            exam.buildMaxHeap();
            break;
        
        case 2:
            cout << "Maximum in the arr is: " << exam.max() << endl;
            break;
        
        case 3:
            exam.buildMinHeap();
            break;
        
        case 4:
            cout << "Maximum in the arr is: " << exam.min() << endl;
            break;
        
        case 5:
        cout << "Exit Successfully!" << endl;
            break;
        
        default:
        cout << "Invalid choice" << endl;
            break;
        }

    } while (choice != 5);
}
