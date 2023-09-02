
create table sailor(sid int,sname varchar(20),rating varchar(20),age int);
describe sailor;

#a)
insert into sailor values(1,'raju','3',23);
insert into sailor values(2,'harsha','1',46);
insert into sailor values(3,'dhanush','4',24);
insert into sailor values(4,'asish','5',20);
commit;
-- select * from sailor

#testing commit
start transaction;
insert into sailor values(5,'manoj','5',56);
rollback;

#b) adding save point
commit;
start transaction;
savepoint inserted;
#testing
insert into sailor values(5,'killua','2',99);
rollback to inserted;

#c) adding constraints
alter table sailor 
add primary key(sid);
alter table sailor
modify sname varchar(20) not null;
describe sailor;

#d)
alter table sailor
add column experience int;

#f)
insert into sailor values(6,'rajiv','9',23,10);
insert into sailor values(7,'roop','10',23,10);

delete from sailor
where rating>8;
select * from sailor;

#g) 
update sailor
set experience=10;

#h)
insert into sailor values(5,NULL,NULL,NULL,NULL);
insert into sailor values(5,'rock',NULL,NULL,NULL);









