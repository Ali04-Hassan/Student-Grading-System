#!/usr/bin/env python3
"""
Simple HTTP Server for Student Grading System Dashboard
This server allows the dashboard to load the students.json file via fetch()
which doesn't work when opening HTML files directly (file:// URLs).

Usage:
  python server.py
  
Then open in browser:
  http://localhost:8000/dashboard.html
"""

import http.server
import socketserver
import os
import webbrowser

PORT = 8000
DIRECTORY = os.path.dirname(os.path.abspath(__file__))

class MyHTTPRequestHandler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=DIRECTORY, **kwargs)
    
    def end_headers(self):
        self.send_header('Cache-Control', 'no-store, no-cache, must-revalidate, max-age=0')
        self.send_header('Pragma', 'no-cache')
        super().end_headers()

if __name__ == '__main__':
    os.chdir(DIRECTORY)
    with socketserver.TCPServer(("", PORT), MyHTTPRequestHandler) as httpd:
        print(f"✓ Server running at http://localhost:{PORT}")
        print(f"✓ Open dashboard: http://localhost:{PORT}/dashboard.html")
        print(f"✓ Press Ctrl+C to stop\n")
        try:
            webbrowser.open(f'http://localhost:{PORT}/dashboard.html')
        except:
            pass
        httpd.serve_forever()
