#include <iostream>
#include <algorithm>

using namespace std;

int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    // YOUR CODE HERE
    //In a fast food restaurant, a customer is served by following the first-come, first-served rule. The manager wants to minimize the total waiting time of his customers. So he gets to decide who is served first, regardless of how sooner or later a person comes.
    //Different kinds of food take different amounts of time to cook. And he can't cook food for two customers at the same time, which means when he start cooking for customer A, he has to finish A 's order before cooking for customer B. For example, if there are 3 customers and they come at time 0, 1, 2 respectively, the time needed to cook their food is 3, 9, 6 respectively. If the manager uses first-come, first-served rule to serve his customer, the total waiting time will be 3 + 11 + 16 = 30. In case the manager serves his customer in order 1, 3, 2, the total waiting time will be 3 + 7 + 17 = 27.
    //Note: The manager does not know about the future orders.
    //In this question, you should implement function minWaitingTime to help the customer find minimum total waiting time to serve all his customers. You are also encouraged to use data structure Heap to complete this question. You can use your own code of Heap, or use functions related to Heap in library <algorithm>.

    int total = 0;
    int current = 0;


    return total;
}