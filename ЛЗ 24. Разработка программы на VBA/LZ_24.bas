Attribute VB_Name = "LZ_24"
Option Explicit

Public Const MAXINT As Integer = (2 ^ 15) - 1

Type TRect
    a As Integer
    b As Integer
End Type

Sub Begin20()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Begin20. Найти расстояние между двумя  точками  с  заданными  координатами
Rem  (x1, y1) и (x2, y2) на плоскости.
Rem Гусятинер Л.Б., 22.05.2020
    Dim x1 As Double, x2 As Double, y1 As Double, y2 As Double, r As Double
    x1 = InputBox("")
    y1 = InputBox("")
    
    x2 = InputBox("")
    y2 = InputBox("")
    
    r = Math.Sqr((x2 - x1) ^ 2 + (y2 - y1) ^ 2)
    MsgBox (r)
End Sub

Sub Integer1()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Integer1. Дано расстояние L в сантиметрах. Используя операцию деления нацело,
Rem найти количество полных метров в нем (1 метр = 100 см).
Rem Гусятинер Л.Б., 22.05.2020
    Dim m As Integer, Sm As Integer
    Sm = InputBox("")
    m = Sm \ 100
    MsgBox (m)
End Sub

Sub Boolean36()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Boolean36. Даны координаты двух различных полей шахматной доски x1, y1, x2, y2
Rem (целые числа, лежащие в диапазоне 1–8). Проверить истинность высказывания:
Rem "Ладья за один ход может перейти с одного поля на другое".}
Rem Гусятинер Л.Б., 22.05.2020
    Dim x1 As Integer, y1 As Integer
    Dim x2 As Integer, y2 As Integer
    
    x1 = InputBox("")
    y1 = InputBox("")
    x2 = InputBox("")
    y2 = InputBox("")
    
    MsgBox ((x1 = x2) And (y1 <> y2) Or (y1 = y2) And (x1 <> x2))
End Sub

Sub If4()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem If4. Даны три целых числа. Найти количество положительных чисел в исходном наборе.
Rem Гусятинер Л.Б., 22.05.2020

    Dim a As Integer, b As Integer, c As Integer, k As Integer
    a = InputBox("")
    b = InputBox("")
    c = InputBox("")
    k = 0
    If a > 0 Then
        k = k + 1
    End If
    If b > 0 Then
        k = k + 1
    End If
    If c > 0 Then
        k = k + 1
    End If
    
    MsgBox (k)
End Sub

Sub Case3()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Case3. Дан номер месяца — целое число в диапазоне 1–12 (1 — январь, 2 — февраль и т. д.).
Rem  Вывести название соответствующего времени года («зима», «весна», «лето», «осень»).
Rem Гусятинер Л.Б., 22.05.2020

    Dim x As Integer
    x = InputBox("")
    Select Case x
        Case 1, 2, 12
            MsgBox ("зима")
        Case 1, 2, 12
            MsgBox ("зима")
        Case 3, 4, 5
            MsgBox ("весна")
        Case 6, 7, 8
            MsgBox ("лето")
        Case 9, 10, 11
            MsgBox ("осень")
        Case Else
            MsgBox ("неизвестное")
    End Select
End Sub

Sub For5()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem For 5. Дано вещественное число — цена 1 кг конфет.
Rem Вывести стоимость 0.1, 0.2, …, 1 кг конфет.}
Rem Гусятинер Л.Б., 23.05.2020

    Dim i As Integer, a As Double
    Dim ans As String
    a = InputBox("")
    ans = "Вес Стоимость" & vbNewLine
    ans = ans & "-------------" & vbNewLine
    
    For i = 1 To 10
        ans = ans & i / 10 & "     " & (a * i / 10) & vbNewLine
    Next i
    MsgBox (ans)
End Sub

Sub While5()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem While5. Дано  целое  число N (> 0),  являющееся  некоторой  степенью  числа 2:
Rem N = 2^K. Найти целое число K - показатель этой степени.
Rem Гусятинер Л.Б., 23.05.2020

    Dim n As Integer, k As Integer, st As Integer
    n = InputBox("")
    k = 0
    st = 1
  
    Do While st < n
        st = st * 2
        k = k + 1
    Loop
    MsgBox (k)
End Sub

Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Series24. Дано целое число N и набор из N целых чисел,
Rem содержащий по крайней мере два нуля. Вывести сумму чисел из данного набора,
Rem расположенных между последними двумя нулями (если последние нули идут подряд,
Rem то вывести 0.
Rem Гусятинер Л.Б., 23.05.2020
Sub Series24()
    Const MaxN = 100
    Dim n As Integer, i As Integer
    Dim v(1 To MaxN) As Integer
    Dim s As Integer
    
    n = InputBox("N=")
    Rem Заполнение массива
    For i = 1 To n
        v(i) = InputBox("")
    Next i
  
    Rem Поиск последнего нуля (в условии гарантируется, что он есть)
    i = n
    Do While (i > 0) And (v(i) <> 0)
        i = i - 1
    Loop
    s = 0
    Rem Последний нуль найден, но чисел для суммирования пока нет
    i = i - 1 ' это либо предпоследний нуль, либо первое ненулевое число
  
    Rem ищем предпоследний нуль и наращиваем сумму
    Do While (i > 0) And (v(i) <> 0)
        s = s + v(i)
        i = i - 1
    Loop
    MsgBox ("s=" & s)
End Sub

Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Proc7. Описать процедуру DigitCountSum(K, C, S), находящую количество C цифр целого
Rem положительного числа K, а также их сумму S (K — входной, C и S — выходные параметры
Rem целого типа). С помощью этой процедуры найти количество и сумму цифр для каждого из
Rem пяти данных целых чисел
Rem Гусятинер Л.Б., 23.05.2020

Sub DigitCountSum(ByVal k As Long, ByRef c As Integer, ByRef s As Integer)
  s = 0
  c = 0
  Do While k > 0
    c = c + 1
    s = s + k Mod 10
    k = k \ 10
  Loop
End Sub

Sub Proc7()
    Dim k As Integer, i As Integer, c As Integer, s As Integer
    Dim ans As String
    ans = ""
    For i = 1 To 5
        k = InputBox("")
        Call DigitCountSum(k, c, s)
        ans = ans & "k=" & k & " c=" & c & " sum=" & s & vbNewLine
    Next i
    MsgBox (ans)
End Sub

Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Minmax2. Дано целое число N и набор из N прямоугольников, заданных своими
Rem сторонами — парами чисел (a, b). Найти минимальную площадь прямоугольника из
Rem данного набора.
Rem Гусятинер Л.Б., 23.05.2020
Rem С использованием Record и Function

Function Square(ByRef rect As TRect) As Integer
  Square = rect.a * rect.b
End Function

Sub MinMax2()
    Dim i As Integer, n As Integer
    Dim rect As TRect
    Dim Smin As Integer
    Dim s As Integer
    Dim FirstInput As Boolean

    FirstInput = True ' Первая запись
    n = InputBox("Число прямоугольников")

    Smin = MAXINT
  
    For i = 1 To n
        rect.a = InputBox("Прямоугольник " & i & "Сторона a")
        rect.b = InputBox("Прямоугольник " & i & "Сторона b")
        s = Square(rect)
        If FirstInput Then
            FirstInput = False
            Smin = s
        ElseIf s < Smin Then
            Smin = s
        End If
    Next i
    MsgBox ("Минимальная площадь Smin=" & Smin)
End Sub

Sub Array9()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Array9. Дан целочисленный массив размера N.
Rem Вывести все содержащиеся в данном массиве четные числа в порядке убывания их индексов,
Rem а также их количество K.
Rem Гусятинер Л.Б., 23.05.2020
    Const MaxN As Integer = 100
    Dim i As Integer, k As Integer, n As Integer
    Dim a(1 To MaxN) As Integer
    n = InputBox("")
    k = 0
    For i = 1 To n
        a(i) = InputBox("")
    Next i
  
    Dim ans As String
    ans = ""
    For i = n To 1 Step -1
        If (a(i) Mod 2 = 0) Then
            ans = ans & a(i) & ","
            k = k + 1
        End If
    Next i
    ans = ans & vbNewLine & "k=" & k
    MsgBox (ans)
End Sub

Sub Matrix()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Даны целые положительные числа M, N и набор из M чисел. Сформировать матрицу
Rem размера M x N, у которой в каждом столбце содержатся все числа из исходного
Rem набора (в том же порядке) }
Rem Гусятинер Л.Б., 23.05.2020

    Const m As Integer = 5
    Const n As Integer = 5
    
    Dim i As Integer, j As Integer
    Dim a(1 To m, 1 To n) As Integer
    Dim v(1 To n) As Integer

    For i = 1 To m
        v(i) = InputBox("")
    Next i
  
    For i = 1 To m
        For j = 1 To n
            a(i, j) = v(i)
        Next j
    Next i
    
    Dim ans As String
    ans = ""
    For i = 1 To m
        For j = 1 To n
            ans = ans & a(i, j) & " "
        Next j
        ans = ans & vbNewLine
    Next i
    MsgBox (ans)
End Sub

Sub String10()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem String10. Дана строка. Вывести строку, содержащую те же символы, но расположенные в обратном порядке.
Rem Гусятинер Л.Б., 23.05.2020
    Dim i As Integer
    Dim s1 As String, s2 As String
    s1 = InputBox("")
    s2 = ""
    For i = Len(s1) To 1 Step -1
        s2 = s2 & Mid(s1, i, 1)
    Next i
    MsgBox (s2)
End Sub

Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Param11. Описать процедуру Sort(A, N), выполняющую сортировку по возрастанию
Rem вещественного массива A размера N. Массив A является входным и выходным параметром.
Rem С помощью этой процедуры отсортировать массивы A, B, C размера NA, NB, NC соответственно.
Rem Гусятинер Л.Б., 23.05.2020

Sub VPrint(ByRef v() As Integer, ByVal n As Integer, ByVal s As String)
    Dim i As Integer
    Dim ans As String
    ans = s & " <"
    For i = 0 To n - 1
        If i > 0 Then
            ans = ans & ","
        End If
        ans = ans & v(i)
    Next i
    ans = ans & ">"
    MsgBox (ans)
End Sub

Sub VSort(ByRef v() As Integer, ByVal n As Integer)
Rem Гусятинер Л.Б., 23.05.2020
    Dim x As Integer
    Dim i As Integer, j As Integer
  
    For i = 0 To n - 2
        For j = n - 1 To i + 1 Step -1
            If v(j - 1) > v(j) Then
                x = v(j)
                v(j) = v(j - 1)
                v(j - 1) = x
            End If
        Next j
    Next i
End Sub

Sub Param11()
Rem Гусятинер Л.Б., 23.05.2020

Const MaxN As Integer = 10
Dim i As Integer
Dim a(0 To MaxN - 1) As Integer
Dim na As Integer
    randomize
    na = MaxN
    For i = 0 To na - 1
        a(i) = -10 + Rnd * 20
    Next i
    
    Call VPrint(a, na, "Массив A до сортировки")
    Call VSort(a, na)
    Call VPrint(a, na, "Массив A после сортировки")
End Sub

Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Recur13. Описать рекурсивную функцию Palindrom(S) логического типа,
Rem возвращающую True, если строка S является палиндромом (то есть читается одинаково
Rem слева направо и справа налево), и False в противном случае.
Rem Оператор цикла в теле функции не использовать.
Rem Вывести значения функции Palindrom для пяти данных строк. }
Rem Гусятинер Л.Б., 23.05.2020

Function Palindrom(s As String) As Boolean
    If s = "" Then
        Palindrom = True
    Else
        Dim lenn As Integer
        lenn = Len(s)
        If lenn = 1 Then
            Palindrom = True
        Else
            Palindrom = Left(s, 1) = Right(s, 1) And Palindrom(Mid(s, 2, lenn - 2))
        End If
    End If
End Function

Sub Recur13()
Rem Гусятинер Л.Б., 23.05.2020
    Dim i As Integer, s As String
    'For i = 1 To 5
        s = InputBox("")
        MsgBox (Palindrom(s))
    'Next i
End Sub
