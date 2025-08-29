# Internet-Banking-and-Payment-System

## 📌 Problem Definition
This project simulates an **Internet Banking System** that enables users to securely access their bank accounts and carry out financial transactions online. It enhances the normal banking experience as it is **quick, free, and allows multiple operations without visiting a bank or ATM**.  

Key features:
- Maintains a validated transaction record and history.  
- Reduces unwanted risk through **encryption-based password protection**.  
- Allows account creation with details such as account holder name, account number, account type (Savings/Current), and initial amount.  
- Provides balance inquiry with account details.  
- Displays a list of all account holders.  

---

## ⚙️ Functionalities

1. **`new_acc()`** – Create a new account (Customer/Admin) using **File Handling**.  
2. **`edit()`** – Edit existing account details (Customer/Admin).  
3. **`erase()`** – Delete an account (Customer).  
4. **`transact()`** – Deposit or withdraw money (Customer).  
5. **`balance_enquiry()`** – Check balance with account details (Customer).  
6. **`near_bank()`** – View nearest ATM based on location using **Brute Force Searching Algorithm**.  
7. **`sort_acc()`** – Sort accounts by account number using **Insertion Sort Algorithm**.  
8. **`sort_amt(first, last)`** – Sort accounts by account balance using **Quick Sort Algorithm**.  

---

## 🛠️ Tools and Techniques

- **Data Structures & File Handling**
  - File data structure is used for storing and retrieving account details efficiently.  
  - File handling ensures persistence of account information across sessions.  

- **Sorting Algorithms**
  - **Insertion Sort** – Used for sorting account numbers. Best case runtime: `O(n)`, worst/average case: `O(n²)`. Simple and stable.  
  - **Quick Sort** – Used for sorting accounts by balance. Average case: `O(n log n)`, efficient and widely used despite worst case `O(n²)`.  

- **Searching Algorithm**
  - **Brute Force String Search** – Used to locate the nearest bank/ATM based on user’s location.  
  - Best case: `O(m)` comparisons, Worst case: `O(m*n)` comparisons.  

---

## 🚀 Key Learnings & Takeaways
- Choosing the **right data structure and algorithm** is crucial for solving real-world problems efficiently.  
- Ability to correlate **theory with practical applications** in banking systems.  
- Understanding and comparing **time complexities** of algorithms to improve code performance.  
- Focus should not only be on how code looks but on **efficiency, correctness, and scalability**.  
- Learned the importance of **encryption for security** in financial applications.
