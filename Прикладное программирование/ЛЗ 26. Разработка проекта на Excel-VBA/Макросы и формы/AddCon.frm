VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} AddCon 
   Caption         =   "Добавление нового клиента"
   ClientHeight    =   2325
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   3255
   OleObjectBlob   =   "AddCon.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "AddCon"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Add_Click()
    Dim Id As Integer
    Dim Name As String
    Dim Passport As String
    Dim Error As Boolean
    
    If NameObj.Value <> "" Then
        Name = NameObj.Value
    Else
        MsgBox "Введите имя"
        Error = True
    End If
    
    If PassportObj.Value <> "" Then
        Passport = PassportObj.Value
    Else
        MsgBox "Введите паспорт"
        Error = True
    End If
    
    If Not Error Then
        AddCon.Hide
        With Worksheets("Клиенты")
            If IsNumeric(.Cells(Rows.Count, 1).End(xlUp).Value) Then
                Id = CInt(.Cells(Rows.Count, 1).End(xlUp).Value) + 1
            Else
                Id = 1
            End If
            
            .Cells(Rows.Count, 1).End(xlUp).Offset(1).Value = Id
            .Cells(Rows.Count, 1).End(xlUp).Offset(0, 1) = Name
            .Cells(Rows.Count, 1).End(xlUp).Offset(0, 2) = Passport
            
            .Cells(Rows.Count, 1).End(xlUp).EntireColumn.AutoFit
            .Cells(Rows.Count, 1).End(xlUp).Offset(0, 1).EntireColumn.AutoFit
            .Cells(Rows.Count, 1).End(xlUp).Offset(0, 2).EntireColumn.AutoFit
            
            Range(.Cells(Rows.Count, 1).End(xlUp), .Cells(Rows.Count, 1).End(xlUp).Offset(0, 2)).Borders.LineStyle = True
        End With
        
        Deal.Cons.AddItem Name
    End If
End Sub
