#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct hub {
    hub *root;

    unsigned int number;

    hub(unsigned int n) :
            number(n),
            root(this) {};
};

hub *getRoot(hub *cur) {
    while (cur->root != cur->root->root) {
        cur->root = cur->root->root;
    }

    return cur->root;
}

struct wire {
    hub *start;
    hub *last;

    unsigned int len;

    wire(hub *start, hub *last, unsigned int len) :
            start(start),
            last(last),
            len(len) {};
};

int main() {
    unsigned long n;
    unsigned long m;
    int result_wire_len = 0;

    cin >> n;
    cin >> m;
    vector<hub> hubs;
    hubs.reserve(n);
    for (unsigned int i = 0; i < n; i++) {
        hubs.emplace_back(i + 1);
    }

    int start;
    int last;
    int length;
    vector<wire> wires;
    wires.reserve(m);
    for (unsigned int i = 0; i < m; i++) {
        cin >> start;
        cin >> last;
        cin >> length;
        wires.emplace_back(&hubs[start - 1], &hubs[last - 1], length);
    }

    sort(wires.begin(), wires.end(), [](wire a, wire b) {
        return a.len < b.len;
    });

    vector<wire> answer;
    answer.reserve(m);
    for (auto item : wires) {
        if (getRoot(item.start) != getRoot(item.last)) {
            item.start->root->root = item.last->root->root;
            answer.push_back(item);

            if (result_wire_len < item.len) {
                result_wire_len = item.len;
            }
        }
    }

    cout << result_wire_len << endl;
    cout << answer.size() << endl;

    for (auto item : answer) {
        cout << item.start->number << " " << item.last->number << endl;
    }
    return 0;
}