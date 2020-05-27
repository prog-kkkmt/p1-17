Attribute VB_Name = "Module1"
Option Explicit
'Begin8°. Даны два числа a и b. Найти их среднее арифметическое: (a + b)/2.
'Выполнила: Саполетова Анастасия

Sub begin8()
    Dim a As Integer
    Dim b As Integer
    a = InputBox("Введите а: ")
    b = InputBox("Введите b: ")
    MsgBox ((a + b) / 2)
End Sub
'Integer7°. Дано двузначное число. Найти сумму и произведение его цифр.
Sub integer7()
    Dim a As Integer
    a = InputBox("Введите а: ")
    MsgBox ("Сумма: " & (a \ 10 + a Mod 10) & " Произведение: " & ((a \ 10) * (a Mod 10)))
End Sub
'Boolean3°. Дано целое число A. Проверить истинность высказывания: «Число A является четным».
Sub boolean3()
    Dim a As Integer
    a = InputBox("Введите а: ")
    If a Mod 2 = 0 Then
        MsgBox (True)
    Else
        MsgBox (False)
    End If
End Sub
'Дано целое число. Если оно является положительным, то вычесть из него 8; если отрицательным, то прибавить к нему 6; если нулевым, то заменить его на 10. Вывести полученное число.
Sub if3()
    Dim a As Integer
    a = InputBox("Введите а: ")
    If a > 0 Then
        MsgBox (a - 8)
    ElseIf a < 0 Then
        MsgBox (a + 6)
    Else
        MsgBox (10)
    End If
End Sub
'Case3. Дан номер месяца — целое число в диапазоне 1–12 (1 — январь, 2 — февраль и т. д.). Вывести название соответствующего времени года («зима», «весна», «лето», «осень»).
Sub case3()
    Dim a As Integer
    a = InputBox("Введите а: ")
    
    Select Case a
    Case 12, 1 To 2
        MsgBox ("Зима")
    Case 3 To 5
        MsgBox ("Весна")
    Case 6 To 8
        MsgBox ("Лето")
    Case 9 To 11
        MsgBox ("Осень")
    End Select
    
End Sub
'For7. Даны два целых числа A и B (A < B). Найти сумму всех целых чисел от A до B включительно.
Sub for7()
    Dim a As Integer
    Dim b As Integer
    Dim sum As Integer
    Dim i As Integer
    a = InputBox("Введите а: ")
    b = InputBox("Введите b: ")
    sum = 0
    For i = a To b
        sum = sum + i
    Next i
    MsgBox (sum)
End Sub
'While7°. Дано целое число N (> 0). Найти наименьшее целое положительное число K, квадрат которого превосходит N: K2 > N. Функцию извлечения квадратного корня не использовать.
Sub while7()
    Dim a As Integer
    Dim k As Integer
    a = InputBox("Введите а: ")
    k = 1
    Do While k ^ 2 < a
        k = k + 1
    Loop
    MsgBox (k)
End Sub
'Series8. Дано целое число N и набор из N целых чисел. Вывести в том же порядке все четные числа из данного набора и количество K таких чисел.
Sub Series8()
    Dim n As Integer
    Dim count As Integer
    Dim a(9) As Integer
    Dim s As String
    Dim i As Integer
    For i = 0 To 9
        a(i) = InputBox("Введите " & i & " число = ")
    Next i
    count = 0
    For i = 0 To 9
        If a(i) Mod 2 = 0 Then
            s = s & a(i) & " "
            count = count + 1
        End If
    Next i
    
    MsgBox (s & " " & count)
End Sub
'Proc1. Описать процедуру PowerA3(A, B), вычисляющую третью степень числа A и возвращающую ее в переменной B (A — входной, B — выходной параметр; оба параметра являются вещественными). С помощью этой процедуры найти третьи степени пяти данных чисел.
Sub proc1()
    Dim a As Single
    Dim b As Single
    Dim i As Integer
    For i = 0 To 4
        a = InputBox("Введите а: ")
        Call PowerA3(a, b)
        MsgBox (b)
    Next i
    
End Sub
Sub PowerA3(ByVal a As Single, ByRef b As Single)
    b = a ^ 3
End Sub
'Minmax4°. Дано целое число N и набор из N чисел. Найти номер минимального элемента из данного набора.
Sub minmax4()
    Dim n As Integer
    Dim min As Integer
    Dim i As Integer
    min = 10000
    For i = 0 To 9
        n = InputBox("Введите " & i & " число = ")
        If n < min Then
            min = n
        End If
    Next i
    MsgBox (min)
End Sub
'Array1. Дано целое число N (> 0). Сформировать и вывести целочисленный массив размера N, содержащий N первых положительных нечетных чисел: 1, 3, 5, … .
Sub Array1()
    Dim n As Integer
    n = InputBox("Введите n: ")
    Dim a(100) As Integer
    Dim s As String
    Dim i As Integer
    For i = 1 To n
        a(i) = 2 * i - 1
        s = s & a(i) & " "
    Next i
    
    MsgBox (s)

End Sub
'Matrix4. Даны целые положительные числа M, N и набор из N чисел. Сформировать матрицу размера M x N, у которой в каждой строке содержатся все числа из исходного набора (в том же порядке).
Sub Matrix4()
    Dim m As Integer
    Dim n As Integer
    Dim i As Integer, j As Integer
    Dim s As String
    m = InputBox("Введите m: ")
    n = InputBox("Введите n: ")
    Dim arr() As Integer
    ReDim arr(0 To n - 1) As Integer
    For i = 0 To n - 1
        arr(i) = InputBox("Введите " & i + 1 & " число = ")
    Next i
    Dim a() As Integer
    ReDim a(0 To m - 1, 0 To n - 1) As Integer
    
    For i = 0 To m - 1
        For j = 0 To n - 1
            a(i, j) = arr(j)
            s = s & a(i, j) & " "
        Next j
        s = s & vbCrLf
    Next i
    MsgBox (s)
End Sub
'String2. Дано целое число N (32 < N < 126). Вывести символ с кодом, равным N.
Sub String2()
    Dim n As Integer
    n = InputBox("Введите n: ")
    MsgBox (Chr(n))
End Sub
'Param2. Описать функцию MaxNum(A, N) целого типа, находящую номер максимального элемента вещественного массива A размера N. С помощью этой функции найти номера максимальных элементов массивов A, B, C размера NA, NB, NC соответственно.
Sub Param2()
    Dim a() As Double
    
    Dim n As Integer
    Dim i As Integer
    n = InputBox("Введите n: ")
    
    ReDim a(0 To n - 1) As Double
    
    For i = 0 To n - 1
        a(i) = InputBox("Введите " & i + 1 & " число = ")
    Next i
    
    MsgBox (MaxNum(a, n))
End Sub
Function MaxNum(a() As Double, n As Integer) As Integer
    Dim max As Double
    Dim maxI As Integer
    Dim i As Integer
    max = 0
    For i = 0 To n - 1
        If a(i) > max Then
            max = a(i)
            maxI = i
        End If
    Next i
    MaxNum = maxI
End Function
'Описать рекурсивную функцию Fact(N) вещественного типа, вычисляющую значение факториала
Sub Recur1()
    Dim n As Integer
    n = InputBox("Введите n: ")
    
    MsgBox Fact(n)
End Sub
Function Fact(n As Integer) As Integer
    If n = 0 Then
        Fact = 1
    Else
        Fact = n * Fact(n - 1)
    End If
    
End Function
