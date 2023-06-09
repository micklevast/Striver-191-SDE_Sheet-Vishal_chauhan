#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// #include <thread>

// // Function 1 to be executed in a separate thread
// void function1() {
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Function 1 executing\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));
//     }
// }

// // Function 2 to be executed in a separate thread
// void function2() {
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Function 2 executing\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(750));
//     }
// }

// // Function 3 to be executed in a separate thread
// void function3() {
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Function 3 executing\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     }
// }

// int main() {
//     // Create threads for each function
//     std::thread t1(function1);
//     std::thread t2(function2);
//     std::thread t3(function3);

//     // Perform some task in the main thread
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Main function executing\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));
//     }

//     // Join the threads to the main thread
//     t1.join();
//     t2.join();
//     t3.join();

//     return 0;
// }

// int main()
// {
//         const char* concatStr = "hello" "world";
//         string str="radhe" " - krishna";
//         cout<<concatStr<< " || "<<str<<endl;
//         unsigned char u=255;
//         signed char s=-1;           // char might be either
//         unsigned long x =0xffffffffL;   

//         cout<<"u:"<<u<<"  s:"<<s<<"  x:"<<x<<endl;
//         std::string strr = R"(Hello World)"; 
//         cout<<" strr:"<<strr<<endl;
// }

// #include <iostream>

// class MyClass {
// public:
//     static int x; // Static variable declaration

//     void printX() {
//         std::cout << "x = " << x << std::endl;
//     }
// };

// int MyClass::x = 0; // Static variable definition and initialization

// int main() {
//     MyClass obj1;
//     MyClass obj2;

//     obj1.x = 5;
//     obj2.x = 10;

//     obj1.printX(); // Output: x = 10
//     obj2.printX(); // Output: x = 10

//     return 0;
// }

class MyClass {
public:
    int operator+(int x, int y) {
        return x + y;
    }
};

int main(){
    MyClass obj;
    int result = obj.operator+(5, 3); // result = 8
    cout<<"res:"<<result<<endl;
}


