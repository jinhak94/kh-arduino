-- web 계정으로 온습도 정보 관리

create table tb_dht(
    no number,
    h number not null,
    c number not null,
    hi number not null,
    time timestamp,
    constraint pk_tb_dht_no primary key(no)
);

create sequence seq_tb_dht_no;
commit;
select * from tb_dht;
desc tb_dht;
select * from tb_dht;