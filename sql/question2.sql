-- show databases;
-- use dbms;
-- show tables;

-- begin;
-- create table Department(Deptno int,Deptname varchar(20),location varchar(20),Designation varchar(20));
-- insert into Department values(1,'cse','admin_block','ast_prof');
-- select * from Department;
-- rollback;
-- select * from Department;
-- commit;

-- insert into Department values(1,'cse','admin_block','ast_prof');
-- insert into Department values(2,'cse','admin_block','proffesor');
-- insert into Department values(3,'ece','admin_block','lecturer');

#adding unique contraint
#this syntax used to add contraint to multiple columns
-- alter table department
-- add constraint test unique key(Deptno);

-- describe department;

#trying to add but error due to unique constraint
-- insert into department (Deptno) values (1)


#not null constrain
-- alter table Department
-- modify Deptno int NOT NULL,
-- modify Deptname varchar(20) NOT NULL,
-- modify location varchar(20) NOT NULL,
-- modify Designation varchar(20) NOT NULL;

#inserting null values 
-- select * from Department
-- insert into Department values(3,NULL,NULL,NULL)

#adding new column
-- alter table department
-- add column age int;
-- desc department

-- insert into department values(4,'mech','new_block','phd',23);
-- insert into department values(5,'mech','new_block','phd',46);
-- insert into department values(6,'ece','new_block','student',22);
-- insert into department values(7,'cse','new_block','student',19);

-- select * from department

#order
-- select *
-- from department
-- order by deptname;

#update record 
-- update department
-- set deptname='mtech',location='research_block',designation='student',age=20
-- where deptno=3
-- select * from department

#drop a column
-- alter table department
-- drop column age









