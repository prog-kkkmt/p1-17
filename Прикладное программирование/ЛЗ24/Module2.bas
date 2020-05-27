Attribute VB_Name = "Module2"
Sub Begin25()

    Rem Begin25°. Найти значение функции y = 3x6 - 6x2 - 7 при данном значении x.
    Rem Выполнила Попкова Алена П1-17 26.05.2020
    
    Dim x As Double, y As Double
    x = InputBox("Введите значение x")
    y = 3 * x ^ 6 - 6 * x ^ 2 - 7
    MsgBox (y)

End Sub

Sub Integer14()

    Rem Integer14°. Дано трехзначное число. В нем зачеркнули первую цифру справа и рпиписали её слева. Выфвести полученное число
    Rem Выполнила Попкова Алена П1-17 26.05.2020
    
    Dim num As Integer, buf As Integer
    num = InputBox("Введите число")
    buf = num \ 100
    num = (num Mod 100) * 10 + buf
    MsgBox (num)
    
End Sub


Sub Boolean33()

    Rem Boolean33°. Даны целые числа a, b, c. Проверить истинность высказывания: «Существует треугольник со сторонами a, b, c».
    Rem Выполнила Попкова Алена П1-17 26.05.2020
    
    Dim a As Integer, b As Integer, c As Integer
    
    a = InputBox("Введите а:")
    b = InputBox("Введите b:")
    c = InputBox("Введите c:")
    
    MsgBox (a + b > c And a + c > b And b + c > a)
    
End Sub

Sub If22()
    
    Rem if22°. Даны координаты точки, не не лежащей на координатных осях OX и OY.
    Rem Определить номер координатной четверти, в которой находится данная точка
    Rem Выполнила Попкова Алена П1-17 26.05.2020
    
    Dim x As Double, y As Double
    Dim res As Integer
    
    x = InputBox("Введите x:")
    y = InputBox("Введите y:")
    
    If x > 0 And y > 0 Then
        res = 1
    ElseIf x < 0 And y > 0 Then
        res = 2
    ElseIf x < 0 And y < 0 Then
        res = 3
    Else
        res = 4
        
    End If
    
    MsgBox (res)
    
End Sub

Sub Case1()
    Rem Case18°. Дано число в диапазоне 100–999. Вывести строку описание данного числа
    Rem Выполнила Попкова Алена П1-17 26.05.2020
    
    Dim num As Integer, hund As Integer, tens As Integer, un As Integer
    Dim answer As String
    
    num = InputBox("Введите число:")
    hund = num \ 100
    tens = (num Mod 100) \ 10
    un = num Mod 10
    
    Select Case hund
        Case 1: answer = "сто"
        Case 2: answer = "двести"
        Case 3: answer = "триста"
        Case 4: answer = "четреста"
        Case 5: answer = "пятьсот"
        Case 6: answer = "шестьсот"
        Case 7: answer = "семьсот"
        Case 8: answer = "восемьсот"
        Case 9: answer = "девятьсот"
    End Select
    
    Select Case tens
        Case 2: answer = answer + " двадцать"
        Case 3: answer = answer + " тридцать"
        Case 4: answer = answer + " сорок"
        Case 5: answer = answer + " пятьдесят"
        Case 6: answer = answer + " шестьдесят"
        Case 7: answer = answer + " семьдесят"
        Case 8: answer = answer + " восемьдесят"
        Case 9: answer = answer + " девяносто"
    End Select
    
    If tens = 1 Then
        Select Case un
            Case 0: answer = answer + " десять"
            Case 1: answer = answer + " одиннадцать"
            Case 2: answer = answer + " двенадцать"
            Case 3: answer = answer + " тринадцать"
            Case 4: answer = answer + " четырнадцать"
            Case 5: answer = answer + " пятнадцать"
            Case 6: answer = answer + " шестнадцать"
            Case 7: answer = answer + " семнадцать"
            Case 8: answer = answer + " восемнадцать"
            Case 9: answer = answer + " девятнадцать"
        End Select
    Else
        Select Case un
            Case 1: answer = answer + " один"
            Case 2: answer = answer + " два"
            Case 3: answer = answer + " три"
            Case 4: answer = answer + " четыре"
            Case 5: answer = answer + " пять"
            Case 6: answer = answer + " шесть"
            Case 7: answer = answer + " семь"
            Case 8: answer = answer + " восемь"
            Case 9: answer = answer + " девять"
        End Select
    
    End If
    
    MsgBox (answer)
 
End Sub
Sub For18()

    Rem For18. Дано вещественное число A и целое число N (> 0). Используя один цикл, найти значение выражения
    Rem 1 - A + A2 - A3 + … + (-1)N·AN.
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim a As Double, res As Double
    Dim n As Integer, i As Integer
    
    a = InputBox("Введите а:")
    n = InputBox("Введите n:")
    res = 1
    
    For i = 1 To n
        res = res + (a * -1) ^ i
    Next i
    
    MsgBox (res)
  
End Sub

Sub While17()
    Rem While17. Дано целое число N (> 0).
    Rem Используя операцию деление нацело и взятие остатка, вывести все его цифры, начиная с самой правой (разряда единиц).
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim num As Integer, un As Integer
    Dim answer As String

    num = InputBox("Введите число")

    Do While num <> 0
        un = num Mod 10
        ans = ans & "   " & un
        num = num \ 10
    Loop
    
    MsgBox (ans)
    
End Sub

Sub Series19()
    Rem Series19°. Дано целое число N (> 1) и набор из N целых чисел.
    Rem Вывести те элементы в наборе, которые меньше своего левого соседа, и количество K таких элементов.
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim n As Integer, k As Integer
    Const MaxN = 100
    Dim arr(1 To MaxN) As Integer
    Dim ans As String
    
     n = InputBox("Введите число n")
    For i = 1 To n
        arr(i) = InputBox("Введите набор чисел")
    Next i
    
    For i = 2 To n
        If arr(i) < arr(i - 1) Then
            ans = ans & " " & arr(i)
            k = k + 1
        End If
    Next i
    
    ans = ans & " k = " & k
    MsgBox (ans)
    
End Sub

Sub AddLeftDigit(ByRef k As Long, ByVal d As Integer)
    Dim categ As Integer, num As Integer
    categ = IIf(k > 0, 1, -1)
    num = k
    Do While num <> 0
        num = num \ 10
        categ = categ * 10
    Loop
      
    k = k + d * categ

End Sub

Sub Proc9()

    Rem Описать процедуру AddLeftDigit(D, K), добавляющую к целому положительному числу K слева цифру D
    Rem (D — входной параметр целого типа, лежащий в диапазоне 1–9, K — параметр целого типа, являющийся одновременно входным и выходным).
    Rem С помощью этой процедуры последовательно добавитьк данному числу K слева данные цифры D1 и D2, выводя результат каждого добавления
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim k As Long
    Dim d1 As Integer, d2 As Integer
    Dim ans As String
    
    k = InputBox("Введите число k")
    d1 = InputBox("Введите цифру")
    Call AddLeftDigit(k, d1)
    ans = ans & k
    MsgBox (ans)
    d2 = InputBox("Введите цифру")
    Call AddLeftDigit(k, d2)
    ans = ans & " " & k
    MsgBox (ans)
    
End Sub

Sub MinMax4()

    Rem Minmax4°. Дано целое число N и набор из N чисел. Найти номер минимального элемента из данного набора.
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim n As Integer, i As Integer
    Const MaxN = 100
    Dim arr(1 To MaxN) As Integer
    Dim min As Integer, minInd As Integer
    
    n = InputBox("Введите число n")
    For i = 1 To n
        arr(i) = InputBox("Введите набор чисел")
    Next i
    
    min = arr(1)
    For i = 2 To n
        If arr(i) < min Then
            min = arr(i)
            minInd = i
        End If
    Next i
    
    MsgBox (minInd)
 
End Sub

Sub Array57()

    Rem Array57. Дан целочисленный массив A размера N. Переписать в целочисленый массив B того же размера
    Rem вначале все элементы исходного массива с четными номерами, а затем с нечетными:
    Rem A2,    A4,    A6,    …,    A1,    A3,    A5,    … . Условный оператор неиспользовать
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Const MaxN = 100
    Dim arr(1 To MaxN) As Integer
    Dim res(1 To MaxN) As Integer
    Dim n As Integer, i As Integer
    Dim ans As String
    
    
    n = InputBox("Введите число n")
    For i = 1 To n
        arr(i) = InputBox("Введите набор чисел")
    Next i
    
    For i = 1 To n \ 2
        res(i) = arr(i * 2)
        ans = ans & " " & res(i)
    Next i

    For i = 1 To n \ 2
        res(n \ 2 + i) = arr(i * 2 - 1)
        ans = ans & " " & res(n \ 2 + i)
    Next i
    
    MsgBox (ans)

End Sub

Sub Matrix18()

    Rem Matrix18. Дана матрица размера M * N и целое число K (1 <= K <= N). Найти сумму и произведение элементов K-го столбца данной матрицы
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Const MaxN = 10, MaxM = 10
    Dim arr(1 To MaxN, 1 To MaxN) As Integer
    Dim n As Integer, m As Integer, k As Integer
    Dim sum As Integer, mult As Integer
    Dim ans As String
    
    n = InputBox("Введите количество строк")
    m = InputBox("Введите количество столбцов")
    
    For i = 1 To n
        For j = 1 To m
            arr(i, j) = InputBox("Введите элемент матрицы")
        Next j
    Next i
    
    k = InputBox("Введите номер столбца")
    mult = 1
    
    For i = 1 To n
        sum = sum + arr(i, k)
        mult = mult * arr(i, k)
    Next i
    
    ans = "Сумма = " & sum & " Произведение = " & mult
    MsgBox (ans)
    
    
End Sub

Sub String13()
    
    Rem String13. Дана строка. Подсчитать количество содержащихся в ней цифр.
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim str As String
    Dim count As Integer
    
    str = InputBox("Введите строку")
    
    For i = 1 To Len(str)
        If IsNumeric(Mid(str, i, 1)) Then
            count = count + 1
        End If
    Next i
        
    MsgBox (count)
    
End Sub

Sub Inv(ByRef a() As Double, ByVal n As Integer)
    Dim i As Integer
    Dim temp As Double
    
    For i = 1 To n \ 2
        temp = a(i)
        a(i) = a(n - i + 1)
        a(n - i + 1) = temp
    Next i
    
End Sub
Sub Param32()

    Rem Param4. Описать процедуру Inv(A, N), меняющую порядок следования элементов вещественного массива A размера N на обратный (?????????????? ???????).
    Rem Массив A является входным и выходным параметром.
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Const MaxN = 100
    Dim arr(1 To MaxN) As Double
    Dim n As Integer, i As Integer
    Dim ans As String
    
    n = InputBox("Введите число n")
    For i = 1 To n
        arr(i) = InputBox("Введите набор чисел")
    Next i
    
    Call Inv(arr, n)
    For i = 1 To n
        ans = ans & " " & arr(i)
        
    Next i
    
    MsgBox (ans)

End Sub

Function Fact(ByVal num As Double) As Double
    If num > 1 Then
        Fact = num * Fact(num - 1)
    Else
        Fact = 1
    End If
    
End Function

Sub Recur1()
    Rem Описать рекурсивную функцию Fact(N) вещественного типа, вычисляющую значение факториала
    Rem Выполнила Попкова Алена П1-17 27.05.2020
    
    Dim num As Double
    num = InputBox("Введите число")
    
    MsgBox (Fact(num))
    
End Sub
