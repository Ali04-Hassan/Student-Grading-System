// Student.h
// Student class — holds 6 fixed subjects, computes GPA
// Demonstrates: Classes, Arrays of Objects, Member Functions

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Subject.h"
using namespace std;

const int SUBJECT_COUNT = 6;

// Fixed subjects for all students (same 6 for everyone)
const string SUBJ_NAMES[SUBJECT_COUNT] = {
    "Digital Logic Design",
    "Object Oriented Programming",
    "Applied Stat & Probability",
    "Calculus II",
    "Communication Skills",
    "DBMS"
};
const string SUBJ_CODES[SUBJECT_COUNT] = {
    "DLD", "OOP", "ASP", "CAL", "CS", "DBMS"
};
const int SUBJ_CREDITS[SUBJECT_COUNT] = { 2, 3, 3, 3, 3, 3 };
const int TOTAL_CREDITS = 17; // 2+3+3+3+3+3

class Student {
private:
    int    id;
    int    serial;
    string regNumber;
    string name;
    Subject subjects[SUBJECT_COUNT]; // Array of 6 Subject objects

public:
    // Default Constructor
    Student() : id(0), serial(0), regNumber(""), name("") {
        initSubjects();
    }

    // Parameterized Constructor
    Student(int id, int serial, string reg, string name)
        : id(id), serial(serial), regNumber(reg), name(name) {
        initSubjects();
    }

    // Initialize the 6 fixed subjects
    void initSubjects() {
        for (int i = 0; i < SUBJECT_COUNT; i++) {
            subjects[i] = Subject(SUBJ_NAMES[i], SUBJ_CODES[i], SUBJ_CREDITS[i]);
        }
    }

    // ── Setters ──────────────────────────────────────────
    void setId(int i)          { id = i; }
    void setSerial(int s)      { serial = s; }
    void setRegNumber(string r){ regNumber = r; }
    void setName(string n)     { name = n; }
    void setSubjectMarks(int idx, float q1, float q2, float mid, float fin, float att) {
        if (idx < 0 || idx >= SUBJECT_COUNT) return;
        subjects[idx].setQuiz1(q1);
        subjects[idx].setQuiz2(q2);
        subjects[idx].setMidterm(mid);
        subjects[idx].setFinalExam(fin);
        subjects[idx].setAttendance(att);
    }

    // ── Getters ──────────────────────────────────────────
    int    getId()        const { return id; }
    int    getSerial()    const { return serial; }
    string getRegNumber() const { return regNumber; }
    string getName()      const { return name; }
    Subject getSubject(int i) const { return subjects[i]; }

    // ── GPA Calculation (4.0 scale, weighted by credit hours) ────
    float computeGPA() const {
        float weightedSum = 0;
        for (int i = 0; i < SUBJECT_COUNT; i++) {
            weightedSum += subjects[i].getGradePoints() * subjects[i].getCreditHours();
        }
        return weightedSum / TOTAL_CREDITS;
    }

    // ── Overall Average Marks ────────────────────────────
    float overallAverage() const {
        float sum = 0;
        for (int i = 0; i < SUBJECT_COUNT; i++)
            sum += subjects[i].getTotalMarks();
        return sum / SUBJECT_COUNT;
    }

    // ── Pass/Fail (GPA >= 1.0) ───────────────────────────
    bool isPassed() const { return computeGPA() >= 1.0; }

    // ── Initials for avatar ──────────────────────────────
    string getInitials() const {
        string init = "";
        bool space = true;
        for (char c : name) {
            if (space && c != ' ') { init += c; space = false; }
            if (c == ' ') space = true;
            if (init.length() >= 2) break;
        }
        return init;
    }

    // ── Input all subject marks from user ────────────────
    void inputAllMarks() {
        cout << "\n  Enter marks for: " << name << " (" << regNumber << ")\n";
        for (int i = 0; i < SUBJECT_COUNT; i++)
            subjects[i].inputMarks();
    }

    // ── Display student summary ──────────────────────────
    void display() const {
        cout << "\n  ┌─────────────────────────────────────────────────┐\n";
        cout << "  │  " << left << setw(45) << name << "  │\n";
        cout << "  │  Reg: " << left << setw(20) << regNumber
             << "  Serial: " << setw(16) << serial << "  │\n";
        cout << "  ├─────────────────────────────────────────────────┤\n";
        cout << "  │  " << left << setw(28) << "Subject"
             << setw(8) << "Total"
             << setw(6) << "Grade" << "             │\n";
        cout << "  ├─────────────────────────────────────────────────┤\n";
        for (int i = 0; i < SUBJECT_COUNT; i++) {
            cout << "  │  " << left << setw(28) << subjects[i].getName()
                 << setw(8) << fixed << setprecision(0) << subjects[i].getTotalMarks()
                 << setw(6) << subjects[i].getGrade()
                 << "             │\n";
        }
        cout << "  ├─────────────────────────────────────────────────┤\n";
        cout << "  │  GPA: " << fixed << setprecision(2) << computeGPA()
             << "   Avg: " << overallAverage()
             << "%   Status: " << (isPassed() ? "PASSED" : "FAILED")
             << "                 │\n";
        cout << "  └─────────────────────────────────────────────────┘\n";
    }

    // ── JSON export ──────────────────────────────────────
    string toJSON() const {
        string json = "{";
        json += "\"id\":" + to_string(id) + ",";
        json += "\"serial\":" + to_string(serial) + ",";
        json += "\"reg\":\"" + regNumber + "\",";
        json += "\"name\":\"" + name + "\",";
        json += "\"gpa\":" + to_string(computeGPA()) + ",";
        json += "\"avg\":" + to_string(overallAverage()) + ",";
        json += "\"passed\":" + string(isPassed() ? "true" : "false") + ",";
        json += "\"subjects\":[";
        for (int i = 0; i < SUBJECT_COUNT; i++) {
            json += subjects[i].toJSON();
            if (i < SUBJECT_COUNT - 1) json += ",";
        }
        json += "]}";
        return json;
    }

    // ── CSV line for file saving ─────────────────────────
    string toCSV() const {
        string line = to_string(id) + "," + to_string(serial) + ","
                    + regNumber + "," + name;
        for (int i = 0; i < SUBJECT_COUNT; i++)
            line += "," + subjects[i].toCSV();
        return line;
    }

    void fromCSV(string line) {
        // parse CSV: id,serial,reg,name,q1,q2,mid,fin,att (x6)
        string tokens[4 + SUBJECT_COUNT * 5];
        int count = 0;
        string cur = "";
        for (char c : line) {
            if (c == ',') { tokens[count++] = cur; cur = ""; }
            else cur += c;
        }
        tokens[count++] = cur;
        if (count < 4) return;
        id        = stoi(tokens[0]);
        serial    = stoi(tokens[1]);
        regNumber = tokens[2];
        name      = tokens[3];
        initSubjects();
        for (int i = 0; i < SUBJECT_COUNT && (4 + i*5 + 4) < count; i++) {
            int base = 4 + i * 5;
            subjects[i].fromCSV(tokens[base], tokens[base+1],
                                 tokens[base+2], tokens[base+3], tokens[base+4]);
        }
    }
};

#endif // STUDENT_H
