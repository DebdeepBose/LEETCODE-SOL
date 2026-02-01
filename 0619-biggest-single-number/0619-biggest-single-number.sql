select max(num) as num from MyNumbers where num IN (
    select num from MyNUmbers group by num having count(*)=1
)
