 🎓 Student Grading System

A complete **Student Grading System** built in **C++** with an 
interactive **HTML Dashboard** for visual data representation.

Developed as part of **CL-1004 Object Oriented Programming** Lab  
**BSc Computer Engineering** — 2025 Batch

---

 📌 Project Overview

This system manages 18 students of BSc Computer Engineering 2025 batch.
It calculates GPA, assigns grades, and displays results through 
a professional web dashboard.

---

 🏗️ Project Structure

| File | Language | Purpose |
|------|----------|---------|
| `main.cpp` | C++ | Main menu-driven program |
| `Subject.h` | C++ | Subject class with marks |
| `Student.h` | C++ | Student class with 6 subjects |
| `GradeSystem.h` | C++ | Manages all students |
| `students.csv` | Data | Permanent student storage |
| `students.json` | Data | Dashboard data export |
| `dashboard.html` | HTML/CSS/JS | Visual dashboard |

---

 💻 Technologies Used

- **C++** — Backend logic, OOP concepts, File I/O
- **HTML** — Dashboard structure
- **CSS** — Professional styling and layout
- **JavaScript** — Interactivity and calculations
- **Chart.js** — Data visualization charts

---

 📚 OOP Concepts Demonstrated

- ✅ Classes and Objects
- ✅ Encapsulation (private/public)
- ✅ Constructors and Destructors
- ✅ Dynamic Memory (new/delete)
- ✅ Arrays of Objects
- ✅ File I/O (ofstream/ifstream)
- ✅ Sorting Algorithms (Bubble Sort)
- ✅ Pointers

---

 📖 Subjects (Same for All Students)

| Subject | Code | Credit Hours |
|---------|------|-------------|
| Digital Logic Design | DLD | 2 |
| Object Oriented Programming | OOP | 3 |
| Applied Stat & Probability | ASP | 3 |
| Calculus II | CAL | 3 |
| Communication Skills | CS | 3 |
| DBMS | DBMS | 3 |
| **Total** | | **17** |

---

 📊 Marks Distribution (Per Subject)

| Component | Marks |
|-----------|-------|
| Quiz 1 | 10 |
| Quiz 2 | 10 |
| Midterm | 30 |
| Final Exam | 40 |
| Attendance | 10 |
| **Total** | **100** |

---

 🔢 GPA Scale

| Marks | Grade | GPA Points |
|-------|-------|-----------|
| 90-100 | A | 4.0 |
| 80-89 | B | 3.0 |
| 70-79 | C | 2.0 |
| 60-69 | D | 1.0 |
| Below 60 | F | 0.0 |

---

 🚀 How to Run

 C++ Backend
```bash
# Compile
g++ -std=c++11 -o grading main.cpp

# Run
./grading          # Linux/Mac
grading.exe        # Windows
```

### Dashboard
