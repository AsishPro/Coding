use dbms;
create table cities(name varchar(20),state varchar(20));
describe cities;

insert into cities values('Rajahmundry','AndhraPradesh');
insert into cities values('Vijaywada','AndhraPradesh');
insert into cities values('chennai','tamil_nadu');
insert into cities values('Delhi','new delhi');

select * from cities