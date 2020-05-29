VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Меню 
   Caption         =   "Меню"
   ClientHeight    =   3495
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   7635
   OleObjectBlob   =   "Меню.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Меню"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Add_Click()
    Dim i As Integer
    i = 2
    If Num = 0 Then
        Do While Worksheets("Меню заведения").Cells(i, 1).Value <> ""
            Num = Num + 1
            ReDim Preserve dish(Num)
            dish(Num).Код = Worksheets("Меню заведения").Cells(i, 1).Value
            dish(Num).Название = Worksheets("Меню заведения").Cells(i, 2).Value
            dish(Num).Цена = Worksheets("Меню заведения").Cells(i, 3).Value
            dish(Num).Время = Worksheets("Меню заведения").Cells(i, 4).Value
            i = i + 1
        Loop
    End If
     
    If IsNumeric(Code.Value) And IsNumeric(Price.Value) Then
        Num = Num + 1
        ReDim Preserve dish(Num)
        dish(Num).Код = Code.Value
        dish(Num).Название = NameOfDish.Value
        dish(Num).Цена = Price.Value
        dish(Num).Время = Time.Value
        With Worksheets("Меню заведения")
            .Cells(Num + 1, 1).Value = dish(Num).Код
            .Cells(Num + 1, 2).Value = dish(Num).Название
            .Cells(Num + 1, 3).Value = dish(Num).Цена
            .Cells(Num + 1, 4).Value = dish(Num).Время
        End With
    Else
        MsgBox ("Были введены некорректные данные. Попробуйте еще раз")
    End If
    
End Sub

Private Sub Change_Click()
    Dim n As Integer, i As Integer
    n = InputBox("Введите код блюда изменяемой записи")
    For i = 1 To Num
        If dish(i).Код = n Then
            If IsNumeric(Code.Value) And IsNumeric(Price.Value) Then
                dish(i).Код = Code.Value
                dish(i).Название = NameOfDish.Value
                dish(i).Цена = Price.Value
                dish(Num).Время = Time.Value
                With Worksheets("Меню заведения")
                    .Cells(i + 1, 1).Value = dish(i).Код
                    .Cells(i + 1, 2).Value = dish(i).Название
                    .Cells(i + 1, 3).Value = dish(i).Цена
                    .Cells(i + 1, 4).Value = dish(i).Время
                End With
            Else
                MsgBox ("Были введены некорректные данные. Попробуйте еще раз")
            End If
        End If
    Next i
End Sub

Private Sub Delete_Click()
    Dim n As Integer, i As Integer
        
    n = InputBox("Введите строчку удаляемой записи")
    Num = Num - 1
    MsgBox Num
    With Worksheets("Меню заведения")
        For i = n - 1 To Num
            dish(i) = dish(i + 1)
            .Cells(i + 1, 1).Value = dish(i).Код
            .Cells(i + 1, 2).Value = dish(i).Название
            .Cells(i + 1, 3).Value = dish(i).Цена
            .Cells(i + 1, 4).Value = dish(i).Время
           
        Next i
            .Cells(i + 1, 1).ClearContents
            .Cells(i + 1, 2).ClearContents
            .Cells(i + 1, 3).ClearContents
            .Cells(i + 1, 4).ClearContents
    End With
    ReDim Preserve dish(Num)

End Sub

