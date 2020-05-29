VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} UserForm1 
   Caption         =   "UserForm1"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   10470
   OleObjectBlob   =   "FormAppendStudent.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "UserForm1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False






Public lastreg As Long, kolpeople As Long
Public kolday As Long

Private Sub CommandButton1_Click()
'Начало работы главной формы
lastreg = WorksheetFunction.CountA(Range("A:A")) + 1
Rows(lastreg).Select
Cells(lastreg, 1) = TextBox1.Value
Cells(lastreg, 2) = TextBox2.Value
Cells(lastreg, 3) = TextBox3.Value
kolpeople = Sheets("Инфо").Cells(1, 2)
kolpeople = kolpeople + 1
lastreg = lastreg + 1
Cells(lastreg, 1) = "оценки\прогулы"
Sheets("Инфо").Cells(1, 2) = kolpeople

End Sub

Private Sub CommandButton2_Click()
'очищение  формы
Call UserForm_Initialize
End Sub

Private Sub CommandButton3_Click()
'Удаление программы
kolpeople = Sheets("Инфо").Cells(1, 2)
MsgBox (kolpeople)
MsgBox (lastreg)

 kolday = Sheets("Инфо").Cells(2, 2)
 For j = lastreg To kolpeople + 2 Step 2
    Cells(lastreg + j - 3, 1) = Cells(lastreg + j - 1, 1)
    Cells(lastreg + j - 3, 2) = Cells(lastreg + j - 1, 2)
    Cells(lastreg + j - 3, 3) = Cells(lastreg + j - 1, 3)
    For i = 1 To kolday + 2
        Cells(lastreg + j - 2, i) = Cells(lastreg + j, i)
    Next
Next
Cells(kolpeople * 2 + 1, 1) = ""
    Cells(kolpeople * 2 + 1, 2) = ""
    Cells(kolpeople * 2 + 1, 3) = ""
     For i = 1 To kolday + 2
        Cells(kolpeople * 2 + 2, i) = ""
    Next
kolpeople = kolpeople - 1
Sheets("Инфо").Cells(1, 2) = kolpeople
End Sub

Private Sub CommandButton4_Click()
' подъем в верх
If lastreg Mod 2 = 0 Then
    lastreg = lastreg - 1
    End If
lastreg = lastreg - 2
If lastreg <= 0 Then
    lastreg = 1
End If
Rows(lastreg).Select
TextBox1.Value = Cells(lastreg, 1)
TextBox2.Value = Cells(lastreg, 2)
TextBox3.Value = Cells(lastreg, 3)
End Sub

Private Sub CommandButton5_Click()
'спуск вниз
lastreg = lastreg + 2
If lastreg Mod 2 = 0 Then
    lastreg = lastreg - 1
    End If
    
Rows(lastreg).Select
TextBox1.Value = Cells(lastreg, 1)
TextBox2.Value = Cells(lastreg, 2)
TextBox3.Value = Cells(lastreg, 3)
End Sub

Private Sub CommandButton6_Click()
'Изменение таблицы
Rows(lastreg).Select
Cells(lastreg, 1) = TextBox1.Value
Cells(lastreg, 2) = TextBox2.Value
Cells(lastreg, 3) = TextBox3.Value
kolpeople = kolpeople + 1
lastreg = lastreg + 2
Cells(lastreg - 1, 1) = "оценки\прогулы"
End Sub

Private Sub CommandButton7_Click()
'Добавить один рабочий день
kolpeople = Sheets("Инфо").Cells(1, 2)
 kolday = Sheets("Инфо").Cells(2, 2)
 kolday = kolday + 1
MsgBox (kolpeople)
For j = 1 To kolpeople
Z = InputBox("оценка студента ")
MsgBox (Z)
Cells(j * 2 + 2, kolday + 1) = Z

Next
 Sheets("Инфо").Cells(2, 2) = kolday
End Sub

Private Sub CommandButton8_Click()
'открытие второй формы
UserForm2.Show
End Sub

Private Sub UserForm_Initialize()
' инициализация работы
TextBox1 = ""
TextBox2 = ""
TextBox3 = ""
End Sub
