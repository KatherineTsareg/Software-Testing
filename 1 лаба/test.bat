echo off

echo Test right input data
triangle.exe 3 4 5 > simple_345.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b simple_345.txt reference/simple.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test empty input data
triangle.exe > invalid_input_data.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b invalid_input_data.txt reference/invalidArguments.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test insufficient input data
triangle.exe 1 2 > insufficient_input_data.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b insufficient_input_data.txt reference/invalidArguments.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test overkill input data
triangle.exe 1 2 3 4 > overkill_input_data.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b overkill_input_data.txt reference/invalidArguments.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test side equal zero
triangle.exe 3 0 5 > side0.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b side0.txt reference/notExist.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test side is negative
triangle.exe 3 4 -5 > negativeSide.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b negativeSide.txt reference/notExist.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test triangle is simple
triangle.exe 6 8 10 > simpleTriangle.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b simpleTriangle.txt reference/simple.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test triangle is isosceles
triangle.exe 17 17 30 > isoscelesTriangle.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b isoscelesTriangle.txt reference/isosceles.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test triangle is equilateral
triangle.exe 5 5 5  > equilateralTriangle.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b equilateralTriangle.txt reference/equilateral.txt
IF ERRORLEVEL 1 GOTO testFailed

echo Test triangle is equilateral with float input data
triangle.exe 5.23 5.23 5.23  > equilateralTriangleFloat.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b equilateralTriangleFloat.txt reference/equilateral.txt
IF ERRORLEVEL 1 GOTO testFailed

echo OK
pause
exit /b

:testFailed
echo Testing Failed
pause
exit /b