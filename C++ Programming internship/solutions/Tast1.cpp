// Simple CGPA calculator
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    cout << "CGPA Calculator\n";
    int n;
    cout << "Enter number of courses: ";
    if(!(cin>>n) || n<=0){
        cerr<<"Invalid number of courses\n"; return 1;
    }
    struct Course{string name; double grade; double credits;};
    vector<Course> courses;
    for(int i=0;i<n;++i){
        Course c; cout << "\nCourse " << (i+1) << " name (single word, or - to skip): ";
        cin >> c.name;
        cout << "Enter grade points for " << c.name << " (e.g. 4.0 or 10.0): "; cin >> c.grade;
        cout << "Enter credit hours for " << c.name << ": "; cin >> c.credits;
        courses.push_back(c);
    }

    double totalCredits=0.0, totalGradePoints=0.0;
    cout << fixed << setprecision(2) << "\nCourse results:\n";
    for(size_t i=0;i<courses.size();++i){
        double gp = courses[i].grade * courses[i].credits;
        cout << i+1 << ". " << courses[i].name << " — grade=" << courses[i].grade << " credits=" << courses[i].credits << " points=" << gp << "\n";
        totalCredits += courses[i].credits;
        totalGradePoints += gp;
    }

    if(totalCredits <= 0){ cout << "No credits entered.\n"; return 0; }
    double cgpa = totalGradePoints / totalCredits;
    cout << "\nTotal Credits: " << totalCredits << "\nTotal Grade Points: " << totalGradePoints << "\nCGPA: " << cgpa << "\n";
    return 0;
}
