/*
=============================================================================
Title       : hotel_reservation_system.c
Description : A C program that simulates a hotel reservation system with up to
              20 rooms. Supports booking rooms (normal/deluxe), storing and 
              editing customer information, viewing room status, calculating 
              stay duration and billing upon checkout, and generating room 
              reports via a menu-driven interface.
Author      : matthcab 
Date        : 12/04/2023
Version     : 1.0
Usage       : Compile using GCC (e.g., gcc hotel_reservation_system.c -o hotel)
C Version   : C11
=============================================================================
*/
#include<stdio.h>
#include<ctype.h>

char choice;
int tempSelection;

struct Date
{
    int day;
    int month;
    int year;
};

struct CustomerInfo
{
    char firstName[50];
    char lastName[50];
    char email[50];
    char address[50];
    char phoneNum[50];
    struct Date checkIn;
    struct Date checkOut;
};

struct RoomInfo
{
    int num;
    int status; //0 means vacant, 1 means booked
    int type; // 0 means normal, 1 means deluxe
    struct CustomerInfo customer;
}roomArr[20];

int monthToDay(int month)
{
    if(month == 1){
        return 0;
    }
    else if(month == 2){
        return 31;
    }
    else if(month == 3){
        return 59;
    }
    else if(month == 4){
        return 90;
    }
    else if(month == 5){
        return 120;
    }
    else if(month == 6){
        return 151;
    }
    else if(month == 7){
        return 181;
    }
    else if(month == 8){
        return 212;
    }
    else if(month == 9){
        return 243;
    }
    else if(month == 10){
        return 273;
    }
    else if(month == 11){
        return 304;
    }
    else if(month == 12){
        return 334;
    }
}

int daysSpentCalulator(int dayIn, int monthIn, int yearIn, int dayOut, int monthOut, int yearOut)
{

    int yearDiff = yearOut-yearIn;
    int monthDiff = monthToDay(monthOut) - monthToDay(monthIn);
    int dayDiff = dayOut - dayIn;

    return ((yearDiff)*365 + monthDiff + dayDiff);
}

void bookRoom(struct RoomInfo room[], int roomType)
{
    int assigned = 0;
    for(int i = 0; i<20; i++)
    {
        if((room[i].status == 0) && (room[i].type == roomType))
            {
            assigned = 1;
            room[i].status = 1;

            printf("\n");
            printf("Enter customer's first name: ");
            scanf("%s", &room[i].customer.firstName);
            printf("Enter customer's last name: ");
            scanf("%s", &room[i].customer.lastName);
            printf("Enter customer's email: ");
            scanf("%s", &room[i].customer.email);
            printf("Enter customer's address (use \".\" instead of spaces): ");
            scanf("%s", &room[i].customer.address);
            printf("Enter customer's phone number: ");
            scanf("%s", &room[i].customer.phoneNum);
            printf("Enter customer's check-in date (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &room[i].customer.checkIn.month, &room[i].customer.checkIn.day, &room[i].customer.checkIn.year);
            printf("Enter customer's check-out date (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &room[i].customer.checkOut.month, &room[i].customer.checkOut.day, &room[i].customer.checkOut.year);

            printf("\n");
            printf("Room %d is now checked out to %s %s\n", room[i].num, room[i].customer.firstName, room[i].customer.lastName);
            printf("\n");
            break;
        }
    }
    if(assigned == 0)
        {
        printf("No rooms of desired type available");
        }
}

void viewCustomerDetails(struct RoomInfo room[], int roomNum)
{
    if(room[roomNum-1].status == 1)
        {
        printf("\n");
        printf("Customer's first name: %s\n", room[roomNum-1].customer.firstName);
        printf("Customer's last name: %s\n", room[roomNum-1].customer.lastName);
        printf("Customer's email: %s\n", room[roomNum-1].customer.email);
        printf("Customer's address: %s\n", room[roomNum-1].customer.address);
        printf("Customer's phone number: %s\n", room[roomNum-1].customer.phoneNum);
        printf("Customer's check-in date: %d/%d/%d\n", room[roomNum-1].customer.checkIn.month, room[roomNum-1].customer.checkIn.day, room[roomNum-1].customer.checkIn.year);
        printf("Customer's check-out date: %d/%d/%d\n", room[roomNum-1].customer.checkOut.month, room[roomNum-1].customer.checkOut.day, room[roomNum-1].customer.checkOut.year);
        printf("\n");
        }
        else
        {
        printf("\n");
        printf("Room %d is vacant", roomNum);
        printf("\n");
        }
}

void editCustomerDetails(struct RoomInfo room[], int roomNum)
{

    if(room[roomNum-1].status == 1)
        {
        printf("\n");
        printf("Enter customer's first name: ");
        scanf("%s", &room[roomNum-1].customer.firstName);
        printf("Enter customer's last name: ");
        scanf("%s", &room[roomNum-1].customer.lastName);
        printf("Enter customer's email: ");
        scanf("%s", &room[roomNum-1].customer.email);
        printf("Enter customer's address (use \".\" instead of spaces): ");
        scanf("%s", &room[roomNum-1].customer.address);
        printf("Enter customer's phone number: ");
        scanf("%s", &room[roomNum-1].customer.phoneNum);
        printf("Enter customer's check-in date (Enter in the form of mm/dd/yyyy): ");
        scanf("%d/%d/%d", &room[roomNum-1].customer.checkIn.month, &room[roomNum-1].customer.checkIn.day, &room[roomNum-1].customer.checkIn.year);
        printf("Enter customer's check-out date (Enter in the form of mm/dd/yyyy): ");
        scanf("%d/%d/%d", &room[roomNum-1].customer.checkOut.month, &room[roomNum-1].customer.checkOut.day, &room[roomNum-1].customer.checkOut.year);
        }
    else
        {
        printf("\n");
        printf("Room %d is vacant", roomNum);
        printf("\n");
        }
}

void checkOut(struct RoomInfo room[], int roomNum)
{
    if(room[roomNum-1].status == 1)
        {
        int daysStayed = daysSpentCalulator(room[roomNum-1].customer.checkIn.day, room[roomNum-1].customer.checkIn.month, room[roomNum-1].customer.checkIn.year, room[roomNum-1].customer.checkOut.day, room[roomNum-1].customer.checkOut.month, room[roomNum-1].customer.checkOut.year);
        if(room[roomNum-1].type == 0)
            {
            int totalDue = daysStayed*50;
            printf("\nYour total due is $%d.00\n", totalDue);
            }
        else if(room[roomNum-1].type == 1)
            {
            int totalDue = daysStayed*80;
            printf("\nYour total due is $%d.00\n", totalDue);
            }
        room[roomNum-1].status = 0;
        }
    else{
        printf("\n");
        printf("Room %d is vacant", roomNum);
        printf("\n");
    }
}

void viewRoomReport(struct RoomInfo room[])
{
    printf("Room Number\tStatus\t\tCustomer First name\tCustomer Last Name\n");
    for(int i = 0; i < 20; i++)
        {
        printf("%d", room[i].num);//

        if(room[i].status == 1)
            {
            printf("\t\tBooked");
            printf("\t\t%s", room[i].customer.firstName);
            printf("\t\t\t%s\n", room[i].customer.lastName);
            }
        else
        {
            printf("\t\tVacant\n");
        }
    }
}

int main()
{
     for(int i = 0; i < 20; i++){ //adds room numbers and room types
        roomArr[i].num = i+1;

        if(i/10 == 1)
            {
            roomArr[i].type = 1;
            }
            else
            {
            roomArr[i].type = 0;
            }
    }
    while(choice!='X')
        {
        printf("\n**********MAIN MENU**********\n"); //Menu-driven program
        printf("Want to book a room? (Type B)\n");
        printf("View customer details? (Type V)\n");
        printf("Edit customer details? (Type E)\n");
        printf("Check out and get bill? (Type C)\n");
        printf("View room report (Type A)\n");
        printf("Exit and close all accounts? (Type X)");
        printf("\n*****************************\n");
        scanf(" %c",&choice);
        choice=toupper(choice);
        switch(choice)
        {
        case 'B': //book room
        printf("Enter the type of room(0 for normal and 1 for deluxe): ");
        scanf("%d", &tempSelection);
        bookRoom(roomArr, tempSelection);
        break;

        case 'V': //customer details
        printf("Enter the room number for the customer info would you like to view: ");
        scanf("%d", &tempSelection);
        viewCustomerDetails(roomArr, tempSelection);
        break;

        case 'E': //edit customer details
        printf("Enter the room number for the customer info would you like to edit: ");
        scanf("%d", &tempSelection);
        editCustomerDetails(roomArr, tempSelection);
        break;

        case 'C': //check out and know price for bill
        printf("Enter the room number for the customer info would you like to check out and bill: ");
        scanf("%d", &tempSelection);
        checkOut(roomArr, tempSelection);
        break;

        case 'A': //view all rooms
        viewRoomReport(roomArr);
        break;

        case 'X': //exit and closes all accounts
        break;

        default: printf("Please enter a correct function...");
        break;
        }
    }
    printf("Exiting program... (Press any button to exit terminal)");
}





