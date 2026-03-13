USE QLVT 
GO
INSERT INTO NHAN_HIEU VALUES
('NH01',N'Panasonic',N'Nhật Bản'),
('NH02',N'Sony',N'Nhật Bản'),
('NH03',N'Samsung',N'Hàn Quốc'),
('NH04',N'LG',N'Hàn Quốc'),
('NH05',N'Dell',N'Mỹ'),
('NH06',N'HP',N'Mỹ'),
('NH07',N'Asus',N'Đài Loan'),
('NH08',N'Acer',N'Đài Loan'),
('NH09',N'Canon',N'Nhật Bản'),
('NH10',N'Epson',N'Nhật Bản');
INSERT INTO THIET_BI VALUES
('TB01',N'Máy chiếu Panasonic','NH01','PX100',2020,'L01'),
('TB02',N'Máy lạnh Panasonic','NH01','AC200',2021,'L02'),
('TB03',N'Máy quạt Panasonic','NH01','F300',2019,'L03'),
('TB04',N'Máy in Sony','NH02','SN500',2019,'L04'),
('TB05',N'Máy lạnh Samsung','NH03','SS900',2021,'L02'),
('TB06',N'Máy chiếu LG','NH04','LG300',2022,'L01'),
('TB07',N'Máy tính Dell','NH05','DL100',2023,'L05'),
('TB08',N'Máy tính HP','NH06','HP500',2022,'L05'),
('TB09',N'Máy tính Asus','NH07','AS200',2021,'L05'),
('TB10',N'Máy in Canon','NH09','CN700',2020,'L04');
INSERT INTO LOAI_TB VALUES
('L01',N'Máy tính'),
('L02',N'Máy in'),
('L03',N'Máy chiếu'),
('L04',N'Máy scan'),
('L05',N'Tivi'),
('L06',N'Máy chủ'),
('L07',N'Màn hình'),
('L08',N'Router'),
('L09',N'Switch'),
('L10',N'UPS');
INSERT INTO MON_TB VALUES
('M01','TB01','2022-01-01',12000000),
('M02','TB01','2022-02-01',12000000),
('M03','TB02','2022-03-01',9000000),
('M04','TB02','2022-04-01',9000000),
('M05','TB02','2022-05-01',9000000),
('M06','TB03','2022-06-01',2000000),
('M07','TB03','2022-07-01',2000000),
('M08','TB04','2022-08-01',5000000),
('M09','TB05','2022-09-01',8000000),
('M10','TB06','2022-10-01',10000000);
INSERT INTO DON_VI VALUES
('DV01',N'Phòng Kế Toán'),
('DV02',N'Phòng Hành Chính'),
('DV03',N'Phòng CNTT'),
('DV04',N'Phòng Đào Tạo'),
('DV05',N'Phòng Kỹ Thuật'),
('DV06',N'Phòng Marketing'),
('DV07',N'Phòng Nhân Sự'),
('DV08',N'Phòng Kinh Doanh'),
('DV09',N'Phòng Bảo Trì'),
('DV10',N'Phòng Nghiên Cứu');
INSERT INTO PHONG VALUES
('P01',N'Tầng 1 A101',40),
('P02',N'Tầng 1 A102',35),
('P03',N'Tầng 2 B201',50),
('P04',N'Tầng 2 B202',45),
('P05',N'Tầng 3 C301',30),
('P06',N'Tầng 3 C302',40),
('P07',N'Tầng 4 D401',60),
('P08',N'Tầng 4 D402',55),
('P09',N'Tầng 5 E501',50),
('P10',N'Tầng 5 E502',65);
INSERT INTO NV VALUES
('A123456',N'Nguyễn',N'An',N'Nam','2020-01-01'),
('B234567',N'Trần',N'Bình',N'Nữ','2019-02-01'),
('C345678',N'Lê',N'Chi',N'Nữ','2021-03-01'),
('D456789',N'Phạm',N'Dũng',N'Nam','2018-04-01'),
('E567890',N'Hoàng',N'Lan',N'Nữ','2022-05-01'),
('F678901',N'Võ',N'Minh',N'Nam','2021-06-01'),
('G789012',N'Ngô',N'Hải',N'Nam','2020-07-01'),
('H890123',N'Đỗ',N'Hương',N'Nữ','2019-08-01'),
('I901234',N'Bùi',N'Khánh',N'Nam','2023-09-01'),
('J123456',N'Phan',N'Linh',N'Nữ','2024-10-01');
INSERT INTO PHG_DV VALUES
('P01','DV01','2020-01-01',NULL),
('P02','DV02','2020-01-01',NULL),
('P03','DV03','2020-01-01',NULL),
('P04','DV04','2020-01-01',NULL),
('P05','DV05','2020-01-01',NULL),
('P06','DV06','2020-01-01',NULL),
('P07','DV07','2020-01-01',NULL),
('P08','DV08','2020-01-01',NULL),
('P09','DV09','2020-01-01',NULL),
('P10','DV10','2020-01-01',NULL);
INSERT INTO LDAO_CQ VALUES
('A123456',N'Giám đốc','2022-01-01',NULL),
('B234567',N'Phó giám đốc','2022-01-01',NULL),
('C345678',N'Trưởng phòng','2022-01-01',NULL),
('D456789',N'Phó phòng','2022-01-01',NULL),
('E567890',N'Trưởng phòng','2022-01-01',NULL),
('F678901',N'Phó phòng','2022-01-01',NULL),
('G789012',N'Trưởng phòng','2022-01-01',NULL),
('H890123',N'Phó phòng','2022-01-01',NULL),
('I901234',N'Trưởng phòng','2022-01-01',NULL),
('J123456',N'Phó phòng','2022-01-01',NULL);
INSERT INTO LDAO_DV VALUES
('A123456','DV01',N'Trưởng phòng','2022-01-01',NULL),
('B234567','DV02',N'Trưởng phòng','2022-01-01',NULL),
('C345678','DV03',N'Trưởng phòng','2022-01-01',NULL),
('D456789','DV04',N'Trưởng phòng','2022-01-01',NULL),
('E567890','DV05',N'Trưởng phòng','2022-01-01',NULL),
('F678901','DV06',N'Trưởng phòng','2022-01-01',NULL),
('G789012','DV07',N'Trưởng phòng','2022-01-01',NULL),
('H890123','DV08',N'Trưởng phòng','2022-01-01',NULL),
('I901234','DV09',N'Trưởng phòng','2022-01-01',NULL),
('J123456','DV10',N'Trưởng phòng','2022-01-01',NULL);
INSERT INTO PH_PHOI_TB VALUES
('P01','M01','2022-03-01',NULL,'Tốt',N'Hoạt động tốt'),
('P02','M02','2022-03-02',NULL,'Tốt',N'Hoạt động tốt'),
('P03','M03','2022-03-03',NULL,'Tốt',N'Hoạt động tốt'),
('P04','M04','2022-03-04',NULL,'Tốt',N'Hoạt động tốt'),
('P05','M05','2022-03-05',NULL,'Hỏng',N'Không hoat động'),
('P06','M06','2022-03-06',NULL,'Tốt',N'Hoạt động tốt'),
('P07','M07','2022-03-07',NULL,'Tốt',N'Hoạt động tốt'),
('P08','M08','2022-03-08',NULL,'Tốt',N'Hoạt động tốt'),
('P09','M09','2022-03-09',NULL,'Hỏng',N'Không hoat động'),
('P10','M10','2022-03-10',NULL,'Tốt',N'Hoạt động tốt');
INSERT INTO PHTRACH_TB VALUES
('A123456','DV01','2021-01-01',NULL),
('B234567','DV02','2021-01-01',NULL),
('C345678','DV03','2021-01-01',NULL),
('D456789','DV04','2021-01-01',NULL),
('E567890','DV05','2021-01-01',NULL),
('F678901','DV06','2021-01-01',NULL),
('G789012','DV07','2021-01-01',NULL),
('H890123','DV08','2021-01-01',NULL),
('I901234','DV09','2021-01-01',NULL),
('J123456','DV10','2021-01-01',NULL);
INSERT INTO KHAU_HAO VALUES
('M01','2023-12-31',0.1),
('M02','2023-12-31',0.15),
('M03','2023-12-31',0.2),
('M04','2023-12-31',0.05),
('M05','2023-12-31',0.3),
('M06','2023-12-31',0.12),
('M07','2023-12-31',0.18),
('M08','2023-12-31',0.1),
('M09','2023-12-31',0.08),
('M10','2023-12-31',0.25);
INSERT INTO THANH_LY VALUES
('M01','2024-01-01 08:00',2000000,'VND'),
('M02','2024-01-02 09:00',1800000,'VND'),
('M03','2024-01-03 10:00',1500000,'VND'),
('M04','2024-01-04 11:00',1700000,'VND'),
('M05','2024-01-05 12:00',1200000,'VND'),
('M06','2024-01-06 13:00',1600000,'VND'),
('M07','2024-01-07 14:00',1400000,'VND'),
('M08','2024-01-08 15:00',1300000,'VND'),
('M09','2024-01-09 16:00',1100000,'VND'),
('M10','2024-01-10 17:00',1900000,'VND');

SELECT TB.MA_TB, TB.TEN_TB, COUNT(M.MA_MON) AS SO_MON
FROM THIET_BI TB, NHAN_HIEU NH, MON_TB M 
WHERE TB.MA_NHHIEU = NH.MA_NSX
AND TB.MA_TB = M.MA_TB
AND NH.TEN_NSX = N'Panasonic'
GROUP BY TB.MA_TB, TB.TEN_TB

SELECT TOP 1 NH.TEN_NSX , NH.NUOC, COUNT(M.MA_MON) AS SO_LUONG
FROM NHAN_HIEU NH, THIET_BI TB, MON_TB M
WHERE NH.MA_NSX = TB.MA_NHHIEU
AND TB.MA_TB = M.MA_TB
GROUP BY NH.TEN_NSX, NH.NUOC
ORDER BY SO_LUONG DESC --ODERBY SẮP XẾP: ASC=1-10, DESC=10-1



SELECT TOP 1 NV.MA_NV, NV.HO_NV, NV.TEN_NV, L.CHUC_VU, COUNT(M.MA_MON) AS SO_MON
FROM NV ,LDAO_DV L, PHTRACH_TB P , MON_TB M
WHERE NV.MA_NV=L.MA_NV 
AND NV.MA_NV=P.MA_NV
AND M.NGAY_MUA BETWEEN L.NGAY_BD AND ISNULL(L.NGAY_KT,GETDATE())
GROUP BY NV.MA_NV , NV.HO_NV,NV.TEN_NV,L.CHUC_VU
ORDER BY SO_MON DESC


SELECT TOP 1 NV.HO_NV,NV.HO_NV,NV.TEN_NV,L.CHUC_VU, COUNT(M.MA_MON) AS SO_MON
FROM NV,LDAO_CQ L, MON_TB M
WHERE NV.MA_NV=L.MA_NV
AND M.NGAY_MUA BETWEEN L.NGAY_BD AND ISNULL(L.NGAY_KT,GETDATE())
GROUP BY NV.MA_NV,NV.HO_NV,NV.TEN_NV,L.CHUC_VU
ORDER BY SO_MON DESC 

