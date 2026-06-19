╔══════════════════════════════════════════════════════════════╗
║          STUDENT GRADING SYSTEM — SGS Project                ║
║          BSc Computer Engineering 2025 Batch                 ║
║          CL-1004 Object Oriented Programming                  ║
╚══════════════════════════════════════════════════════════════╝

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 FILES IN THIS FOLDER
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  Subject.h       → C++ class for one subject marks
  Student.h       → C++ class for one student (6 subjects)
  GradeSystem.h   → C++ class manages all students
  main.cpp        → C++ main program (run this)
  students.csv    → Student data file (auto saved by C++)
  students.json   → JSON data file (for dashboard)
  dashboard.html  → Visual dashboard (open in browser)
  README.txt      → This file

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 HOW TO OPEN IN VS CODE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  1. Open VS Code
  2. Click File → Open Folder
  3. Select this SGS_Project folder
  4. Click "Select Folder"
  5. All files appear in the left panel (Explorer)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 HOW TO COMPILE AND RUN C++ IN VS CODE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  Step 1: Open Terminal in VS Code
          Press:  Ctrl + `  (backtick key, top-left of keyboard)
          OR:     Terminal menu → New Terminal

  Step 2: Go to project folder (if not already there)
          cd path/to/SGS_Project

  Step 3: Compile the C++ code
          Windows (MinGW):
            g++ -std=c++11 -o grading main.cpp

          Linux / Mac:
            g++ -std=c++11 -o grading main.cpp

  Step 4: Run the program
          Windows:   grading.exe   OR   .\grading.exe
          Linux/Mac: ./grading

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 HOW TO VIEW THE DASHBOARD
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  Method 1 — Simple (recommended):
    Double click dashboard.html → opens in browser

  Method 2 — From VS Code:
    Right click dashboard.html → Open with Live Server
    (requires Live Server extension installed)

  Method 3 — From VS Code Explorer:
    Click dashboard.html in left panel
    Press Ctrl+Shift+P → type "Live Server" → Enter

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 HOW TO EDIT STUDENT DATA
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  METHOD A — Through C++ Program (Proper Way):
    1. Run the program (see above)
    2. Choose option 3 → Edit Student Marks
    3. Enter Student ID
    4. Enter new marks
    5. Choose option 14 → Export JSON
    6. Refresh dashboard.html in browser

  METHOD B — Edit CSV directly in VS Code:
    1. Open students.csv in VS Code
    2. Find student row (Ctrl+F to search name)
    3. Change numbers (respect max marks!)
    4. Ctrl+S to save
    5. Run C++ program → option 13 (Load CSV)
    6. Option 14 (Export JSON)
    7. Refresh dashboard.html

  METHOD C — Edit in Dashboard directly:
    1. Open dashboard.html in browser
    2. Go to "All Students" page
    3. Click Edit button on any student
    4. Change marks → Save Changes
    (saves in browser memory automatically)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 MARKS DISTRIBUTION (same for all subjects)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  Quiz 1       = 10 marks
  Quiz 2       = 10 marks
  Midterm      = 30 marks
  Final Exam   = 40 marks
  Attendance   = 10 marks
  ─────────────────────────
  TOTAL        = 100 marks

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 SUBJECTS (6 subjects, same for all)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  1. Digital Logic Design          (DLD)   2 credit hours
  2. Object Oriented Programming   (OOP)   3 credit hours
  3. Applied Stat & Probability    (ASP)   3 credit hours
  4. Calculus II                   (CAL)   3 credit hours
  5. Communication Skills          (CS)    3 credit hours
  6. DBMS                          (DBMS)  3 credit hours
  ─────────────────────────────────────────────────────────
  Total Credit Hours = 17

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 GPA SCALE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  90-100  →  A  →  4.0
  80-89   →  B  →  3.0
  70-79   →  C  →  2.0
  60-69   →  D  →  1.0
  0-59    →  F  →  0.0

  Pass = GPA >= 1.0
  Fail = GPA <  1.0

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 C++ MENU OPTIONS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   1  Add Student
   2  Add Student + Enter Marks
   3  Edit Student Marks          ← change data
   4  Delete Student
   5  View All Students
   6  View Student Profile
   7  Class Statistics
   8  Top Student
   9  Failed Students
  10  Sort by GPA
  11  Sort by Name
  12  Save to CSV File
  13  Load from CSV File
  14  Export JSON → for Dashboard  ← always do this after editing
  15  Load Default 18 Students
   0  Exit

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 IMPORTANT NOTES
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  • Always run option 14 after any change to update dashboard
  • Do NOT delete students.csv or students.json
  • Keep all files in the SAME folder
  • dashboard.html must be in same folder as students.json
  • All files must stay together — do not move them separately

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 LANGUAGES USED
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  C++       → Backend: all logic, calculations, file I/O
  HTML      → Dashboard structure
  CSS       → Dashboard styling
  JavaScript→ Dashboard interactivity and charts
  Chart.js  → Graph library
  JSON      → Data exchange between C++ and HTML

