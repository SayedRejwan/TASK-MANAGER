### **README: Task Management System**

---

## **Task Management System**

The **Task Management System** is a feature-rich project built in **C++** to efficiently manage tasks using various data structures and a simple **Graphical User Interface (GUI)** powered by the **FLTK framework**. It enables users to add, complete, delete, and sort tasks dynamically while maintaining task history for better organization.

---

### **Features**

1. **Add Tasks**:
   - Users can add tasks with assigned priorities: **High**, **Medium**, or **Low**.

2. **Complete Tasks**:
   - Mark tasks as completed and move them from the pending list to the completed list.

3. **Delete Tasks**:
   - Remove tasks from the pending list by specifying their task number.

4. **Sort Tasks by Priority**:
   - Automatically sort tasks in the pending list by priority order (High > Medium > Low).

5. **Task History**:
   - Maintain a log of all tasks and actions (added/completed) for reference.

6. **Graphical User Interface (GUI)**:
   - A simple, interactive interface using **FLTK** for better usability.
   - Two separate sections for viewing **Pending Tasks** and **Completed Tasks**.

---

### **Technologies Used**

- **Programming Language**: C++
- **Data Structures**:
  - Linked List (for pending tasks)
  - STL List (for completed tasks)
  - STL Vector (for task history)
- **GUI Framework**: FLTK (Fast Light Toolkit)

---

### **How to Use**

1. **Add Tasks**:
   - Enter the task description in the input field.
   - Select the priority (High, Medium, Low) from the dropdown menu.
   - Click the **"Add Task"** button.

2. **Complete Tasks**:
   - Enter the task number in the input field.
   - Click the **"Complete Task"** button to move the task to the completed list.

3. **Delete Tasks**:
   - Enter the task number in the input field.
   - Click the **"Delete Task"** button to remove the task.

4. **Sort Tasks by Priority**:
   - Click the **"Sort Tasks"** button to reorder pending tasks by priority.

5. **View Tasks**:
   - Pending tasks and completed tasks are displayed in separate sections.

---

### **Setup Instructions**

#### **1. Prerequisites**
- **C++ Compiler** (e.g., GCC, MinGW, or MSVC).
- **FLTK Library**:
  - Install FLTK:
    - For Linux: `sudo apt-get install libfltk1.3-dev`
    - For Windows/Mac: Download and install from [FLTK.org](https://www.fltk.org/).

#### **2. Compilation**
- Compile the project using the following command:
  ```
  g++ -Wall -Wextra -g task_management_gui.cpp -o task_manager -lfltk
  ```

#### **3. Run the Program**
- Execute the program:
  ```
  ./task_manager
  ```

---

### **Folder Structure**

```
Project/
│
├── task_management_gui.cpp     # Main C++ source file
├── README.md                   # Project README file
└── output/                     # Directory for compiled executable
```

---

### **Future Enhancements**

1. **Persistent Storage**:
   - Save tasks to a file and reload them on program restart.
2. **Advanced Search**:
   - Add search functionality to quickly find tasks.
3. **Improved Styling**:
   - Enhance the GUI for a more modern and visually appealing design.

---

### **Contributors**

- **Your Name**
  - LinkedIn: [Your LinkedIn Profile Link](#)
  - GitHub: [Your GitHub Profile Link](#)

---

### **License**

This project is licensed under the **MIT License** – feel free to use, modify, and share it.

---

Feel free to copy, modify, or expand this **README** based on your project requirements or personal branding!
