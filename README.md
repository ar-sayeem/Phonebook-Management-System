
# 📱 Phonebook Management System

The **Phonebook Management System** is a C-based application for efficient contact management, offering features like add, delete, update, search, sort, call history tracking, and quick dial via a user-friendly console interface.

---

## 🚀 Features

- **Add Contacts**: Add new contacts with a name and phone number.
- **Delete Contacts**: Remove contacts by name.
- **Update Contact Information**: Modify existing contact details.
- **Search Contacts**: Find a contact quickly by name.
- **Sort Contacts**: Sort contacts by name or phone number.
- **Show All Contacts**: Display the complete contact list.
- **Call History**: View the number of calls made to each contact.
- **Quick Dial**: Simulate calling a contact instantly.
- **Recent Calls**: Check the recent call activity.
- **Data Persistence**: All contacts are saved to a file (`contacts.txt`) for reuse in future sessions.

---

## 🛠️ Technology Stack

- **Language**: C
- **File Handling**: Used for persistent storage of contact data.
- **Standard Libraries**: `stdio.h`, `stdlib.h`, and `string.h`.

---

## 📂 Project Structure

- **`contacts.txt`**: Stores all contact information to ensure data is retained between sessions.
- **Functions**: Modularized to handle each functionality like adding, updating, or deleting contacts.

---

## 🎯 How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/phonebook-management-system.git
   ```
2. Open the project in your preferred IDE (e.g., Code::Blocks, Visual Studio, etc.).
3. Compile and run the `main.c` file.
4. Use the menu options to interact with the system.

---

## 💡 Key Highlights

- **Modular Code**: Each functionality is handled by a separate function, making the code easy to read and maintain.
- **User-Friendly Interface**: Intuitive menu-driven navigation with helpful prompts and feedback messages.
- **File Storage**: Ensures all contact data is securely saved in a file, eliminating data loss on program termination.

---

## 🔍 Sample Menu

```
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
x                               PHONEBOOK MANAGEMENT                        x
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
x                               1. Add Contact                              x
x                               2. Delete Contact                           x
x                               3. Update Contact                           x
x                               4. Search Contact                           x
x                               5. Sort Contacts                            x
x                               6. Show Contacts                            x
x                               7. Show Call History                        x
x                               8. Quick Dial                               x
x                               9. Recent Call List                         x
x                              10. Exit                                     x
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
```

---

## 📌 Future Enhancements

- Add import/export functionality for contacts in `.csv` format.
- Implement password protection for secure access.
- Enhance call history tracking with timestamps.
- Add a graphical user interface (GUI) for a more modern experience.

---

## 📝 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 🤝 Contributing

Contributions are welcome! Feel free to fork the repository, create a new branch, and submit a pull request with your improvements.
