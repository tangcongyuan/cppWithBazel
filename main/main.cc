#include <thread>
#include <mutex>
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "You're in project: cppWithBazel" << std::endl;

    std::mutex mu;

    std::thread t([&mu] () {
        std::lock_guard<std::mutex> lk(mu);
        std::cout << "Inside thread: " << std::this_thread::get_id() << std::endl;
    });

    for(int i = 0; i < 100; i++) {
        std::lock_guard<std::mutex> lk(mu);
        std::cout << "Inside thread: " << std::this_thread::get_id() << std::endl;
    }

    t.join();

    return 0;
}
