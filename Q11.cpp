Q-11 sum of n numbers

#include <iostream>
#include <pthread.h>
#include <vector>

// Structure to hold the data for each thread
struct ThreadData {
    std::vector<int> numbers;
    int sum;
};

// Function to calculate the sum of a sublist
void* sumSublist(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    int sum = 0;
    for (int num : data->numbers) {
        sum += num;
    }
    data->sum = sum;
    pthread_exit(nullptr);
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Generate the list of numbers
    std::vector<int> numbers(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    // Divide the list into two sublists
    int sublistSize = n / 2;
    std::vector<int> sublist1(numbers.begin(), numbers.begin() + sublistSize);
    std::vector<int> sublist2(numbers.begin() + sublistSize, numbers.end());

    // Create the thread data structures
    ThreadData data1{sublist1, 0};
    ThreadData data2{sublist2, 0};

    // Create the threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, sumSublist, &data1);
    pthread_create(&thread2, nullptr, sumSublist, &data2);

    // Wait for the threads to finish
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    // Calculate the final sum
    int sum = data1.sum + data2.sum;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
