SET SQL_MODE ="NO_AUTO_VALUE_ON_ZERO";

CREATE TABLE `DBTABLE` (
  `id` int(5) NOT NULL,
  `d1` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `DBTABLE` (`id`,`d1`) VALUES ( 1,0);

ALTER TABLE `DBTABLE`
    ADD PRIMARY KEY (`id`);

ALTER TABLE `DBTABLE`
  MODIFY `id` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=100000;