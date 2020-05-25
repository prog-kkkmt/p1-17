VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} AddCurr 
   Caption         =   "Добавление валюты"
   ClientHeight    =   1830
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   3270
   OleObjectBlob   =   "AddCurr.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "AddCurr"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Add_Click()
    Dim Name As String
    Dim Rate As String
    Dim Id As Integer
    Dim Error As Boolean
    
    Error = False
    
    If NameObj.Value <> "" Then
        Name = NameObj.Value
    Else
        MsgBox "Введите название"
        Error = True
    End If
    
    If RateObj.Value <> "" Then
        Rate = RateObj.Value
    Else
        MsgBox "Введите курс"
        Error = True
    End If
    
    If Not Error Then
        AddCurr.Hide
        If IsNumeric(Cells(Rows.Count, 1).End(xlUp).Value) Then
            Id = CInt(Cells(Rows.Count, 1).End(xlUp).Value) + 1
        Else
            Id = 1
        End If
        
        Cells(Rows.Count, 1).End(xlUp).Offset(1).Select
        
        ActiveCell.Value = Id
        ActiveCell.Offset(0, 1) = Name
        ActiveCell.Offset(0, 2) = Rate
        
        ActiveCell.EntireColumn.AutoFit
        ActiveCell.Offset(0, 1).EntireColumn.AutoFit
        ActiveCell.Offset(0, 2).EntireColumn.AutoFit
        
        Range(ActiveCell, ActiveCell.Offset(0, 2)).Borders.LineStyle = True
    End If
End Sub
