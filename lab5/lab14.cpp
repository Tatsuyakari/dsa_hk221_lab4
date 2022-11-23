#include <iostream>
using namespace std;
class PrinterQueue
{
    // your attributes
    int *queue;
    int size;
    int front;
    int rear;

public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        if (size == 0)
        {
            queue[rear] = priority;
            rear++;
            size++;
        }
        else
        {
            int i = rear - 1;
            while (i >= 0 && queue[i] > priority)
            {
                queue[i + 1] = queue[i];
                i--;
            }
            queue[i + 1] = priority;
            rear++;
            size++;
        }
        
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        for (int i = front; i < rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    PrinterQueue *myPrinterQueue = new PrinterQueue();
    myPrinterQueue->addNewRequest(1, "hello.pdf");
    myPrinterQueue->addNewRequest(2, "goodbye.pdf");
    myPrinterQueue->addNewRequest(2, "goodnight.pdf");
    myPrinterQueue->print();
    myPrinterQueue->print();
    myPrinterQueue->print();
}