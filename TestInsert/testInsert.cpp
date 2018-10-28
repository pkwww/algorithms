#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>
using namespace std;
static size_t size;
static size_t range;

void gen_int()
{
    ofstream fout("randInt");
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        fout << rand() % range << endl;
    }
}

void read_int(vector<int>& rand_int)
{
    rand_int.reserve(size + 1);

    int x = 0;
    ifstream fin("randInt");

    if (!fin.is_open()) {
        cerr << "cannot open file" << endl;
        return;
    }

    while(!fin.eof()) {
        fin >> x;
        rand_int.push_back(x);
    }
    rand_int.pop_back();
}

// ==================seperate========================

struct Node
{
    int data;
    Node* next;
    Node(): data(-1), next(nullptr) {};
    Node(int _data): data(_data), next(nullptr) {};
};

void listDelAll(Node*& head)
{
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    head = nullptr;
}

void printList(Node* head)
{
    for (Node* p = head; p != nullptr; p = p->next) {
        cout << p->data << endl;
    }
}

void listInsertSingleStar(Node*& head, int data)
{
    if (head == nullptr) {
        head = new Node(data);
        return;
    } else if (head->next == nullptr) {
        if (head->data >= data) {
            Node* tmp = new Node(data);
            tmp->next = head;
            head = tmp;
        } else {
            head->next = new Node(data);
        }
        return;
    } else {
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data >= data) {
                Node* tmp = new Node(data);
                tmp->next = curr;
                prev->next = tmp;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new Node(data);
    }
}

void listInsertTwoStar(Node** head, int data)
{
    Node** curr = nullptr;
    for (curr = head; *curr != nullptr;) {
        Node* entry = *curr;
        if (entry->data >= data) {
            Node* tmp = new Node(data);
            tmp->next = entry;
            *curr = tmp;
            return;
        } else {
            curr = &(entry->next);
        }
    }
    *curr = new Node(data);
}

double testListInsertSingleStar(Node*& head)
{
    vector<int> unsort;
    read_int(unsort);

    auto begin = clock();

    for (auto i : unsort) {
        listInsertSingleStar(head, i);
    }

    auto end = clock();
    return double(end - begin) / CLOCKS_PER_SEC;
}

double testListInsertTwoStar(Node*& head)
{
    vector<int> unsort;
    read_int(unsort);

    auto begin = clock();

    for (auto i : unsort) {
        listInsertTwoStar(&head, i);
    }

    auto end = clock();
    return double(end - begin) / CLOCKS_PER_SEC;
}

// ================seperate==================

struct ArrT {
    int* arr;
    size_t count;
    ArrT(): count(0)
    {
        arr = new int[size];
    }
    ~ArrT()
    {
        delete[] arr;
    }
};

void arrInsert(ArrT& arr, int data)
{
    int i = 0;
    for (i = 0; i < arr.count; ++i) {
        if (arr.arr[i] >= data) {
            for (int j = arr.count - 1; j >= i; --j) {
                arr.arr[j+1] = arr.arr[j];
            }
            arr.arr[i] = data;
            arr.count++;
            return;
        }
    }
    if (i == arr.count) {
        arr.arr[i] = data;
        arr.count++;
    }
}

double testArrInsert(ArrT& arr)
{
    vector<int> unsort;
    read_int(unsort);
    auto begin = clock();

    for (auto i : unsort) {
        arrInsert(arr, i);
    }

    auto end = clock();
    return double(end - begin) / CLOCKS_PER_SEC;
}

//===============================seperate============================

int main(int argc, char *argv[])
{
    size = atoi(argv[1]);
    range = size * 10;

    Node* head1 = nullptr;
    double double_star_elapsed = testListInsertTwoStar(head1);
    cout << "double star list: "  << double_star_elapsed << endl;
    listDelAll(head1);

    Node* head2 = nullptr;
    double single_star_elapsed = testListInsertSingleStar(head2);
    cout << "single star list: " << single_star_elapsed << endl;
    listDelAll(head2);

    ArrT arr;
    double arr_elapsed_sec = testArrInsert(arr);
    cout << "arr: " << arr_elapsed_sec << endl;
    return 0;
}
