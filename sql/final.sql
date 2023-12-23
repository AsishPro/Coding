show databases;
use dbms;
create database endsem;
show tables;
use endsem;
show tables;
create table branch(name int, area varchar(20), aassert varchar(20));
show tables;
describe branch;
alter table branch
add primary key(name);
alter table branch
modify area varchar(40) not null;

#to modify datatype
alter table branch
modify area varchar(20);


#w1)
insert into branch(name,area) values(1,'23');
select * from branch;

#add column
alter table branch
add column price int;

#drop column
alter table branch
drop column price;

##rename
alter table branch
change rate mat varchar(20);

select * from branch;

start transaction;
insert into branch values(2,'45','5000','1cr');
insert into branch values(1,'45','5000','1cr');
rollback;


delete from branch
where name=1 or name=2;

start transaction;
insert into branch values(1,'55','3000','2cr',NULL);
insert into branch values(2,'45','5000','1cr',NULL);
savepoint insertion;

delete from branch
where  name=2;

rollback to insertion;

#update 
update branch
set area=50;
alter table branch
add column t2 time;
select * from branch;

rollback to insertion;

insert into branch values(3,40,6000,'3cr',NULL);
update branch
set mat='5cr'
where area=40;

alter table branch
add unique key(mat);

insert into branch values(5,40,6000,'3cr',NULL);
delete from branch where name>3


#week3
#1
use dbms;
select * from employee;
select ename from employee where deptno=10;
select ename,avg(Sal) from employee where deptno=10 group by ename;
select deptno,avg(Sal) from employee group by deptno;


select deptno,count(*) from employee group by deptno;
select * from employee where Sal in (select max(Sal) from employee);

select * from employee where ename in (select max(ename) from employee);


#lowest paid employee
select min(Sal) from employee group by deptno;
select * from employee where Sal in (select min(Sal) from employee group by deptno);
select count(*) from employee;

select * from employee where ename like 's%' or ename like 'a%';

#2
use dbms;
select * from employee;
select job,avg(Sal) from employee group by job;

select job,avg(Sal) from employee group by job having job!="Manager";
select job,avg(Sal) from employee  where job not in ('Manager') group by job;

select deptno,avg(Sal) from employee  group by deptno having count(deptno)>3;

select min(Sal) from employee where deptno=10;
select * from employee where Sal>(select min(Sal) from employee where deptno=10);

select sign(22.5);

show databases;
select * from branch;
alter table branch
change tim birth date;
update branch
set birth="2004-05-28"
where name=1;
select * from branch;
select datediff(curdate(),birth) as age
from branch where name=1;

use dbms;
select * from employee;
select concat(ename,'-',job) as concatt from employee;

select ename, Sal, 15*(Sal/100) as incre from employee;

select * from employee where managerid is not null and  Sal in (Select min(Sal) from employee group by managerid);

select avg(Sal) from employee group by deptno;

select * from employee;
select deptno,avg(Sal) from employee group by deptno having count(*)>2;

select ename,avg(Sal) from employee where deptno=10 group by ename,deptno;

select count(*) from employee where deptno=10;

select * from employee where job='clerk';
select * from employee where job="clerk" and Sal in (Select min(Sal) from employee where job="clerk");

select min(Sal) from employee group by ename,job having job="clerk";

select min(Sal),max(Sal), avg(Sal) from employee;

select job,min(Sal),max(Sal) from employee group by job;

select ename from employee order by ename desc;

select empno,ename from employee order by empno;

select * from sailor;

select * from sailor where age in (select min(age) from sailor where age>18 group by rating having count(*)<2);

select sname,sailor.sid,bid,datee from sailor,reservations where sailor.sid=reservations.sid;
insert into sailor values(9,'arush',5,10,2,NULL);
select sname,age from sailor where sname like "a__%h";
select sname from sailor,reservations where sailor.sid=reservations.sid;

select min(age),rating from sailor group by rating;
select * from vendor;
select * from vendor where abs(datediff(date1,date2))<180;
insert into vendor values(5,'assembled','non-local',300,'2021-05-01','2023-05-01');
insert into vendor values(6,'sub-parts','non-local',100000,'2021-05-01','2023-05-01');
select id from vendor where part_type in ('assembled','sub-parts');

select id from vendor group by id having count(distinct part_type)=2;
select vendor_type from vendor group by vendor_type;
select * from vendor where part_type='sub-parts' and part_cost>(select max(part_cost) from vendor where part_type='assembled');

select part_type from vendor group by part_type;

select  * from vendor where part_type='assembled'and part_cost!=(select max(part_cost)from vendor where part_type='assembled')  order by part_cost desc limit 1;
select  * from vendor where part_type='assembled' order by part_cost desc limit 1 offset 1;

select * from catalog;

select parts.pid from catalog,parts where catalog.pid=parts.pid group by parts.pid order by count(parts.pid) desc limit 1;

select sName from suppliers where sid in (select sid,count(pid) as cnt from catalog group by sid order by count(pid) desc limit 1);


select sid from catalog group by sid having count(*)= (select count(*) from parts);

select sName from Suppliers where sid =
(select sid from Catalog where pid in (SELECT pid FROM Parts WHERE color = 'red') order by
cost limit 1);

create view temp(sid,pid) as (select sid,pid from catalog);
select distinct(pid) from temp;

use endsem;
show tables;

create table patient (PID int primary key,namee varchar(20),DID int ,report varchar(20),phno varchar(11));
create table roomdet(PID int, roomno int, foreign key(PID) references patient(PID));

insert into roomdet values(1,2)
