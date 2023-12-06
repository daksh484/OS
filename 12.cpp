#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

void firstFit(vector<MemoryBlock> &memory, int size) {
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= size) {
            memory[i].allocated = true;
            cout << "Memory block allocated successfully. Block ID: " << memory[i].id << endl;
            return;
        }
    }
    cout << "No suitable memory block found for allocation." << endl;
}

void bestFit(vector<MemoryBlock> &memory, int size) {
    int minSize = INT_MAX;
    int index = -1;

    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size < minSize) {
            minSize = memory[i].size;
            index = i;
        }
    }

    if (index != -1) {
        memory[index].allocated = true;
        cout << "Memory block allocated successfully. Block ID: " << memory[index].id << endl;
    } else {
        cout << "No suitable memory block found for allocation." << endl;
    }
}

void worstFit(vector<MemoryBlock> &memory, int size) {
    int maxSize = 0;
    int index = -1;

    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size > maxSize) {
            maxSize = memory[i].size;
            index = i;
        }
    }

    if (index != -1) {
        memory[index].allocated = true;
        cout << "Memory block allocated successfully. Block ID: " << memory[index].id << endl;
    } else {
        cout << "No suitable memory block found for allocation." << endl;
    }
}

void deallocateMemory(vector<MemoryBlock> &memory, int blockId) {
    for (int i = 0; i < memory.size(); ++i) {
        if (memory[i].id == blockId && memory[i].allocated) {
            memory[i].allocated = false;
            cout << "Memory block deallocated successfully. Block ID: " << blockId << endl;
            return;
        }
    }
    cout << "Memory block not found or already deallocated." << endl;
}

int main() {
    vector<MemoryBlock> memory = {
        {1, 100, false},
        {2, 200, false},
        {3, 150, false},
        {4, 300, false}
    };

    int choice, size, blockId;
    while (true) {
        cout << "Memory Allocation Strategies Menu:" << endl;
        cout << "1. First Fit Allocation" << endl;
        cout << "2. Best Fit Allocation" << endl;
        cout << "3. Worst Fit Allocation" << endl;
        cout << "4. Deallocate Memory Block" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter memory block size for allocation: ";
                cin >> size;
                firstFit(memory, size);
                break;
            case 2:
                cout << "Enter memory block size for allocation: ";
                cin >> size;
                bestFit(memory, size);
                break;
            case 3:
                cout << "Enter memory block size for allocation: ";
                cin >> size;
                worstFit(memory, size);
                break;
            case 4:
                cout << "Enter memory block ID for deallocation: ";
                cin >> blockId;
                deallocateMemory(memory, blockId);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
