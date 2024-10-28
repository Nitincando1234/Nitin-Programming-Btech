create DATABASE employee1;
use employee1;
create table employee(
    name VARCHAR(255),
    dept VARCHAR(20)
);
insert into employee VALUES
('nitin','sales'),
('nitin','hr'),
('nitin','finance'),
('nitin','hr'),
('nitin','sales'),
('nitin','sales'),
('nitin','sales'),
('nitin','sales');
SELECT * FROM employee;
create View sales_employee as 
select * from employee where dept='sales';
SELECT * from sales_employee;