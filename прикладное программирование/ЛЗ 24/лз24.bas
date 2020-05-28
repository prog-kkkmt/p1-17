Sub begin13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Begin13.Даны два круга с общим центром и радиусами R1 и R2 (R1 > R2). Найти площади этих кругов S1 и S2, а также площадь S3 кольца, внешний радиус которого равен R1, а внутренний радиус равен R2:
Rem S1 = pi(R1)^2,        S2 = pi(R2)^2,        S3 = S1 - S2.
Rem В качестве значения pi использовать 3.14.
Rem Озерова А. С., 27.05.2020
    Const pi = 3.14
    Dim r1 As Integer, r2 As Integer
    Dim s1 As Double, s2 As Double, s3 As Double
    r1 = InputBox("Введите радиус S1(R1 > R2)")
    r2 = InputBox("Введите радиус  S2(R1 > R2)")
    s1 = pi * r1 ^ 2
    s2 = pi * r2 ^ 2
    s3 = s1 - s2
    MsgBox ("s1 = " & s1)
    MsgBox ("s2 = " & s2)
    MsgBox ("s3 = " & s3)
End Sub

Sub integer13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Integer13.Дано трехзначное число. В нем зачеркнули первую слева цифру и приписали ее справа. Вывести полученное число.
Rem Озерова А. С., 27.05.2020
    Dim a As Integer, z As Integer
    a = InputBox("Введите число ")
    z = (a Mod 100) * 10 + a \ 100
    MsgBox ("Число : " & z)
End Sub

Sub boolean13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Boolean13.Даны три целых числа: A, B, C. Проверить истинность высказывания: «Хотя бы одно из чисел A, B, C положительное».
Rem Озерова А. С., 27.05.2020
    Dim a As Integer, b As Integer, c As Integer
    a = InputBox("А =")
    b = InputBox("B =")
    c = InputBox("C =")
    MsgBox ((a > 0) Or (b > 0) Or (c > 0))
End Sub

Sub if13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem If13.Даны три числа. Найти среднее из них (т. е. число, расположенное между наименьшим и наибольшим).
Rem Озерова А. С., 27.05.2020
    Dim a As Integer, b As Integer, c As Integer
    a = InputBox("А =")
    b = InputBox("B =")
    c = InputBox("C =")
    If ((a > b) And (a < c)) Or ((a > c) And (a < b)) Then
        MsgBox ("Среднее  : " & a)
    ElseIf ((b > a) And (b < c)) Or ((b > c) And (b < a)) Then
        MsgBox ("Среднее  : " & b)
    Else
        MsgBox ("Среднее  : " & c)
    End If
End Sub

Sub case13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Case13.ЭЭлементы равнобедренного прямоугольного треугольника пронумерованы следующим образом: 1 — катет a, 2 — гипотенуза
Rem c= a * 2 ^ 1/2, 3 — высота h, опущенная на гипотенузу (h = c/2), 4 — площадь S = c*h/2. Дан номер одного из этих элементов и его значение. Вывести
Rem значения остальных элементов данного треугольника (в том же порядке).
Rem Озерова А. С., 27.05.2020
    Dim a As Integer, c As Integer, h As Integer, n As Integer
    Dim s As Double
    n = InputBox("n = ")
    Select Case n
        Case 1
            a = InputBox("Катет : ")
            c = a * (2 ^ (1 / 2))
            h = c / 2
            s = c * h / 2
            MsgBox ("гипотенуза = " & c)
            MsgBox ("высота = " & h)
            MsgBox ("площадь = " & s)
        Case 2
            c = InputBox("гипотенуза : ")
            a = c / (2 ^ (1 / 2))
            h = c / 2
            s = c * h / 2
            MsgBox ("катет = " & a)
            MsgBox ("высота = " & h)
            MsgBox ("площадь = " & s)
        Case 3
            c = InputBox("высота : ")
            c = h * 2
            a = c / (2 ^ (1 / 2))
            s = c * h / 2
            MsgBox ("катет = " & a)
            MsgBox ("гипотенуза = " & c)
            MsgBox ("площадь = " & s)
        Case 4
            s = InputBox("площадь : ")
            h = s ^ 0.5
            c = 2 * h
            a = c / (2 ^ (1 / 2))
            MsgBox ("катет = " & a)
            MsgBox ("гипотенуза = " & c)
            MsgBox ("высота = " & h)
    End Select
End Sub
Sub for13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem For13.Дано целое число N (> 0). Найти значение выражения
Rem 1.1 - 1.2 + 1.3 - …
Rem (N слагаемых, знаки чередуются). Условный оператор не использовать.
Rem Озерова А. С., 27.05.2020
    Dim n As Integer, k As Integer, i As Integer
    Dim sum As Double
    sum = 0
    k = -1
    n = InputBox("n = ")
    For i = 1 To n
        k = k * (-1)
        sum = sum + k * (1 + 0.1 * i)
    Next i
    MsgBox (sum)
End Sub
Sub While13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem While13.Дано число A (> 1). Вывести наименьшее из целых чисел K, для которых сумма 1 + 1/2 + … + 1/K будет больше A, и саму эту сумму.
Rem Озерова А. С., 27.05.2020
    Dim a As Integer, k As Integer
    Dim sum As Double
    a = InputBox(" a = ")
    k = 0
    sum = 0
    Do While sum <= a
        k = k + 1
        sum = sum + 1 / k
    Loop
    MsgBox ("k = " & k & " sum = " & sum)
End Sub

Sub Series13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Series13.Дан набор ненулевых целых чисел; признак его завершения — число 0. Вывести сумму всех положительных четных чисел из данного набора. Если
Rem требуемые числа в наборе отсутствуют, то вывести 0
Rem Озерова А. С., 27.05.2020
    Dim sum As Integer, a As Integer
    sum = 0
    a = 1
    Do While a <> 0
        a = InputBox("a = ")
        If (a > 0) And (a Mod 2 = 0) Then
            sum = sum + a
        End If
    Loop
    MsgBox ("sum = " & sum)
End Sub
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Proc13.Описать процедуру SortDec3(A, B, C), меняющую содержимое переменных A, B, C таким образом, чтобы их значения оказались
Rem упорядоченными по убыванию (A, B, C — вещественные параметры, являющиеся одновременно входными и выходными). С помощью этой процедуры упорядочить по
Rem убыванию два данных набора из трех чисел: (A1, B1, C1) и (A2, B2, C2)
Rem Озерова А. С., 27.05.2020
Sub swap(ByRef a As Double, ByRef b As Double)
    Dim tmp As Double
    tmp = b
    b = a
    a = tmp
End Sub
Sub SortDec(ByRef a As Double, ByRef b As Double, ByRef c As Double)
    If a < b Then
        Call swap(a, b)
    End If
    If a < c Then
        Call swap(a, c)
    End If
    If b < c Then
        Call swap(b, c)
    End If
    End Sub
Sub Proc13()
    Dim a As Double, b As Double, c As Double
    For i = 1 To 2
        a = InputBox("a = ")
        b = InputBox("b = ")
        c = InputBox("c = ")
        Call SortDec(a, b, c)
        MsgBox a & ", " & b & ", " & c
    Next i
End Sub

Sub MinMax13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Minmax13.Дано целое число N и набор из N целых чисел. Найти номер первого
Rem максимального нечетного числа из данного набора. Если нечетные числа в наборе
Rem отсутствуют, то вывести 0.
Rem Озерова А. С., 27.05.2020
    Dim n As Integer, r As Integer, max As Integer, num As Integer
    n = InputBox(" n = ")
    For i = 1 To n
        r = InputBox(" r = ")
        If ((r Mod 2 <> 0) And (r > max)) Then
            max = r
            num = i
        End If
    Next i
    MsgBox "max = " & max & " number : " & num
End Sub

Sub Array13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Array13.Дан массив A размера N (N - нечетное число). Вывести его элементы с нечетными номерами в порядке
Rem убывания номеров: AN, AN-2, AN-4, …, A1. Условный оператор не использовать.
Rem Озерова А. С., 27.05.2020
    Const MaxN As Integer = 100
    Dim a(1 To MaxN) As Integer
    Dim n As Integer
    Dim ans As String
    ans = ""
    n = InputBox("Размер : ")
    For i = 1 To n
        a(i) = InputBox("")
    Next i
    For i = n To 1 Step -2
        ans = ans & a(i) & " "
    Next i
    MsgBox (ans)
End Sub

Sub Matrix13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Matrix13.Дана квадратная матрица A порядка M. Начиная с элемента A1,1, вывести ее элементы следующим образом («уголками»):
Rem все элементы первой строки; элементы последнего столбца, кроме первого (уже выведенного) элемента; оставшиеся
Rem элементы второй строки; оставшиеся элементы предпоследнего столбца и т. д.; последним выводится элемент AM,1.
Rem Озерова А. С., 27.05.2020
    Const m As Integer = 4
    Const n As Integer = 4
    Dim a(1 To m, 1 To n) As Integer
    Dim i As Integer, j As Integer, k As Integer
    
    For i = 1 To m
        For j = 1 To n
            a(i, j) = InputBox("")
        Next j
    Next i
    
    Dim ans As String
    ans = ""
    For i = 1 To m
        For j = 1 To m - i + 1
            ans = ans & a(i, j)
        Next j
        For k = i + 1 To m
            ans = ans & a(k, m - i + 1)
        Next k
        ans = ans & vbNewLine
    Next i

    MsgBox (ans)
    Rem Worksheets("Лист 1").Cells(1, 1).Resize(m, n).Value = a
End Sub

Sub String13()
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem String13.Дана строка. Подсчитать количество содержащихся в ней цифр.
Rem Озерова А. С., 27.05.2020
    Dim length As Integer, i As Integer, kol As Integer
    Dim s As String
    s = InputBox("Введите строку")
    length = Len(s)
    Do While i < length
        i = i + 1
        If IsNumeric(Mid(s, i, 1)) Then
            kol = kol + 1
        End If
    Loop
        MsgBox ("Кол-во : " & kol)
End Sub

Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Param13. Описать процедуру Hill(A, N), меняющую порядок элементов
Rem вещественного массива A размера N на следующий: наименьший элемент
Rem массива располагается на первом месте, наименьший из оставшихся
Rem элементов — на последнем, следующий по величине располагается на
Rem втором месте, следующий — на предпоследнем и т. д. (в результате
Rem график значений элементов будет напоминать холм). Массив A является
Rem входным и выходным параметром. С помощью этой процедуры
Rem преобразовать массивы A, B, C размера NA, NB, NC соответственно.
Rem Озерова А. С., 27.05.2020
Sub swaph(ByRef a As Double, ByRef b As Double)
    Dim tmp As Double
    tmp = a
    a = b
    b = tmp
End Sub
Sub Hill(ByRef a() As Double, ByVal n As Integer)
    Dim i As Integer, j As Integer, imin As Integer
    For i = 1 To n / 2
        imin = i
        For j = imin + 1 To n - i + 1
            If a(j) < a(imin) Then
                imin = j 'ищем мин'
            End If
            Call swaph(a(i), a(imin)) 'обмен с текущим левым'
            imin = i + 1
        Next j
        For j = imin + 1 To n - i + 1
            If a(j) < a(imin) Then
                imin = j
            End If
            Call swaph(a(n - i + 1), a(imin)) 'обмен с текущем правым'
        Next j
    Next i
End Sub
Sub Param13()
    Const MaxN As Integer = 100
    Dim a(1 To MaxN) As Double
    Dim n As Integer, i As Integer
    For j = 1 To 3
        n = InputBox("Размер : ")
        For i = 1 To n
            a(i) = InputBox("")
        Next i
        Call Hill(a, n)
        Dim ans As String
        ans = ""
        For i = 1 To n
            ans = ans & a(i)
        Next i
        MsgBox (ans & vbNewLine)
    Next j
End Sub
Rem М. Э. Абрамян. 1000 ЗАДАЧ ПО ПРОГРАММИРОВАНИЮ, Ростов-на-Дону 2004.
Rem Recur13. Описать рекурсивную функцию Palindrome(S) логического типа,
Rem возвращающую True, если строка S является палиндромом (т. е.
Rem читается одинаково слева направо и справа налево), и False в
Rem противном случае. Оператор цикла в теле функции не использовать.
Rem Вывести значения функции Palindrome для пяти данных строк.
Rem Озерова А. С., 27.05.2020
Function Palindrom(s As String) As Boolean
    Dim lenn As Integer
    lenn = Len(s)
    If lenn < 2 Then
        Palindrom = True
    Else
        Palindrom = (s = StrReverse(s))
    End If
End Function
Sub Recur13()
    Dim s As String
    s = InputBox("Строка : ")
    MsgBox ("палиндром? " & Palindrom(s))
End Sub
