use dbms;
select * from sailor;

#a)
alter table sailor
add column boat varchar(20);
insert into sailor values(6,'parul',3,19,10,'Interlake');
insert into sailor values(7,'govind',3,25,5,'Interlake');

select * from sailor where boat='Interlake';

#find age of youngest sailor from each rating who is eligible to vote
select min(age) from sailor group by rating;
select * from sailor where age in (select min(age) from sailor group by rating) and age>18;

#b)
#reservations table
create table reservations(reservation_id int,bid int,sid int,datee date);
insert into reservations 
values
  (1, 101, 1, '2023-08-15'),
  (2, 102, 2, '2023-08-16'),
  (3, 103, 3, '2023-08-17'),
  (4, 104, 4, '2023-08-18'),
  (5, 105, 6, '2023-08-19');
  
select * from reservations;

#cartesian product and selection of correct records (can also use join)
select sname,bid,datee from sailor,reservations where sailor.sid=reservations.sid;

#c)
#starts and ends with r,u and has atleast 3 characters in between
select sname,age from sailor where sname like 'r__%u';

#d)
select * from sailor where boat='bringham';

#e)
select * from sailor where age in (select min(age) from sailor group by rating)