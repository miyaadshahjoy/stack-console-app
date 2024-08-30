#include <iostream>
#include <vector>
using namespace std;

class Stack{


public:
    vector <int> stackContainer;
    vector <int> sortedStack;
    int stackTop;
    Stack(){
        stackTop = -1;
    }
    [[nodiscard]] bool stackEmpty() const;
    void push(int element);
    int pop();
    int peek();
    void reverseStack();
    int maxElement();
    int minElement();
    void displayStack();
};
bool Stack :: stackEmpty() const {
    if(stackTop == -1) return true;
    return false;
}
void Stack :: push(int element){
    stackContainer.push_back(element);
    if(!sortedStack.empty()){
        int i = 0;
        while(i < sortedStack.size()){
            if(element <= sortedStack[i]) break;
            i++;
        }
        for(int n = sortedStack.size() - 1; n >= i; n--){

            if(n == sortedStack.size() - 1)
                sortedStack.push_back(sortedStack[n]);
            else sortedStack[n + 1] = sortedStack[n];
        }
        if(i == sortedStack.size())
            sortedStack.push_back(element);
        else sortedStack[i] = element;
    } else sortedStack.push_back(element);
    ++stackTop;
}
int Stack :: pop(){
    int poppedElement = -1;
    if(!stackEmpty()){
        poppedElement = stackContainer[stackTop];
        stackContainer.pop_back();
        --stackTop;

        int i = 0;
        while(i < sortedStack.size()){
            if(poppedElement == sortedStack[i]) break;
            i++;
        }
        for(int n = i; n < sortedStack.size(); n++){
            sortedStack[n] = sortedStack[n + 1];
        }
        sortedStack.pop_back();

    }
    return poppedElement;
}
int Stack :: peek(){
    if(!stackEmpty()) return stackContainer[stackTop];
    return -1;
}
void Stack :: reverseStack(){
    int length = (int) stackContainer.size();

    for(int i = 0, j = length - 1; i <= length / 2; i++, j--){
        swap(stackContainer[i], stackContainer[j]);
    }
}

int Stack :: maxElement() {
    if(!stackEmpty())
        return sortedStack[stackTop];
    return -1;
}
int Stack :: minElement() {
    if(!stackEmpty())
        return sortedStack[0];
    return -1;
}
void Stack :: displayStack(){
    cout<<"The stack : ";
    for(int i : stackContainer)
        cout<<i<<" ";
    cout<<endl;
}
int main(){
//
//    ob.push(5);
//    ob.push(7);
//    ob.push(11);
//    ob.displayStack();
//    ob.reverseStack();
//    ob.displayStack();
    Stack ob;
    main:
    cout<<"---------------MENU---------------"<<endl;
    cout << "[1] create a stack" << endl;
    cout << "[2] push an element" << endl;
    cout << "[3] pop the top element" << endl;
    cout << "[4] reverse the stack" << endl;
    cout << "[5] get minimum element of the stack" << endl;
    cout << "[6] get maximum element of the stack" << endl;
    cout << "[7] get the top most element of the stack" << endl;
    cout << "[8] display the stack" << endl;


    int choice;
    int el;

    cout << "Enter your choice : ";
    cin >> choice;
    cout << endl;

    switch (choice){

        case 1:
            ob = Stack();
            cout << "A stack is created." << endl;
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;

        case 2:
            cout << "Enter an element to push : ";
            cin >> el;
            ob.push(el);
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        case 3:
            cout << "The deleted element : " << ob.pop() << endl;
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        case 4:
            ob.reverseStack();
            cout << "The stack elements are reversed." << endl;
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        case 5:
            cout << "The minimum element of the stack : " << ob.minElement() << endl;
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        case 6:
            cout << "The maximum element of the stack : " << ob.maxElement() << endl;
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        case 7:
            cout << "The top element of the stack is : " << ob.peek() << endl;
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        case 8:
            ob.displayStack();
            cout << "Enter [1] to return to the main menu or press [0] to exit : ";
            cin >> choice;
            if(choice == 1)
                goto main;
            else break;
        default:
            break;
    }


}