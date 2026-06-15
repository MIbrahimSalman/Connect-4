// #include "raylib.h"
// #include <iostream>
// #include <stdlib.h>
// #include <cmath>

// using namespace std;

// template<typename T>
// class Queue {
// private:
//     T* arr;
//     int capacity;
//     int front, rear, size, tempSize;

//     //Modulus function to calculate the index of the element and make the readability of the code better
//     int mod(int index) const {
//         return (index + capacity) % capacity;
//     }

//     //Function to resize the array when the capacity is full
//     void resize(int newCapacity) {
//         T* newArr = new T[newCapacity];
//         for (int i = 0; i < size; ++i) {
//             newArr[i] = arr[mod(front + i)];
//         }
//         delete[] arr;
//         arr = newArr;
//         capacity = newCapacity;
//         front = 0;
//         rear = size - 1;
//     }

// public:
//     //Constructor
//     Queue(int initCapacity = 5) : capacity(initCapacity), size(0), front(0), rear(-1), tempSize(0) {
//         arr = new T[capacity];
//     }

//     //Destructor
//     ~Queue() {
//         delete[] arr;
//     }

//     //Function to check if the queue is empty
//     bool isEmpty() const {
//         return size == 0;
//     }

//     //Function to get the size of the queue
//     int getTempSize() const {
//         return tempSize;
//     }

//     //Function to push an element into the queue
//     void push(const T& element) {
//         if (size == capacity) {
//             resize(capacity * 2);
//         }
//         rear = mod(rear + 1);
//         arr[rear] = element;
//         size++;
//         tempSize++;
//     }

//     //Function to pop an element from the queue
//     T pop() {
//         if (isEmpty()) {
//             throw runtime_error("Queue is empty");
//         }
//         T element = arr[front];
//         front = mod(front + 1);
//         size--;
//         return element;
//     }

//     //Function to get the top element of the queue
//     T top() const {
//         if (isEmpty()) {
//             throw runtime_error("Queue is empty");
//         }
//         return arr[front];
//     }

//     //Function to print the elements of the queue
//     void print() const {
//         if (isEmpty()) {
//             cout << "Queue is empty" << endl;
//             return;
//         }

//         cout << "Queue elements: ";
//         for (int i = 0; i < size; ++i) {
//             int index = mod(front + i);
//             cout << arr[index] << " ";
//         }
//         cout << endl;
//     }

//     //Function to remove the soldier from the circle
//     int customPop(int& start, int k) {
//         int count = 0;
//         int index = start;

//         while (count < k - 1) {
//             index = (index + 1) % capacity;
//             if (arr[index] != -1) count++;
//         }

//         cout << "Removing soldier at position: " << arr[index] << endl;
//         arr[index] = -1;

//         tempSize--;

//         do {
//             index = (index + 1) % capacity;
//         } while (arr[index] == -1);
//         return index;
//     }

//     //Function to calculate the next soldier to be removed
//     int calculateNextSoldier(int start, int k) {
//         int count = 0;
//         int index = start;

//         while (count < k - 1) {
//             index = (index + 1) % capacity;
//             if (arr[index] != -1) count++;
//         }

//         return index;
//     }

//     //Function to get the array of the queue
//     const T* getArray() const {
//         return arr;
//     }

//     //Function to get the capacity of the queue
//     int getCapacity() const {
//         return capacity;
//     }
// };

// //Function to draw the Josephus Circle (GUI)
// void DrawJosephusCircle(int n, const int* soldiers, int screenWidth, int screenHeight, int start, int next, int k, int totalSoldiers) {
//     float radius = screenHeight / 3;
//     float centerX = screenWidth / 2;
//     float centerY = screenHeight / 2;

//     DrawCircle(centerX, centerY, radius + 50, BLUE);

//     float angleStep = (2 * PI) / n;

//     for (int i = 0; i < n; i++) {
//         if (soldiers[i] == -1) continue;

//         float angle = i * angleStep;
//         float x = centerX + radius * cos(angle);
//         float y = centerY + radius * sin(angle);

//         if (i == start) DrawCircle(x, y, 30, GREEN);
//         else if (i == next) DrawCircle(x, y, 30, BROWN);
//         else DrawCircle(x, y, 30, WHITE);

//         DrawText(TextFormat("%d", soldiers[i]), x - 10, y - 10, 20, BLACK);
//     }

//     DrawCircle(30, 30, 10, GREEN);
//     DrawText("Start", 50, 20, 20, BLACK);

//     DrawCircle(30, 60, 10, BROWN);
//     DrawText("To Be Removed", 50, 50, 20, BLACK);

//     DrawCircle(screenWidth - 230, 30, 10, BLUE);
//     DrawText("JOSEPHUS CIRCLE", screenWidth - 210, 20, 20, BLACK);


//     DrawText(TextFormat("n = %d", totalSoldiers), centerX - 40, centerY - 20, 30, BLACK);
//     DrawText(TextFormat("k = %d", k), centerX - 40, centerY + 10, 30, BLACK);
// }

// int main() {
//     int n = 20, k = 3;
//     cout << "Enter the number of soldiers: ";
//     cin >> n;
//     cout << "Enter the value of k: ";
//     cin >> k;
//     Queue<int> soldiers(n);

//     for (int i = 1; i <= n; i++) soldiers.push(i);

//     srand(time(NULL));
//     int start = rand() % n;
//     int next = soldiers.calculateNextSoldier(start, k);

//     const int screenWidth = 800;
//     const int screenHeight = 600;

//     InitWindow(screenWidth, screenHeight, "Josephus Problem Visualization");
//     SetTargetFPS(60);

//     float lastUpdateTime = GetTime();
//     //Initializing the window
//     while (!WindowShouldClose()) {
//         BeginDrawing();
//         ClearBackground(RED);

//         DrawJosephusCircle(n, soldiers.getArray(), screenWidth, screenHeight, start, next, k, n);
//         EndDrawing();

//         if (soldiers.getTempSize() > 1 && GetTime() - lastUpdateTime >= 2.0) {
//             start = soldiers.customPop(start, k);
//             next = soldiers.calculateNextSoldier(start, k);
//             lastUpdateTime = GetTime();
//         }
//     }

//     CloseWindow();
//     return 0;
// }