#include <bits/stdc++.h>
#define ll long long
using namespace std;

stack<ll> stk;
vector<string> commands;
vector<ll> num_x;

int numx(ll x) {
    stk.push(x);
    return 0;
}

int pop() {
    if(stk.empty()) return -1;
    stk.pop();
    return 0;
}

int inv() {
    if(stk.empty()) return -1;
    stk.top() *= -1;
    return 0;
}

int dup() {
    if(stk.empty()) return -1;
    stk.push(stk.top());
    return 0;
}

int swp() {
    if(stk.size() < 2) return -1;
    ll n1 = stk.top(); stk.pop();
    ll n2 = stk.top(); stk.pop();
    stk.push(n1); stk.push(n2);
    return 0;
}

int add() {
    if(stk.size() < 2) return -1;
    ll n1 = stk.top(); stk.pop();
    ll n2 = stk.top(); stk.pop();
    if(abs(n1 + n2) > 1e9) return -1;
    stk.push(n1 + n2);
    return 0;
}

int sub() {
    if(stk.size() < 2) return -1;
    ll n1 = stk.top(); stk.pop();
    ll n2 = stk.top(); stk.pop();
    if(abs(n2 - n1) > 1e9) return -1;
    stk.push(n2 - n1);
    return 0;
}

int mul() {
    if(stk.size() < 2) return -1;
    ll n1 = stk.top(); stk.pop();
    ll n2 = stk.top(); stk.pop();
    if(abs(n1 * n2) > 1e9) return -1;
    stk.push(n1 * n2);
    return 0;
}

int div() {
    if(stk.size() < 2) return -1;
    ll n1 = stk.top(); stk.pop();
    ll n2 = stk.top(); stk.pop();
    if(n1 == 0) return -1;
    if(abs(n2 / n1) > 1e9) return -1;
    stk.push(n2 / n1);
    return 0;
}

int mod() {
    if(stk.size() < 2) return -1;
    ll n1 = stk.top(); stk.pop();
    ll n2 = stk.top(); stk.pop();
    if(n1 == 0) return -1;
    if(abs(n2 % n1) > 1e9) return -1;
    stk.push(n2 % n1);
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s;
    while(1) {
        cin >> s;
        if(s == "QUIT") break;
        while(1) {
            if(s == "END") break;
            commands.push_back(s);
            if(s == "NUM") {
                ll x;
                cin >> x;
                num_x.push_back(x);
            }
            cin >> s;
        }
        int t;
        cin >> t;
        for(int i=0; i<t; i++) {
            ll n;
            cin >> n;
            stk.push(n);
            int idx = 0;
            int flag = 0;
            
            for(string command : commands) {
                if(command == "NUM") {
                    flag = numx(num_x[idx++]);
                }
                else if(command == "POP") {
                    flag = pop();
                }
                else if(command == "INV") {
                    flag = inv();
                }
                else if(command == "DUP") {
                    flag = dup();
                }
                else if(command == "SWP") {
                    flag = swp();
                }
                else if(command == "ADD") {
                    flag = add();
                }
                else if(command == "SUB") {
                    flag = sub();
                }
                else if(command == "MUL") {
                    flag = mul();
                }
                else if(command == "DIV") {
                    flag = div();
                }
                else if(command == "MOD") {
                    flag = mod();
                }
                if(flag == -1) break;
            }
            if(flag == 0 && stk.size() == 1) cout << stk.top() << '\n';
            else cout << "ERROR\n";
            while(!stk.empty()) stk.pop();
        }
        commands.clear();
        num_x.clear();
        cout << '\n';
    }
    
    return 0;
}
