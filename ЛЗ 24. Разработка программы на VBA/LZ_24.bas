Attribute VB_Name = "LZ_24"
Option Explicit

Public Const MAXINT As Integer = (2 ^ 15) - 1

Type TRect
    a As Integer
    b As Integer
End Type

Sub Begin20()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Begin20. ����� ���������� ����� �����  �������  �  ���������  ������������
Rem  (x1, y1) � (x2, y2) �� ���������.
Rem ��������� �.�., 22.05.2020
    Dim x1 As Double, x2 As Double, y1 As Double, y2 As Double, r As Double
    x1 = InputBox("")
    y1 = InputBox("")
    
    x2 = InputBox("")
    y2 = InputBox("")
    
    r = Math.Sqr((x2 - x1) ^ 2 + (y2 - y1) ^ 2)
    MsgBox (r)
End Sub

Sub Integer1()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Integer1. ���� ���������� L � �����������. ��������� �������� ������� ������,
Rem ����� ���������� ������ ������ � ��� (1 ���� = 100 ��).
Rem ��������� �.�., 22.05.2020
    Dim m As Integer, Sm As Integer
    Sm = InputBox("")
    m = Sm \ 100
    MsgBox (m)
End Sub

Sub Boolean36()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Boolean36. ���� ���������� ���� ��������� ����� ��������� ����� x1, y1, x2, y2
Rem (����� �����, ������� � ��������� 1�8). ��������� ���������� ������������:
Rem "����� �� ���� ��� ����� ������� � ������ ���� �� ������".}
Rem ��������� �.�., 22.05.2020
    Dim x1 As Integer, y1 As Integer
    Dim x2 As Integer, y2 As Integer
    
    x1 = InputBox("")
    y1 = InputBox("")
    x2 = InputBox("")
    y2 = InputBox("")
    
    MsgBox ((x1 = x2) And (y1 <> y2) Or (y1 = y2) And (x1 <> x2))
End Sub

Sub If4()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem If4. ���� ��� ����� �����. ����� ���������� ������������� ����� � �������� ������.
Rem ��������� �.�., 22.05.2020

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
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Case3. ��� ����� ������ � ����� ����� � ��������� 1�12 (1 � ������, 2 � ������� � �. �.).
Rem  ������� �������� ���������������� ������� ���� (�����, ������, �����, �������).
Rem ��������� �.�., 22.05.2020

    Dim x As Integer
    x = InputBox("")
    Select Case x
        Case 1, 2, 12
            MsgBox ("����")
        Case 1, 2, 12
            MsgBox ("����")
        Case 3, 4, 5
            MsgBox ("�����")
        Case 6, 7, 8
            MsgBox ("����")
        Case 9, 10, 11
            MsgBox ("�����")
        Case Else
            MsgBox ("�����������")
    End Select
End Sub

Sub For5()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem For 5. ���� ������������ ����� � ���� 1 �� ������.
Rem ������� ��������� 0.1, 0.2, �, 1 �� ������.}
Rem ��������� �.�., 23.05.2020

    Dim i As Integer, a As Double
    Dim ans As String
    a = InputBox("")
    ans = "��� ���������" & vbNewLine
    ans = ans & "-------------" & vbNewLine
    
    For i = 1 To 10
        ans = ans & i / 10 & "     " & (a * i / 10) & vbNewLine
    Next i
    MsgBox (ans)
End Sub

Sub While5()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem While5. ����  �����  ����� N (> 0),  ����������  ���������  ��������  ����� 2:
Rem N = 2^K. ����� ����� ����� K - ���������� ���� �������.
Rem ��������� �.�., 23.05.2020

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

Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Series24. ���� ����� ����� N � ����� �� N ����� �����,
Rem ���������� �� ������� ���� ��� ����. ������� ����� ����� �� ������� ������,
Rem ������������� ����� ���������� ����� ������ (���� ��������� ���� ���� ������,
Rem �� ������� 0.
Rem ��������� �.�., 23.05.2020
Sub Series24()
    Const MaxN = 100
    Dim n As Integer, i As Integer
    Dim v(1 To MaxN) As Integer
    Dim s As Integer
    
    n = InputBox("N=")
    Rem ���������� �������
    For i = 1 To n
        v(i) = InputBox("")
    Next i
  
    Rem ����� ���������� ���� (� ������� �������������, ��� �� ����)
    i = n
    Do While (i > 0) And (v(i) <> 0)
        i = i - 1
    Loop
    s = 0
    Rem ��������� ���� ������, �� ����� ��� ������������ ���� ���
    i = i - 1 ' ��� ���� ������������� ����, ���� ������ ��������� �����
  
    Rem ���� ������������� ���� � ���������� �����
    Do While (i > 0) And (v(i) <> 0)
        s = s + v(i)
        i = i - 1
    Loop
    MsgBox ("s=" & s)
End Sub

Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Proc7. ������� ��������� DigitCountSum(K, C, S), ��������� ���������� C ���� ������
Rem �������������� ����� K, � ����� �� ����� S (K � �������, C � S � �������� ���������
Rem ������ ����). � ������� ���� ��������� ����� ���������� � ����� ���� ��� ������� ��
Rem ���� ������ ����� �����
Rem ��������� �.�., 23.05.2020

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

Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Minmax2. ���� ����� ����� N � ����� �� N ���������������, �������� ������
Rem ��������� � ������ ����� (a, b). ����� ����������� ������� �������������� ��
Rem ������� ������.
Rem ��������� �.�., 23.05.2020
Rem � �������������� Record � Function

Function Square(ByRef rect As TRect) As Integer
  Square = rect.a * rect.b
End Function

Sub MinMax2()
    Dim i As Integer, n As Integer
    Dim rect As TRect
    Dim Smin As Integer
    Dim s As Integer
    Dim FirstInput As Boolean

    FirstInput = True ' ������ ������
    n = InputBox("����� ���������������")

    Smin = MAXINT
  
    For i = 1 To n
        rect.a = InputBox("������������� " & i & "������� a")
        rect.b = InputBox("������������� " & i & "������� b")
        s = Square(rect)
        If FirstInput Then
            FirstInput = False
            Smin = s
        ElseIf s < Smin Then
            Smin = s
        End If
    Next i
    MsgBox ("����������� ������� Smin=" & Smin)
End Sub

Sub Array9()
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Array9. ��� ������������� ������ ������� N.
Rem ������� ��� ������������ � ������ ������� ������ ����� � ������� �������� �� ��������,
Rem � ����� �� ���������� K.
Rem ��������� �.�., 23.05.2020
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
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem ���� ����� ������������� ����� M, N � ����� �� M �����. ������������ �������
Rem ������� M x N, � ������� � ������ ������� ���������� ��� ����� �� ���������
Rem ������ (� ��� �� �������) }
Rem ��������� �.�., 23.05.2020

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
Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem String10. ���� ������. ������� ������, ���������� �� �� �������, �� ������������� � �������� �������.
Rem ��������� �.�., 23.05.2020
    Dim i As Integer
    Dim s1 As String, s2 As String
    s1 = InputBox("")
    s2 = ""
    For i = Len(s1) To 1 Step -1
        s2 = s2 & Mid(s1, i, 1)
    Next i
    MsgBox (s2)
End Sub

Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Param11. ������� ��������� Sort(A, N), ����������� ���������� �� �����������
Rem ������������� ������� A ������� N. ������ A �������� ������� � �������� ����������.
Rem � ������� ���� ��������� ������������� ������� A, B, C ������� NA, NB, NC ��������������.
Rem ��������� �.�., 23.05.2020

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
Rem ��������� �.�., 23.05.2020
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
Rem ��������� �.�., 23.05.2020

Const MaxN As Integer = 10
Dim i As Integer
Dim a(0 To MaxN - 1) As Integer
Dim na As Integer
    randomize
    na = MaxN
    For i = 0 To na - 1
        a(i) = -10 + Rnd * 20
    Next i
    
    Call VPrint(a, na, "������ A �� ����������")
    Call VSort(a, na)
    Call VPrint(a, na, "������ A ����� ����������")
End Sub

Rem �. �. �������. 1000 ����� �� ����������������, ������-��-���� 2004.
Rem Recur13. ������� ����������� ������� Palindrom(S) ����������� ����,
Rem ������������ True, ���� ������ S �������� ����������� (�� ���� �������� ���������
Rem ����� ������� � ������ ������), � False � ��������� ������.
Rem �������� ����� � ���� ������� �� ������������.
Rem ������� �������� ������� Palindrom ��� ���� ������ �����. }
Rem ��������� �.�., 23.05.2020

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
Rem ��������� �.�., 23.05.2020
    Dim i As Integer, s As String
    'For i = 1 To 5
        s = InputBox("")
        MsgBox (Palindrom(s))
    'Next i
End Sub
