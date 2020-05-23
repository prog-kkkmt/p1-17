Attribute VB_Name = "Module1"
' ��������: ������� �����
' 23.05.2020
Option Explicit
Sub Begin14()
' ���� ����� L ����������. ����� �� ������ R � ������� S �����, ������������� ���� �����������, ��������, ��� L = 2�?�R,    S = ?�R2. � �������� �������� ? ������������ 3.14
    Const Pi As Double = 3.14

    Dim L As Double
    Dim r As Double
    Dim S As Double
    
    L = Cells(4, 2)
    
    r = L / (2 * Pi)
    Cells(5, 2) = r
    
    S = Pi * r ^ 2
    Cells(6, 2) = S
    
End Sub
Sub Integer14()
' ���� ����������� �����. � ��� ���������� ������ ������ ����� � ��������� �� �����. ������� ���������� �����.
    Dim num As Integer
    
    num = Cells(14, 2)
    
    Dim r As Integer
    Dim cel As Integer
    r = num Mod 10
    cel = num \ 10
    
    Cells(14, 3) = r * 100 + cel
End Sub
Sub Boolean14()
' ���� ��� ����� �����: A, B, C. ��������� ���������� ������������: ������ ���� �� ����� A, B, C �������������.
    Dim a As Integer
    Dim B As Integer
    Dim C As Integer
    
    a = Cells(22, 2)
    B = Cells(23, 2)
    C = Cells(24, 2)
    
    If (a > 0 And B < 0 And C < 0) Or _
       (a < 0 And B > 0 And C < 0) Or _
       (a < 0 And B < 0 And C > 0) Then
        Cells(24, 3) = "True"
    Else
        Cells(24, 3) = "False"
    End If
End Sub
Sub If_14()
' ���� ��� �����. ������� ������� ����������, � ����� ���������� �� ������ �����.
    Cells(5, 10) = WorksheetFunction.Max(Range("I4:I6"))
    Cells(7, 10) = WorksheetFunction.min(Range("I4:I6"))
    
End Sub
Sub Case14()
' �������� ��������������� ������������ ������������� ��������� �������: 1 � ������� a,
'2 � ������ R1 ��������� ���������� (R1 = a�(3)1/2/6), 3 � ������ R2 ��������� ����������
'(R2 = 2�R1), 4 � ������� S = a2�(3)1/2/4. ��� ����� ������ �� ���� ��������� � ��� ��������.
'������� �������� ��������� ��������� ������� ������������ (� ��� �� �������).
    Dim N As Integer
    Dim q As Double
    
    N = CInt(Cells(17, 9))
    q = CDbl(Cells(18, 9))
    
    Select Case N
        Case 1
            Cells(20, 9) = q
            Cells(21, 9) = q * Sqr(q) / 6
            Cells(22, 9) = 2 * Cells(21, 9)
            Cells(23, 9) = q ^ 2 * Sqr(3) / 4
        Case 2
            Cells(21, 9) = q
            Cells(20, 9) = Cells(21, 9) * 6 / Sqr(Cells(21, 9))
            Cells(22, 9) = 2 * Cells(21, 9)
            Cells(23, 9) = Cells(20, 9) ^ 2 * Sqr(3) / 4
        Case 3
            Cells(22, 9) = q
            Cells(21, 9) = Cells(22, 9) / 2
            Cells(20, 9) = Cells(21, 9) * 6 / Sqr(Cells(21, 9))
            Cells(23, 9) = Cells(20, 9) ^ 2 * Sqr(3) / 4
        Case 4
            Cells(23, 9) = q
            Cells(20, 9) = Sqr(q * 4 / Sqr(3))
            Cells(21, 9) = q * Sqr(q) / 6
            Cells(22, 9) = 2 * Cells(21, 9)
    End Select
            
End Sub
Sub For_14()
' ���� ����� ����� N (> 0). ����� ������� ������� �����
    Dim N As Integer
    Dim i As Integer
    Dim res As Integer
    
    i = 1
    res = 0
    
    N = CInt(Cells(31, 2))

    For i = 1 To N
        res = res + (2 * i - 1)
        Cells(i, 15) = res
    Next i
    Range("O1", Cells(i, 15)).Borders.LineStyle = True
    Cells(30, 6) = "O1:O" & CStr(i)
End Sub
Sub While14()
' ���� ����� A (> 1). ������� ���������� �� ����� ����� K, ��� ������� ����� 1 + 1/2 + � + 1/K ����� ������ A, � ���� ��� �����.
    Dim a As Integer
    Dim K As Integer
    Dim sum As Double
    
    a = CInt(Cells(32, 9))
    sum = 0
    K = 0
    
    Do While sum + (1 / (K + 1)) < a
        K = K + 1
        sum = sum + 1 / K
    Loop
    
    Cells(33, 9) = K
    Cells(33, 10) = sum
End Sub
Sub Series14()
    Dim a() As String
    Dim K As Integer
    Dim count As Integer
    Dim num As Variant
    
    K = Cells(40, 2)
    
    a = Split(Cells(41, 2))
    
    count = 0
    
    For Each num In a
        If CInt(num) < CInt(K) Then
            count = count + 1
        End If
    Next num
    
    Cells(41, 3) = count
End Sub
Sub Proc14()
'������� ��������� ShiftRight3(A, B, C), ����������� ������ ����������� �����: �������� A ���������
'� B, �������� B � � C, �������� C � � A (A, B, C � ������������ ���������, ���������� ������������ �������� � ���������).
'� ������� ���� ��������� ��������� ������ ����������� ����� ��� ���� ������ ������� �� ���� �����
    Dim a() As String
    
    a = Split(Cells(46, 9))
    
    Cells(47, 9) = a(2) & " " & a(0) & " " & a(1)
End Sub
Sub Minmax14()
' ���� ����� B (> 0) � ����� �� ������ �����. ������� ����������� �� ��� ��������� ������,
' ������� ������ B, � ����� ��� �����. ���� �����, ������� B, � ������ ���, �� ������ ������� 0.
    Dim a() As String
    Dim B As Integer
    Dim min As Integer
    Dim i As Integer
    Dim index As Integer
    Dim num As Variant
    
    B = Cells(50, 2)
    
    a = Split(Cells(51, 2))
    i = 1
    index = 0
    min = 1000
    
    For Each num In a
        If CInt(num) > CInt(B) Then
            If CInt(num) < min Then
                min = num
                index = i
            End If
        End If
        i = i + 1
    Next num
    
    If min = 1000 Then
        min = 0
    End If
    Cells(51, 3) = min & " " & index
End Sub
Sub Array14()
' ��� ������ A ������� N. ������� ������� ��� �������� � ������� �������� (� ������� ����������� �������),
' � ����� � �������� � ��������� �������� (����� � ������� ����������� �������):
    Dim a() As String
    Dim N As Integer
    Dim i As Integer
    
    N = Cells(59, 2)
    a = Split(Cells(60, 2))
    
    Cells(61, 2) = ""
    
    For i = 0 To N - 1
        If i Mod 2 = 1 Then
            Cells(61, 2) = Cells(61, 2) & " " & a(i)
        End If
    Next i
    i = 0
    For i = 0 To N - 1
        If i Mod 2 = 0 Then
            Cells(61, 2) = Cells(61, 2) & " " & a(i)
        End If
    Next i
End Sub
Sub Matrix14()
'���� ���������� ������� A ������� M. ������� � �������� A1,1, ������� �� �������� ��������� ������� (���������):
' ��� �������� ������� �������; �������� ��������� ������, ����� ������� (��� �����������) ��������; ���������� ��������
' ������� �������;
' ���������� �������� ������������� ������ � �. �.; ��������� ��������� ������� A1,M.
    Dim M As Integer
    M = Cells(58, 9)
    Dim i As Integer
    
    Dim mx As Integer
    Dim my As Integer
    Dim x As Integer
    
    mx = 59
    my = 8
    x = 59
    
    Do While M > 0
        For i = 0 To M - 1
            Cells(x, 15).Offset(0, i) = Cells(mx, my).Offset(i, 0)
            If (i < M - 1) Then
                Cells(x + 1, 15).Offset(0, i) = Cells(mx + M - 1, my + 1).Offset(0, i)
            End If
        Next i
        x = x + 2
        M = M - 1
        my = my + 1
    Loop
End Sub
Sub String14()
' ���� ������. ���������� ���������� ������������ � ��� ��������� ��������� ����.
    Dim str As String
    str = Cells(68, 2)
    Dim i As Integer
    Dim sCharacter As String
    Dim count As Integer
    
    For i = 1 To Len(str)
        sCharacter = Mid(str, i, 1)
        If Not sCharacter Like LCase(sCharacter) Then
            count = count + 1
        End If
    Next i
    
    Cells(69, 2) = count
End Sub
Sub Param14()
' ������� ��������� Split1(A, NA, B, NB, C, NC), ����������� �� ������������� ������� A ������� NA ��� ������������
' ������� B � C ������� NB � NC ��������������; ��� ���� ������ B �������� ��� �������� ������� A � ��������� �����������
' �������� (1, 3, �), � ������ C � ��� �������� ������� A � ������� �������� (2, 4, �). ������� B � C � ����� NB � NC
' �������� ��������� �����������.
' ��������� ��� ��������� � ������� ������� A ������� NA � ������� ������ � ���������� ���������� �������� B � C.
    Dim a() As String
    Dim N As Integer
    Dim i As Integer
    
    N = Cells(84, 2)
    a = Split(Cells(85, 2))
    
    Cells(87, 2) = ""
    Cells(87, 3) = 0
    
    For i = 0 To N - 1
        If i Mod 2 = 1 Then
            Cells(87, 2) = Cells(87, 2) & " " & a(i)
            Cells(87, 3) = Cells(87, 3) + 1
        End If
    Next i
    
    Cells(88, 2) = ""
    Cells(88, 3) = 0
    
    For i = 0 To N - 1
        If i Mod 2 = 0 Then
            Cells(88, 2) = Cells(88, 2) & " " & a(i)
            Cells(88, 3) = Cells(88, 3) + 1
        End If
    Next i
End Sub
Sub Recur14()
    Dim str As String
    
    
    str = Cells(76, 9)
    Cells(77, 9) = Recur(str)

End Sub
Function Recur(ByVal str As String) As Integer
    Dim exp As String
    Dim sign As String
    exp = Mid(str, 1, 1)
    If Len(str) = 1 Then
        Recur = CInt(exp)
    Else
        sign = Mid(str, 2, 1)
        If sign = "+" Then
            Recur = CInt(exp) + Recur(Mid(str, 3, Len(str) - 2))
        Else
            Recur = CInt(exp) - Recur(Mid(str, 3, Len(str) - 2))
        End If
    End If
    

End Function
