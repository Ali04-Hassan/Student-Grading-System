@echo off
REM Start HTTP Server for Dashboard
REM This allows the dashboard to fetch students.json properly

echo ================================
echo Student Grading System Dashboard
echo ================================
echo.

cd /d "%~dp0"

echo Starting local server...
echo.
echo Open your browser and go to:
echo   http://localhost:8000/dashboard.html
echo.
echo Press Ctrl+C in this window to stop the server.
echo.

python -m http.server 8000 --directory "%cd%"
