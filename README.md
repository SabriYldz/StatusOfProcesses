# 🐧 Linux Process Monitor

A lightweight system monitoring tool written in C that parses the Linux `/proc` filesystem to track active processes in real-time.

This project demonstrates low-level file handling, string parsing, and process management concepts in the Linux environment.

## 🚀 Features

* **Virtual Filesystem Parsing:** Reads directly from `/proc/[pid]/stat` and `/proc/[pid]/status`.
* **Process Enumeration:** Lists all active Process IDs (PIDs).
* **Status Reporting:** Displays process names and current states (Running, Sleeping, Idle, etc.).
* **Zero Dependencies:** Built using only standard C libraries (`<dirent.h>`, `<stdio.h>`, etc.).

## 🛠️ Build & Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/SabriYldz/StatusOfProcesses.git](https://github.com/SabriYldz/StatusOfProcesses.git)
    cd StatusOfProcesses
    ```

2.  **Compile using Make:**
    ```bash
    make
    ```

3.  **Run the monitor:**
    ```bash
    ./linux_monitor
    ```

4.  **Clean up build files:**
    ```bash
    make clean
    ```

## 📝 License

This project is licensed under the MIT License.
