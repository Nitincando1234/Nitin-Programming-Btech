--Write the query to implement the concept of Integrity constrains.
CREATE DATABASE EXERCISE5;
USE EXERCISE5;
CREATE TABLE employee(
    EmployeeID INT(10) PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255)
);
CREATE TABLE orders(
    OrderID INT(10) PRIMARY KEY,
    OrderDate DATE,
    EmployeeID INT(10),
    FOREIGN KEY (OrderID) REFERENCES Employee(EmployeeID)
);
CREATE TABLE users(
    UserID INT(20) PRIMARY KEY,
    Username VARCHAR(100) NOT NULL,
    Email VARCHAR(100) UNIQUE
);
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Age INT,
    CHECK (Age >= 18)
);
CREATE TABLE ordersMOBILE(
    OrderID INT(10) PRIMARY KEY,
    OrderDATE DATE,
    Status VARCHAR(20) DEFAULT 'PENDING'
);