#include <fstream>
#include <climits>
#include <random>
#include <vector>
#include <ctime>
#include <cmath>
#include <chrono>

//...

using namespace std::chrono;

#include <iostream>
//#include <sys/time.h>
//#include <bits/stdc++.h>


using namespace std;

string makeHTMLDocument(string head, string body) {
    return "<!DOCTYPE HTML>\n<html>\n<head>\n" + head + "<\head>\n<body>" + body + "\n<\html>";
}

string to_string(long a) {
    string ans;
    if (a == 0) {
        return "0";
    }
    else {
        while (a != 0) {
            ans = (char)('0' + a % 10) + ans;
            a /= 10;
        }
    }
    return ans;
}

string to_string(int a) {
    string ans;
    if (a == 0) {
        return "0";
    }
    else {
        while (a != 0) {
            ans = (char)('0' + a % 10) + ans;
            a /= 10;
        }
    }
    return ans;
}

//long currentTimeMillis() {
//    /*struct timeval time;
//    gettimeofday(&time, NULL);
//    long time = currentTimeMillis();
//    int64_t s1 = (int64_t)(time.tv_sec) * 1000;
//    int64_t s2 = (time.tv_usec / 1000);*/
//    return currentTimeMillis();
//}

vector <int> bubble(vector <int> arr) {
    vector <int> sortArr(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        sortArr[i] = arr[i];
    }

    while (true) {
        bool changed = false;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (sortArr[i] > sortArr[i + 1]) {
                int temp = sortArr[i];
                sortArr[i] = sortArr[i + 1];
                sortArr[i + 1] = temp;
                changed = true;
            }
        }
        if (changed) {
            continue;
        }
        else {
            break;
        }
    }

    return sortArr;
}
vector <int> selection(vector <int> arr) {
    vector <int> sortedArr(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        sortedArr[i] = arr[i];
    }

    for (int i = 0; i < arr.size(); i++) {
        int max = INT_MAX;
        int where = i;
        for (int j = i; j < arr.size(); j++) {
            if (sortedArr[j] < max) {
                max = sortedArr[j];
                where = j;
            }
        }
        int temp = sortedArr[i];
        sortedArr[i] = sortedArr[where];
        sortedArr[where] = temp;
    }

    return sortedArr;
}
void insertion(vector <int> arr) {
    int q, temp;
    for (int i = 0; i < arr.size(); i++) {
        q = i;
        while (q > 0 && arr[q] < arr[q - 1]) {
            temp = arr[q];
            arr[q] = arr[q - 1];
            arr[q - 1] = temp;
            q--;
        }
    }
}
int numberSize(int number) {
    if (number != 0) {
        int count = 0;
        while (number != 0) {
            count++;
            number /= 10;
        }
        return count;
    }
    else {
        return 1;
    }
}
int maxSize(vector <int> a) {
    int ans = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > ans) {
            ans = a[i];
        }
    }
    return ans;
}
int getDigit(int number, int place) {
    if (numberSize(number) >= place) {
        int returner;
        for (int i = 0; i < place; i++) {
            returner = number % 10;
            number /= 10;
        }

        return returner;
    }
    else {
        return 0;
    }
}
vector <vector <int>> razryadSort(vector <int> arr, int maxSize) {
    vector <vector <int>> sortedArr1(10);

    for (int i = 0; i < arr.size(); i++) {
        sortedArr1[getDigit(arr[i], 1)].push_back(arr[i]);
    }

    for (int i = 2; i <= maxSize; i++) {
        vector <vector <int>> sortedArr(10);
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < sortedArr1[k].size(); j++) {
                sortedArr[getDigit(sortedArr1[k][j], i)].push_back(sortedArr1[k][j]);
            }
        }
        //printArr(sortedArr1); cout << endl;
        sortedArr1 = sortedArr;
        //printArr(sortedArr1); cout << endl;
    }
    return sortedArr1;
}
vector <int> mergenSort(vector <int> arr) {
    if (arr.size() != 0 && arr.size() != 1) {
        vector <int> a1(arr.size() / 2 + arr.size() % 2);
        vector <int> a2(arr.size() / 2);
        for (int i = 0; i < a1.size(); i++) {
            a1[i] = arr[i];
        }
        for (int i = a1.size(); i < arr.size(); i++) {
            a2[i - a1.size()] = arr[i];
        }

        a1 = mergenSort(a1);
        a2 = mergenSort(a2);

        //printVector(a1); cout << endl;
        //printVector(a2);cout << endl << endl;

        arr.clear();

        int i1 = 0, j1 = 0;
        for (; i1 < a1.size() || j1 < a2.size();) {
            if (i1 == a1.size()) {
                for (int i = j1; i < a2.size(); i++) {
                    arr.push_back(a2[i]);
                }
                break;
            }
            else if (j1 == a2.size()) {
                for (int i = i1; i < a1.size(); i++) {
                    arr.push_back(a1[i]);
                }
                break;
            }
            else if (a1[i1] <= a2[j1]) {
                arr.push_back(a1[i1]);
                i1++;
            }
            else if (a1[i1] > a2[j1]) {
                arr.push_back(a2[j1]);
                j1++;
            }
        }
    }
    return arr;
}
vector <int>  fastSort(vector <int> arr) {
    if (arr.size() != 0 && arr.size() != 1) {
        int mainEl = arr[arr.size() / 2];
        int place = arr.size() / 2;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mainEl && place > i) {
                int temp = arr[i];
                arr.erase(arr.begin() + i);
                arr.push_back(temp);
                place--;
                i -= 1;
            }
            else if (arr[i] < mainEl && place < i) {
                int temp = arr[i];
                arr.erase(arr.begin() + i);
                arr.insert(arr.begin(), temp);
                place++;
                i -= 1;
            }
        }
        //printVector(arr);
        vector <int> a1;
        for (int i = 0; i < place; i++) {
            a1.push_back(arr[i]);
        }

        vector <int> a2;
        for (int i = place + 1; i < arr.size(); i++) {
            a2.push_back(arr[i]);
        }

        a1 = fastSort(a1);
        a2 = fastSort(a2);

        arr.clear();

        for (int i = 0; i < a1.size(); i++) {
            arr.push_back(a1[i]);
        }
        arr.push_back(mainEl);
        for (int i = 0; i < a2.size(); i++) {
            arr.push_back(a2[i]);
        }
        //cout << "arr - ";  printVector(arr); cout << endl;
    }
    return arr;
}

string makeTable(vector <vector <int>> arrays, string title) {
    setlocale(LC_ALL, "ru");
    string table;
    table += "<table align=\"center\" style=\"border: 1px solid black\" style=\"width:100%\">\n\t<tr style=\"border: 1px solid black\">\n";
    table += "<caption>" + title + "</caption>";
    table += "\t\t<th>\n";
    for (int i = 0; i < arrays.size(); i++) {
        table += "\t\t<th>Size array - ";
        table += to_string((int) arrays[i].size());
        table += "\n";
    }
    table += "\t\n\n";

    table += "\t<tr>\n";
    table += "\t\t<td>Standard sort\n";

    for (int i = 0; i < arrays.size(); i++) {
        long t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        sort(arrays[i].begin(), arrays[i].end());
        cout << "Standart sort " + to_string(i + 1) + " have been finished!" << endl;
        long t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        long t = t2 - t1;
        table += "\t\t<td align=\"center\">"; table += to_string(t); table += "\n";
    }

    cout << "Standard sort have been finished" << endl;

    table += "\t\n\n";

    table += "\t<tr>\n";
    table += "\t\t<td>Bubble\n";

    for (int i = 0; i < arrays.size(); i++) {
        long t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        bubble(arrays[i]);
        cout << "Bubble sort " + to_string(i + 1) + " have been finished!" << endl;
        long t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        long t = t2 - t1;
        table += "\t\t<td align=\"center\">"; table += to_string(t); table += "\n";
    }
    cout << "Bubble have been finished" << endl;

    table += "\t\n\n";
    table += "\t<tr>\n";
    table += "\t\t<td>Selection\n";

    for (int i = 0; i < 3; i++) {
        long t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        selection(arrays[i]);
        cout << "Selection sort " + to_string(i + 1) + " have been finished!" << endl;
        long t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        long t = t2 - t1;
        table += "\t\t<td align=\"center\">"; table += to_string(t); table += "\n";
    }
    
    for (int i = 3; i < arrays.size(); i++) {
        table += "\t\t<td align=\"center\">"; table += "-"; table += "\n";
    }

    cout << "Selection sort have been finished" << endl;


    table += "\t\n\n";


    table += "\t<tr>\n";
    table += "\t\t<td>Insertion\n";

    for (int i = 0; i < arrays.size(); i++) {
        long t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        insertion(arrays[i]);
        cout << "Insertion sort " + to_string(i + 1) + " have been finished!" << endl;
        long t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        long t = t2 - t1;
        table += "\t\t<td align=\"center\">"; table += to_string(t); table += "\n";
    }

    cout << "Insertion have been finished" << endl;


    table += "\t\n\n";

    //    table += "\t<tr>\n";
    //    table += "\t\t<th>Выбор<\\th>\n";

    //    for (int i = 0; i < arrays.size(); i++){
    //        long t1 = currentTimeMillis();
    //        razryadSort(arrays[i], 1000000000);
    //        long t2 = currentTimeMillis();
    //        long t = t2 - t1;
    //        table += "\t\t<th>"; table += to_string(t); table += "<\\th>\n";
    //    }

    //    table += "\t<\\tr>\n\n";

    table += "\t<tr>\n";
    table += "\t\t<td>Merger\n";

    for (int i = 0; i < arrays.size(); i++) {
        long t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        mergenSort(arrays[i]);
        cout << "Merger sort " + to_string(i + 1) + " have been finished!" << endl;
        long t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        long t = t2 - t1;
        table += "\t\t<td align=\"center\">"; table += to_string(t); table += "\n";
    }

    cout << "Merger have been finished" << endl;


    table += "\t\n\n";


    table += "\t<tr>\n";
    table += "\t\t<td>Fast\n";

    for (int i = 0; i < arrays.size(); i++) {
        long t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        fastSort(arrays[i]);
        cout << "Fast sort " + to_string(i + 1) + " have been finished!" << endl;
        long t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        long t = t2 - t1;
        table += "\t\t<td align=\"center\">"; table += to_string(t); table += "\n";
    }

    cout << "Fast sort have been finished" << endl;


    table += "\t\n<br>\n\n";

    table += "\n";
    return table;
}

void printVector(vector <int> a) {
    cout << a[0];
    for (int i = 1; i < a.size(); i++) {
        cout << ' ' << a[i];
    }
}

vector <int> makeSortedArr(int size) {
    vector <int> returner(size);
    for (int i = 0; i < size; i++) {
        returner[i] = i;
    }
    return returner;
}

vector <int> makeUnsortedArr(int size) {
    vector <int> returner(size);
    for (int i = size - 1; i > -1; i--) {
        returner[returner.size() - i - 1] = i;
    }
    return returner;
}

vector <int> makeRandArr(int size) {
    vector <int> returner(size);
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        srand(time(NULL) + rand());
        int temp = rand();
        returner[i] = temp % rand();
    }
    return returner;
}

int main()
{

    setlocale(LC_ALL, "ru");
    vector <vector <int>> arraysRand;
    vector <vector <int>> arraysSorted;
    vector <vector <int>> arraysUnSorted;

        int n;

        cin >> n;

    for (int i = 3; i < n; i += 1) {
        vector <int> a = makeRandArr(pow(10, i));
        vector <int> b = makeSortedArr(pow(10, i));
        vector <int> c = makeUnsortedArr(pow(10, i));
        arraysRand.push_back(a);
        arraysSorted.push_back(b);
        arraysUnSorted.push_back(c);
    }

    cout << "Arrays are created!" << endl;

    string randTable = makeTable(arraysRand, "Random arrays");
    string sortedArrays = makeTable(arraysSorted, "Sorted arrays");
    string unSortedArrays = makeTable(arraysUnSorted, "Unsorted arrays");

    string mainTable = "<h1 align=\"center\" >Comparison of sorts<\h1>\n<table style=\"width:100%\">\n\t<tr>" + randTable + "\t<tr>" + sortedArrays + "\t<tr>" + unSortedArrays;

    cout << mainTable;

    ofstream fout, fout1;
    fout.open("MainTable.html");
    fout1.open("MainTable.txt");
    if (fout.is_open() && fout1.is_open()) {
        fout << makeHTMLDocument("<meta charset=utf-8\">", mainTable);
        fout1 << makeHTMLDocument("<meta charset=utf-8\">", mainTable);
        cout << "Files have been saved!" << endl;
    }
    else {
        cout << "You are Khan" << endl;
    }


    fout.close();
    fout1.close();

    return 0;
}
