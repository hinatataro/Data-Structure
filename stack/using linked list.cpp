#include <iostream>
class StackList;

class StackNode{
private:
    int data;
    StackNode *next;
public:
    StackNode():data(0){
        next = 0;
    }
    StackNode(int x):data(x){
        next = 0;
    }
    StackNode(int x, StackNode *nextNode):data(x),next(nextNode){};
    friend class StackList;
};

class StackList{
private:
    StackNode *top;     // remember the address of top element 
    int size;           // number of elements in Stack
public:                 
    StackList():size(0),top(0){};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackList::Push(int x){

    if (IsEmpty()) {
        top = new StackNode(x);
        size++;
        return;
    }

    StackNode *newnode = new StackNode(x);  // 這行代碼創建了一個新的 StackNode 對象，數據部分 data 被初始化為 x，next 被初始化為 nullptr（或 0）。
    newnode->next = top;                    // 這行代碼將新節點的 next 指標設置為當前的 top。也就是說，新節點的 next 現在指向了原來的棧頂節點。這樣做的目的是保持鏈接，確保新的棧頂節點連接到原來的節點上。
    top = newnode;                          // 這行代碼將 top 更新為新節點，這樣新節點就成為了新的棧頂。
    size++;
}

void StackList::Pop(){

    if (IsEmpty()) {
        std::cout << "Stack is empty.\n";
        return;
    }

    StackNode *deletenode = top;  // 將 top 指向的節點賦值給 deletenode。這一步是為了保存即將刪除的節點的指標，以便稍後釋放其內存空間。
    top = top->next;              // 將 top 指向原來 top 節點的下一個節點。這樣做是為了將棧頂指標移到下一個節點，從而從棧中移除了原來的棧頂節點。
    delete deletenode;            // 使用 delete 關鍵字釋放 deletenode 指向的節點所佔用的內存空間。這一步是真正從內存中刪除這個節點，以防止內存泄漏。
    deletenode = 0;               // 將 deletenode 指標設置為空指針（nullptr）。這一步是為了確保 deletenode 不再指向任何有效的內存位置，避免潛在的指標錯誤。
    size--;
}

bool StackList::IsEmpty(){

    return (size == 0);     // if size==0, return true
}

int StackList::Top(){

    if (IsEmpty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }
    return top->data;
}

int StackList::getSize(){

    return size;
}

int main(){

    StackList s;
    s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;        
    s.Push(15);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;         
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;          
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;

    return 0;
}
