-- contains queries to be used in-app
-- only for reference purpose, not to be executed directly
-- the source code will decide how to query the database


-- while purchasing
-- insert into transactions, med_available, med_purchased
insert into transactions values ("batch", "name", (int)"qty", (float)"cost", "client", (bool)"iscustomer", (date)"tdate" = today);

insert into med_available values ("batch", "name", (int)"qty", (float)"price", (date)"mfg", (date)"exp");

insert into med_purchased values ("batch", "name", (int)"qty", (float)"price", (date)"mfg", (date)"exp", "producer", (date)"pdate" = today);


-- while selling
-- insert into transaction, med_sold
-- deduct/remove from med_available
insert into transaction values ("batch", "name" = autofilled, (int)"qty" = autochecked, (float)"cost", "client", (bool)"iscustomer", (date)"tdate" = today);

insert into med_sold values ("batch", "name" = autofilled, (int)"qty", (float)"price", "customer", (date)"sdate" = today);

string medname
int sqty
list = select batch, qty from meds_available where name = madname order by exp;
for i in list:
	if (sqty > i[qty]):
		sqty -= i[qty]
		i[qty] = 0
	else:
		i[qty] -= sqty
		sqty = 0
if (sqty != 0):
	medleft = 0
	for i in list:
		medleft += i[qty]
	return medleft -- medicines left
for i in list:
	if (i[qty] == 0):
		delete from meds_available where batch = i[batch];
	else:
		update table meds_available set qty = i[qty] where batch = i[batch];
return 0 -- medicines purchasable	


-- while searchin
-- search by batch, medname, producer, customer
select * from transactions where batch = "batch";
select * from transactions where name = "medname";


-- while collecting stats
-- about bought, sold and dumped medicines


-- dumping expired medicines
batches = select batch from meds_available where exp <= getdate();
delete from meds_available where exp <= getdate();
for i in batches:
	insert into meds_dumped (select * from meds_purchased where batch = i);
