CREATE DATABASE QL_PHONG

USE QL_PHONG

--Tạo bảng PHONG-- (DONE)
CREATE TABLE PHONG (
	MAPHONG CHAR(10) NOT NULL,
	TINHTRANG NVARCHAR(10),
	LOAIPHONG NVARCHAR(10),
	DONGIA FLOAT,
	PRIMARY KEY (MAPHONG)
)

--Tạo bảng KHACH-- (DONE)
CREATE TABLE KHACH (
	MAKH CHAR(10) NOT NULL,
	HOTEN NVARCHAR(50),
	DIACHI NVARCHAR(100),
	DIENTHOAI CHAR(11),
	PRIMARY KEY (MAKH)
)

--Tạo bảng DATPHONG-- (DONE)
CREATE TABLE DATPHONG (
	MA CHAR(10) NOT NULL,
	MAKH CHAR(10),
	MAPHONG CHAR(10),
	NGAYDP SMALLDATETIME,
	NGAYTRA SMALLDATETIME,
	THANHTIEN FLOAT,
	PRIMARY KEY (MA)
)

--Thêm khoá ngoại MAKH-- (DONE)
ALTER TABLE DATPHONG
ADD CONSTRAINT FK_DATPHONG_MAKH
FOREIGN KEY (MAKH)
REFERENCES KHACH(MAKH)

--Thêm khoá ngoại MAPHONG-- (DONE)
ALTER TABLE DATPHONG
ADD CONSTRAINT FK_DATPHONG_MAPHONG
FOREIGN KEY (MAPHONG)
REFERENCES PHONG(MAPHONG)

GO

--stored procedure spDatPhong--
CREATE PROCEDURE spDatPhong @makh CHAR(10), @maphong CHAR(10), @ngaydat SMALLDATETIME
AS
	IF (EXISTS (SELECT * FROM KHACH WHERE MAKH = @makh) -- Check xem @makh có tồn tại trong bảng KHACH hay không
		AND EXISTS (SELECT * FROM PHONG WHERE MAPHONG = @maphong AND TINHTRANG = N'Rảnh')) -- Check xem @maphong có tồn tại trong bảng PHONG hay không ?
		-- Đồng thời kèm thêm điều kiện tình trạng của phòng phải là rảnh
		BEGIN
			DECLARE @ma INT -- Phát sinh mã mới

			IF (EXISTS (SELECT MA FROM DATPHONG)) 
			-- Nếu có bất kì phòng nào đã được đặt rồi thì mã mới sẽ bằng mã lớn nhất + 1
				SET @ma = (SELECT MAX(MA) FROM DATPHONG) + 1
			ELSE -- Nếu chưa có mã nào thì mã phát sinh sẽ là mã đầu tiên, do đó bằng 1
				SET @ma = 1

			-- Thêm các giá trị và bảng DATPHONG
			INSERT INTO DATPHONG VALUES (@ma, @makh, @maphong, @ngaydat, NULL, NULL)

			-- Cập nhật tình trạng phòng thành bận
			UPDATE PHONG SET TINHTRANG = N'Bận' WHERE MAPHONG = @maphong

			-- In ra thông báo thành công
			PRINT N'Đã đặt phòng thành công'
		END
	ELSE -- Ngược lại in ra thông báo không thành công
		PRINT N'Đặt phòng không thành công'
GO

--stored procedure spTraPhong--
CREATE PROCEDURE spTraPhong @madp CHAR(10), @makh CHAR(10)
AS
	-- check xem mã đặt phòng có tồn tại hay không và check mã kh có tồn tại hay không, đồng thời thành tiền chưa có bởi vì phòng chưa được trả
	IF (EXISTS (SELECT * FROM DATPHONG WHERE MA = @madp AND MAKH = @makh AND THANHTIEN IS NULL))
		BEGIN
			-- đặt ngày trả phòng là ngày hiện tại
			DECLARE @ngaytraphong SMALLDATETIME
			SET @ngaytraphong = GETDATE()

			-- Tìm mã phòng
			DECLARE @maphong CHAR(10)
			SET @maphong = (SELECT * FROM DATPHONG WHERE MA = @madp)

			-- thành tiền sẽ được tính bằng khoảng cách giữa ngày tới ngày đặt phòng nhân cho đơn giá
			DECLARE @thanhtien FLOAT
			SET @thanhtien = DATEDIFF(day, (SELECT NGAYDP FROM DATPHONG WHERE MA = @madp), @ngaytraphong)
							* (SELECT DONGIA FROM PHONG WHERE MAPHONG = @maphong)

			-- Cập nhật tình trạng trả phòng
			UPDATE DATPHONG SET NGAYTRA = @ngaytraphong, THANHTIEN = @thanhtien WHERE MA = @madp
			-- Cập nhật tình trạng phòng
			UPDATE PHONG SET TINHTRANG = N'Rảnh' WHERE MAPHONG = @maphong

			-- In ra thông báo thành công
			PRINT N'Trả phòng thành công'
		END
	ELSE
		PRINT N'Không thể trả phòng'
GO