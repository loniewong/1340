# 1340 Group Project
Project Ideas: Topic 1

## Problem Statement (what problem to solve)
To build a table management system for a family-owned restaurant. The system would manage reservation, occupancy on its own. It would basically replace the job of the employee standing behind the reception desk. Making the operating processes of the restaurnat become more efficient, the system could manage tables to fulfill the maximum amount of customer needs, thus increasing profit and decreasing workload of waiters.

## Problem Setting (reasonable assumptions)
Assume there are 50 seats and 3 different sizes of tables in the restaurant. First of all, for the small sized tables, they are mainly for people coming in pairs, like couples. Secondly, the medium sized tables are for people coming in small groups, a maximum of 4 people, like small families. Lastly, as for the large sized tables. They are for people coming in large groups, supporting more than 4 people, likes a big group of family and friends.

As the customer base of the restaruant changes seasonally, so the number and the size of tables could be modified in different seasons by combining and separating different tables. However, the number of seats is fixed, due to the limited physical size of the restaurant. 

## Functionalities and Features
There are a variety of functions and features that this system could perform.

To begin with, the system is mainly used to manage the table status of the restaurant, including the occupying and releasing of tables. The system should display clearly which tables are occupied and which are not. It would be able to change the status availability of tables through the input system.

Apart from doing basic table management, it would also be able to perform simple processing or calculations. For example, the system could automatically assign tables for customers in different sizes. The table is not assigned ramdomly, but to suggest a vacant table which has minimal enough seats to fulfill the customer size.

## Input/output Specifications & Execution Instructions
There are serveral inputs that the user should provide throughout the program operation.
First of all, after the start of the program. The user should type in the file name which contains the number of 6 and 4-person tables. The prgram should look the same as follows:
```
Input your table information file name: 
```
After the input of correct file name. A user manual would be printed out on screen asking for the user to select a specific function which the user wish to perform. The menu look like this:
```
Restaurent Table Management Menu
--------------------------------
1) Check Table Availability
2) Occupy a table
3) Release a table
4) Print table status

-1) Exit

Please enter your choice: 
```
The user should now input a integer corresponding to the menu shown to perform the described function.
# Suppose "1" is entered:
This function is to help check whehter a table is occupied or not.

The following menu would be printed out:
```
Table number of 2-person table: 1-9
Table number of 4-person table: 10-14
Table number of 6-person table: 15-17
Please input a valid table number: 
```
It would show the range of table numbers of those 3 sizes of tables. For this example, the number of tables of 2,4,6-person table is 9,5,3. 
The user should then enter the table number which he wants to check its availability on. Supposed ```1```is entered. It would print out a sentence:
```
Table 1 is unoccupied!
```
or
```
Table 1 is occupied!
```
to show whether the table number inputted is available or not.

# Suppose "2" is entered:
This function could help change the availability of tables into "Occupied".

The following sentence would be printed out:
```
Please input the number of customers:
```
The program would expect the user to input a integer. For example, ```4```.
After that, the program would search through the list of tables and output a smallest possible size of table which could fit the number of customers:
```
Thank you! Your table number is 17.
```
If all the tables are unavilable, then the prgram would output:
```
Sorry! All our tables are occupied at this moment! Please wait!
```
Or If the number of customers exceed the capacity of the largest table, then the program would output:
```
Sorry! We could not provide a table for more than 6 people! Please separate into 2 tables! Thanks!
Please input the number of customers again: 
```
Until a possible number of customers is inputted.

# Suppose "3" is entered:
This function is to help release a table, to change its availability to "unoccupied".

The following sentence would be pritned out:
```
Please input a table number of the table you want to release: 
```
It asks for a integer input denoting the table number of a table which the user wants to release. For example, ```17``` is entered by the user. The following sentence would be printed out to verify your action:
```
Table 17 is released!
```

# Suppose "4" is entered:
This function help print out all of the information of tables which the user wants. 

The following sentence would be printed out first:
```
Please input a table number to show its table information (0 = all tables): 
```
It asks for a integer input which denotes the table number of a table. If 0 is inputted, the program would print out the information of all tables. For example ```5``` is inputted instead. The following would be the output:
```
Table Number: 5
Table Size: 2
Table availability: Unoccupied
```
It would show the table number, the size of the table, and the availability of that table too.

# Suppose "-1" is entered:
The program would stop and all the data would be deleted, except the file and the data stored inside the file (number of 4 and 6-person table)
