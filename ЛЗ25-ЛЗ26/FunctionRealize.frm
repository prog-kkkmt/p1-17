VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} UserForm2 
   Caption         =   "UserForm2"
   ClientHeight    =   4065
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   8625.001
   OleObjectBlob   =   "FunctionRealize.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "UserForm2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False




Private Sub CommandButton1_Click()
'������� �������� � ����� ������� ����������� ��������
Dim maxname As String
Dim maxkol As Long
maxkol = -1
temp = 0
kolpeople = Sheets("����").Cells(1, 2)
 kolday = Sheets("����").Cells(2, 2)
MsgBox (kolpeople)
For j = 1 To kolpeople
temp = 0
    For i = 2 To kolday
        If Cells(j * 2 + 2, i) = 0 Then
         temp = temp + 1
         End If
         
    Next
    If temp > maxkol Then
        maxkol = temp
        maxname = Cells(j * 2 + 1, 1)
    End If
Next
    MsgBox (maxname & " ����� ������� ���������")
End Sub

Private Sub CommandButton2_Click()
'������� ������� �������� �� �������� ����
Dim maxname As String
Dim maxkol As Double
maxkol = -1
temp = 0
kolpeople = Sheets("����").Cells(1, 2)
 kolday = Sheets("����").Cells(2, 2)
MsgBox (kolpeople)
For j = 1 To kolpeople
temp = 0
    For i = 2 To kolday
        If Not Cells(j * 2 + 2, i) = 0 Then
         temp = temp + 1
         End If
         temp = temp / kolday
    Next
    If temp > maxkol Then
        maxkol = temp
        maxname = Cells(j * 2 + 1, 1)
    End If
Next
    MsgBox (maxname & " ����� ������ ������")
End Sub

Private Sub CommandButton3_Click()
'������� ������� ��� ���������
Dim maxkol As Double
maxkol = 0
kolpeople = Sheets("����").Cells(1, 2)
 kolday = Sheets("����").Cells(2, 2)
MsgBox (kolpeople)
For j = 1 To kolpeople
temp = 0
    For i = 2 To kolday
        If Not Cells(j * 2 + 2, i) = 0 Then
          maxkol = maxkol + Cells(j * 2 + 2, i)
         End If
    Next
Next
    MsgBox (maxkol / kolpeople / kolday & " ������� ��� ������")
End Sub
