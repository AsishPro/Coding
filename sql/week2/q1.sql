use dbms;
create table branch(name int,area varchar(20),asserts varchar(20));
describe branch;

#A
alter table branch
add foreign key(name)
references cities(name);

#B)
alter table branch
modify asserts varchar(50);

#C
alter table branch
add column income int;

alter table branch
drop column income;

#D)
#renaming the column to avoid confusion
alter table branch
change city area varchar(20);
insert into branch values('rajahmundry','av_road','20000000');
insert into branch values('Vijaywada','ring','15000000');
insert into branch values('chennai','gandhi_rd','2223000');
select * from branch;

-- insert into branch values('guntur','ring','2020202')

#F) #dropping two columns
alter table branch
drop column area,
drop column asserts;


