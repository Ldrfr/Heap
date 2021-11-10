#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int i = 0;
//vector <int> max_root;

class Heap {
private:
    vector <int> heap_max;
    int i = 0;
public:
    int ExtractMax() {  // i должно менять значение 
        if (heap_max.size() == 2) {
            if (heap_max[0] < heap_max[1]) {
                int tmp = heap_max[1];
                heap_max.erase(heap_max.begin() + 1);
                --i;
                
                return tmp;
            }
            else {
                int tmp = heap_max[0];
                heap_max.erase(heap_max.begin());
                --i;
                
                return tmp;
            }
        }
        else {
            int tmp = heap_max[0];
            swap(heap_max[0], heap_max[heap_max.size() - 1]);
            heap_max.pop_back();
            SiftRootDown(0);
            --i;
            
            return tmp;
        }

    }
    void Insert(int& x) {
        heap_max.push_back(x);
        SiftUp(heap_max.size() - 1);
        ++i;
    }
    void SiftRootDown(int pos) { // просеивал корень вниз
        while (2 * pos + 1 < heap_max.size()) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int j = left;
            // если есть правая ветвь с бОльшим значением   
            if ((right < heap_max.size()) && heap_max[right] > heap_max[left]) { 
                j = right;
            }
            if (heap_max[pos] > heap_max[j]) { // если ниже меньшие завершаем цикл
                break;
            }
            swap(heap_max[pos], heap_max[j]);
            pos = j;
        }
    }
    void SiftUp(int number) {
        int k = number;
        while (heap_max[k] > heap_max[(k - 1) / 2]) {
            swap(heap_max[k], heap_max[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Heap heap;
    while (n--) {
        string order;
        cin >> order;
        if (order == "ExtractMax") {
            cout << heap.ExtractMax() << '\n';
        }
        else if (order == "Insert") {
            int x;
            cin >> x;
            heap.Insert(x);
        }
    }
}

