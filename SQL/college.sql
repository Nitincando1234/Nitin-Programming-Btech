drop DATABASE college;
create DATABASE college;
use college;
create table Student(sid varchar(10),sname varchar(30),address varchar(100),phone int(10),gender char(2));
create table Semester(unid varchar (10),semester varchar(4),section varchar(4));
create table NewClass(sid varchar(10),unid varchar(10));
create table NewSubject(subjectcode varchar(10),title varchar (10),semester varchar(4),credits int(3));
create table marks(unid varchar(10),subjectcode varchar(10),sid varchar(10),test1 int(10),test2 int(10),test3 int(10),finalA int(10));
drop table Semester;
desc Student;
desc Semester;
desc Newclass;
desc NewSubject;
desc marks;
alter table newclass
change unid SSID varchar(10);
insert into Student 
VALUES
("101","Kailash","Makhupura",978400000,"m"),
("102","Nitin","Ajmer",97840000,"m"),
("103","Aman","Ajmer",978400000,"m"),
("104","Anil","Nagaur",978400000,"m"),
("105","Vineet","Ajmer",978400000,"m");
--drop TABLE Student;
SELECT *from Student;
insert into Semester
VALUES
("abc1","four","cb2"),
("abc2","four","cb2"),
("abc3","four","cb1"),
("abc4","four","cb1"),
("abc5","four","cb1");
SELECT* from Semester;
insert INTO NewClass
values
("101","abc1"),
("102","abc2"),
("103","abc3"),
("104","abc4"),
("105","abc5");
SELECT* from NewClass;
insert into NewSubject
VALUES
("math1","maths","four",4),
("se3","softwareen","four",3),
("pyth","python","four",2),
("C11","c++","four",4),
("d32","digitalec","four",3);
--drop table NewSubject;
select * from NewSubject;
insert into marks
VALUES
("abc1","math1","101",98,67,96,90),
("abc1","se3","101",78,56,67,56),
("abc1","pyth","101",89,76,56,68),
("abc1","c11","101",87,78,75,67),
("abc1","d32","101",90,68,67,67);
insert into marks
VALUES
("abc2","C11","102",56,67,96,90),
("abc2","d32","102",78,87,67,56),
("abc2","pyth","102",89,76,65,68),
("abc2","math1","102",87,78,75,96),
("abc2","se3","102",90,68,26,67);
--drop table marks;
select *from marks;
--making primary keys
alter table Student
add primary key (sid);
--sid->usn in Student
alter table Student
change sid USN varchar(10);
--unid-> SSID in Semester
alter Table Semester
CHANGE unid SSID varchar(10);
alter table Semester
add primary key(SSID);
alter table NewSubject
add primary key(subjectcode);
alter table NewClass change COLUMN usn USN varchar(10);
select * from marks;
alter table marks
add FOREIGN KEY (USN) REFERENCES Student (USN);
select *from Semester;
--find the students based on sem='four' and section='cb2'
select s.*,sem.semester,sem.section
from Student s,Semester sem,NewClass c
where sem.SSID=c.SSID and
s.USN=c.USN AND
sem.Semester='four' AND
sem.section='cb2'
;
--count the number of the female and male students of each section and semester
select ss.Semester,ss.section,s.gender,count (s.Gender) FROM
NewClass c, Semester ss, Student s
where ss.SSID=c.SSID AND
s.USN=c.USN
GROUP BY ss.semester,ss.section,s.gender
ORDER BY ss.semester;
--create a view for the student 'usn=101' 's test1 marks
create view view_of_marks AS
select subjectcode,test1
from marks 
where USN='101';
select *from view_of_marks;
--find finalA
update marks
set finalA=((test1+test2+test3-least(test1,test2,test3))/2);
SELECT* from marks;
select m.finalA,s.USN,s.sname,s.gender,s.address,
case
    when m.finalA > 80 then 'outstanding'
    when m.finalA <= 80 and m.finalA >= 70 then 'average'
    else 'weak'
end as cat
from Marks m,Student s,semester sem,NewSubject sub
where s.USN=m.USN and
sem.semester='four' and
m.SSID=SEM.SSID AND
m.subjectcode=sub.subjectcode;