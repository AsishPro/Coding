use dbms;
create table test(sno int,name varchar(20));
alter table test
add primary key(sno);

insert into test(sno) values(1);
select * from test;