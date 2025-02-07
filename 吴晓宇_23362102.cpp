#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;


class Sort {
public:
    Sort(int a[], int n) {
        data.assign(a, a + n);
    }

    void sort() {
        quickSort(0, data.size() - 1);
    }

    int get(int i) {
        return data[i];
    }

    vector<int> data;
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int partition(int low, int high) {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        int temp = data[i + 1];
        data[i + 1] = data[high];
        data[high] = temp;
        return i + 1;
    }
};

class ExSort : public Sort {
public:
    ExSort(int a[], int n) : Sort(a, n) {}

    void exsort(int order) {
        if (order == 0) { 
            quickSort(0, data.size() - 1);
        } else if (order == 1) { 
            quickSortDesc(0, data.size() - 1);
        }
    }

    void quickSortDesc(int low, int high) {
        if (low < high) {
            int pi = partitionDesc(low, high);
            quickSortDesc(low, pi - 1);
            quickSortDesc(pi + 1, high);
        }
    }

    int partitionDesc(int low, int high) {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (data[j] > pivot) {
                i++;
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        int temp = data[i + 1];
        data[i + 1] = data[high];
        data[high] = temp;
        return i + 1;
    }
};

//DO NOT modify any parts below this line

void disp(Sort *s, int partial, int n){
    if(partial==0){
        for(int i=0;i<n;i++){
            cout<<s->get(i)<<" ";
        }
        cout<<endl;
    }else{
        int nprint=n;
        if(nprint>20)
        nprint=20;
        for(int i=0;i<nprint;i++){
            cout<<s->get(rand()%(n))<<" ";
        }
        cout<<endl;
    }
}

//以下程序会自动产生随机数组list，自动将list输入Sort对象和ExSort对象，
//并调用排序函数进行排序，以及进行打印，不需要进行更改
int main(int argc, char **argv){

    int *list;
    int n=stoi(argv[1]);
    int partial_disp=stoi(argv[2]);
    int seed=stoi(argv[3]);
    srand(seed);

    list=new int[n];
    for(int i=0;i<n;i++){
        list[i]=rand()%(n*20);
    }
    
    //开始
    Sort s0(list,n);//初始化
    disp(&s0,partial_disp,n);
    s0.sort();      //排序（升序）
    disp(&s0,partial_disp,n);

    ExSort s1(list,n);//初始化
    disp(&s1,partial_disp,n);
    s1.exsort(1);     //降序排序
    disp(&s1,partial_disp,n);
    
    delete[] list;

}