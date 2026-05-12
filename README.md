# 🚀 CodSoft C++ Internship Projects

**A comprehensive portfolio of C++ projects demonstrating Object-Oriented Programming (OOP), problem-solving, and clean code practices.**

---

## 📌 About This Repository

This repository contains hands-on C++ projects completed during the **CodSoft Internship Program**. Each project demonstrates practical implementation of core programming concepts including OOP principles, data structures, error handling, and user interface design.

---

## 📚 Projects Overview

### Project 1: 🧮 **Simple Calculator with OOP**

#### Description
A fully functional command-line calculator built using Object-Oriented Programming principles in C++. The calculator supports basic arithmetic operations with continuous use capability and robust error handling.

#### Key Features
- ✨ **OOP Design**: Calculator class with encapsulated operations
- ➕ **Basic Operations**: Addition, Subtraction, Multiplication, Division
- 🛡️ **Error Handling**: Division by zero protection
- 🔄 **User-Friendly Loop**: Continue calculations without restart
- 📱 **Interactive Menu**: Clear UI with operation selection

#### Concepts Implemented
```
✓ Classes and Objects          ✓ Methods and Functions
✓ Encapsulation               ✓ Switch-case Logic
✓ Do-while Loops              ✓ Input Validation
✓ Error Handling              ✓ Float Data Operations
```

#### Code Highlights
```cpp
class calculator {
    public:
    float add(float a, float b) { return a + b; }
    float subtract(float a, float b) { return a - b; }
    float multiply(float a, float b) { return a * b; }
    float divide(float a, float b) {
        if(b != 0) return a / b;
        else { cout << "Error! Division by zero\n"; return 0; }
    }
};
```

#### How to Compile & Run
```bash
# Using g++ compiler
g++ -o calculator calculator.cpp

# Run the executable
./calculator

# Windows users
calculator.exe
```

#### Usage Example
```
=======calculator menu========
+:Addition
-:Subtraction
*:Multiplication
/:Division

 Enter first number: 10
Enter operator: +
Enter second number: 5
result=15

 do you want to continue?(y/n): y
```

#### Live Demo
📹 **Video Proof**: [Watch Calculator Demo](calculator%20proof.mp4)

---

## 🛠️ Technical Stack

| Technology | Purpose |
|-----------|---------|
| **C++** | Primary programming language |
| **G++/MinGW** | Compilation |
| **OOP Concepts** | Design & Architecture |
| **Git/GitHub** | Version Control |

---

## 💡 Key Learning Outcomes

Through these projects, I've developed proficiency in:

- ✅ **Object-Oriented Programming** (Classes, Objects, Methods, Encapsulation)
- ✅ **Control Structures** (Loops, Conditionals, Switch Statements)
- ✅ **Error Handling & Edge Cases** (Validation, Exception Prevention)
- ✅ **User Interface Design** (Interactive Menus, Clear Prompts)
- ✅ **Code Organization & Best Practices** (Comments, Variable Naming)
- ✅ **Debugging & Testing** (Error Identification, Verification)

---

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| **Language** | C++ (100%) |
| **Total Lines of Code** | 70+ |
| **OOP Classes** | 1+ |
| **Error Handling Cases** | 2+ |

---

## 📂 Repository Structure

```
codsoft/
├── README.md                 # Project documentation
├── calculator.cpp            # Calculator source code
└── calculator proof.mp4       # Demo video
```

---

## 🎓 CodSoft Internship Info

**Program**: CodSoft Virtual Internship  
**Domain**: C++ Programming  
**Duration**: 4 Weeks  
**Certificates**: Upon completion of all projects  

---

## 📝 How to Use This Repository

1. **Clone the repository**
   ```bash
   git clone https://github.com/shan16052008-maker/codsoft.git
   cd codsoft
   ```

2. **Compile any project**
   ```bash
   g++ -o calculator calculator.cpp
   ```

3. **Run the executable**
   ```bash
   ./calculator
   ```

4. **Watch demo videos** for project output examples

---

## 👤 Author

**Shanmuga Priya**  
- 📧 Email: [Your Email]
- 🔗 LinkedIn: [Your LinkedIn]
- 💼 GitHub: [@shan16052008-maker](https://github.com/shan16052008-maker)

---

## 📜 License

This project is part of the CodSoft Internship Program.  
Feel free to use this code for learning purposes.

---

## 🤝 Contributing

Suggestions for code improvements are welcome!

---

## ⭐ If You Found This Helpful

Feel free to **star** this repository! It helps others discover quality learning resources.

---

**Last Updated**: May 12, 2026
