#include <iostream>
#include <fstream>
#include <string>
#include <functional>
using namespace std;

const string USER_FILE = "users.txt";

string hash_pw(const string &pw){
    size_t h = hash<string>{}(pw);
    return to_string(h);
}

bool user_exists(const string &username, string *out_hash=nullptr){
    ifstream file(USER_FILE);
    if(!file.is_open()) return false;

    string line;
    while(getline(file, line)){
        size_t pos = line.find(':');
        if(pos != string::npos){
            string u = line.substr(0, pos);
            string h = line.substr(pos + 1);
            if(u == username){
                if(out_hash) *out_hash = h;
                return true;
            }
        }
    }
    return false;
}

bool register_user(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if(user_exists(username)){
        cout << "User already exists.\n";
        return false;
    }

    ofstream file(USER_FILE, ios::app);
    if(!file.is_open()){
        cerr << "Error opening user file.\n";
        return false;
    }

    file << username << ':' << hash_pw(password) << '\n';
    file.close();
    cout << "User registered successfully.\n";
    return true;
}

bool login_user(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string stored_hash;
    if(!user_exists(username, &stored_hash)){
        cout << "Invalid username or password.\n";
        return false;
    }

    if(hash_pw(password) == stored_hash){
        cout << "Login successful.\n";
        return true;
    } else {
        cout << "Invalid username or password.\n";
        return false;
    }
}

int main(){
    cout << "Simple Auth Demo\n";

    while(true){
        cout << "\n1) Register  2) Login  3) Exit\nChoose: ";
        int c;
        cin >> c;

        if(c==1)
            register_user();
        else if(c==2)
            login_user();
        else
            break;
    }

    return 0;
}
