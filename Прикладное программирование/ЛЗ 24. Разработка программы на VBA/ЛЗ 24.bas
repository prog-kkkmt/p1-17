Attribute VB_Name = "Module1"
Option Explicit

Sub begin21()
'���� ���������� ������ ������������: (x1, y1), (x2, y2), (x3, y3). ����� ��� �������� � �������, ��������� ������� ���
'���������� ����� ����� �������. ��� ���������� ������� ������������ �� ��������� a, b, c ������������ ������� ������
    Dim x1 As Integer, x2 As Integer, x3 As Integer, y1 As Integer, y2 As Integer, y3 As Integer
    Dim a As Double, b As Double, c As Double, p As Double
       
    '���� ���������
    x1 = InputBox("x1 = ")
    y1 = InputBox("y1 = ")
    x2 = InputBox("x2 = ")
    y2 = InputBox("y2 = ")
    x3 = InputBox("x3 = ")
    y3 = InputBox("y3 = ")
    
    '���������� ������ ������������
    a = ((x2 - x1) ^ 2 + (y2 - y1) ^ 2) ^ 0.5
    b = ((x3 - x2) ^ 2 + (y3 - y2) ^ 2) ^ 0.5
    c = ((x1 - x3) ^ 2 + (y1 - y3) ^ 2) ^ 0.5
    
    '���������� �������������
    p = (a + b + c) / 2
    
    '���������� � ����� ���������
    MsgBox ("P = " & p * 2)
    
    '���������� ������� �� ������� ������ � � �����
    MsgBox ("S = " & (p * (p - a) * (p - b) * (p - c)) ^ 0.5)
End Sub

Sub integer21()
'� ������ ����� ������ N ������ (N � �����). ����� ���������� ������, ��������� � ������ ��������� ������.
    Dim n As Integer
    n = InputBox("������� ���-�� ��������� ������ � ������ �����")
    MsgBox (n Mod 60 & " ������(�) ������ � ������ ��������� ������")
End Sub

Sub boolean21()
'���� ����������� �����. ��������� ���������� ������������: ������ ������� ����� �������� ������������ �������������������.
    Dim n As Integer
    
    n = InputBox("������� ���������� �����")
    
    '��������� ����� �� ����� � ���������� ��, ������� ���������
    MsgBox ((n Mod 10) > ((n Mod 100) \ 10) And ((n Mod 100) \ 10) > (n \ 100))
End Sub

Sub if21()
'���� ������������� ���������� ����� �� ���������. ���� ����� ��������� � ������� ���������, �� ������� 0. ���� ����� �� ��������� � �������
'���������, �� ����� �� ��� OX ��� OY, �� ������� �������������� 1 ��� 2. ���� ����� �� ����� �� ������������ ����, �� ������� 3.
    Dim x As Integer, y As Integer
    
    '���� ���������
    x = InputBox("x = ")
    y = InputBox("y = ")
    
    '�������� �� �������������� ����� � ����
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
'���� ����� ����� � ��������� �� 1 �� 7. ������� �������� ��� ������, ������������� ������� �����
    Dim n As Integer
    
    '���� ����� n
    n = InputBox("������� n")
    
    '����� �������� ��� ������ � ������� ��������� ������
    Select Case n
        Case 1
            MsgBox ("�����������")
        Case 2
            MsgBox ("�������")
        Case 3
            MsgBox ("�����")
        Case 4
            MsgBox ("�������")
        Case 5
            MsgBox ("�������")
        Case 6
            MsgBox ("�������")
        Case 7
            MsgBox ("�����������")
        Case Else
            MsgBox ("������� ������������ ��������")
    End Select
End Sub

Sub for21()
'���� ����� ����� N (> 0). ��������� ���� ����, ������� ����� 1 + 1/(1!) + 1/(2!) + 1/(3!) + � + 1/(N!)
'���������� ����� �������� ������������ ��������� ��������� e = exp(1).
    Dim n As Integer, i As Integer, factorial As Integer, e As Double
    
    '���� ����� n
    n = InputBox("������� n")
    
    e = 1
    factorial = 1
    
    '��������� ����
    For i = 1 To n
        factorial = factorial * i '������� ��������� ����� i
        e = e + (1 / factorial)
    Next i
End Sub

Sub while21()
'���� ����� ����� N (> 0). ����������, ������� �� � ������ ����� N �������� �����. ���� �������, ������� true, � ��������� ������ - false
    Dim n As Integer, b As Boolean
    
    '���� ����� n
    n = InputBox("������� n")
    
    b = False
    
    '��������� ����
    While n > 0
        If (n Mod 10) Mod 2 = 1 Then b = True '��������� ��������� ����� ����� �� ����������
        n = n \ 10 '����������� ��������� ����� �����
    Wend
    
    MsgBox (b)
End Sub

Sub series21()
'���� ����� ����� N (> 0) � ����� �� N ������������ �����. ���������, �������� �� ������ ����� ������������ ������������������ �����.
    Dim n As Integer, i As Integer, a As Double, preva As Double, b As Boolean
    
    '���� ����� n
    n = InputBox("������� n")
    
    '���� 1-�� �����
    preva = InputBox("������� 1 �����")
    
    b = True
    
    For i = 2 To n
        a = InputBox("������� " & i & " �����")
        If preva > a Then b = False
        preva = a
    Next i
    
    MsgBox (b)
End Sub

Sub minmax21()
'���� ����� ����� N (> 2) � ����� �� N ����� - �������� ��������� ��������, ���������� � N ������. ����� ������ �������� ��� ��������.
'��� ���������� �������� �������� �� ��������� ������������ � ����������� �� ������ ��������.
    Dim arr(100) As Integer, n As Integer, i As Integer, max As Integer, min As Integer, sum As Integer, count As Integer
    
    sum = 0
    count = 0
    max = -999
    min = 999
    
    '���� ����� n
    n = InputBox("������� n")
    
    '���� �������� ��������� ��������, ���������� �������� � ���������
    For i = 1 To n
        arr(i) = InputBox("������� a[" & i & "]")
        If arr(i) > max Then max = arr(i)
        If arr(i) < min Then min = arr(i)
    Next i
    
    '������� ����� � ���������� ���������, �� ������ �������� ��� ���������
    For i = 1 To n
        If arr(i) <> min And arr(i) <> max Then
            sum = sum + arr(i)
            count = count + 1
        End If
    Next i
    
    '��������� � ������� ������� ��������������
    MsgBox (sum / count)
End Sub

Sub array21()
'��� ������ ������� N � ����� ����� K � L (1 = K = L = N). ����� ������� �������������� ��������� ������� �� K �� L ������������.
    Dim arr(100) As Integer, n As Integer, l As Integer, k As Integer, sum As Integer, i As Integer
    
    sum = 0
    
    '���� �����
    n = InputBox("������� n")
    k = InputBox("������� k")
    l = InputBox("������� l")
    
    '���� �������
    For i = 1 To n
        arr(i) = InputBox("������� a[" & i & "]")
    Next i
    
    '������� ����� �� ����������
    For i = k To l
        sum = sum + arr(i)
    Next i
    
    '��������� � ������� ������� ��������������
    MsgBox (sum / (k - l + 1))
End Sub


'���������: ������� �.�.
'���� ����������: 27.05.2020
