// Console App To Kill a Device

#include <iostream>
#include <thread>
#include <vector>

// Stress test function
void stressTestFunction() {
    // Example: Find and print prime numbers in a range
    for (long long num = 1; num < 1000000; num++) { // You can adjust the range as needed
        bool prime = true;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime && num > 1) { // Check if the number is prime and greater than 1
            std::cout << num << " "; // Print the prime number followed by a space
        }
    }
    std::cout << std::endl; // Print a newline at the end of the sequence
}

int main() {
    const int threadCount = 10; // You can adjust the number of threads

    // Create a vector to hold threads
    std::vector<std::thread> threads;

    // Launch multiple threads running the stress test function
    for (int i = 0; i < threadCount; ++i) {
        threads.emplace_back(stressTestFunction);
    }

    // Wait for all threads to complete
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Stress test completed." << std::endl;

    return 0;
}
