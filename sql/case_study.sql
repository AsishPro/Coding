create database library;
show databases;
use library;
create table Books(BID int ,Bookname varchar(20),Author varchar(20), Totalcopies int, available int,
CID int, primary key(BID));
describe books;
create table Categories(CID int,cname varchar(20),BID int,foreign key(BID)
references Books(BID));
describe Categories;

insert into Books values(1,'Wings of fire','apj_kalam',56,21,1);
select * from Books;
insert into Categories values(1,'Biography',1);
select * from Categories;


-- CREATE INDEX idx_categories_cid ON Categories(CID);
-- SHOW INDEX FROM Categories;

#adding foreign key of CID to Books
alter table Books
add foreign key(CID)
references Categories(CID);

create table Users(UID int primary key, Name varchar(20),Email varchar(20),Type varchar(20));
describe Users;

create table transactions(TID int primary key,UID int,BID int,borrowdata date,duedate date, returndate date,
foreign key(BID) references Books(BID),
foreign key(UID) references Users(UID));
describe transactions;

create table Fines(UID int,fineamount float,foreign key(UID) references Users(UID));
describe Fines;