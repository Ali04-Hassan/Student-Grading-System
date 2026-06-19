// Subject.h
// Represents one subject with marks breakdown
// Marks: Quiz1(10) + Quiz2(10) + Mid(30) + Final(40) + Attendance(10) = 100

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
using namespace std;

class Subject {
private:
    string name;
    string shortCode;
    int    creditHours;
    float  quiz1;      // max 10
    float  quiz2;      // max 10
    float  midterm;    // max 30
    float  finalExam;  // max 40
    float  attendance; // max 10

public:
    // Default Constructor
    Subject() : name(""), shortCode(""), creditHours(0),
                quiz1(0), quiz2(0), midterm(0), finalExam(0), attendance(0) {}

    // Parameterized Constructor
    Subject(string n, string code, int cr)
        : name(n), shortCode(code), creditHours(cr),
          quiz1(0), quiz2(0), midterm(0), finalExam(0), attendance(0) {}

    // ── Setters ──────────────────────────────────────────
    void setName(string n)       { name = n; }
    void setShortCode(string c)  { shortCode = c; }
    void setCreditHours(int c)   { creditHours = c; }

    void setQuiz1(float v)      { quiz1      = (v > 10) ? 10 : v; }
    void setQuiz2(float v)      { quiz2      = (v > 10) ? 10 : v; }
    void setMidterm(float v)    { midterm    = (v > 30) ? 30 : v; }
    void setFinalExam(float v)  { finalExam  = (v > 40) ? 40 : v; }
    void setAttendance(float v) { attendance = (v > 10) ? 10 : v; }

    // ── Getters ──────────────────────────────────────────
    string getName()      const { return name; }
    string getShortCode() const { return shortCode; }
    int    getCreditHours()const{ return creditHours; }
    float  getQuiz1()     const { return quiz1; }
    float  getQuiz2()     const { return quiz2; }
    float  getMidterm()   const { return midterm; }
    float  getFinalExam() const { return finalExam; }
    float  getAttendance()const { return attendance; }

    // ── Total Marks out of 100 ───────────────────────────
    float getTotalMarks() const {
        return quiz1 + quiz2 + midterm + finalExam + attendance;
    }

    // ── Letter Grade ─────────────────────────────────────
    char getGrade() const {
        float total = getTotalMarks();
        if (total >= 90) return 'A';
        if (total >= 80) return 'B';
        if (total >= 70) return 'C';
        if (total >= 60) return 'D';
        return 'F';
    }

    // ── Grade Points (4.0 scale) ─────────────────────────
    float getGradePoints() const {
        char g = getGrade();
        if (g == 'A') return 4.0;
        if (g == 'B') return 3.0;
        if (g == 'C') return 2.0;
        if (g == 'D') return 1.0;
        return 0.0;
    }

    // ── Input from user ──────────────────────────────────
    void inputMarks() {
        cout << "\n  [" << shortCode << "] " << name << " (" << creditHours << " cr hours)\n";
        cout << "    Marks Distribution: Quiz1/10  Quiz2/10  Mid/30  Final/40  Att/10\n";

        cout << "    Quiz 1  (max 10): "; cin >> quiz1;  setQuiz1(quiz1);
        cout << "    Quiz 2  (max 10): "; cin >> quiz2;  setQuiz2(quiz2);
        cout << "    Midterm (max 30): "; cin >> midterm; setMidterm(midterm);
        cout << "    Final   (max 40): "; cin >> finalExam; setFinalExam(finalExam);
        cout << "    Attend  (max 10): "; cin >> attendance; setAttendance(attendance);
    }

    // ── Display ──────────────────────────────────────────
    void display() const {
        cout << "    " << shortCode << " | " << name
             << " | Total: " << getTotalMarks() << "/100"
             << " | Grade: " << getGrade() << "\n";
    }

    // ── JSON export ──────────────────────────────────────
    string toJSON() const {
        return "{\"name\":\"" + name + "\","
             + "\"code\":\"" + shortCode + "\","
             + "\"credits\":" + to_string(creditHours) + ","
             + "\"quiz1\":"   + to_string((int)quiz1) + ","
             + "\"quiz2\":"   + to_string((int)quiz2) + ","
             + "\"mid\":"     + to_string((int)midterm) + ","
             + "\"final\":"   + to_string((int)finalExam) + ","
             + "\"att\":"     + to_string((int)attendance) + ","
             + "\"total\":"   + to_string((int)getTotalMarks()) + ","
             + "\"grade\":\"" + getGrade() + "\","
             + "\"gp\":"      + to_string(getGradePoints()) + "}";
    }

    // ── Simple CSV for file ──────────────────────────────
    string toCSV() const {
        return to_string(quiz1) + "," + to_string(quiz2) + ","
             + to_string(midterm) + "," + to_string(finalExam) + ","
             + to_string(attendance);
    }

    void fromCSV(string q1, string q2, string mid, string fin, string att) {
        setQuiz1(stof(q1)); setQuiz2(stof(q2));
        setMidterm(stof(mid)); setFinalExam(stof(fin));
        setAttendance(stof(att));
    }
};

#endif // SUBJECT_H
