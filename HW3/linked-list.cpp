#include <iostream>
using namespace std;

// ساختار یک گره در لیست پیوندی
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// تابع برای اضافه کردن یک گره به انتهای لیست
void append(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
}

// تابع برای جابه‌جایی جفت‌های مجاور در لیست
Node* swapPairs(Node* head) {
    if (!head || !head->next) return head; // اگر لیست خالی باشد یا تنها یک گره داشته باشد

    Node* newHead = head->next; // گره دوم به عنوان سر جدید لیست

    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->next) {
        Node* nextPair = curr->next->next; // اشاره به جفت بعدی
        Node* second = curr->next;

        // جابه‌جایی
        second->next = curr;
        curr->next = nextPair;
        if (prev) {
            prev->next = second;
        }

        // به‌روز‌رسانی اشاره‌گر‌ها برای جفت بعدی
        prev = curr;
        curr = nextPair;
    }

    return newHead;
}

// تابع برای چاپ لیست پیوندی
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        append(head, val);
    }

    head = swapPairs(head);

    printList(head);

    return 0;
}
