-- use dbms;
-- create table Customer(Cust_name int,Cust_street varchar(20),Cust_city varchar(20));
-- describe Customer
#adding primary key
-- alter table Customer 
-- add primary key(Cust_name)

#a) 
#adding foreign key construct to name referencing empno from Employee table
-- alter table Customer
-- add foreign key(Cust_name)
-- references Employee(empno)

#b) testing foregin key constraint
-- insert into Customer values(1,'ring','guntur')  #not possible as '1' is not present 

#testing with good value
-- insert into Customer values(101,'ring','guntur')   #sucess

#c) inserting records
-- insert into Customer values(102,'iltd','rajahmundry');
-- insert into Customer values(103,'kkr','vizag');

#d) adding salary column
-- alter table Customer
-- add column Salary float
-- select * from Customer 

#e) changing domain of Customer from float to int
-- alter table Customer
-- modify Salary int 
-- describe Customer

#f) Dropping salary column
-- alter table Customer
-- drop column Salary
-- describe Customer

#g) adding one row and deleting 
-- insert into Customer values(105,'gach','hyd');
-- select * from Customer

#h) removing the rows(if multiple)
-- delete from Customer
-- where Cust_city='hyd'
-- select * from Customer
