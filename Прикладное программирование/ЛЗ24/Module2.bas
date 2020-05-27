Attribute VB_Name = "Module2"
Sub Begin25()

    Rem Begin25�. ����� �������� ������� y = 3x6 - 6x2 - 7 ��� ������ �������� x.
    Rem ��������� ������� ����� �1-17 26.05.2020
    
    Dim x As Double, y As Double
    x = InputBox("������� �������� x")
    y = 3 * x ^ 6 - 6 * x ^ 2 - 7
    MsgBox (y)

End Sub

Sub Integer14()

    Rem Integer14�. ���� ����������� �����. � ��� ���������� ������ ����� ������ � ��������� � �����. �������� ���������� �����
    Rem ��������� ������� ����� �1-17 26.05.2020
    
    Dim num As Integer, buf As Integer
    num = InputBox("������� �����")
    buf = num \ 100
    num = (num Mod 100) * 10 + buf
    MsgBox (num)
    
End Sub


Sub Boolean33()

    Rem Boolean33�. ���� ����� ����� a, b, c. ��������� ���������� ������������: ����������� ����������� �� ��������� a, b, c�.
    Rem ��������� ������� ����� �1-17 26.05.2020
    
    Dim a As Integer, b As Integer, c As Integer
    
    a = InputBox("������� �:")
    b = InputBox("������� b:")
    c = InputBox("������� c:")
    
    MsgBox (a + b > c And a + c > b And b + c > a)
    
End Sub

Sub If22()
    
    Rem if22�. ���� ���������� �����, �� �� ������� �� ������������ ���� OX � OY.
    Rem ���������� ����� ������������ ��������, � ������� ��������� ������ �����
    Rem ��������� ������� ����� �1-17 26.05.2020
    
    Dim x As Double, y As Double
    Dim res As Integer
    
    x = InputBox("������� x:")
    y = InputBox("������� y:")
    
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
    Rem Case18�. ���� ����� � ��������� 100�999. ������� ������ �������� ������� �����
    Rem ��������� ������� ����� �1-17 26.05.2020
    
    Dim num As Integer, hund As Integer, tens As Integer, un As Integer
    Dim answer As String
    
    num = InputBox("������� �����:")
    hund = num \ 100
    tens = (num Mod 100) \ 10
    un = num Mod 10
    
    Select Case hund
        Case 1: answer = "���"
        Case 2: answer = "������"
        Case 3: answer = "������"
        Case 4: answer = "��������"
        Case 5: answer = "�������"
        Case 6: answer = "��������"
        Case 7: answer = "�������"
        Case 8: answer = "���������"
        Case 9: answer = "���������"
    End Select
    
    Select Case tens
        Case 2: answer = answer + " ��������"
        Case 3: answer = answer + " ��������"
        Case 4: answer = answer + " �����"
        Case 5: answer = answer + " ���������"
        Case 6: answer = answer + " ����������"
        Case 7: answer = answer + " ���������"
        Case 8: answer = answer + " �����������"
        Case 9: answer = answer + " ���������"
    End Select
    
    If tens = 1 Then
        Select Case un
            Case 0: answer = answer + " ������"
            Case 1: answer = answer + " �����������"
            Case 2: answer = answer + " ����������"
            Case 3: answer = answer + " ����������"
            Case 4: answer = answer + " ������������"
            Case 5: answer = answer + " ����������"
            Case 6: answer = answer + " �����������"
            Case 7: answer = answer + " ����������"
            Case 8: answer = answer + " ������������"
            Case 9: answer = answer + " ������������"
        End Select
    Else
        Select Case un
            Case 1: answer = answer + " ����"
            Case 2: answer = answer + " ���"
            Case 3: answer = answer + " ���"
            Case 4: answer = answer + " ������"
            Case 5: answer = answer + " ����"
            Case 6: answer = answer + " �����"
            Case 7: answer = answer + " ����"
            Case 8: answer = answer + " ������"
            Case 9: answer = answer + " ������"
        End Select
    
    End If
    
    MsgBox (answer)
 
End Sub
Sub For18()

    Rem For18. ���� ������������ ����� A � ����� ����� N (> 0). ��������� ���� ����, ����� �������� ���������
    Rem 1 - A + A2 - A3 + � + (-1)N�AN.
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim a As Double, res As Double
    Dim n As Integer, i As Integer
    
    a = InputBox("������� �:")
    n = InputBox("������� n:")
    res = 1
    
    For i = 1 To n
        res = res + (a * -1) ^ i
    Next i
    
    MsgBox (res)
  
End Sub

Sub While17()
    Rem While17. ���� ����� ����� N (> 0).
    Rem ��������� �������� ������� ������ � ������ �������, ������� ��� ��� �����, ������� � ����� ������ (������� ������).
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim num As Integer, un As Integer
    Dim answer As String

    num = InputBox("������� �����")

    Do While num <> 0
        un = num Mod 10
        ans = ans & "   " & un
        num = num \ 10
    Loop
    
    MsgBox (ans)
    
End Sub

Sub Series19()
    Rem Series19�. ���� ����� ����� N (> 1) � ����� �� N ����� �����.
    Rem ������� �� �������� � ������, ������� ������ ������ ������ ������, � ���������� K ����� ���������.
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim n As Integer, k As Integer
    Const MaxN = 100
    Dim arr(1 To MaxN) As Integer
    Dim ans As String
    
     n = InputBox("������� ����� n")
    For i = 1 To n
        arr(i) = InputBox("������� ����� �����")
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

    Rem ������� ��������� AddLeftDigit(D, K), ����������� � ������ �������������� ����� K ����� ����� D
    Rem (D � ������� �������� ������ ����, ������� � ��������� 1�9, K � �������� ������ ����, ���������� ������������ ������� � ��������).
    Rem � ������� ���� ��������� ��������������� ��������� ������� ����� K ����� ������ ����� D1 � D2, ������ ��������� ������� ����������
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim k As Long
    Dim d1 As Integer, d2 As Integer
    Dim ans As String
    
    k = InputBox("������� ����� k")
    d1 = InputBox("������� �����")
    Call AddLeftDigit(k, d1)
    ans = ans & k
    MsgBox (ans)
    d2 = InputBox("������� �����")
    Call AddLeftDigit(k, d2)
    ans = ans & " " & k
    MsgBox (ans)
    
End Sub

Sub MinMax4()

    Rem Minmax4�. ���� ����� ����� N � ����� �� N �����. ����� ����� ������������ �������� �� ������� ������.
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim n As Integer, i As Integer
    Const MaxN = 100
    Dim arr(1 To MaxN) As Integer
    Dim min As Integer, minInd As Integer
    
    n = InputBox("������� ����� n")
    For i = 1 To n
        arr(i) = InputBox("������� ����� �����")
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

    Rem Array57. ��� ������������� ������ A ������� N. ���������� � ������������ ������ B ���� �� �������
    Rem ������� ��� �������� ��������� ������� � ������� ��������, � ����� � ���������:
    Rem A2,    A4,    A6,    �,    A1,    A3,    A5,    � . �������� �������� ��������������
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Const MaxN = 100
    Dim arr(1 To MaxN) As Integer
    Dim res(1 To MaxN) As Integer
    Dim n As Integer, i As Integer
    Dim ans As String
    
    
    n = InputBox("������� ����� n")
    For i = 1 To n
        arr(i) = InputBox("������� ����� �����")
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

    Rem Matrix18. ���� ������� ������� M * N � ����� ����� K (1 <= K <= N). ����� ����� � ������������ ��������� K-�� ������� ������ �������
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Const MaxN = 10, MaxM = 10
    Dim arr(1 To MaxN, 1 To MaxN) As Integer
    Dim n As Integer, m As Integer, k As Integer
    Dim sum As Integer, mult As Integer
    Dim ans As String
    
    n = InputBox("������� ���������� �����")
    m = InputBox("������� ���������� ��������")
    
    For i = 1 To n
        For j = 1 To m
            arr(i, j) = InputBox("������� ������� �������")
        Next j
    Next i
    
    k = InputBox("������� ����� �������")
    mult = 1
    
    For i = 1 To n
        sum = sum + arr(i, k)
        mult = mult * arr(i, k)
    Next i
    
    ans = "����� = " & sum & " ������������ = " & mult
    MsgBox (ans)
    
    
End Sub

Sub String13()
    
    Rem String13. ���� ������. ���������� ���������� ������������ � ��� ����.
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim str As String
    Dim count As Integer
    
    str = InputBox("������� ������")
    
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

    Rem Param4. ������� ��������� Inv(A, N), �������� ������� ���������� ��������� ������������� ������� A ������� N �� �������� (?????????????? ???????).
    Rem ������ A �������� ������� � �������� ����������.
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Const MaxN = 100
    Dim arr(1 To MaxN) As Double
    Dim n As Integer, i As Integer
    Dim ans As String
    
    n = InputBox("������� ����� n")
    For i = 1 To n
        arr(i) = InputBox("������� ����� �����")
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
    Rem ������� ����������� ������� Fact(N) ������������� ����, ����������� �������� ����������
    Rem ��������� ������� ����� �1-17 27.05.2020
    
    Dim num As Double
    num = InputBox("������� �����")
    
    MsgBox (Fact(num))
    
End Sub
