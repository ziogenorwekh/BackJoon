#include <algorithm>
#include <string>
#include <vector>
using namespace std;


struct Data {
    int code;
    int date;
    int maxium;
    int remain;

    Data() {
    }

    Data(int code, int date, int maxium, int remain) : code(code), date(date), maxium(maxium), remain(remain) {
    }
};

struct compare {
    int selected;
    compare(int s) : selected(s) {}

    bool operator()(const Data &lhs, const Data &rhs) const {
        switch (selected) {
            case 0: return lhs.code < rhs.code;
            case 1: return lhs.date < rhs.date;
            case 2: return lhs.maxium < rhs.maxium;
            case 3: return lhs.remain < rhs.remain;
            default: return false;
        }
    }
};
int selectData(string ext) {
    if (ext == "code") return 0;
    else if (ext == "date") return 1;
    else if (ext == "maximum") return 2;
    else if (ext == "remain") return 3;
    return -1; // or 예외 처리
}

// 무조건 오름차순, ext는 뽑아낼 데이터, val_ext는 이보다 작은 데이터만
vector<vector<int> > solution(vector<vector<int> > data, string ext, int val_ext, string sort_by) {
    vector<Data> sorted;
    int firstSorted = selectData(ext);
    int secondSorted = selectData(sort_by);
    for (int i = 0; i < data.size(); i++) {
        if (data[i][firstSorted] <= val_ext) {
            sorted.push_back(Data(data[i][0], data[i][1], data[i][2], data[i][3]));
        }
    }
    compare comp(secondSorted);
    vector<vector<int>> answer(sorted.size(), vector<int>(4));
    sort(sorted.begin(), sorted.end(), comp);
    for (int i = 0; i < sorted.size(); i++) {
        answer[i][0] = sorted[i].code;
        answer[i][1] = sorted[i].date;
        answer[i][2] = sorted[i].maxium;
        answer[i][3] = sorted[i].remain;
    }
    return answer;
}