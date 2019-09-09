/*
SQLyog Ultimate v11.11 (64 bit)
MySQL - 5.5.5-10.1.28-MariaDB : Database - maker
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`maker` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `maker`;

/*Table structure for table `acesso` */

DROP TABLE IF EXISTS `acesso`;

CREATE TABLE `acesso` (
  `acesso_id` int(11) NOT NULL AUTO_INCREMENT,
  `acesso_descricao` varchar(30) NOT NULL,
  `acesso_js` varchar(11) DEFAULT NULL,
  `acesso_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `acesso_estado` int(1) NOT NULL,
  PRIMARY KEY (`acesso_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `acesso` */

insert  into `acesso`(`acesso_id`,`acesso_descricao`,`acesso_js`,`acesso_data`,`acesso_estado`) values (1,'ENTRADA PRINCIPAL','Abrir1()','2018-05-20 10:14:04',0),(2,'ENTRADA TESTE','Abrir2()','2018-05-16 21:41:06',0);

/*Table structure for table `acesso_rel` */

DROP TABLE IF EXISTS `acesso_rel`;

CREATE TABLE `acesso_rel` (
  `acesso_sec` int(11) NOT NULL AUTO_INCREMENT,
  `acesso_id` int(2) NOT NULL,
  `acesso_nome` varchar(20) DEFAULT NULL,
  `acesso_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`acesso_sec`)
) ENGINE=InnoDB AUTO_INCREMENT=63 DEFAULT CHARSET=utf8;

/*Data for the table `acesso_rel` */

insert  into `acesso_rel`(`acesso_sec`,`acesso_id`,`acesso_nome`,`acesso_data`) values (1,1,'joao','2018-05-14 17:29:29'),(2,1,'joao','2018-05-14 17:30:35'),(3,1,'joao','2018-05-14 17:35:18'),(4,1,'joao','2018-05-14 21:58:43'),(5,1,'joao','2018-05-14 22:00:53'),(6,1,'joao','2018-05-14 22:01:50'),(7,1,'joao','2018-05-14 22:05:43'),(8,1,'joao','2018-05-14 22:09:08'),(9,1,'joao','2018-05-14 22:15:10'),(10,1,'joao','2018-05-15 09:55:58'),(11,1,'joao','2018-05-15 09:57:27'),(12,1,'joao','2018-05-15 09:59:53'),(13,1,'joao','2018-05-15 10:00:02'),(14,1,'joao','2018-05-15 10:00:35'),(15,1,'joao','2018-05-15 10:04:13'),(16,1,'joao','2018-05-15 10:11:13'),(17,1,'joao','2018-05-15 10:17:46'),(18,1,'joao','2018-05-15 10:18:18'),(19,1,'joao','2018-05-15 11:05:00'),(20,1,'joao','2018-05-15 11:09:40'),(21,1,'joao','2018-05-15 11:10:27'),(22,1,'joao','2018-05-15 11:13:15'),(23,1,'joao','2018-05-15 11:25:15'),(24,1,'joao','2018-05-15 11:30:58'),(25,1,'joao','2018-05-15 11:31:14'),(26,1,'joao','2018-05-15 11:31:35'),(27,1,'joao','2018-05-15 11:32:36'),(28,1,'joao','2018-05-15 11:32:49'),(29,1,'joao','2018-05-16 19:42:49'),(30,1,'joao','2018-05-16 19:42:54'),(31,1,'joao','2018-05-16 19:43:01'),(32,1,'joao','2018-05-16 19:45:06'),(33,1,'joao','2018-05-16 19:45:32'),(34,1,'joao','2018-05-16 19:49:40'),(35,1,'joao','2018-05-16 19:50:10'),(36,1,'joao','2018-05-16 19:59:55'),(37,1,'joao','2018-05-16 21:06:35'),(38,1,'joao','2018-05-16 21:28:47'),(39,1,'joao','2018-05-16 21:49:34'),(40,1,'joao','2018-05-16 21:50:17'),(41,1,'joao','2018-05-16 21:51:00'),(42,1,'joao','2018-05-16 21:51:36'),(43,1,'joao','2018-05-16 21:51:53'),(44,1,'joao','2018-05-16 21:54:09'),(45,1,'joao','2018-05-16 22:06:39'),(46,1,'joao','2018-05-20 09:50:59'),(47,1,'joao','2018-05-20 09:54:44'),(48,1,'joao','2018-05-20 09:55:37'),(49,1,'joao','2018-05-20 09:55:55'),(50,1,'joao','2018-05-20 09:56:09'),(51,1,'joao','2018-05-20 09:56:33'),(52,1,'joao','2018-05-20 09:56:51'),(53,1,'joao','2018-05-20 09:57:13'),(54,1,'joao','2018-05-20 09:59:26'),(55,1,'joao','2018-05-20 09:59:51'),(56,1,'joao','2018-05-20 10:00:04'),(57,1,'joao','2018-05-20 10:13:39'),(58,1,'joao','2018-05-20 10:13:49'),(59,1,'joao','2018-06-07 15:48:41'),(60,1,'joao','2018-06-07 15:48:50'),(61,1,'joao','2018-06-07 15:49:11'),(62,1,'joao','2018-06-07 15:49:34');

/*Table structure for table `alarme` */

DROP TABLE IF EXISTS `alarme`;

CREATE TABLE `alarme` (
  `alarme_id` int(11) NOT NULL AUTO_INCREMENT,
  `alarme_descricao` varchar(30) NOT NULL,
  `alarme_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `alarme_estado` int(1) NOT NULL,
  `alarme_violado` int(1) NOT NULL,
  PRIMARY KEY (`alarme_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

/*Data for the table `alarme` */

insert  into `alarme`(`alarme_id`,`alarme_descricao`,`alarme_data`,`alarme_estado`,`alarme_violado`) values (1,'alarme casa','2018-05-26 17:14:22',0,0);

/*Table structure for table `alarme_rel` */

DROP TABLE IF EXISTS `alarme_rel`;

CREATE TABLE `alarme_rel` (
  `alarme_sec` int(11) NOT NULL AUTO_INCREMENT,
  `alarme_id` int(2) NOT NULL,
  `alarme_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `alarme_violado` int(1) NOT NULL,
  PRIMARY KEY (`alarme_sec`)
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8;

/*Data for the table `alarme_rel` */

insert  into `alarme_rel`(`alarme_sec`,`alarme_id`,`alarme_data`,`alarme_violado`) values (1,1,'2018-04-27 19:56:59',1),(2,1,'2018-04-27 20:07:49',1),(3,1,'2018-04-27 20:13:48',1),(4,1,'2018-04-28 15:35:11',1),(5,1,'2018-04-28 15:39:59',1),(6,1,'2018-04-28 15:41:46',1),(7,1,'2018-04-28 15:43:40',1),(8,1,'2018-04-28 15:47:02',1),(9,1,'2018-04-28 15:47:26',1),(10,1,'2018-04-28 15:47:55',1),(11,1,'2018-04-28 15:49:40',1),(12,1,'2018-04-28 15:51:26',1),(13,1,'2018-04-28 15:51:36',1),(14,1,'2018-04-28 15:51:56',1),(15,1,'2018-04-28 15:55:27',1),(16,1,'2018-04-28 15:55:41',1),(17,1,'2018-04-28 15:56:01',1),(18,1,'2018-04-28 15:56:11',1),(19,1,'2018-04-28 15:56:26',1),(20,1,'2018-04-28 16:09:08',1),(21,1,'2018-04-28 16:22:53',1),(22,1,'2018-04-28 16:24:05',1),(23,1,'2018-04-28 16:24:59',1),(24,1,'2018-04-28 16:27:35',1),(25,1,'2018-04-28 16:28:47',1),(26,1,'2018-05-26 15:59:11',1),(27,1,'2018-05-26 16:01:46',1),(28,1,'2018-05-26 16:02:34',1),(29,1,'2018-05-26 16:05:48',1),(30,1,'2018-05-26 16:22:40',1),(31,1,'2018-05-26 17:14:08',1);

/*Table structure for table `ar` */

DROP TABLE IF EXISTS `ar`;

CREATE TABLE `ar` (
  `ar_id` int(11) NOT NULL AUTO_INCREMENT,
  `ar_descricao` varchar(30) NOT NULL,
  `ar_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ar_estado` int(1) NOT NULL,
  `ar_temp` int(2) NOT NULL,
  PRIMARY KEY (`ar_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

/*Data for the table `ar` */

insert  into `ar`(`ar_id`,`ar_descricao`,`ar_data`,`ar_estado`,`ar_temp`) values (1,'Ar Sala','2018-04-04 17:13:12',1,17);

/*Table structure for table `lampadas` */

DROP TABLE IF EXISTS `lampadas`;

CREATE TABLE `lampadas` (
  `lamp_id` int(11) NOT NULL AUTO_INCREMENT,
  `lamp_descricao` varchar(30) NOT NULL,
  `lamp_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `lamp_estado` int(1) NOT NULL,
  PRIMARY KEY (`lamp_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

/*Data for the table `lampadas` */

insert  into `lampadas`(`lamp_id`,`lamp_descricao`,`lamp_data`,`lamp_estado`) values (1,'Sala','2018-04-04 21:53:16',0),(2,'lampada de teste2','2017-11-02 20:32:50',1),(3,'lampada de teste3','2017-11-03 20:22:09',0),(4,'lampada de teste4','2017-11-03 20:22:21',0),(5,'lampada de teste5','2017-11-03 20:22:33',0);

/*Table structure for table `lampadas_rel` */

DROP TABLE IF EXISTS `lampadas_rel`;

CREATE TABLE `lampadas_rel` (
  `lamp_sec` int(11) NOT NULL AUTO_INCREMENT,
  `lamp_id` int(2) NOT NULL,
  `lamp_data` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `lamp_estado` int(1) NOT NULL,
  PRIMARY KEY (`lamp_sec`)
) ENGINE=InnoDB AUTO_INCREMENT=149 DEFAULT CHARSET=utf8;

/*Data for the table `lampadas_rel` */

insert  into `lampadas_rel`(`lamp_sec`,`lamp_id`,`lamp_data`,`lamp_estado`) values (1,1,'2017-12-27 12:22:19',1),(3,1,'2017-12-27 15:31:05',0),(4,1,'2017-12-27 15:32:43',1),(5,1,'2017-12-27 15:32:46',0),(6,1,'2017-12-27 15:33:25',1),(7,1,'2017-12-27 15:33:32',0),(8,1,'2017-12-27 15:34:02',1),(9,1,'2017-12-27 15:34:06',0),(10,1,'2017-12-27 15:37:10',1),(11,1,'2017-12-27 15:37:12',0),(12,1,'2017-12-27 15:37:49',1),(13,1,'2017-12-27 15:38:06',0),(14,1,'2017-12-27 15:38:24',1),(15,1,'2017-12-27 15:38:29',0),(16,1,'2017-12-27 15:41:57',1),(17,1,'2017-12-27 15:42:02',0),(18,1,'2017-12-27 15:42:25',1),(19,1,'2017-12-27 15:42:36',0),(21,1,'2017-12-28 09:15:18',1),(22,1,'2017-12-28 09:15:21',0),(23,1,'2017-12-28 09:16:23',1),(24,1,'2017-12-28 09:16:35',0),(25,1,'2017-12-28 09:16:53',1),(26,1,'2017-12-28 09:16:58',0),(27,1,'2017-12-28 09:17:04',1),(28,1,'2017-12-28 09:17:07',0),(29,1,'2017-12-28 09:17:13',1),(30,1,'2017-12-28 09:17:15',0),(31,1,'2017-12-28 09:17:22',1),(32,1,'2017-12-28 09:17:40',0),(34,1,'2018-01-04 15:47:20',1),(35,1,'2018-01-04 15:47:25',0),(36,1,'2018-01-04 15:47:53',1),(37,1,'2018-01-04 15:47:54',0),(38,1,'2018-01-04 15:47:58',1),(39,1,'2018-01-04 15:47:59',0),(40,1,'2018-01-04 15:48:01',1),(41,1,'2018-01-04 15:48:20',0),(42,1,'2018-01-04 15:48:25',1),(43,1,'2018-01-04 15:48:27',0),(45,1,'2018-01-27 18:12:16',1),(46,1,'2018-01-27 18:12:37',0),(47,1,'2018-01-27 18:12:43',1),(48,1,'2018-01-27 18:13:16',0),(49,1,'2018-01-27 18:13:21',1),(50,1,'2018-01-27 18:13:22',0),(51,1,'2018-01-27 18:14:02',1),(52,1,'2018-01-27 18:14:37',0),(53,1,'2018-01-27 18:17:32',1),(54,1,'2018-01-27 18:17:38',0),(55,1,'2018-01-27 18:29:16',1),(56,1,'2018-01-27 18:29:22',0),(57,1,'2018-01-27 18:31:36',1),(58,1,'2018-01-27 18:31:59',0),(59,1,'2018-01-27 18:36:31',1),(60,1,'2018-01-27 18:36:42',0),(61,1,'2018-01-27 18:37:33',1),(62,1,'2018-01-27 18:37:39',0),(63,1,'2018-01-27 18:39:35',1),(64,1,'2018-01-27 18:39:55',0),(65,1,'2018-01-27 18:40:39',1),(66,1,'2018-01-27 18:44:20',0),(67,1,'2018-01-27 18:46:33',1),(68,1,'2018-01-27 18:52:53',0),(69,1,'2018-01-27 18:53:10',1),(70,1,'2018-01-27 18:53:21',0),(71,1,'2018-01-27 18:53:34',1),(72,1,'2018-01-27 18:53:45',0),(73,1,'2018-01-27 18:56:15',1),(74,1,'2018-01-27 18:56:19',0),(75,1,'2018-01-27 18:58:03',1),(76,1,'2018-01-27 18:58:14',0),(77,1,'2018-01-27 18:59:03',1),(78,1,'2018-01-27 18:59:41',0),(79,1,'2018-01-27 19:05:12',1),(80,1,'2018-01-27 19:05:17',0),(81,1,'2018-01-27 19:05:22',1),(82,1,'2018-01-27 19:05:24',0),(83,1,'2018-01-27 19:06:29',1),(84,1,'2018-01-27 19:06:37',0),(85,1,'2018-01-27 19:06:44',1),(86,1,'2018-01-27 19:06:52',0),(87,1,'2018-03-02 20:54:02',1),(88,1,'2018-03-02 20:54:06',0),(89,1,'2018-03-02 20:54:59',1),(90,1,'2018-03-02 20:55:04',0),(91,1,'2018-03-02 20:55:10',1),(92,1,'2018-03-02 20:55:14',0),(93,1,'2018-03-02 20:55:46',1),(94,1,'2018-03-02 20:55:54',0),(95,1,'2018-03-02 20:56:01',1),(96,1,'2018-03-02 20:56:06',0),(97,1,'2018-03-02 20:56:15',1),(98,1,'2018-03-02 20:56:20',0),(99,1,'2018-03-02 20:56:23',1),(100,1,'2018-03-02 20:56:37',0),(101,1,'2018-04-04 17:20:17',0),(102,1,'2018-04-04 17:33:37',1),(103,1,'2018-04-04 17:35:48',0),(104,1,'2018-04-04 17:35:57',1),(105,1,'2018-04-04 17:38:20',0),(106,1,'2018-04-04 17:42:33',1),(107,1,'2018-04-04 17:43:11',0),(108,1,'2018-04-04 17:44:44',1),(109,1,'2018-04-04 17:45:32',0),(110,1,'2018-04-04 17:45:54',1),(111,1,'2018-04-04 17:45:56',0),(112,1,'2018-04-04 17:46:04',1),(113,1,'2018-04-04 17:46:11',0),(114,1,'2018-04-04 17:48:47',1),(115,1,'2018-04-04 17:49:31',0),(116,1,'2018-04-04 17:49:46',1),(117,1,'2018-04-04 17:49:51',0),(118,1,'2018-04-04 17:50:13',1),(119,1,'2018-04-04 17:50:16',0),(120,1,'2018-04-04 17:50:59',1),(121,1,'2018-04-04 17:51:13',0),(122,1,'2018-04-04 19:23:19',0),(123,1,'2018-04-04 19:24:21',1),(124,1,'2018-04-04 19:24:30',0),(125,1,'2018-04-04 19:24:40',1),(126,1,'2018-04-04 19:24:43',0),(127,1,'2018-04-04 19:51:13',1),(128,1,'2018-04-04 19:51:24',0),(129,1,'2018-04-04 19:51:26',1),(130,1,'2018-04-04 19:51:36',0),(131,1,'2018-04-04 20:14:48',1),(132,1,'2018-04-04 20:14:50',0),(133,1,'2018-04-04 20:53:18',1),(134,1,'2018-04-04 20:53:21',0),(135,1,'2018-04-04 21:18:25',1),(136,1,'2018-04-04 21:18:28',0),(137,1,'2018-04-04 21:32:32',1),(138,1,'2018-04-04 21:32:46',0),(139,1,'2018-04-04 21:44:58',1),(140,1,'2018-04-04 21:45:04',0),(141,1,'2018-04-04 21:51:02',1),(142,1,'2018-04-04 21:51:09',0),(143,1,'2018-04-04 21:51:46',1),(144,1,'2018-04-04 21:51:48',0),(145,1,'2018-04-04 21:51:50',1),(146,1,'2018-04-04 21:51:58',0),(147,1,'2018-04-04 21:53:11',1),(148,1,'2018-04-04 21:53:16',0);

/*Table structure for table `permicoes` */

DROP TABLE IF EXISTS `permicoes`;

CREATE TABLE `permicoes` (
  `login` varchar(30) NOT NULL,
  `per_per` int(1) NOT NULL,
  `per_cad` int(1) NOT NULL,
  `per_exc` int(1) DEFAULT NULL,
  `per_acesso` int(1) NOT NULL,
  `per_ace1` int(1) NOT NULL,
  `per_ace2` int(1) NOT NULL,
  `per_ar` int(1) NOT NULL,
  `per_lampadas` int(1) NOT NULL,
  `per_lamp1` int(1) NOT NULL,
  `per_lamp2` int(1) NOT NULL,
  `per_tv` int(1) NOT NULL,
  `per_alarme` int(1) NOT NULL,
  `per_cortinas` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `permicoes` */

insert  into `permicoes`(`login`,`per_per`,`per_cad`,`per_exc`,`per_acesso`,`per_ace1`,`per_ace2`,`per_ar`,`per_lampadas`,`per_lamp1`,`per_lamp2`,`per_tv`,`per_alarme`,`per_cortinas`) values ('admin',1,1,1,1,1,1,1,1,1,1,1,1,1),('joao',1,1,1,1,0,0,1,1,0,0,1,1,1),('teste',0,0,NULL,0,0,0,0,0,0,0,0,0,0),('teste',0,0,NULL,0,0,0,0,0,0,0,0,0,0);

/*Table structure for table `testec` */

DROP TABLE IF EXISTS `testec`;

CREATE TABLE `testec` (
  `id` int(100) NOT NULL,
  `nome` varchar(30) NOT NULL,
  `SENHA` int(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `testec` */

insert  into `testec`(`id`,`nome`,`SENHA`) values (20,'juan',123),(20,'juan',123),(20333,'juan nnja',123),(151515,'jhon Seenaaaa',45678),(2,'wgeqw',0);

/*Table structure for table `usuarios` */

DROP TABLE IF EXISTS `usuarios`;

CREATE TABLE `usuarios` (
  `ID` int(10) unsigned zerofill NOT NULL AUTO_INCREMENT,
  `login` varchar(30) DEFAULT NULL,
  `senha` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=36 DEFAULT CHARSET=utf8;

/*Data for the table `usuarios` */

insert  into `usuarios`(`ID`,`login`,`senha`) values (0000000033,'joao','fa9f399ca2dc41a8500df8f33acaf9fc'),(0000000027,'admin','2aa9d53a4fe3f3af3107bbf0cf6bb8d8');

/*Table structure for table `weather` */

DROP TABLE IF EXISTS `weather`;

CREATE TABLE `weather` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `wea_name` varchar(30) NOT NULL,
  `wea_date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `wea_temp` decimal(4,2) DEFAULT NULL,
  `wea_humid` decimal(4,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=354 DEFAULT CHARSET=utf8;

/*Data for the table `weather` */

insert  into `weather`(`id`,`wea_name`,`wea_date`,`wea_temp`,`wea_humid`) values (1,'','2017-10-29 16:20:43',24.30,75.74),(2,'','2017-10-29 16:20:47',24.30,75.74),(3,'','2017-10-29 16:20:50',24.30,75.74),(4,'','2017-10-29 16:20:54',24.30,75.74),(5,'','2017-10-29 16:20:57',24.30,75.74),(6,'','2017-10-29 16:21:00',24.30,75.74),(7,'','2017-10-29 16:21:04',24.30,75.74),(8,'','2017-10-29 16:21:07',24.30,75.74),(9,'','2017-10-29 16:21:11',24.30,75.74),(10,'','2017-10-29 16:21:14',24.30,75.74),(11,'','2017-10-29 16:21:17',24.30,75.74),(12,'','2017-10-29 16:21:21',24.30,75.74),(13,'','2017-10-29 16:21:24',24.30,75.74),(14,'','2017-10-29 16:21:27',24.30,75.74),(15,'','2017-10-29 16:21:31',24.30,75.74),(16,'','2017-10-29 16:21:34',24.30,75.74),(17,'','2017-10-29 16:21:38',24.40,75.92),(18,'','2017-10-29 16:21:41',24.30,75.74),(19,'','2017-10-29 16:21:44',24.30,75.74),(20,'','2017-10-29 16:21:48',24.40,75.92),(21,'','2017-10-29 16:21:51',24.30,75.74),(22,'','2017-10-29 16:21:55',24.40,75.92),(23,'','2017-10-29 16:21:58',24.30,75.74),(24,'','2017-10-29 16:22:01',24.10,75.38),(25,'','2017-10-29 16:22:05',24.30,75.74),(26,'','2017-10-29 16:22:08',24.30,75.74),(27,'','2017-10-29 16:22:12',24.30,75.74),(28,'','2017-10-29 16:22:15',24.30,75.74),(29,'','2017-10-29 16:22:18',24.30,75.74),(30,'','2017-10-29 16:22:22',24.30,75.74),(31,'','2017-10-29 16:22:25',24.30,75.74),(32,'','2017-10-29 16:22:29',24.30,75.74),(33,'','2017-10-29 16:22:32',24.30,75.74),(34,'','2017-10-29 16:22:36',24.30,75.74),(35,'','2017-10-29 16:22:39',24.30,75.74),(36,'','2017-10-29 16:22:42',24.30,75.74),(37,'','2017-10-29 16:22:46',24.30,75.74),(38,'','2017-10-29 16:22:49',24.30,75.74),(39,'','2017-10-29 16:22:53',24.30,75.74),(40,'','2017-10-29 16:22:56',24.30,75.74),(41,'','2017-10-29 16:22:59',24.30,75.74),(42,'','2017-10-29 16:23:03',24.30,75.74),(43,'','2017-10-29 16:23:06',24.30,75.74),(44,'','2017-10-29 16:23:10',24.30,75.74),(45,'','2017-10-29 16:23:13',24.30,75.74),(46,'','2017-10-29 16:23:16',24.30,75.74),(47,'','2017-10-29 16:23:20',24.30,75.74),(48,'','2017-10-29 16:23:23',24.40,75.92),(49,'','2017-10-29 16:23:27',24.10,75.38),(50,'','2017-10-29 16:23:31',24.40,75.92),(51,'','2017-10-29 16:23:34',24.30,75.74),(52,'','2017-10-29 16:23:38',24.30,75.74),(53,'','2017-10-29 16:23:41',24.30,75.74),(54,'','2017-10-29 16:23:45',24.30,75.74),(55,'','2017-10-29 16:23:48',24.30,75.74),(56,'','2017-10-29 16:23:51',24.30,75.74),(57,'','2017-10-29 16:23:55',24.30,75.74),(58,'','2017-10-29 16:23:58',24.40,75.92),(59,'','2017-10-29 16:24:02',24.00,75.20),(60,'','2017-10-29 16:24:05',24.30,75.74),(61,'','2017-10-29 16:35:05',24.30,75.74),(62,'','2017-10-30 19:41:02',23.40,74.12),(63,'','2017-10-30 19:41:07',23.50,74.30),(64,'','2017-10-30 19:41:12',23.40,74.12),(65,'','2017-10-30 19:41:18',23.30,73.94),(66,'','2017-10-30 19:41:23',23.40,74.12),(67,'','2017-10-30 19:41:29',21.30,70.34),(68,'','2017-10-30 19:41:34',23.40,74.12),(69,'','2017-10-30 19:41:40',23.40,74.12),(70,'','2017-10-30 19:41:45',23.40,74.12),(71,'','2017-10-30 19:41:50',23.40,74.12),(72,'','2017-10-30 19:41:56',23.40,74.12),(73,'','2017-10-30 19:42:01',23.40,74.12),(74,'teste','2017-10-30 19:42:07',23.60,74.48),(75,'teste','2017-10-30 19:42:12',23.40,74.12),(76,'teste','2017-10-30 19:42:17',23.40,74.12),(77,'teste','2017-10-30 19:42:23',23.50,74.30),(78,'teste','2017-10-30 19:42:28',23.40,74.12),(79,'teste','2017-10-30 19:42:34',23.30,73.94),(80,'teste','2017-10-30 19:42:39',21.40,70.52),(81,'teste','2017-10-30 19:42:45',23.30,73.94),(82,'teste','2017-10-30 19:42:50',23.30,73.94),(83,'teste','2017-10-30 19:42:55',23.40,74.12),(84,'teste','2017-10-30 19:43:01',23.40,74.12),(85,'sensor1','2017-10-30 19:43:06',23.40,74.12),(86,'sensor1','2017-10-30 19:43:12',23.40,74.12),(87,'sensor1','2017-10-30 19:43:17',23.40,74.12),(88,'sensor1','2017-10-30 19:43:23',23.50,74.30),(89,'sensor1','2017-10-30 19:43:28',23.40,74.12),(90,'sensor1','2017-10-30 19:43:33',23.40,74.12),(91,'sensor1','2017-10-30 19:43:39',23.40,74.12),(92,'sensor1','2017-10-30 19:43:44',23.40,74.12),(93,'sensor1','2017-10-30 19:43:50',23.40,74.12),(94,'sensor1','2017-10-30 19:43:55',23.40,74.12),(95,'sensor1','2017-10-30 19:44:00',23.50,74.30),(96,'sensor1','2017-10-30 19:44:06',23.20,73.76),(97,'sensor1','2017-10-30 19:44:11',25.40,77.72),(98,'sensor1','2017-10-30 19:44:17',23.30,73.94),(99,'sensor1','2017-10-30 19:44:22',23.30,73.94),(100,'sensor1','2017-10-30 19:44:28',23.40,74.12),(101,'sensor1','2017-10-30 19:44:33',23.60,74.48),(102,'sensor1','2017-10-30 19:44:38',23.50,74.30),(103,'sensor1','2017-10-30 19:44:44',24.70,76.46),(104,'sensor1','2017-10-30 19:44:49',23.80,74.84),(105,'sensor1','2017-10-30 19:44:55',24.00,75.20),(106,'sensor1','2017-10-30 19:45:00',24.00,75.20),(107,'sensor1','2017-10-30 19:45:05',23.90,75.02),(108,'sensor1','2017-10-30 19:45:11',24.00,75.20),(109,'sensor1','2017-10-30 19:45:16',24.00,75.20),(110,'sensor1','2017-10-30 19:45:22',24.20,75.56),(111,'sensor1','2017-10-30 19:45:27',24.00,75.20),(112,'sensor1','2017-10-30 19:45:32',23.90,75.02),(113,'sensor1','2017-10-30 19:45:38',24.10,75.38),(114,'sensor1','2017-10-30 19:45:43',24.00,75.20),(115,'sensor1','2017-10-30 19:45:49',24.00,75.20),(116,'sensor1','2017-10-30 19:45:54',24.00,75.20),(117,'sensor1','2017-10-30 19:45:59',24.00,75.20),(118,'sensor1','2017-10-30 19:46:05',24.00,75.20),(119,'sensor1','2017-10-30 19:46:10',24.00,75.20),(120,'sensor1','2017-10-30 19:46:16',24.10,75.38),(121,'sensor1','2017-10-30 19:46:21',24.00,75.20),(122,'sensor1','2017-10-30 19:46:26',24.00,75.20),(123,'sensor1','2017-10-30 19:46:32',24.10,75.38),(124,'sensor1','2017-10-30 19:46:37',23.80,74.84),(125,'sensor1','2017-10-30 19:46:43',23.90,75.02),(126,'sensor1','2017-10-30 19:46:48',23.90,75.02),(127,'sensor1','2017-10-30 19:46:53',23.90,75.02),(128,'sensor1','2017-10-30 19:46:59',23.90,75.02),(129,'sensor1','2017-10-30 19:47:04',23.90,75.02),(130,'sensor1','2017-10-30 19:47:10',23.80,74.84),(131,'sensor1','2017-10-30 19:47:15',23.80,74.84),(132,'sensor1','2017-10-30 19:47:20',24.00,75.20),(133,'sensor1','2017-10-30 19:47:26',23.80,74.84),(134,'sensor1','2017-10-30 19:47:31',23.80,74.84),(135,'sensor1','2017-10-30 19:47:37',23.80,74.84),(136,'sensor1','2017-10-30 19:47:42',23.70,74.66),(137,'sensor1','2017-10-30 19:47:47',23.70,74.66),(138,'sensor1','2017-10-30 19:47:53',23.70,74.66),(139,'sensor1','2017-10-30 19:47:58',23.70,74.66),(140,'sensor1','2017-10-30 19:48:04',25.10,77.18),(141,'sensor1','2017-10-30 19:48:09',23.70,74.66),(142,'sensor1','2017-10-30 19:48:15',23.80,74.84),(143,'sensor1','2017-10-30 19:48:20',23.60,74.48),(144,'sensor1','2017-10-30 19:48:25',23.60,74.48),(145,'sensor1','2017-10-30 19:48:31',23.80,74.84),(146,'sensor1','2017-10-30 19:48:36',23.60,74.48),(147,'sensor1','2017-10-30 19:48:42',23.60,74.48),(148,'sensor1','2017-10-30 19:48:47',23.60,74.48),(149,'sensor1','2017-10-30 19:48:52',23.60,74.48),(150,'sensor1','2017-10-30 19:48:58',23.60,74.48),(151,'sensor1','2017-10-30 19:49:03',23.60,74.48),(152,'sensor1','2017-10-30 19:49:09',23.40,74.12),(153,'sensor1','2017-10-30 19:49:14',23.50,74.30),(154,'sensor1','2017-10-30 19:49:19',23.50,74.30),(155,'sensor1','2017-10-30 19:49:25',23.50,74.30),(156,'sensor1','2017-10-30 19:49:30',23.70,74.66),(157,'sensor1','2017-10-30 19:49:36',23.80,74.84),(158,'sensor1','2017-10-30 19:49:41',24.10,75.38),(159,'sensor1','2017-10-30 19:49:47',24.30,75.74),(160,'sensor1','2017-10-30 19:49:52',24.60,76.28),(161,'sensor1','2017-10-30 19:49:57',24.60,76.28),(162,'sensor1','2017-10-30 19:50:03',24.60,76.28),(163,'sensor1','2017-10-30 19:50:08',24.60,76.28),(164,'sensor1','2017-10-30 19:50:14',24.80,76.64),(165,'sensor1','2017-10-30 19:50:19',22.60,72.68),(166,'sensor1','2017-10-30 19:50:25',24.70,76.46),(167,'sensor1','2017-10-30 19:50:30',24.60,76.28),(168,'sensor1','2017-10-30 19:50:35',24.50,76.10),(169,'sensor1','2017-10-30 19:50:41',24.60,76.28),(170,'sensor1','2017-10-30 19:50:46',24.60,76.28),(171,'sensor1','2017-10-30 19:50:52',26.00,78.80),(172,'sensor1','2017-10-30 19:50:57',24.60,76.28),(173,'sensor1','2017-10-30 19:51:02',24.50,76.10),(174,'sensor1','2017-10-30 19:51:08',24.50,76.10),(175,'sensor1','2017-10-30 19:51:13',24.50,76.10),(176,'sensor1','2017-10-30 19:51:19',24.40,75.92),(177,'sensor1','2017-10-30 19:51:24',24.40,75.92),(178,'sensor1','2017-10-30 19:51:29',24.00,75.20),(179,'sensor1','2017-10-30 19:51:35',24.40,75.92),(180,'sensor1','2017-10-30 19:51:40',24.40,75.92),(181,'sensor1','2017-10-30 19:51:46',25.10,77.18),(182,'sensor1','2017-10-30 19:51:51',24.30,75.74),(183,'sensor1','2017-10-30 19:51:56',24.40,75.92),(184,'sensor1','2017-10-30 19:52:02',24.30,75.74),(185,'sensor1','2017-10-30 19:52:07',24.30,75.74),(186,'sensor1','2017-10-30 19:52:13',24.30,75.74),(187,'sensor1','2017-10-30 19:52:18',24.20,75.56),(188,'sensor1','2017-10-30 19:52:23',24.20,75.56),(189,'sensor1','2017-10-30 19:52:29',25.30,77.54),(190,'sensor1','2017-10-30 19:52:34',24.20,75.56),(191,'sensor1','2017-10-30 19:52:40',24.20,75.56),(192,'sensor1','2017-10-30 19:52:45',24.20,75.56),(193,'sensor1','2017-10-30 19:52:51',24.20,75.56),(194,'sensor1','2017-10-30 19:52:56',24.20,75.56),(195,'sensor1','2017-10-30 19:53:01',24.30,75.74),(196,'sensor1','2017-10-30 19:53:07',24.20,75.56),(197,'sensor1','2017-10-30 19:53:12',23.70,74.66),(198,'sensor1','2017-10-30 19:53:18',24.20,75.56),(199,'sensor1','2017-10-30 19:53:23',24.20,75.56),(200,'sensor1','2017-10-30 19:53:29',24.20,75.56),(201,'sensor1','2017-10-30 19:53:34',24.10,75.38),(202,'sensor1','2017-10-30 19:53:39',24.10,75.38),(203,'sensor1','2017-10-30 19:53:45',24.10,75.38),(204,'sensor1','2017-10-30 19:53:50',24.10,75.38),(205,'sensor1','2017-10-30 19:53:56',24.00,75.20),(206,'sensor1','2017-10-30 19:54:01',24.00,75.20),(207,'sensor1','2017-10-30 19:54:06',24.00,75.20),(208,'sensor1','2017-10-30 19:54:12',24.00,75.20),(209,'sensor1','2017-10-30 19:54:17',24.00,75.20),(210,'sensor1','2017-10-30 19:54:23',24.00,75.20),(211,'sensor1','2017-10-30 19:54:28',24.00,75.20),(212,'sensor1','2017-10-30 19:54:34',23.80,74.84),(213,'sensor1','2017-10-30 19:54:39',23.50,74.30),(214,'sensor1','2017-10-30 19:54:44',23.90,75.02),(215,'sensor1','2017-10-30 19:54:50',23.90,75.02),(216,'sensor1','2017-10-30 19:54:55',23.80,74.84),(217,'sensor1','2017-10-30 19:55:01',23.80,74.84),(218,'sensor1','2017-10-30 19:55:06',23.80,74.84),(219,'sensor1','2017-10-30 19:55:11',23.80,74.84),(220,'sensor1','2017-10-30 19:55:17',23.80,74.84),(221,'sensor1','2017-10-30 19:55:22',23.70,74.66),(222,'sensor1','2017-10-30 19:55:28',23.60,74.48),(223,'sensor1','2017-10-30 19:55:33',23.70,74.66),(224,'sensor1','2017-10-30 19:55:39',23.70,74.66),(225,'sensor1','2017-10-30 19:55:44',23.70,74.66),(226,'sensor1','2017-10-30 19:55:50',23.70,74.66),(227,'sensor1','2017-10-30 19:55:55',23.70,74.66),(228,'sensor1','2017-10-30 19:56:00',23.70,74.66),(229,'sensor1','2017-10-30 19:56:06',23.70,74.66),(230,'sensor1','2017-10-30 19:56:11',23.70,74.66),(231,'sensor1','2017-10-30 19:56:17',23.60,74.48),(232,'sensor1','2017-10-30 19:56:22',23.70,74.66),(233,'sensor1','2017-10-30 19:56:27',23.70,74.66),(234,'sensor1','2017-10-30 19:56:33',23.70,74.66),(235,'sensor1','2017-10-30 19:56:38',23.70,74.66),(236,'sensor1','2017-10-30 19:56:44',23.70,74.66),(237,'sensor1','2017-10-30 19:56:49',23.70,74.66),(238,'sensor1','2017-10-30 19:56:55',23.70,74.66),(239,'sensor1','2017-10-30 19:57:00',23.70,74.66),(240,'sensor1','2017-10-30 19:57:06',23.70,74.66),(241,'sensor1','2017-10-30 19:57:11',23.70,74.66),(242,'sensor1','2017-10-30 19:57:16',23.60,74.48),(243,'sensor1','2017-10-30 19:57:22',23.60,74.48),(244,'sensor1','2017-10-30 19:57:27',23.60,74.48),(245,'sensor1','2017-10-30 19:57:33',23.60,74.48),(246,'sensor1','2017-10-30 19:57:38',23.70,74.66),(247,'sensor1','2017-10-30 19:57:44',23.70,74.66),(248,'sensor1','2017-10-30 19:57:49',23.60,74.48),(249,'sensor1','2017-10-30 19:57:54',23.60,74.48),(250,'sensor1','2017-10-30 19:58:00',23.70,74.66),(251,'sensor1','2017-10-30 19:58:05',23.60,74.48),(252,'sensor1','2017-10-30 19:58:11',23.60,74.48),(253,'sensor1','2017-10-30 19:58:16',23.40,74.12),(254,'sensor1','2017-10-30 19:58:22',23.60,74.48),(255,'sensor1','2017-10-30 19:58:27',23.60,74.48),(256,'sensor1','2017-10-30 19:58:32',23.60,74.48),(257,'sensor1','2017-10-30 19:58:38',23.60,74.48),(258,'sensor1','2017-10-30 19:58:43',23.60,74.48),(259,'sensor1','2017-10-30 19:58:49',23.60,74.48),(260,'sensor1','2017-10-30 19:58:54',23.60,74.48),(261,'sensor1','2017-10-30 19:58:59',23.60,74.48),(262,'sensor1','2017-10-30 19:59:05',23.70,74.66),(263,'sensor1','2017-10-30 19:59:10',23.90,75.02),(264,'sensor1','2017-10-30 19:59:16',23.60,74.48),(265,'sensor1','2017-10-30 19:59:21',23.60,74.48),(266,'sensor1','2017-10-30 19:59:27',23.60,74.48),(267,'sensor1','2017-10-30 19:59:32',23.60,74.48),(268,'sensor1','2017-10-30 19:59:37',23.70,74.66),(269,'sensor1','2017-10-30 19:59:43',23.60,74.48),(270,'sensor1','2017-10-30 19:59:48',23.40,74.12),(271,'sensor1','2017-10-30 19:59:54',23.60,74.48),(272,'sensor1','2017-10-30 19:59:59',23.60,74.48),(273,'sensor1','2017-10-30 20:00:04',23.60,74.48),(274,'sensor1','2017-10-30 20:00:10',23.60,74.48),(275,'sensor1','2017-10-30 20:00:15',23.60,74.48),(276,'sensor1','2017-10-30 20:00:21',23.60,74.48),(277,'sensor1','2017-10-30 20:00:26',23.60,74.48),(278,'sensor1','2017-10-30 20:00:31',23.70,74.66),(279,'sensor1','2017-10-30 20:00:37',23.60,74.48),(280,'sensor1','2017-10-30 20:00:42',23.70,74.66),(281,'sensor1','2017-10-30 20:00:48',23.70,74.66),(282,'sensor1','2017-10-30 20:00:53',23.80,74.84),(283,'sensor1','2017-10-30 20:00:59',23.70,74.66),(284,'sensor1','2017-10-30 20:01:04',23.70,74.66),(285,'sensor1','2017-10-30 20:01:09',23.60,74.48),(286,'sensor1','2017-10-30 20:01:15',23.70,74.66),(287,'sensor1','2017-10-30 20:01:20',23.70,74.66),(288,'sensor1','2017-10-30 20:01:26',23.70,74.66),(289,'sensor1','2017-10-30 20:01:31',23.70,74.66),(290,'sensor1','2017-10-30 20:01:36',24.00,75.20),(291,'sensor1','2017-10-30 20:01:42',23.80,74.84),(292,'sensor1','2017-10-30 20:01:47',23.80,74.84),(293,'sensor1','2017-10-30 20:01:53',23.80,74.84),(294,'sensor1','2017-10-30 20:01:58',23.80,74.84),(295,'sensor1','2017-10-30 20:02:03',23.80,74.84),(296,'sensor1','2017-10-30 20:02:09',23.80,74.84),(297,'sensor1','2017-10-30 20:02:14',23.80,74.84),(298,'sensor1','2017-10-30 20:02:20',23.80,74.84),(299,'sensor1','2017-10-30 20:02:25',23.80,74.84),(300,'sensor1','2017-10-30 20:02:30',23.80,74.84),(301,'sensor1','2017-10-30 20:02:36',23.80,74.84),(302,'sensor1','2017-10-30 20:02:41',23.80,74.84),(303,'sensor1','2017-10-30 20:02:47',23.80,74.84),(304,'sensor1','2017-10-30 20:02:52',23.80,74.84),(305,'sensor1','2017-10-30 20:02:58',23.80,74.84),(306,'sensor1','2017-10-30 20:03:03',23.80,74.84),(307,'sensor1','2017-10-30 20:03:08',23.70,74.66),(308,'sensor1','2017-10-30 20:03:14',23.80,74.84),(309,'sensor1','2017-10-30 20:03:19',23.80,74.84),(310,'sensor1','2017-10-30 20:03:25',23.80,74.84),(311,'sensor1','2017-10-30 20:03:30',23.80,74.84),(312,'sensor1','2017-10-30 20:03:36',24.10,75.38),(313,'sensor1','2017-10-30 20:03:41',23.70,74.66),(314,'sensor1','2017-10-30 20:03:46',23.70,74.66),(315,'sensor1','2017-10-30 20:03:52',23.70,74.66),(316,'sensor1','2017-10-30 20:03:57',23.70,74.66),(317,'sensor1','2017-10-30 20:04:03',23.70,74.66),(318,'sensor1','2017-10-30 20:04:08',23.70,74.66),(319,'sensor1','2017-10-30 20:04:13',23.70,74.66),(320,'sensor1','2017-10-30 20:04:19',23.60,74.48),(321,'sensor1','2017-10-30 20:04:24',23.60,74.48),(322,'sensor1','2017-10-30 20:04:30',23.60,74.48),(323,'sensor1','2017-10-30 20:04:35',23.60,74.48),(324,'sensor1','2017-10-30 20:04:40',23.60,74.48),(325,'sensor1','2017-10-30 20:04:46',23.60,74.48),(326,'sensor1','2017-10-30 20:04:51',23.60,74.48),(327,'sensor1','2017-10-30 20:04:57',23.60,74.48),(328,'sensor1','2017-10-30 20:05:02',23.60,74.48),(329,'sensor1','2017-10-30 20:05:08',23.60,74.48),(330,'sensor1','2017-10-30 20:05:13',23.60,74.48),(331,'sensor1','2017-10-30 20:05:18',23.60,74.48),(332,'sensor1','2017-10-30 20:05:24',23.50,74.30),(333,'sensor1','2017-10-30 20:05:29',23.50,74.30),(334,'sensor1','2017-10-30 20:05:35',23.50,74.30),(335,'sensor1','2017-10-30 20:05:40',23.50,74.30),(336,'sensor1','2017-10-30 20:05:45',23.50,74.30),(337,'sensor1','2017-10-30 20:05:51',23.50,74.30),(338,'sensor1','2017-10-30 20:05:56',23.50,74.30),(339,'sensor1','2017-10-30 20:06:02',23.40,74.12),(340,'sensor1','2017-10-30 20:06:07',23.40,74.12),(341,'sensor1','2017-10-30 20:06:12',23.40,74.12),(342,'sensor1','2017-10-30 20:06:18',23.40,74.12),(343,'sensor1','2017-10-30 20:06:23',23.40,74.12),(344,'sensor1','2017-10-30 20:06:29',23.30,73.94),(345,'sensor1','2017-10-30 20:06:34',23.30,73.94),(346,'sensor1','2017-10-30 20:06:40',23.30,73.94),(347,'sensor1','2017-10-30 20:06:45',23.30,73.94),(348,'sensor1','2017-10-30 20:06:51',23.30,73.94),(349,'sensor1','2017-10-30 20:06:56',23.20,73.76),(350,'sensor1','2017-10-30 20:07:01',23.20,73.76),(351,'sensor1','2017-10-30 20:07:07',23.20,73.76),(352,'sensor1','2017-10-30 20:07:12',23.20,73.76),(353,'sensor1','2017-10-30 20:07:18',23.20,73.76);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
