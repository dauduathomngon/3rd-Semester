--a--
CREATE PROCEDURE HelloWorld
AS
	PRINT 'Hello World'
GO
--EXEC HelloWorld

--b--
CREATE PROCEDURE PrintSumTwoNumber @num1 int, @num2 int
AS
	PRINT @num1 + @num2
GO
--EXEC PrintSumTwoNumber 1, 3

--c--
CREATE PROCEDURE SumTwoNumber @num1 int, @num2 int, @total int out
AS
	SET @total = @num1 + @num2
GO
--DECLARE @sum int
--EXEC SumTwoNumber 1, -2, @sum out
--PRINT @sum

--d--
CREATE PROCEDURE SumThreeNumber @num1 int, @num2 int, @num3 int, @total int out
AS
	DECLARE @sumTwo int
	EXEC SumTwoNumber @num1, @num2, @sumTwo out
	SET @total = @num3 + @sumTwo
GO
--DECLARE @sum int
--EXEC SumThreeNumber 1, -2, 3, @sum out
--PRINT @sum

--e--
CREATE PROCEDURE SumMtoN @m int, @n int
AS
	-- Biến tổng
	DECLARE @total int
	SET @total = 0

	-- Biến đếm
	DECLARE @i int
	SET @i = @m

	-- Tổng n -> m
	WHILE (@i <= @n)
	BEGIN
		SET @total = @total + @i
		SET @i = @i + 1
	END

	-- In ra tổng
	PRINT @total
GO
--EXEC SumMtoN 1, 3

--f--
CREATE PROCEDURE IsPrime @n INT, @isPrime INT OUT
AS
	SET @isPrime = 1
	
	IF (@n <= 1)
		SET @isPrime = 0

	DECLARE @i INT
	SET @i = 2

	WHILE (@i <= SQRT(@n))
	BEGIN
		IF (@n % @i = 0)
			SET @isPrime = 0
		SET @i = @i + 1
	END
GO
--DECLARE @isPrime INT
--EXEC IsPrime 97, @isPrime OUT
--PRINT @isPrime

--g--
CREATE PROCEDURE SumPrimeFromMToN @m INT, @n INT, @total INT OUT
AS
	SET @total = 0 -- biến tổng

	DECLARE @i INT -- biến đếm
	SET @i = @m
	
	DECLARE @isPrime INT -- biến check số nguyên tố

	WHILE (@i < @n)
	BEGIN 
		EXEC IsPrime @i, @isPrime OUT
		IF (@isPrime = 1)
			SET @total = @total + @i
		SET @i = @i + 1
	END
GO

--h--
CREATE PROCEDURE FindGCD @n INT, @m INT, @gcd INT OUT
AS
	DECLARE @a INT
	SET @a = @n

	DECLARE @b INT
	SET @b = @m

	DECLARE @rem INT

	WHILE (@b <> 0)
	BEGIN
		SET @rem = @a % @b
		SET @a = @b 
		SET @b = @rem
	END

	SET @gcd = @a
GO

--i--
CREATE PROCEDURE FindLCM @n INT, @m INT, @lcm INT OUT
AS
	DECLARE @gcd INT
	EXEC FindGCD @n, @m, @gcd OUT
	SET @lcm = (@n * @m) / (@gcd)
GO

USE QL_THAMGIADT
GO

--j--
CREATE PROCEDURE XuatDSGV 
AS
	SELECT * 
	FROM GIAOVIEN
GO

--k--
CREATE PROCEDURE SoluongDeTai @magv CHAR(3), @soluong INT OUT
AS
	SET @soluong = (SELECT COUNT(DT.MADT)
					FROM DETAI AS DT, THAMGIADT AS TG
					WHERE TG.MAGV = @magv AND DT.MADT = TG.MADT)
GO

--l--
CREATE PROCEDURE InChiTiet @magv CHAR(3)
AS
	-- Các thông tin cơ bản
	DECLARE @ten NVARCHAR(40)
	DECLARE @luong FLOAT
	DECLARE @ngaysinh SMALLDATETIME
	DECLARE @diachi NVARCHAR(50)
	DECLARE @gvql CHAR(3)
	DECLARE @mabm CHAR(5)

	SELECT @ten = GV.HOTEN, @luong = GV.LUONG, @ngaysinh = GV.NGAYSINH, @diachi = GV.DIACHI, @gvql = GV.GVQLCM, @mabm = GV.MABM
	FROM GIAOVIEN AS GV
	WHERE GV.MAGV = @magv

	-- Số lượng đề tài
	DECLARE @soluongdt INT
	EXEC SoluongDeTai @magv, @soluongdt OUT

	-- Số lượng thân nhân
	DECLARE @soluongtn INT
	SET @soluongtn = (SELECT COUNT(*)
					  FROM NGUOITHAN 
					  WHERE MAGV = @magv)

	-- In thông tin
	PRINT N'Họ tên: ' + @ten
	PRINT N'Lương: ' + @luong
	PRINT N'Ngày sinh: ' + @ngaysinh
	PRINT N'Địa chỉ: ' + @diachir

	IF (@gvql IS NOT NULL)
		PRINT N'Mã giáo viên quản lý: ' + @gvql
	ELSE
		PRINT N'Không có giáo viên quản lý'

	PRINT N'Mã bộ môn: ' + @mabm
	PRINT N'Số lượng đề tài: ' + @soluongdt
	PRINT N'Số lượng thân nhân: ' + @soluongtn
GO

--m--
CREATE PROCEDURE KiemTraTonTai @magv CHAR(3), @tontai INT OUT
AS
	IF (EXISTS (SELECT * FROM GIAOVIEN WHERE MAGV = @magv))
		BEGIN
			PRINT N'Có tồn tại giáo viên với mã: ' + @magv
			SET @tontai = 1
		END
	ELSE
		PRINT N'Không tồn tại giáo viên với mã: ' + @magv
		SET @tontai = 0
GO

--n--
CREATE PROCEDURE KiemTraQuyDinh @magv CHAR(3), @madt CHAR(3), @quydinh INT OUT
AS		
	IF (EXISTS (SELECT *
		FROM GIAOVIEN GV 
		JOIN DETAI DT ON GV.MAGV = @MaGV AND DT.MADT = @MaDT
		JOIN GIAOVIEN CNDT ON CNDT.MAGV = DT.GVCNDT AND GV.MABM != CNDT.MABM)) 
		BEGIN
			PRINT N'Không đúng quy định'
			SET @quydinh = 0
		END
	ELSE
		PRINT N'Đúng quy định'
		SET @quydinh = 1
GO

--o--
CREATE PROCEDURE PhanCongGiaoVien @magv CHAR(3), @madt CHAR(10), @stt int, @thoigian INT
AS
	IF (NOT EXISTS (SELECT * FROM GIAOVIEN WHERE MAGV = @magv) 
		OR NOT EXISTS (SELECT CV.MADT FROM CONGVIEC AS CV WHERE CV.MADT = @madt AND CV.SOTT = @stt)
		OR @thoigian <= 0)
		PRINT N'Thông tin đầu vào không hợp lệ'
	ELSE
		DECLARE @quydinh INT
		EXEC KiemTraQuyDinh @magv, @madt, @quydinh OUT
		IF (@quydinh = 0)
			PRINT N'Sai quy định'
		ELSE
			INSERT INTO THAMGIADT VALUES (@magv, @madt, @stt, 0, NULL)
			PRINT N'Đã phân công giáo viên có mã: ' + @magv
GO