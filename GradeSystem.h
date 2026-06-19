// GradeSystem.h
// Manages all students — add, delete, edit, search, sort, export
// Demonstrates: Dynamic Arrays, Sorting, File I/O, Friend Functions

#ifndef GRADESYSTEM_H
#define GRADESYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Student.h"
using namespace std;

class GradeSystem {
private:
    Student* students;   // Dynamic array of students
    int      count;      // Current number of students
    int      capacity;   // Current capacity of array
    int      nextId;     // Auto-increment ID

    // ── Resize dynamic array ─────────────────────────────
    void resize() {
        capacity *= 2;
        Student* newArr = new Student[capacity];
        for (int i = 0; i < count; i++)
            newArr[i] = students[i];
        delete[] students;
        students = newArr;
    }

public:
    // Constructor
    GradeSystem() : count(0), capacity(20), nextId(1) {
        students = new Student[capacity];
    }

    // Destructor
    ~GradeSystem() { delete[] students; }

    // ── Add student ──────────────────────────────────────
    void addStudent(int serial, string reg, string name) {
        if (count >= capacity) resize();
        students[count] = Student(nextId++, serial, reg, name);
        count++;
        cout << "  ✓ Student added: " << name << " (" << reg << ")\n";
    }

    void addStudentWithMarks(int serial, string reg, string name) {
        if (count >= capacity) resize();
        students[count] = Student(nextId++, serial, reg, name);
        students[count - 1].inputAllMarks();
        cout << "  ✓ Student added with marks.\n";
    }

    // ── Find student by ID ───────────────────────────────
    int findById(int id) const {
        for (int i = 0; i < count; i++)
            if (students[i].getId() == id) return i;
        return -1;
    }

    // ── Find student by reg number ───────────────────────
    int findByReg(string reg) const {
        for (int i = 0; i < count; i++)
            if (students[i].getRegNumber() == reg) return i;
        return -1;
    }

    // ── Edit student marks ───────────────────────────────
    void editStudent(int id) {
        int idx = findById(id);
        if (idx == -1) { cout << "  ✗ Student not found.\n"; return; }
        cout << "  Editing: " << students[idx].getName() << "\n";
        students[idx].inputAllMarks();
        cout << "  ✓ Marks updated.\n";
    }

    // ── Delete student ───────────────────────────────────
    void deleteStudent(int id) {
        int idx = findById(id);
        if (idx == -1) { cout << "  ✗ Student not found.\n"; return; }
        cout << "  Deleting: " << students[idx].getName() << "\n";
        for (int i = idx; i < count - 1; i++)
            students[i] = students[i + 1];
        count--;
        cout << "  ✓ Student deleted.\n";
    }

    // ── Display all students (table) ─────────────────────
    void displayAll() const {
        if (count == 0) { cout << "  No students found.\n"; return; }
        cout << "\n  " << string(80, '=') << "\n";
        cout << "  " << left << setw(4)  << "#"
             << setw(20) << "Registration #"
             << setw(25) << "Name"
             << setw(8)  << "Avg"
             << setw(6)  << "GPA"
             << setw(8)  << "Status" << "\n";
        cout << "  " << string(80, '-') << "\n";
        for (int i = 0; i < count; i++) {
            cout << "  " << left << setw(4) << (i+1)
                 << setw(20) << students[i].getRegNumber()
                 << setw(25) << students[i].getName()
                 << setw(8)  << fixed << setprecision(1) << students[i].overallAverage()
                 << setw(6)  << fixed << setprecision(2) << students[i].computeGPA()
                 << setw(8)  << (students[i].isPassed() ? "PASS" : "FAIL") << "\n";
        }
        cout << "  " << string(80, '=') << "\n";
        cout << "  Total: " << count << " students\n";
    }

    // ── Display one student full profile ─────────────────
    void displayStudent(int id) const {
        int idx = findById(id);
        if (idx == -1) { cout << "  ✗ Student not found.\n"; return; }
        students[idx].display();
    }

    // ── Class statistics ─────────────────────────────────
    void displayStats() const {
        if (count == 0) { cout << "  No data.\n"; return; }
        int passed = 0, failed = 0;
        int gradeCount[5] = {0}; // A B C D F
        float totalGPA = 0;
        float subjectAvg[SUBJECT_COUNT] = {0};

        for (int i = 0; i < count; i++) {
            if (students[i].isPassed()) passed++; else failed++;
            totalGPA += students[i].computeGPA();
            for (int j = 0; j < SUBJECT_COUNT; j++)
                subjectAvg[j] += students[i].getSubject(j).getTotalMarks();
            char g = students[i].getSubject(0).getGrade(); // example
            // count all subject grades
            for (int j = 0; j < SUBJECT_COUNT; j++) {
                char sg = students[i].getSubject(j).getGrade();
                if (sg=='A') gradeCount[0]++;
                else if (sg=='B') gradeCount[1]++;
                else if (sg=='C') gradeCount[2]++;
                else if (sg=='D') gradeCount[3]++;
                else gradeCount[4]++;
            }
        }

        cout << "\n  ══ CLASS STATISTICS ══\n";
        cout << "  Total Students : " << count << "\n";
        cout << "  Passed         : " << passed << "\n";
        cout << "  Failed         : " << failed << "\n";
        cout << "  Class Avg GPA  : " << fixed << setprecision(2) << (totalGPA/count) << "\n";
        cout << "\n  Grade Distribution (all subjects combined):\n";
        cout << "  A: " << gradeCount[0] << "  B: " << gradeCount[1]
             << "  C: " << gradeCount[2] << "  D: " << gradeCount[3]
             << "  F: " << gradeCount[4] << "\n";
        cout << "\n  Subject-wise Average:\n";
        for (int j = 0; j < SUBJECT_COUNT; j++)
            cout << "  " << left << setw(35) << SUBJ_NAMES[j]
                 << fixed << setprecision(1) << (subjectAvg[j]/count) << "/100\n";
    }

    // ── Sort by GPA descending ───────────────────────────
    void sortByGPA() {
        // Bubble sort
        for (int i = 0; i < count - 1; i++)
            for (int j = 0; j < count - i - 1; j++)
                if (students[j].computeGPA() < students[j+1].computeGPA())
                    swap(students[j], students[j+1]);
        cout << "  ✓ Sorted by GPA (highest first).\n";
    }

    // ── Sort by name ─────────────────────────────────────
    void sortByName() {
        for (int i = 0; i < count - 1; i++)
            for (int j = 0; j < count - i - 1; j++)
                if (students[j].getName() > students[j+1].getName())
                    swap(students[j], students[j+1]);
        cout << "  ✓ Sorted alphabetically by name.\n";
    }

    // ── Top student ──────────────────────────────────────
    void displayTopStudent() const {
        if (count == 0) return;
        int top = 0;
        for (int i = 1; i < count; i++)
            if (students[i].computeGPA() > students[top].computeGPA()) top = i;
        cout << "\n  🏆 Top Student: " << students[top].getName()
             << " | GPA: " << fixed << setprecision(2) << students[top].computeGPA() << "\n";
    }

    // ── Failed students list ─────────────────────────────
    void displayFailedStudents() const {
        cout << "\n  Failed Students:\n";
        bool any = false;
        for (int i = 0; i < count; i++) {
            if (!students[i].isPassed()) {
                cout << "  - " << students[i].getName()
                     << " (" << students[i].getRegNumber() << ")"
                     << " GPA: " << fixed << setprecision(2) << students[i].computeGPA() << "\n";
                any = true;
            }
        }
        if (!any) cout << "  No failed students!\n";
    }

    // ── Save to CSV file ─────────────────────────────────
    bool saveToFile(string filename = "students.csv") const {
        ofstream file(filename);
        if (!file) { cout << "  ✗ Cannot open file: " << filename << "\n"; return false; }
        file << "id,serial,reg,name";
        for (int i = 0; i < SUBJECT_COUNT; i++)
            file << "," << SUBJ_CODES[i] << "_q1," << SUBJ_CODES[i] << "_q2,"
                 << SUBJ_CODES[i] << "_mid," << SUBJ_CODES[i] << "_fin,"
                 << SUBJ_CODES[i] << "_att";
        file << "\n";
        for (int i = 0; i < count; i++)
            file << students[i].toCSV() << "\n";
        file.close();
        cout << "  ✓ Saved " << count << " students to " << filename << "\n";
        return true;
    }

    // ── Load from CSV file ───────────────────────────────
    bool loadFromFile(string filename = "students.csv") {
        ifstream file(filename);
        if (!file) { cout << "  ✗ File not found: " << filename << "\n"; return false; }
        string line;
        getline(file, line); // skip header
        count = 0; nextId = 1;
        while (getline(file, line) && count < capacity) {
            if (line.empty()) continue;
            if (count >= capacity) resize();
            students[count].fromCSV(line);
            if (students[count].getId() >= nextId)
                nextId = students[count].getId() + 1;
            count++;
        }
        file.close();
        cout << "  ✓ Loaded " << count << " students from " << filename << "\n";
        return true;
    }

    // ── Export JSON for HTML dashboard ───────────────────
    bool exportJSON(string filename = "students.json") const {
        ofstream file(filename);
        if (!file) { cout << "  ✗ Cannot open file: " << filename << "\n"; return false; }
        file << "[\n";
        for (int i = 0; i < count; i++) {
            file << "  " << students[i].toJSON();
            if (i < count - 1) file << ",";
            file << "\n";
        }
        file << "]\n";
        file.close();
        cout << "  ✓ JSON exported to " << filename << " (open dashboard.html to view)\n";
        return true;
    }

    int getCount() const { return count; }
    Student getStudent(int idx) const { return students[idx]; }
};

#endif // GRADESYSTEM_H
