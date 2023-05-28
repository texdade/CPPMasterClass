// Threads that waste CPU cycles

#include <thread>
#include <vector>
#include <chrono>
#include <unistd.h>
#include <iostream>

// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
    std::cout << "CPU Waster Process ID: " << getpid() << std::endl;
    std::cout << "CPU Waster Thread ID: " << std::this_thread::get_id() << std::endl;
    while(true) continue;
}

int main() {
    std::cout << "Main Process ID: " << getpid() << std::endl;
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;
    
    const uint32_t processor_count = std::thread::hardware_concurrency();
    uint32_t thread_count = 0;
    
    std::cout << "This machine supports concurrency with " << processor_count << " processors" << std::endl;
    std::cout << "Specify the number of cores to keep busy:" << std::endl;
    std::cin >> thread_count;

    if(thread_count > processor_count) {
        std::cout << "You have specified more threads than processors. Defaulting to maximum." << std::endl;
        thread_count = processor_count;
    }

    std::vector<std::thread> threads;

    for(uint32_t i = 0; i < thread_count; ++i) {
        threads.push_back(std::thread(cpu_waster));
    }

    while(true) { // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}