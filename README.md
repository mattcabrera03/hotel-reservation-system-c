# hotel-reservation-system-c

A command-line hotel reservation system implemented in C. The program simulates a basic hotel management system with support for booking rooms, managing customer information, calculating stay duration, generating bills, and viewing room status reports through a menu-driven interface.

---

## 📌 Features

- Book hotel rooms (Normal or Deluxe)
- Store and manage customer information
- View and edit customer details
- Calculate stay duration automatically
- Generate billing upon checkout
- View full room status report
- Menu-driven interface for easy interaction

---

## 📌 Available Operations

### B (Book Room)

Books a room based on type:

- 0 = Normal room  
- 1 = Deluxe room  

You will be prompted to enter customer details including:

- Name  
- Email  
- Address  
- Phone number  
- Check-in and check-out dates  

---

### V (View Customer Details)

Displays all stored information for a selected room.

---

### E (Edit Customer Details)

Allows modification of an existing booking’s customer information.

---

### C (Check Out)

Checks out a customer and calculates the total bill based on:

- Room type:
  - Normal: $50 per day  
  - Deluxe: $80 per day  
- Duration of stay  

---

### A (Room Report)

Displays a summary of all rooms including:

- Room number  
- Status (Vacant or Booked)  
- Customer name (if booked)  

---

### X (Exit)

Exits the program.

---

## 🏨 System Details

- Supports **20 total rooms**
- Rooms are split into:
  - First 10 → Normal rooms  
  - Last 10 → Deluxe rooms  
- Each room stores:
  - Customer information  
  - Check-in / check-out dates  
  - Booking status  
- Uses structs for organized data handling
