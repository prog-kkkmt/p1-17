Attribute VB_Name = "Module1"
Sub begin8()
'���� ��� ����� a � b. ����� �� ������� ��������������: (a + b)/2.
 Dim x1 As Integer, x2 As Integer
    x1 = InputBox("������� ������ �����")
    x2 = InputBox("������� ������ �����")
    MsgBox (x1 + x2 / 2)
    
End Sub

Sub Int8()
'���� ���������� �����. ������� �����, ���������� ��� ������������ ���� ��������� �����.
    x1 = InputBox("������� �����")
    MsgBox ((x1 Mod 10) * 10 + x1 \ 10)
End Sub

Sub bool8()
'���� ��� ����� �����: A, B. ��������� ���������� ������������: ������� �� ����� A � B ��������.
    x1 = InputBox("������� ������ �����")
    x2 = InputBox("������� ������ �����")
    MsgBox ((x1 Mod 2) = 0 And (x2 Mod 2) = 0)
End Sub

Sub if8()
' ���� ��� �����. ������� ������� �������, � ����� ������� �� ���.
x1 = InputBox("������� ������ �����")
    x2 = InputBox("������� ������ �����")
    If x1 > x2 Then
       MsgBox (x1 & " " & x2)
    Else
       MsgBox (x2 & " " & x1)
    End If
       
End Sub

Sub case8()
'���� ��� ����� �����: D (����) � M (�����), ������������ ���������� ���� ������������� ����. ������� �������� D � M ��� ����, �������������� ���������.
    x1 = InputBox("������� ����")
    x2 = InputBox("������� �����")
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
'���� ��� ����� ����� A � B (A < B). ����� ������������ ���� ����� ����� �� A �� B ������������.
    x1 = InputBox("������� ������ �����")
    x2 = InputBox("������� ������ �����")
    Dim x3 As Integer
    x3 = 1
    For Number = x1 To x2
        x3 = x3 * Number
        Next
    MsgBox (x3)
    
End Sub

Sub while8()
'���� ����� ����� N (> 0). ����� ���������� ����� ����� K, ������� �������� �� ����������� N: K2 ? N. ������� ���������� ����������� ����� �� ������������.
    x1 = InputBox("������� �����")
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
'���� ����� ����� N � ����� �� N ����� �����. ������� � ��� �� ������� ��� ������ ����� �� ������� ������ � ���������� K ����� �����.
    x1 = InputBox("������� ���������� �����")
    For Number = 1 To x1
        z1 = InputBox("������� ���������� �����")
        If z1 Mod 2 = 0 Then
            MsgBox (z1)
        End If
        Next
End Sub

Sub proc8()
'������� ��������� AddRightDigit(D, K), ����������� � ������ �������������� ����� K ������ ����� D (D � ������� �������� ������ ����, ������� � ��������� 0�9, K � �������� ������ ����, ���������� ������������ ������� � ��������). � ������� ���� ��������� ��������������� �������� � ������� ����� K ������ ������ ����� D1 � D2, ������ ��������� ������� ����������.
    x1 = InputBox("������� ������ �����")
    x2 = InputBox("������� ������ �����")
    z = Right(x1, x2)
    MsgBox (x1)
End Sub

Function Quarter(x, y)
If x > 0 And y > 0 Then
     MsgBox ("1 ��������")
ElseIf x > 0 And y < 0 Then
     MsgBox ("2 ��������")
ElseIf x < 0 And y < 0 Then
     MsgBox ("3 ��������")
ElseIf x < 0 And y > 0 Then
     MsgBox ("4 ��������")
End If
     
        
End Function

Sub func8()
'������� ������� Quarter(x, y) ������ ����, ������������ ����� ������������ ��������, � ������� ��������� ����� � ���������� ������������� ������������ (x, y). � ������� ���� ������� ����� ������ ������������ ��������� ��� ���� ����� � ������� ���������� ������������.
    x1 = InputBox("������� ������ �����")
    x2 = InputBox("������� ������ �����")
    z = Quarter(x1, x2)
End Sub

Sub minimummaximum()
'���� ����� ����� N � ����� �� N ����� �����. ����� ������ ������� � ���������� ������������ �������� �� ������� ������ � ������� �� � ��������� �������.
        x1 = InputBox("������� ���������� �����")
    Min = 999
    nax = -999
    minin = 0
    maxim = 0
    For Number = 1 To x1
        z1 = InputBox("������� ���������� �����")
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
'��� ������������� ������ ������� N. ������� ��� ������������ � ������ ������� �������� ����� � ������� ����������� �� ��������, � ����� �� ���������� K.
x1 = InputBox("������� ���������� �����")
 Dim max()
 ReDim max(x1)

    For i = 1 To x1
        max(i) = InputBox("������� �����")
    Next
    k = 0
    For i = 1 To x1
        If max(i) Mod 2 = 1 Then
            MsgBox (max(i))
            k = k + 1
            End If
    Next
    MsgBox ("���������� �������� = " & k)
End Sub

Sub matrix8()
'���� ������� ������� M ? N � ����� ����� K (1 ? K ? N). ������� �������� K-�� ������� ������ �������.
m = InputBox("������� ���������� �����")
n = InputBox("������� ���������� ��������")
 Dim max()
 ReDim max(m, n)
    For i = 1 To m
        For j = 1 To n
            max(i, j) = InputBox("������� �����")
        Next
    Next
    For i = 2 To m Step 2
        For j = 1 To n
            MsgBox ("������� " & i & " ������ " & max(i, j))
        Next
    Next
End Sub

 Sub string8()
 '���� ����� ����� N (> 0) � ������ C. ������� ������ ����� N, ������� ������� �� �������� C.
    c = InputBox("������� ������")
    s = ""
    n = InputBox("���������� ��������")
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
 '������� ��������� RemoveX(A, N, X), ��������� �� �������������� ������� A ������� N ��������, ������ ������ ����� X. ������ A � ����� N �������� �������� � ��������� �����������. � ������� ���� ��������� ������� ����� XA �� �������� A ������� NA �������������� � ������� ������ � ���������� ����������� �������.
    x1 = InputBox("������� ���������� �����")
 Dim max()
 ReDim max(x1)
    For i = 1 To x1
        max(i) = InputBox("������� �����")
    Next
    z = InputBox("��� �������")
    � = pr8(max, x1, z)
    s = ""
    For i = 1 To x1
        s = s + " " + max(i)
    Next
        MsgBox ("�������� ������� " & s)
        MsgBox ("����� ������ ������� " & x1)
 End Sub
 
 Function rc8(x, k, n)
 If Not n = 0 Then
    rc8 = 1
 Else
    rc8 = rc8(x, k, n - 1) - (rc8(x, k, n) - x / Exp(Log(rc8(x, k, n - 1)) * (k - 1))) / k
 End If
 End Function
 
 Sub recur8()
 '������� ����������� ������� RootK(X, K, N) ������������� ����, ��������� ������������ �������� ����� K-� ������� �� ����� X �� �������:
'Y0 = 1,        YN+1 = YN ? (YN ? X/(YN)K?1)/K,
'��� YN ���������� RootK(X, K, N) ��� ������������� X � K. ��������� �������: X (> 0) � ������������ �����, K (> 1) � N (> 0) � �����. � ������� ������� RootK ����� ��� ������� ����� X ������������ �������� ��� ����� K-� ������� ��� ����� ������ ��������� N.
 x = InputBox("x - ")
 k = InputBox("k - ")
 n = InputBox("n - ")
 MsgBox ("������ = " & rc8(x, k, n))
 End Sub



