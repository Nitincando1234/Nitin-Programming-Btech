-- Active: 1721560337354@@127.0.0.1@3306@org
CREATE DATABASE ORG;
use ORG;
DROP DATABASE ORG;
create table worker(
    Worker_id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    Fname VARCHAR(255),
    LastName VARCHAR(255),
    Salary INT(10),
    JoinDate DATETIME,
    Department VARCHAR(50)
);
-- DROP TABLE ---; --- Use by removing "---"
INSERT INTO worker(Worker_id,Fname,LastName,Salary,JoinDate,Department) values
(001,'John', 'Doe', 50000, '2022-01-15 09:00:00', 'IT'),
(002,'Jane', 'Smith', 55000, '2021-02-20 10:30:00', 'HR'),
(003,'Michael', 'Brown', 60000, '2020-03-25 11:45:00', 'Finance'),
(004,'Emily', 'Davis', 65000, '2019-04-30 12:00:00', 'Marketing'),
(005,'Daniel', 'Wilson', 70000, '2018-05-05 08:15:00', 'Sales'),
(006,'Emma', 'Johnson', 75000, '2017-06-10 09:45:00', 'Support'),
(007,'Olivia', 'Taylor', 80000, '2016-07-15 10:00:00', 'R&D'),
(008,'James', 'Anderson', 85000, '2015-08-20 11:15:00', 'Logistics'),
(009,'Charlotte', 'Thomas', 90000, '2014-09-25 12:30:00', 'Production'),
(010,'Liam', 'Martinez', 95000, '2013-10-30 13:45:00', 'Management'),
(011,'McMhon', 'Milne', 95000, '2013-10-30 13:46:00', 'Management');
SELECT * FROM worker;
CREATE Table Bonus(
    Worker_ref_id INT(10) NOT NULL,
    Bonus_amt INT(5),
    Bonus_date DATE,
    FOREIGN KEY(Worker_ref_id) REFERENCES worker(Worker_id)
);
INSERT INTO Bonus(`Worker_ref_id`,`Bonus_amt`,`Bonus_date`) VALUES
(1, 500, '2022-01-15'),
(2, 600, '2022-02-20'),
(3, 700, '2022-03-25'),
(4, 800, '2022-04-30'),
(5, 900, '2022-05-05'),
(6, 1000, '2022-06-10'),
(7, 1100, '2022-07-15'),
(8, 1200, '2022-08-20'),
(9, 1300, '2022-09-25'),
(10, 1400, '2022-10-30');
SELECT * FROM Bonus;
CREATE Table Title(
    Worker_ref_id INT(10),
    Worker_title CHAR(255),
    Affected_from DATE,
    FOREIGN KEY(Worker_ref_id) REFERENCES worker(Worker_id)
);
INSERT INTO Title(`Worker_ref_id`, `Worker_title`, `Affected_from`) VALUES
(1, 'Software Engineer', '2020-01-15'),
(2, 'HR Manager', '2021-02-20'),
(3, 'Financial Analyst', '2022-03-25'),
(4, 'Marketing Specialist', '2019-04-30'),
(5, 'Sales Executive', '2018-05-05'),
(6, 'Support Technician', '2017-06-10'),
(7, 'R&D Scientist', '2016-07-15'),
(8, 'Logistics Coordinator', '2015-08-20'),
(9, 'Production Supervisor', '2014-09-25'),
(10, 'General Manager', '2013-10-30');

SELECT * FROM worker WHERE Salary BETWEEN 50000 and 80000;
-- *SELECT now();
-- *SELECT UCASE("Nitin");
-- *SELECT 66+11; --returns 77
SELECT * FROM worker WHERE `Department`='HR' OR `Department`='IT';
--upper and lower both are same
SELECT * FROM worker WHERE `Department` in ('HR','IT');
SELECT * FROM worker WHERE NOT `Department`='HR';
SELECT * FROM worker WHERE `Department` IS NULL;
SELECT * FROM worker WHERE `Fname` LIKE '%h_';
SELECT * FROM worker ORDER BY `Salary` DESC;--or ...ASC;
SELECT DISTINCT Department from worker;
SELECT Department,COUNT(*) from worker GROUP BY `Department`;
SELECT department, AVG(`Salary`) FROM worker GROUP BY `Department`;
SELECT department, MIN(`Salary`) FROM worker GROUP BY `Department`;
SELECT SUM(salary) from worker ;
SELECT department,count(department) FROM worker GROUP BY `Department` having COUNT(`Department`)=2;
CREATE Table Customer(Name VARCHAR(255), Address VARCHAR(1024), Phone VARCHAR(15), Email VARCHAR(255) UNIQUE DEFAULT "XXX@MAIL.XX", Age INT(5), CONSTRAINT age_check CHECK(Age > 12));
DROP TABLE Customer;
INSERT INTO Customer (Name, Address, Phone, Email, Age) VALUES
('Customer1', '1 Main St, Springfield', '+911234567001', 'customer1@example.com', 25),
('Customer2', '2 Main St, Springfield', '+911234567002', 'customer2@example.com', 30),
('Customer3', '3 Main St, Springfield', '+911234567003', 'customer3@example.com', 22),
('Customer4', '4 Main St, Springfield', '+911234567004', 'customer4@example.com', 27),
('Customer5', '5 Main St, Springfield', '+911234567005', 'customer5@example.com', 35),
('Customer6', '6 Main St, Springfield', '+911234567006', 'customer6@example.com', 40),
('Customer7', '7 Main St, Springfield', '+911234567007', 'customer7@example.com', 28),
('Customer8', '8 Main St, Springfield', '+911234567008', 'customer8@example.com', 31),
('Customer9', '9 Main St, Springfield', '+911234567009', 'customer9@example.com', 33),
('Customer10', '10 Main St, Springfield', '+911234567010', 'customer10@example.com', 24),
('Customer11', '11 Main St, Springfield', '+911234567011', 'customer11@example.com', 29),
('Customer12', '12 Main St, Springfield', '+911234567012', 'customer12@example.com', 36),
('Customer13', '13 Main St, Springfield', '+911234567013', 'customer13@example.com', 23),
('Customer14', '14 Main St, Springfield', '+911234567014', 'customer14@example.com', 32),
('Customer15', '15 Main St, Springfield', '+911234567015', 'customer15@example.com', 38),
('Customer16', '16 Main St, Springfield', '+911234567016', 'customer16@example.com', 27),
('Customer17', '17 Main St, Springfield', '+911234567017', 'customer17@example.com', 34),
('Customer18', '18 Main St, Springfield', '+911234567018', 'customer18@example.com', 29),
('Customer19', '19 Main St, Springfield', '+911234567019', 'customer19@example.com', 31),
('Customer20', '20 Main St, Springfield', '+911234567020', 'customer20@example.com', 26),
('Customer21', '21 Main St, Springfield', '+911234567021', 'customer21@example.com', 25),
('Customer22', '22 Main St, Springfield', '+911234567022', 'customer22@example.com', 30),
('Customer23', '23 Main St, Springfield', '+911234567023', 'customer23@example.com', 22),
('Customer24', '24 Main St, Springfield', '+911234567024', 'customer24@example.com', 27),
('Customer25', '25 Main St, Springfield', '+911234567025', 'customer25@example.com', 35),
('Customer26', '26 Main St, Springfield', '+911234567026', 'customer26@example.com', 40),
('Customer27', '27 Main St, Springfield', '+911234567027', 'customer27@example.com', 28),
('Customer28', '28 Main St, Springfield', '+911234567028', 'customer28@example.com', 31),
('Customer29', '29 Main St, Springfield', '+911234567029', 'customer29@example.com', 33),
('Customer30', '30 Main St, Springfield', '+911234567030', 'customer30@example.com', 24),
('Customer31', '31 Main St, Springfield', '+911234567031', 'customer31@example.com', 29),
('Customer32', '32 Main St, Springfield', '+911234567032', 'customer32@example.com', 36),
('Customer33', '33 Main St, Springfield', '+911234567033', 'customer33@example.com', 23),
('Customer34', '34 Main St, Springfield', '+911234567034', 'customer34@example.com', 32),
('Customer35', '35 Main St, Springfield', '+911234567035', 'customer35@example.com', 38),
('Customer36', '36 Main St, Springfield', '+911234567036', 'customer36@example.com', 27),
('Customer37', '37 Main St, Springfield', '+911234567037', 'customer37@example.com', 34),
('Customer38', '38 Main St, Springfield', '+911234567038', 'customer38@example.com', 29),
('Customer39', '39 Main St, Springfield', '+911234567039', 'customer39@example.com', 31),
('Customer40', '40 Main St, Springfield', '+911234567040', 'customer40@example.com', 26),
('Customer41', '41 Main St, Springfield', '+911234567041', 'customer41@example.com', 25),
('Customer42', '42 Main St, Springfield', '+911234567042', 'customer42@example.com', 30),
('Customer43', '43 Main St, Springfield', '+911234567043', 'customer43@example.com', 22),
('Customer44', '44 Main St, Springfield', '+911234567044', 'customer44@example.com', 27),
('Customer45', '45 Main St, Springfield', '+911234567045', 'customer45@example.com', 35),
('Customer46', '46 Main St, Springfield', '+911234567046', 'customer46@example.com', 40),
('Customer47', '47 Main St, Springfield', '+911234567047', 'customer47@example.com', 28),
('Customer48', '48 Main St, Springfield', '+911234567048', 'customer48@example.com', 31),
('Customer49', '49 Main St, Springfield', '+911234567049', 'customer49@example.com', 33),
('Customer50', '50 Main St, Springfield', '+911234567050', 'customer50@example.com', 24),
('Customer51', '51 Main St, Springfield', '+911234567051', 'customer51@example.com', 29),
('Customer52', '52 Main St, Springfield', '+911234567052', 'customer52@example.com', 36),
('Customer53', '53 Main St, Springfield', '+911234567053', 'customer53@example.com', 23),
('Customer54', '54 Main St, Springfield', '+911234567054', 'customer54@example.com', 32),
('Customer55', '55 Main St, Springfield', '+911234567055', 'customer55@example.com', 38),
('Customer56', '56 Main St, Springfield', '+911234567056', 'customer56@example.com', 27),
('Customer57', '57 Main St, Springfield', '+911234567057', 'customer57@example.com', 34),
('Customer58', '58 Main St, Springfield', '+911234567058', 'customer58@example.com', 29),
('Customer59', '59 Main St, Springfield', '+911234567059', 'customer59@example.com', 31),
('Customer60', '60 Main St, Springfield', '+911234567060', 'customer60@example.com', 26),
('Customer61', '61 Main St, Springfield', '+911234567061', 'customer61@example.com', 25),
('Customer62', '62 Main St, Springfield', '+911234567062', 'customer62@example.com', 30),
('Customer63', '63 Main St, Springfield', '+911234567063', 'customer63@example.com', 22),
('Customer64', '64 Main St, Springfield', '+911234567064', 'customer64@example.com', 27),
('Customer65', '65 Main St, Springfield', '+911234567065', 'customer65@example.com', 35),
('Customer66', '66 Main St, Springfield', '+911234567066', 'customer66@example.com', 40),
('Customer67', '67 Main St, Springfield', '+911234567067', 'customer67@example.com', 28),
('Customer68', '68 Main St, Springfield', '+911234567068', 'customer68@example.com', 31),
('Customer69', '69 Main St, Springfield', '+911234567069', 'customer69@example.com', 33),
('Customer70', '70 Main St, Springfield', '+911234567070', 'customer70@example.com', 24),
('Customer71', '71 Main St, Springfield', '+911234567071', 'customer71@example.com', 29),
('Customer72', '72 Main St, Springfield', '+911234567072', 'customer72@example.com', 36),
('Customer73', '73 Main St, Springfield', '+911234567073', 'customer73@example.com', 23),
('Customer74', '74 Main St, Springfield', '+911234567074', 'customer74@example.com', 32);

SELECT * FROM customer;
ALTER TABLE Customer ADD Col VARCHAR(255);
ALTER TABLE Customer MODIFY Name VARCHAR(1024);
ALTER TABLE Customer CHANGE Name Fullname VARCHAR(255);
ALTER TABLE Customer RENAME COLUMN Fullname TO Name;
ALTER TABLE Customer DROP COLUMN Col;
UPDATE Customer SET Age = Age + 1 WHERE Name = "Customer70";
DELETE FROM Customer WHERE Name = "Customer74";

