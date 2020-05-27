Attribute VB_Name = "Module1"
Option Explicit
'Begin8�. ���� ��� ����� a � b. ����� �� ������� ��������������: (a + b)/2.
'���������: ���������� ���������

Sub begin8()
    Dim a As Integer
    Dim b As Integer
    a = InputBox("������� �: ")
    b = InputBox("������� b: ")
    MsgBox ((a + b) / 2)
End Sub
'Integer7�. ���� ���������� �����. ����� ����� � ������������ ��� ����.
Sub integer7()
    Dim a As Integer
    a = InputBox("������� �: ")
    MsgBox ("�����: " & (a \ 10 + a Mod 10) & " ������������: " & ((a \ 10) * (a Mod 10)))
End Sub
'Boolean3�. ���� ����� ����� A. ��������� ���������� ������������: ������ A �������� ������.
Sub boolean3()
    Dim a As Integer
    a = InputBox("������� �: ")
    If a Mod 2 = 0 Then
        MsgBox (True)
    Else
        MsgBox (False)
    End If
End Sub
'���� ����� �����. ���� ��� �������� �������������, �� ������� �� ���� 8; ���� �������������, �� ��������� � ���� 6; ���� �������, �� �������� ��� �� 10. ������� ���������� �����.
Sub if3()
    Dim a As Integer
    a = InputBox("������� �: ")
    If a > 0 Then
        MsgBox (a - 8)
    ElseIf a < 0 Then
        MsgBox (a + 6)
    Else
        MsgBox (10)
    End If
End Sub
'Case3. ��� ����� ������ � ����� ����� � ��������� 1�12 (1 � ������, 2 � ������� � �. �.). ������� �������� ���������������� ������� ���� (�����, ������, �����, �������).
Sub case3()
    Dim a As Integer
    a = InputBox("������� �: ")
    
    Select Case a
    Case 12, 1 To 2
        MsgBox ("����")
    Case 3 To 5
        MsgBox ("�����")
    Case 6 To 8
        MsgBox ("����")
    Case 9 To 11
        MsgBox ("�����")
    End Select
    
End Sub
'For7. ���� ��� ����� ����� A � B (A < B). ����� ����� ���� ����� ����� �� A �� B ������������.
Sub for7()
    Dim a As Integer
    Dim b As Integer
    Dim sum As Integer
    Dim i As Integer
    a = InputBox("������� �: ")
    b = InputBox("������� b: ")
    sum = 0
    For i = a To b
        sum = sum + i
    Next i
    MsgBox (sum)
End Sub
'While7�. ���� ����� ����� N (> 0). ����� ���������� ����� ������������� ����� K, ������� �������� ����������� N: K2 > N. ������� ���������� ����������� ����� �� ������������.
Sub while7()
    Dim a As Integer
    Dim k As Integer
    a = InputBox("������� �: ")
    k = 1
    Do While k ^ 2 < a
        k = k + 1
    Loop
    MsgBox (k)
End Sub
'Series8. ���� ����� ����� N � ����� �� N ����� �����. ������� � ��� �� ������� ��� ������ ����� �� ������� ������ � ���������� K ����� �����.
Sub Series8()
    Dim n As Integer
    Dim count As Integer
    Dim a(9) As Integer
    Dim s As String
    Dim i As Integer
    For i = 0 To 9
        a(i) = InputBox("������� " & i & " ����� = ")
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
'Proc1. ������� ��������� PowerA3(A, B), ����������� ������ ������� ����� A � ������������ �� � ���������� B (A � �������, B � �������� ��������; ��� ��������� �������� �������������). � ������� ���� ��������� ����� ������ ������� ���� ������ �����.
Sub proc1()
    Dim a As Single
    Dim b As Single
    Dim i As Integer
    For i = 0 To 4
        a = InputBox("������� �: ")
        Call PowerA3(a, b)
        MsgBox (b)
    Next i
    
End Sub
Sub PowerA3(ByVal a As Single, ByRef b As Single)
    b = a ^ 3
End Sub
'Minmax4�. ���� ����� ����� N � ����� �� N �����. ����� ����� ������������ �������� �� ������� ������.
Sub minmax4()
    Dim n As Integer
    Dim min As Integer
    Dim i As Integer
    min = 10000
    For i = 0 To 9
        n = InputBox("������� " & i & " ����� = ")
        If n < min Then
            min = n
        End If
    Next i
    MsgBox (min)
End Sub
'Array1. ���� ����� ����� N (> 0). ������������ � ������� ������������� ������ ������� N, ���������� N ������ ������������� �������� �����: 1, 3, 5, � .
Sub Array1()
    Dim n As Integer
    n = InputBox("������� n: ")
    Dim a(100) As Integer
    Dim s As String
    Dim i As Integer
    For i = 1 To n
        a(i) = 2 * i - 1
        s = s & a(i) & " "
    Next i
    
    MsgBox (s)

End Sub
'Matrix4. ���� ����� ������������� ����� M, N � ����� �� N �����. ������������ ������� ������� M x N, � ������� � ������ ������ ���������� ��� ����� �� ��������� ������ (� ��� �� �������).
Sub Matrix4()
    Dim m As Integer
    Dim n As Integer
    Dim i As Integer, j As Integer
    Dim s As String
    m = InputBox("������� m: ")
    n = InputBox("������� n: ")
    Dim arr() As Integer
    ReDim arr(0 To n - 1) As Integer
    For i = 0 To n - 1
        arr(i) = InputBox("������� " & i + 1 & " ����� = ")
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
'String2. ���� ����� ����� N (32 < N < 126). ������� ������ � �����, ������ N.
Sub String2()
    Dim n As Integer
    n = InputBox("������� n: ")
    MsgBox (Chr(n))
End Sub
'Param2. ������� ������� MaxNum(A, N) ������ ����, ��������� ����� ������������� �������� ������������� ������� A ������� N. � ������� ���� ������� ����� ������ ������������ ��������� �������� A, B, C ������� NA, NB, NC ��������������.
Sub Param2()
    Dim a() As Double
    
    Dim n As Integer
    Dim i As Integer
    n = InputBox("������� n: ")
    
    ReDim a(0 To n - 1) As Double
    
    For i = 0 To n - 1
        a(i) = InputBox("������� " & i + 1 & " ����� = ")
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
'������� ����������� ������� Fact(N) ������������� ����, ����������� �������� ����������
Sub Recur1()
    Dim n As Integer
    n = InputBox("������� n: ")
    
    MsgBox Fact(n)
End Sub
Function Fact(n As Integer) As Integer
    If n = 0 Then
        Fact = 1
    Else
        Fact = n * Fact(n - 1)
    End If
    
End Function
