Option Explicit
'Дан диаметр окружности d. Найти ее длину L = π·d. В качестве значения π использовать 3.14.

Sub begin4()
    Dim x1 As Double
    x1 = InputBox("")
    MsgBox (x1 * 3.14)
    
End Sub

Sub Int4()
'Даны целые положительные числа A и B (A > B).
'На отрезке длины A размещено максимально возможное количество отрезков длины B (без наложений).
'Используя операцию деления нацело, найти количество отрезков B, размещенных на отрезке A..
    Dim x1 As Integer, x2 As Integer
    x1 = InputBox("a-?")
    x2 = InputBox("b-?")
    MsgBox (CInt(x1 / x2))
End Sub


Sub bool4()
'Даны два целых числа: A, B. Проверить истинность высказывания: «Справедливы неравенства A > 2 и B <= 3».
    Dim x1 As Integer, x2 As Integer
    x1 = InputBox("x1 - ")
    x2 = InputBox("x2 - ")
    MsgBox ((x1 > 2) = 0 And (x2 <= 2) = 0)
End Sub

Sub if4()
 'Даны три целых числа. Найти количество положительных чисел в исходном наборе.
    Dim x1 As Integer, x2 As Integer, x3 As Integer, s As Integer
    x1 = InputBox("x1 - ")
    x2 = InputBox("x2 - ")
    x3 = InputBox("x3 - ")
    s = 0
    If x1 >= 0 Then
        s = s + 1
    End If
    If x2 >= 0 Then
        s = s + 1
    End If
    If x3 >= 0 Then
        s = s + 1
    End If
    MsgBox (s)
       
End Sub

Sub case4()
'Дан номер месяца — целое число в диапазоне 1–12 (1 — январь, 2 — февраль и т. д.). Определить количество дней в этом месяце для невисокосного года.
    Dim x1 As Integer
    x1 = InputBox("Введите месяц по номеру")
Select Case x1
    Case 1, 3, 5, 7, 8, 10, 12
        MsgBox ("31 дней")
    Case 4, 6, 9, 11
        MsgBox ("30 дней")
    Case 2
        MsgBox ("28 дней")
    
End Select
End Sub

Sub while4()
'Дано целое число N (> 0). Если оно является степенью числа 3, то вывести true, если не является — вывести false.
    Dim n As Integer
    n = InputBox("N - ")
    Dim k As Integer
    k = 3
    While k < n
        k = k * 3
    Wend
    MsgBox (k = n)
End Sub
    
Sub series4()
'Дано целое число N и набор из N вещественных чисел. Вывести сумму и произведение чисел из данного набора.
    Dim n As Integer
    n = InputBox("N - ")
    Dim k As Integer
    Dim s As Double
    Dim x As Double
    s = 0
    For k = 1 To n
        x = InputBox("x[n] - ")
        s = s + x
        Next
    MsgBox (s)
End Sub

Sub minimummaximum4()

    'Дано целое число N и набор из N чисел. Найти номер минимального элемента из данного набора.
    Dim n As Integer
    Dim i As Integer
    Dim x As Integer
    Dim min As Integer
    Dim mini As Integer
    n = InputBox("n - ")
    min = 999
    mini = 0
    For i = 1 To n
        x = InputBox("x[i] - ")
        If x < min Then
            min = x
            mini = i
        End If
    Next
            MsgBox (mini)
End Sub
