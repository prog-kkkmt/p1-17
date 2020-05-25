Attribute VB_Name = "Module1"
Sub begin8()
'Даны два числа a и b. Найти их среднее арифметическое: (a + b)/2.
 Dim x1 As Integer, x2 As Integer
    x1 = InputBox("Введите первое число")
    x2 = InputBox("Введите второе число")
    MsgBox (x1 + x2 / 2)
    
End Sub

Sub Int8()
'Дано двузначное число. Вывести число, полученное при перестановке цифр исходного числа.
    x1 = InputBox("Введите число")
    MsgBox ((x1 Mod 10) * 10 + x1 \ 10)
End Sub

Sub bool8()
'Даны два целых числа: A, B. Проверить истинность высказывания: «Каждое из чисел A и B нечетное».
    x1 = InputBox("Введите первое число")
    x2 = InputBox("Введите второе число")
    MsgBox ((x1 Mod 2) = 0 And (x2 Mod 2) = 0)
End Sub

Sub if8()
' Даны два числа. Вывести вначале большее, а затем меньшее из них.
x1 = InputBox("Введите первое число")
    x2 = InputBox("Введите второе число")
    If x1 > x2 Then
       MsgBox (x1 & " " & x2)
    Else
       MsgBox (x2 & " " & x1)
    End If
       
End Sub

Sub case8()
'Даны два целых числа: D (день) и M (месяц), определяющие правильную дату невисокосного года. Вывести значения D и M для даты, предшествующей указанной.
    x1 = InputBox("Введите день")
    x2 = InputBox("Введите месяц")
Select Case x2
    Case 5, 7, 8, 10, 12
        If x1 = 1 Then
            If x2 = 8 Then
                x1 = 31
            Else
                x1 = 30
             End If
             x2 = x2 - 1
        End If
    Case 2, 4, 6, 9, 11
        If x1 = 1 Then
            x1 = 31
            x2 = x2 - 1
        End If
    Case 3
        If x1 = 1 Then
            x1 = 28
            x2 = x2 - 1
        End If
    Case 1
        If x1 = 1 Then
            x1 = 31
            x2 = 12
        End If
End Select
MsgBox (x1 & " " & x2)
End Sub

Sub for8()
'Даны два целых числа A и B (A < B). Найти произведение всех целых чисел от A до B включительно.
    x1 = InputBox("Введите первое число")
    x2 = InputBox("Введите второе число")
    Dim x3 As Integer
    x3 = 1
    For Number = x1 To x2
        x3 = x3 * Number
        Next
    MsgBox (x3)
    
End Sub

Sub while8()
'Дано целое число N (> 0). Найти наибольшее целое число K, квадрат которого не превосходит N: K2 ? N. Функцию извлечения квадратного корня не использовать.
    x1 = InputBox("Введите число")
    Dim k As Integer
    k = 0
    While k * k <= x1
        k = k + 1
    Wend
    MsgBox (k - 1)
End Sub

Function Right(ByRef x1, x2)
x1 = x1 * 10 + x2
End Function


Sub series()
'Дано целое число N и набор из N целых чисел. Вывести в том же порядке все четные числа из данного набора и количество K таких чисел.
    x1 = InputBox("Введите количества чисел")
    For Number = 1 To x1
        z1 = InputBox("Введите количества чисел")
        If z1 Mod 2 = 0 Then
            MsgBox (z1)
        End If
        Next
End Sub

Sub proc8()
'Описать процедуру AddRightDigit(D, K), добавляющую к целому положительному числу K справа цифру D (D — входной параметр целого типа, лежащий в диапазоне 0–9, K — параметр целого типа, являющийся одновременно входным и выходным). С помощью этой процедуры последовательно добавить к данному числу K справа данные цифры D1 и D2, выводя результат каждого добавления.
    x1 = InputBox("Введите первое число")
    x2 = InputBox("Введите второе число")
    z = Right(x1, x2)
    MsgBox (x1)
End Sub

Function Quarter(x, y)
If x > 0 And y > 0 Then
     MsgBox ("1 четверть")
ElseIf x > 0 And y < 0 Then
     MsgBox ("2 четверть")
ElseIf x < 0 And y < 0 Then
     MsgBox ("3 четверть")
ElseIf x < 0 And y > 0 Then
     MsgBox ("4 четверть")
End If
     
        
End Function

Sub func8()
'Описать функцию Quarter(x, y) целого типа, определяющую номер координатной четверти, в которой находится точка с ненулевыми вещественными координатами (x, y). С помощью этой функции найти номера координатных четвертей для трех точек с данными ненулевыми координатами.
    x1 = InputBox("Введите первое число")
    x2 = InputBox("Введите второе число")
    z = Quarter(x1, x2)
End Sub

Sub minimummaximum()
'Дано целое число N и набор из N целых чисел. Найти номера первого и последнего минимального элемента из данного набора и вывести их в указанном порядке.
        x1 = InputBox("Введите количества чисел")
    Min = 999
    nax = -999
    minin = 0
    maxim = 0
    For Number = 1 To x1
        z1 = InputBox("Введите количества чисел")
        If z1 > max Then
            max = z1
            maxim = Number
        End If
        If z1 < Min Then
            Min = z1
            minin = Number
        End If
        Next
        If maxim > minin Then
            MsgBox (maxim & " " & minin)
        Else
            MsgBox (minin & " " & maxim)
        End If
            
End Sub
Sub array8()
'Дан целочисленный массив размера N. Вывести все содержащиеся в данном массиве нечетные числа в порядке возрастания их индексов, а также их количество K.
x1 = InputBox("Введите количества чисел")
 Dim max()
 ReDim max(x1)

    For i = 1 To x1
        max(i) = InputBox("Введите число")
    Next
    k = 0
    For i = 1 To x1
        If max(i) Mod 2 = 1 Then
            MsgBox (max(i))
            k = k + 1
            End If
    Next
    MsgBox ("Количество нечетных = " & k)
End Sub

Sub matrix8()
'Дана матрица размера M ? N и целое число K (1 ? K ? N). Вывести элементы K-го столбца данной матрицы.
m = InputBox("Введите количество строк")
n = InputBox("Введите количество столбцов")
 Dim max()
 ReDim max(m, n)
    For i = 1 To m
        For j = 1 To n
            max(i, j) = InputBox("Введите число")
        Next
    Next
    For i = 2 To m Step 2
        For j = 1 To n
            MsgBox ("Элемент " & i & " строки " & max(i, j))
        Next
    Next
End Sub

 Sub string8()
 'Дано целое число N (> 0) и символ C. Вывести строку длины N, которая состоит из символов C.
    c = InputBox("Введите символ")
    s = ""
    n = InputBox("Количество итераций")
    For i = 1 To n
        s = s + c
    Next
        MsgBox (s)
 End Sub
 
 Function pr8(ByRef mas(), ByRef n, x)
 Dim k()
 ReDim k(n)
 kol = 0
    For i = 1 To n
        If Not mas(i) = x Then
            k(i) = mas(i)
            kol = kol + 1
        End If
    Next
    mas() = k()
    n = kol
 End Function
 
 Sub param8()
 'Описать процедуру RemoveX(A, N, X), удаляющую из целочисленного массива A размера N элементы, равные целому числу X. Массив A и число N являются входными и выходными параметрами. С помощью этой процедуры удалить число XA из массивов A размера NA соответственно и вывести размер и содержимое полученного массива.
    x1 = InputBox("Введите количества чисел")
 Dim max()
 ReDim max(x1)
    For i = 1 To x1
        max(i) = InputBox("Введите число")
    Next
    z = InputBox("что удалить")
    е = pr8(max, x1, z)
    s = ""
    For i = 1 To x1
        s = s + " " + max(i)
    Next
        MsgBox ("Элементы массива " & s)
        MsgBox ("Новый размер массива " & x1)
 End Sub
 
 Function rc8(x, k, n)
 If Not n = 0 Then
    rc8 = 1
 Else
    rc8 = rc8(x, k, n - 1) - (rc8(x, k, n) - x / Exp(Log(rc8(x, k, n - 1)) * (k - 1))) / k
 End If
 End Function
 
 Sub recur8()
 'Описать рекурсивную функцию RootK(X, K, N) вещественного типа, находящую приближенное значение корня K-й степени из числа X по формуле:
'Y0 = 1,        YN+1 = YN ? (YN ? X/(YN)K?1)/K,
'где YN обозначает RootK(X, K, N) при фиксированных X и K. Параметры функции: X (> 0) — вещественное число, K (> 1) и N (> 0) — целые. С помощью функции RootK найти для данного числа X приближенные значения его корня K-й степени при шести данных значениях N.
 x = InputBox("x - ")
 k = InputBox("k - ")
 n = InputBox("n - ")
 MsgBox ("Корень = " & rc8(x, k, n))
 End Sub



