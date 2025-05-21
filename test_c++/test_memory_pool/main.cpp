#include <iostream>
#include <vector>
#include <cassert>

// MemoryPool Class
class MemoryPool {
public:
    // Constructor: Initialize the pool with a specific block size and total size
    MemoryPool(size_t blockSize, size_t blockCount) 
        : m_blockSize(blockSize), m_blockCount(blockCount) {
        // Allocate memory for the pool (continuous memory)
        m_pool = ::operator new(blockSize * blockCount);
        
        // Set up free list to manage available memory blocks
        m_freeList.reserve(blockCount);
        for (size_t i = 0; i < blockCount; ++i) {
            m_freeList.push_back(static_cast<char*>(m_pool) + i * blockSize);
        }
    }

    // Destructor: Clean up the memory pool
    ~MemoryPool() {
        ::operator delete(m_pool);
    }

    // Allocate a block of memory from the pool
    void* allocate() {
        if (m_freeList.empty()) {
            std::cerr << "Memory pool is out of memory!" << std::endl;
            return nullptr; // No free memory left in pool
        }

        // Pop the first free block from the free list
        void* block = m_freeList.back();
        m_freeList.pop_back();
        return block;
    }

    // Deallocate a block of memory back into the pool
    void deallocate(void* ptr) {
        // Add the block back into the free list
        m_freeList.push_back(ptr);
    }

private:
    size_t m_blockSize;      // Size of each block in the pool
    size_t m_blockCount;     // Total number of blocks in the pool
    void* m_pool;            // Pointer to the memory pool
    std::vector<void*> m_freeList; // Free list for managing available blocks
};

class MyClass {
public:
    MyClass(int value) : m_value(value) {}
    void print() { std::cout << "MyClass value: " << m_value << std::endl; }
private:
    int m_value;
};

int main() {
    // Create a memory pool to manage 10 blocks of memory, each 256 bytes
    MemoryPool pool(sizeof(MyClass), 10);

    // Allocate a MyClass object from the pool
    MyClass* obj1 = new(pool.allocate()) MyClass(10);
    obj1->print();

    // Allocate another MyClass object
    MyClass* obj2 = new(pool.allocate()) MyClass(20);
    obj2->print();

    // Deallocate the first object back into the pool
    obj1->~MyClass();  // Manually call destructor
    pool.deallocate(obj1);

    // Deallocate the second object
    obj2->~MyClass();  // Manually call destructor
    pool.deallocate(obj2);

    return 0;
}
