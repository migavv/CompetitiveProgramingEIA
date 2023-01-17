
#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

int main() {
    int n, type, x; //type: Indicates if throw (1) or take (2) from the bag.
                    //x: integer to be thrown or taken.
    bool isStack, isQueue, isPQueue;
    while(scanf("%d", &n), n != EOF) {
        isStack = true;
        isQueue = true;
        isPQueue = true;
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> priorityQueue;
        while(n--) {
            scanf("%d %d", &type, &x);
            if(type == 1) { //Throw operation
                stack.push(x);
                queue.push(x);
                priorityQueue.push(x);
            } else { //Take operation
                if(isStack && !stack.empty()) { //Check if bag works as a stack would.
                    isStack = stack.top() == x;
                    stack.pop();
                } else isStack = false;
                if(isQueue && !queue.empty()) { //Check if bag works as a queue would.
                    isQueue = queue.front() == x;
                    queue.pop();
                } else isQueue = false;
                if(isPQueue && !priorityQueue.empty()) { //Check if bag works as a priority queue.
                    isPQueue = priorityQueue.top() == x;
                    priorityQueue.pop();
                } else isPQueue = false;
            }
        }
        if(isStack + isQueue + isPQueue > 1) //If bag works as more than one container
            printf("not sure\n");
        else if(isStack) //If it works as a stack
            printf("stack\n");
        else if(isQueue) //If it works as queue
            printf("queue\n");
        else if(isPQueue) //If it works as a priority queue
            printf("priority queue\n");
        else printf("impossible\n");
    }
}