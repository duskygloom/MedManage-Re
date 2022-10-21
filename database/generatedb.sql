create database MedManage-Re;
using MedManage-Re;


-- price = price per med

create table transactions (
	batch varchar(20),
	name varchar(255),
	qty int(10),
	cost float(12, 2), -- cost of the entire transaction
	client varchar(255),
	iscustomer bool default true,
	tdate date default getdate()
);

create table meds_available (
	batch varchar(20) primary key,
	name varchar(255),
	qty int(10),
	price float(8, 2),
	mfg date,
	exp date
);

create table meds_dumped (
	batch varchar(20) primary key,
	name varchar(255),
	qty int(10),
	price float(8, 2),
	mfg date,
	exp date,
	producer varchar(255),
	pdate date
);

create table meds_purchased (
	batch varchar(20) primary key,
	name varchar(255),
	qty int(10),
	price float(8, 2),
	mfg date,
	exp date,
	producer varchar(255),
	pdate date default getdate()
);

create table meds_sold(
	batch varchar(20),
	name varchar(255),
	qty int(10),
	price float(8, 2),
	consumer varchar(255),
	sdate date default getdate()
);
