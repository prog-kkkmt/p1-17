VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Deal 
   Caption         =   "Добавление сделки"
   ClientHeight    =   1890
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   6600
   OleObjectBlob   =   "Deal.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Deal"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub UserForm_Initialize()
    Dim ConsA() As Variant
    Dim CurrA() As Variant
    Dim Name As Variant
    
    If IsArray(Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        ConsA = Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        ConsA = Array(Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If
    If IsArray(Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        CurrA = Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        CurrA = Array(Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If
    
    Cons.MatchRequired = True
    Currs.MatchRequired = True
    
    For Each Name In ConsA
        Cons.AddItem Name
    Next Name
    For Each Name In CurrA
        Currs.AddItem Name
    Next Name
End Sub
Private Sub AddConB_Click()
    AddCon.Show
End Sub
Private Sub Add_Click()
    Dim IDCon As Integer
    Dim IDCur As Integer
    Dim Id As Integer
    Dim Sum1 As Integer
    Dim Con As String
    Dim Cur As String
    Dim Error As Boolean
    
    Con = Cons.Value
    Cur = Currs.Value
    
    If Con <> "" Then
        IDCon = CInt(Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Find(Con, LookIn:=xlValues).Offset(0, -1).Value)
    Else
        MsgBox "Выберите клиента"
        Error = True
    End If
    
    If Cur <> "" Then
        IDCur = CInt(Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Find(Cur, LookIn:=xlValues).Offset(0, -1).Value)
    Else
        MsgBox "Выберите валюту"
        Error = True
    End If
    
    If IsNumeric(Sum.Value) Then
        Sum1 = Sum.Value
    Else
        MsgBox "Некорректная сумма"
        Error = True
    End If
    
    If Not Error Then
        Deal.Hide
        
        If IsNumeric(Cells(Rows.Count, 1).End(xlUp).Value) Then
            Id = CInt(Cells(Rows.Count, 1).End(xlUp).Value) + 1
        Else
            Id = 1
        End If
        
        Cells(Rows.Count, 1).End(xlUp).Offset(1).Select
        
        ActiveCell.Value = Id
        ActiveCell.Offset(0, 1) = IDCon
        ActiveCell.Offset(0, 2) = IDCur
        ActiveCell.Offset(0, 3) = Sum1
        
        ActiveCell.EntireColumn.AutoFit
        ActiveCell.Offset(0, 1).EntireColumn.AutoFit
        ActiveCell.Offset(0, 2).EntireColumn.AutoFit
        ActiveCell.Offset(0, 3).EntireColumn.AutoFit
        
        Range(ActiveCell, ActiveCell.Offset(0, 3)).Borders.LineStyle = True
    End If
End Sub
