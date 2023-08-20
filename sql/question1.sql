-- show databases
-- create database dbms
-- use dbms
-- create table Employee(empno int,ename varchar(20),job varchar(20),mgr int,Sal int,Commision int)-- 
-- show tables
-- describe Employee
-- insert into Employee values(101,'Asish','Manager',NULL,200000,NULL)
-- insert into Employee values(102,'Roop','assistant',101,100000,200)
-- insert into Employee values(103,'Pujitha','sales',101,150000,500)
-- select * from Employee

-- alter table Employee
-- add primary key(empno)
-- describe Employee

-- select * from Employee
# trying to add not null constraint to mgr (which has null)
-- alter table Employee
-- modify mgr int not null

-- alter table Employee
-- modify empno int not null
-- describe Employee

# trying to insert null values
-- insert into Employee(empno) values(NULL)

# adding one more column
-- alter table Employee
-- add column Commision_new int

-- update Employee
-- set Commision_new=20
-- where empno=101


# adding 5 more records
-- insert into Employee values(104,'Roger','Sales',101,10000,100,30)
-- insert into Employee 
-- values
-- (105,'ramesh','Sales',101,1000,500,70),
-- (109,'Nami','Clerk',101,4500,150,40),
-- (110,'gopi','Engineer',101,8000,300,60),
-- (112,'Rajiv','Engineer',101,3500,100,70);
	 

# update job column
-- update Employee
-- set job='pa'
-- where empno=103

-- select * from Employee where job='pa'

# change column name
-- alter table Employee
-- change mgr managerid int
-- describe Employee

# delete a row
-- delete from Employee
-- where empno=104;
