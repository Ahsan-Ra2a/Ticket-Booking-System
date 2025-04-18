# 🎟️ Ticket Booking System in C++

A powerful **console-based Ticket Booking System**, developed using **pure C++ and Object-Oriented Programming (OOP)** principles. This application simulates a real-world ticket booking experience for multiple services — including **Flights, Trains, Buses**, and **Cinema** — with secure login, signup, location selection, and card-based payment using the **Luhn Algorithm**.

> ✅ Built from scratch using only the C++ Standard Library — No external dependencies!

---

## 🧠 Overview

This system enables two types of users:
- **Admin** – Can log in and manage tickets (foundation built)
- **Customer** – Can **sign up**, **log in**, **choose ticket type**, **enter location**, and **pay online** using a **MasterCard or Debit Card**

After successful payment, the system generates a **ticket receipt**, which is saved in a file.

---

## 🚀 Key Features

### 👤 Authentication System
- **Customer Signup & Login**
  - Credentials are saved and fetched from `Users.txt`
- **Admin Login**
  - Protected admin access

### 🧾 Multi-Ticket Booking Options
- Book from a wide range of ticket types:
  - ✈️ **Plane / Flight Tickets**
  - 🚆 **Train Tickets**
  - 🚌 **Bus Tickets**
  - 🎬 **Cinema Tickets**
- Dynamic menu based on user selection

### 📍 Location Module
- System asks the user for **source** and **destination**
- Adjusts flow based on location and ticket type

### 💳 Secure Payment Integration
- Users can pay via:
  - **MasterCard**
  - **Debit Card**
- Luhn Algorithm checks:
  - Card number validity
  - Expiry date
  - CVV and PIN verification
- Balance deduction and validation
- Details fetched/stored in `Accounts.txt`

### 🖨️ Ticket Receipt
- After successful booking & payment
- Ticket details are printed into a file for user reference

---

## 🧱 Code Structure

File | Description
main.cpp | Entry point of the program, handles the initial menu and user interaction
project.h | Header file for ticket types, locations, and booking utilities
project.cpp | Implements ticket booking, location handling, and user-side logic
Account.h | Contains class declarations for accounts and payments
Account.cpp | Implements account handling, card validation (Luhn), and payment system
Users.txt | Stores registered usernames and passwords
Accounts.txt | Stores card details and balances for payment
---

## 🧰 Tech Stack

- **Language:** C++
- **Concepts Used:**
  - Classes & Inheritance
  - Encapsulation
  - File Handling
  - Control Structures
  - Algorithm (Luhn)
- **Storage:** File-based (plain `.txt`)

---

## ⚙️ How to Compile & Run

### 🔧 Compile:
```bash
g++ main.cpp project.cpp Account.cpp -o booking_system
```

### ▶️ Run:
```bash
./booking_system       # Linux/macOS
booking_system.exe     # Windows
```

---

## 📈 Planned Future Enhancements

- 📄 **Downloadable Tickets as PDF**
- 🖼️ **GUI version** using Qt or Web Interface
- 🌐 **Online Payment Integration** with real-time APIs
- 🧾 **Ticket History & Transaction Logs**
- 🔍 **Search-based Ticket Viewing**
- 📱 Mobile-compatible version

---

## 💡 Sample Flow

```text
1. Program starts → Menu shows ticket type
2. User selects "Plane"
3. System asks for location, destination, date
4. Ticket options are shown
5. User books → Payment via MasterCard or Debit Card
6. Ticket is saved to file
```

---

## 👨‍💻 Developer Note

This project is developed as a foundational practice in C++ using core logic, file handling, and object-oriented design. It's modular, expandable, and demonstrates real-world systems like booking workflows and card payment algorithms — all with a **no-library, from-scratch** approach.
