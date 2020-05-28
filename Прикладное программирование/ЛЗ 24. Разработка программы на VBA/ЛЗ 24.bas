Attribute VB_Name = "Module1"
Option Explicit

Sub begin21()
'Даны координаты вершин треугольника: (x1, y1), (x2, y2), (x3, y3). Найти его периметр и площадь, используя формулу для
'расстояния между двумя точками. Для нахождения площади треугольника со сторонами a, b, c использовать формулу Герона
    Dim x1 As Integer, x2 As Integer, x3 As Integer, y1 As Integer, y2 As Integer, y3 As Integer
    Dim a As Double, b As Double, c As Double, p As Double
       
    'Ввод координат
    x1 = InputBox("x1 = ")
    y1 = InputBox("y1 = ")
    x2 = InputBox("x2 = ")
    y2 = InputBox("y2 = ")
    x3 = InputBox("x3 = ")
    y3 = InputBox("y3 = ")
    
    'Вычисление сторон треугольника
    a = ((x2 - x1) ^ 2 + (y2 - y1) ^ 2) ^ 0.5
    b = ((x3 - x2) ^ 2 + (y3 - y2) ^ 2) ^ 0.5
    c = ((x1 - x3) ^ 2 + (y1 - y3) ^ 2) ^ 0.5
    
    'Вычисление полупериметра
    p = (a + b + c) / 2
    
    'Вычисление и вывод периметра
    MsgBox ("P = " & p * 2)
    
    'Вычисление площади по формуле Герона и её вывод
    MsgBox ("S = " & (p * (p - a) * (p - b) * (p - c)) ^ 0.5)
End Sub

Sub integer21()
'С начала суток прошло N секунд (N — целое). Найти количество секунд, прошедших с начала последней минуты.
    Dim n As Integer
    n = InputBox("Введите кол-во прошедших секунд с начала суток")
    MsgBox (n Mod 60 & " секунд(ы) прошло с начала последней минуты")
End Sub

Sub boolean21()
'Дано трехзначное число. Проверить истинность высказывания: «Цифры данного числа образуют возрастающую последовательность».
    Dim n As Integer
    
    n = InputBox("Введите трёхзначное число")
    
    'Разбираем число на цифры и сравниваем их, выводим результат
    MsgBox ((n Mod 10) > ((n Mod 100) \ 10) And ((n Mod 100) \ 10) > (n \ 100))
End Sub

Sub if21()
'Даны целочисленные координаты точек на плоскости. Если точка совпадает с началом координат, то вывести 0. Если точка не совпадает с началом
'координат, но лежит на оси OX или OY, то вывести соответственно 1 или 2. Если точка не лежит на координатных осях, то вывести 3.
    Dim x As Integer, y As Integer
    
    'Ввод координат
    x = InputBox("x = ")
    y = InputBox("y = ")
    
    'Проверка на принадлежность точки к осям
    If x = 0 And y = 0 Then
        MsgBox (0)
    ElseIf y = 0 And x <> 0 Then
        MsgBox (1)
    ElseIf x = 0 And y <> 0 Then
        MsgBox (2)
    Else: MsgBox (3)
    End If
End Sub


Sub case1()
'Дано целое число в диапазоне от 1 до 7. Вывести название дня недели, соответсвующе данному числу
    Dim n As Integer
    
    'Ввод числа n
    n = InputBox("Введите n")
    
    'Вывод названия дня недели с помощью оператора выбора
    Select Case n
        Case 1
            MsgBox ("Понедельник")
        Case 2
            MsgBox ("Вторник")
        Case 3
            MsgBox ("Среда")
        Case 4
            MsgBox ("Четверг")
        Case 5
            MsgBox ("Пятница")
        Case 6
            MsgBox ("Суббота")
        Case 7
            MsgBox ("Воскресенье")
        Case Else
            MsgBox ("Введено некорректное значение")
    End Select
End Sub

Sub for21()
'Дано целое число N (> 0). Используя один цикл, найдите сумму 1 + 1/(1!) + 1/(2!) + 1/(3!) + … + 1/(N!)
'Полученное число является приближенным значением константы e = exp(1).
    Dim n As Integer, i As Integer, factorial As Integer, e As Double
    
    'Ввод числа n
    n = InputBox("Введите n")
    
    e = 1
    factorial = 1
    
    'Запускаем цикл
    For i = 1 To n
        factorial = factorial * i 'Находим факториал числа i
        e = e + (1 / factorial)
    Next i
End Sub

Sub while21()
'Дано целое число N (> 0). Определить, имеются ли в записи числа N нечётные числа. Если имеются, вывести true, в противном случае - false
    Dim n As Integer, b As Boolean
    
    'Ввод числа n
    n = InputBox("Введите n")
    
    b = False
    
    'Запускаем цикл
    While n > 0
        If (n Mod 10) Mod 2 = 1 Then b = True 'Проверяем последнюю цифру числа на нечётность
        n = n \ 10 'Отбрасываем последнюю цифру числа
    Wend
    
    MsgBox (b)
End Sub

Sub series21()
'Дано целое число N (> 0) и набор из N вещественных чисел. Проверить, образует ли данный набор возрастающую последовательность чисел.
    Dim n As Integer, i As Integer, a As Double, preva As Double, b As Boolean
    
    'Ввод числа n
    n = InputBox("Введите n")
    
    'Ввод 1-го числа
    preva = InputBox("Введите 1 число")
    
    b = True
    
    For i = 2 To n
        a = InputBox("Введите " & i & " число")
        If preva > a Then b = False
        preva = a
    Next i
    
    MsgBox (b)
End Sub

Sub minmax21()
'Дано целое число N (> 2) и набор из N чисел - значений некоторой величины, полученной в N опытах. Найти срднее значение это величины.
'При вычислении среднего значения не учитывать максимальное и минимальное из набора значений.
    Dim arr(100) As Integer, n As Integer, i As Integer, max As Integer, min As Integer, sum As Integer, count As Integer
    
    sum = 0
    count = 0
    max = -999
    min = 999
    
    'Ввод числа n
    n = InputBox("Введите n")
    
    'Ввод значений некоторой величины, нахождение минимума и максимума
    For i = 1 To n
        arr(i) = InputBox("Введите a[" & i & "]")
        If arr(i) > max Then max = arr(i)
        If arr(i) < min Then min = arr(i)
    Next i
    
    'Находим сумму и количество элементов, не равных минимуму или максимуму
    For i = 1 To n
        If arr(i) <> min And arr(i) <> max Then
            sum = sum + arr(i)
            count = count + 1
        End If
    Next i
    
    'Вычисляем и выводим среднее арифметическое
    MsgBox (sum / count)
End Sub

Sub array21()
'Дан массив размера N и целые числа K и L (1 = K = L = N). Найти среднее арифметическое элементов массива от K до L включительно.
    Dim arr(100) As Integer, n As Integer, l As Integer, k As Integer, sum As Integer, i As Integer
    
    sum = 0
    
    'Ввод чисел
    n = InputBox("Введите n")
    k = InputBox("Введите k")
    l = InputBox("Введите l")
    
    'Ввод массива
    For i = 1 To n
        arr(i) = InputBox("Введите a[" & i & "]")
    Next i
    
    'Находим сумму на промежутке
    For i = k To l
        sum = sum + arr(i)
    Next i
    
    'Вычисляем и выводим среднее арифметическое
    MsgBox (sum / (k - l + 1))
End Sub


'Выполнила: Фролова Л.А.
'Дата выполнения: 27.05.2020
