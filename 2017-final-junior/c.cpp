#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second

struct Node {
    Node (int type, string name) {
        this->type = type;
        this->name = name;
    }
    string name;
    int type;
    vector<Node*> arr;
};

Node* root = new Node(1, "");
string ins, dir;
int depth;
vector<string> path;

int getPath (int flag) {
    if (flag && dir == "/") {
        puts("ERROR");
        return 1;
    }
    path.clear();
    string tmp;
    for (int i = 1; i < dir.size(); i++) {
        if (dir[i] == '/') {
            path.push_back(tmp);
            tmp.clear();
        }
        else tmp.push_back(dir[i]);
    }
    if (tmp.size()) path.push_back(tmp);
    return 0;
}

Node* getNext (Node* node, string name) {
    for (auto next: node->arr) {
        if (next->name == name) return next;
    }
    return NULL;
}

void mkdir () {
    if(getPath(1)) return;
    Node* cur = root;
    for (int i = 0; i + 1 < path.size(); i++) {
        int flag = 0;
        for (auto next: cur->arr) {
            if (next->name == path[i] && next->type == 1) {
                cur = next;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("ERROR");
            return;
        }
    }
    Node* exist = getNext(cur, path.back());
    if (exist) {
        puts("ERROR");
        return;
    }
    Node* newDir = new Node(1, path.back());
    cur->arr.push_back(newDir);
}

void rmdir () {
    if(getPath(1)) return;
    Node* cur = root;
    for (int i = 0; i + 1 < path.size(); i++) {
        int flag = 0;
        for (auto next: cur->arr) {
            if (next->name == path[i] && next->type == 1) {
                cur = next;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("ERROR");
            return;
        }
    }
    Node* exist = getNext(cur, path.back());
    if (!exist || exist->type == 0 || exist->arr.size()) {
        puts("ERROR");
        return;
    }
    for (int i = 0; i < cur->arr.size(); i++) {
        if (cur->arr[i]->name == path.back()) {
            cur->arr.erase(cur->arr.begin() + i);
            break;
        }
    }
}

vector<string> now;

void printPath (int flag, int isDir) {
    for (auto name: now) {
        printf("/%s", name.c_str());
    }
    if (isDir) putchar('/');
    if (flag) puts("+");
    else puts("");
}

int cmp (Node* a, Node* b) {
    return a->name < b->name;
}

void dfs (Node* node, int u) {
    if (u == depth) {
        printPath(!node->arr.empty(), node->type);
        return;
    }
    sort(node->arr.begin(), node->arr.end(), cmp);
    printPath(0, node->type);
    for (auto next: node->arr) {
        now.push_back(next->name);
        dfs(next, u + 1);
        now.pop_back();
    }
}

void ls () {
    scanf("%d", &depth);
    now.clear();
    if(getPath(0)) return;
    Node* cur = root;
    for (int i = 0; i < path.size(); i++) {
        int flag = 0;
        for (auto next: cur->arr) {
            if (next->name == path[i] && next->type == 1) {
                cur = next;
                flag = 1;
                break;
            }
        }
        now.push_back(path[i]);
        //puts(path[i].c_str());
        if (!flag) {
            puts("ERROR");
            return;
        }
    }
    dfs(cur, 0);
}

void touch () {
    if(getPath(1)) return;
    Node* cur = root;
    for (int i = 0; i + 1 < path.size(); i++) {
        int flag = 0;
        for (auto next: cur->arr) {
            if (next->name == path[i] && next->type == 1) {
                cur = next;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("ERROR");
            return;
        }
    }
    Node* exist = getNext(cur, path.back());
    if (exist) {
        puts("ERROR");
        return;
    }
    Node* newDir = new Node(0, path.back());
    cur->arr.push_back(newDir);
}

void rm () {
    if(getPath(1)) return;
    Node* cur = root;
    for (int i = 0; i + 1 < path.size(); i++) {
        int flag = 0;
        for (auto next: cur->arr) {
            if (next->name == path[i] && next->type == 1) {
                cur = next;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("ERROR");
            return;
        }
    }
    Node* exist = getNext(cur, path.back());
    if (!exist || exist->type == 1) {
        puts("ERROR");
        return;
    }
    for (int i = 0; i < cur->arr.size(); i++) {
        if (cur->arr[i]->name == path.back()) {
            cur->arr.erase(cur->arr.begin() + i);
            break;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> ins >> dir;
        if (ins == "mkdir") mkdir();
        if (ins == "rmdir") rmdir();
        if (ins == "ls") ls();
        if (ins == "touch") touch();
        if (ins == "rm") rm();
    }
}
