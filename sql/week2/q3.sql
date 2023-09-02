use dbms;
create table reserves(boad_id int,sid varchar(20),day varchar(20));

#a)
alter table reserves
add foreign key(boad_id)
references sailor(sid);

describe reserves;

alter table reserves
modify sid varchar(20) not null;

#b)
start transaction;
insert into reserves values(1,'1','2023-08-21');
select * from reserves;
savepoint sp;

#c)
alter table reserves
add column tim time;

#d) 
alter table reserves
modify day date;
describe reserves;

#e)
alter table reserves
drop column tim;

#f)
delete from reserves
where sid='1';
select * from reserves
