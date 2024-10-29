#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap
{
private:
    std::vector<int> heap;

    // Helper functions to get parent and child indices
    int getParentIndex(int i) { return (i - 1) / 2; }
    int getLeftChildIndex(int i) { return 2 * i + 1; }
    int getRightChildIndex(int i) { return 2 * i + 2; }

    // Heapify up to maintain the min-heap property after insertion
    void heapifyUp(int index)
    {
        while (index > 0 && heap[getParentIndex(index)] > heap[index])
        {
            std::swap(heap[getParentIndex(index)], heap[index]);
            index = getParentIndex(index);
        }
    }

    // Heapify down to maintain the min-heap property after extraction
    void heapifyDown(int index)
    {
        int smallest = index;
        int leftChild = getLeftChildIndex(index);
        int rightChild = getRightChildIndex(index);

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index)
        {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Get the minimum element without removing it
    int getMin()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Heap is empty.");
        }
        return heap[0];
    }

    // Remove and return the minimum element
    int extractMin()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Heap is empty.");
        }

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
        {
            heapifyDown(0);
        }

        return minValue;
    }

    // Check if the heap is empty
    bool isEmpty() const
    {
        return heap.empty();
    }
};

// Example usage
int main()
{
    MinHeap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(7);

    std::cout << "Current minimum: " << heap.getMin() << std::endl;

    std::cout << "Extracted minimum: " << heap.extractMin() << std::endl;
    std::cout << "Current minimum: " << heap.getMin() << std::endl;

    return 0;
}