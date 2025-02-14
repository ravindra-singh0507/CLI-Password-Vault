# CLI-Password-Vault
📌 Secure Password Manager (CLI-based)
🔒 A C++ command-line password manager using SQLite for storage, bcrypt for password hashing, and AES encryption for enhanced security.

🚀 Features
✅ Secure Storage – Saves passwords in an encrypted SQLite database.
✅ Master Password Protection – Uses bcrypt hashing to secure the master password.
✅ AES Encryption – Encrypts stored credentials for maximum security.
✅ Command-line Interface – Simple and fast CLI-based operations.
✅ Cross-Platform Support – Runs on Windows, Linux, and macOS.

🛠 Tech Stack
🔹 C++ – Core programming language
🔹 SQLite – Local database for secure password storage
🔹 bcrypt – Hashing for secure master password authentication
🔹 AES Encryption – Encrypts passwords before storing them

📌 Installation
1️⃣ Clone the Repository
2️⃣ Install Dependencies
🔹 Windows
Install MinGW (if not installed)
Download SQLite3: SQLite Download
Extract and place sqlite3.h, sqlite3.dll, and sqlite3.lib in the project directory
3️⃣ Compile the Project

🔒 Security Features
🔹 Master Password Hashing – Uses bcrypt to securely store master passwords.
🔹 AES Encryption – Encrypts stored credentials before saving them in the database.
🔹 Salting and Hashing – Ensures passwords are never stored in plaintext.
