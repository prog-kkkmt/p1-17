VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} ���� 
   Caption         =   "����"
   ClientHeight    =   3495
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   7635
   OleObjectBlob   =   "����.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "����"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Add_Click()
    Dim i As Integer
    i = 2
    If Num = 0 Then
        Do While Worksheets("���� ���������").Cells(i, 1).Value <> ""
            Num = Num + 1
            ReDim Preserve dish(Num)
            dish(Num).��� = Worksheets("���� ���������").Cells(i, 1).Value
            dish(Num).�������� = Worksheets("���� ���������").Cells(i, 2).Value
            dish(Num).���� = Worksheets("���� ���������").Cells(i, 3).Value
            dish(Num).����� = Worksheets("���� ���������").Cells(i, 4).Value
            i = i + 1
        Loop
    End If
     
    If IsNumeric(Code.Value) And IsNumeric(Price.Value) Then
        Num = Num + 1
        ReDim Preserve dish(Num)
        dish(Num).��� = Code.Value
        dish(Num).�������� = NameOfDish.Value
        dish(Num).���� = Price.Value
        dish(Num).����� = Time.Value
        With Worksheets("���� ���������")
            .Cells(Num + 1, 1).Value = dish(Num).���
            .Cells(Num + 1, 2).Value = dish(Num).��������
            .Cells(Num + 1, 3).Value = dish(Num).����
            .Cells(Num + 1, 4).Value = dish(Num).�����
        End With
    Else
        MsgBox ("���� ������� ������������ ������. ���������� ��� ���")
    End If
    
End Sub

Private Sub Change_Click()
    Dim n As Integer, i As Integer
    n = InputBox("������� ��� ����� ���������� ������")
    For i = 1 To Num
        If dish(i).��� = n Then
            If IsNumeric(Code.Value) And IsNumeric(Price.Value) Then
                dish(i).��� = Code.Value
                dish(i).�������� = NameOfDish.Value
                dish(i).���� = Price.Value
                dish(Num).����� = Time.Value
                With Worksheets("���� ���������")
                    .Cells(i + 1, 1).Value = dish(i).���
                    .Cells(i + 1, 2).Value = dish(i).��������
                    .Cells(i + 1, 3).Value = dish(i).����
                    .Cells(i + 1, 4).Value = dish(i).�����
                End With
            Else
                MsgBox ("���� ������� ������������ ������. ���������� ��� ���")
            End If
        End If
    Next i
End Sub

Private Sub Delete_Click()
    Dim n As Integer, i As Integer
        
    n = InputBox("������� ������� ��������� ������")
    Num = Num - 1
    MsgBox Num
    With Worksheets("���� ���������")
        For i = n - 1 To Num
            dish(i) = dish(i + 1)
            .Cells(i + 1, 1).Value = dish(i).���
            .Cells(i + 1, 2).Value = dish(i).��������
            .Cells(i + 1, 3).Value = dish(i).����
            .Cells(i + 1, 4).Value = dish(i).�����
           
        Next i
            .Cells(i + 1, 1).ClearContents
            .Cells(i + 1, 2).ClearContents
            .Cells(i + 1, 3).ClearContents
            .Cells(i + 1, 4).ClearContents
    End With
    ReDim Preserve dish(Num)

End Sub

